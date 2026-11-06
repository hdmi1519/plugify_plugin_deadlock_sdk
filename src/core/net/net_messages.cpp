#include "pch.hpp"
#include "core/net/net_messages.hpp"
#include "core/globals.hpp"
#include "core/logger.hpp"

#include <networksystem/inetworkmessages.h>
#include <networksystem/inetworkserializer.h>
#include <networksystem/netmessage.h>
#include <igameeventsystem.h>
#include <irecipientfilter.h>
#include <tier1/bitbuf.h>

#include <google/protobuf/message.h>

namespace dsdk {

// ----------------------------------------------------------------------------
// Wire-format Protobuf Encoder (Compact, Zero-allocation where possible)
// ----------------------------------------------------------------------------
namespace proto_writer {

inline void WriteVarint(std::vector<uint8_t> &buf, uint64_t val) {
    while (val > 0x7F) {
        buf.push_back(static_cast<uint8_t>((val & 0x7F) | 0x80));
        val >>= 7;
    }
    buf.push_back(static_cast<uint8_t>(val & 0x7F));
}

inline void WriteInt32(std::vector<uint8_t> &buf, uint32_t fieldNumber, int32_t val) {
    WriteVarint(buf, (fieldNumber << 3) | 0);
    WriteVarint(buf, static_cast<uint64_t>(static_cast<int64_t>(val)));
}

inline void WriteBool(std::vector<uint8_t> &buf, uint32_t fieldNumber, bool val) {
    WriteVarint(buf, (fieldNumber << 3) | 0);
    buf.push_back(val ? 1 : 0);
}

inline void WriteString(std::vector<uint8_t> &buf, uint32_t fieldNumber, std::string_view str) {
    WriteVarint(buf, (fieldNumber << 3) | 2);
    WriteVarint(buf, str.size());
    buf.insert(buf.end(), str.begin(), str.end());
}

inline void WriteFloat(std::vector<uint8_t> &buf, uint32_t fieldNumber, float val) {
    WriteVarint(buf, (fieldNumber << 3) | 5);
    uint8_t bytes[4];
    std::memcpy(bytes, &val, 4);
    buf.insert(buf.end(), bytes, bytes + 4);
}

} // namespace proto_writer

// ----------------------------------------------------------------------------
// Source 2 Recipient Filter
// ----------------------------------------------------------------------------
class CRecipientFilter : public IRecipientFilter {
public:
    CRecipientFilter(NetChannelBufType_t nBufType = BUF_RELIABLE, bool bInitMessage = false)
        : m_nBufType(nBufType), m_bInitMessage(bInitMessage) {}

    ~CRecipientFilter() override = default;

    NetChannelBufType_t GetNetworkBufType(void) const override { return m_nBufType; }
    bool IsInitMessage(void) const override { return m_bInitMessage; }
    const CPlayerBitVec &GetRecipients(void) const override { return m_Recipients; }
    CPlayerSlot GetPredictedByPlayerSlot(void) const override { return -1; }

    void AddRecipient(CPlayerSlot slot) {
        if (slot.Get() >= 0 && slot.Get() < ABSOLUTE_PLAYER_LIMIT)
            m_Recipients.Set(slot.Get());
    }

protected:
    NetChannelBufType_t m_nBufType;
    bool m_bInitMessage;
    CPlayerBitVec m_Recipients;
};

// ----------------------------------------------------------------------------
// NetMessage Dispatcher
// ----------------------------------------------------------------------------
bool SendNetMessage(int msgId, const char *partialName, const uint8_t *protoBytes, int protoLen, uint64_t recipientMask, bool reliable) {
    if (!g_pNetworkMessages || !g_pGameEventSystem || !protoBytes || protoLen <= 0) {
        return false;
    }

    INetworkSerializerPB *serializer = g_pNetworkMessages->FindNetworkMessageById(static_cast<NetworkMessageId>(msgId));
    if (!serializer && partialName) {
        serializer = g_pNetworkMessages->FindNetworkMessagePartial(partialName);
    }
    if (!serializer) {
        Logger::Warning("SendNetMessage: serializer for msg {} ({}) not found", msgId, partialName ? partialName : "null");
        return false;
    }

    CNetMessage *msg = serializer->AllocateMessage();
    if (!msg) {
        return false;
    }

    auto *pbMsg = const_cast<google::protobuf::Message *>(msg->AsMessage());
    bool parsed = false;
    if (pbMsg) {
        parsed = pbMsg->ParseFromArray(protoBytes, protoLen);
    }

    if (parsed) {
        CRecipientFilter filter(reliable ? BUF_RELIABLE : BUF_UNRELIABLE);
        for (int i = 0; i < ABSOLUTE_PLAYER_LIMIT; ++i) {
            if (recipientMask & (1ULL << i)) {
                filter.AddRecipient(CPlayerSlot(i));
            }
        }
        g_pGameEventSystem->PostEventAbstract(-1, false, &filter, serializer, msg, 0);
    } else {
        Logger::Warning("SendNetMessage: failed to deserialize proto message (msgId={})", msgId);
    }

    delete msg;
    return parsed;
}

// ----------------------------------------------------------------------------
// High-Level Message Helpers
// ----------------------------------------------------------------------------

// CUserMessageTextMsg (id 124)
void SendTextMsg(int32_t playerSlot, uint32_t dest, std::string_view text) {
    std::vector<uint8_t> bytes;
    proto_writer::WriteInt32(bytes, 1, static_cast<int32_t>(dest));
    proto_writer::WriteString(bytes, 2, text);

    uint64_t mask = (playerSlot >= 0 && playerSlot < 64) ? (1ULL << playerSlot) : 0xFFFFFFFFFFFFFFFFULL;
    SendNetMessage(124, "TextMsg", bytes.data(), static_cast<int>(bytes.size()), mask, true);
}

void SendTextMsgAll(uint32_t dest, std::string_view text) {
    std::vector<uint8_t> bytes;
    proto_writer::WriteInt32(bytes, 1, static_cast<int32_t>(dest));
    proto_writer::WriteString(bytes, 2, text);

    SendNetMessage(124, "TextMsg", bytes.data(), static_cast<int>(bytes.size()), 0xFFFFFFFFFFFFFFFFULL, true);
}

// CCitadelUserMsg_ChatMsg (id 314)
void SendChatMsg(int32_t playerSlot, std::string_view text, bool allChat) {
    std::vector<uint8_t> bytes;
    proto_writer::WriteInt32(bytes, 1, playerSlot);
    proto_writer::WriteString(bytes, 2, text);
    proto_writer::WriteBool(bytes, 3, allChat);
    proto_writer::WriteInt32(bytes, 4, 0);

    uint64_t mask = (playerSlot >= 0 && playerSlot < 64) ? (1ULL << playerSlot) : 0xFFFFFFFFFFFFFFFFULL;
    SendNetMessage(314, "ChatMsg", bytes.data(), static_cast<int>(bytes.size()), mask, true);
}

void SendChatMsgAll(std::string_view text) {
    std::vector<uint8_t> bytes;
    proto_writer::WriteInt32(bytes, 1, -1);
    proto_writer::WriteString(bytes, 2, text);
    proto_writer::WriteBool(bytes, 3, true);
    proto_writer::WriteInt32(bytes, 4, 0);

    SendNetMessage(314, "ChatMsg", bytes.data(), static_cast<int>(bytes.size()), 0xFFFFFFFFFFFFFFFFULL, true);
}

// CCitadelUserMsg_HudGameAnnouncement (id 363)
void SendHudAnnouncement(int32_t playerSlot, std::string_view title, std::string_view description, float duration) {
    (void)duration;
    std::vector<uint8_t> bytes;
    proto_writer::WriteString(bytes, 1, title);
    proto_writer::WriteString(bytes, 2, description);

    uint64_t mask = (playerSlot >= 0 && playerSlot < 64) ? (1ULL << playerSlot) : 0xFFFFFFFFFFFFFFFFULL;
    SendNetMessage(363, "HudGameAnnouncement", bytes.data(), static_cast<int>(bytes.size()), mask, true);
}

void SendHudAnnouncementAll(std::string_view title, std::string_view description, float duration) {
    (void)duration;
    std::vector<uint8_t> bytes;
    proto_writer::WriteString(bytes, 1, title);
    proto_writer::WriteString(bytes, 2, description);

    SendNetMessage(363, "HudGameAnnouncement", bytes.data(), static_cast<int>(bytes.size()), 0xFFFFFFFFFFFFFFFFULL, true);
}

} // namespace dsdk
