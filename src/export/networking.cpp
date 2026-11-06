#include "pch.hpp"
#include "core/globals.hpp"
#include <eiface.h>
#include <iserver.h>
#include <irecipientfilter.h>
#include <networksystem/inetworkmessages.h>
#include <networksystem/inetworkserializer.h>
#include <networksystem/netmessage.h>
#include <tier1/bitbuf.h>

class CSimpleRecipientFilter : public IRecipientFilter {
public:
    CSimpleRecipientFilter(uint64_t mask, int32_t bufType) : m_bufType(static_cast<NetChannelBufType_t>(bufType)) {
        m_recipients.Init(mask);
    }
    NetChannelBufType_t GetNetworkBufType() const override { return m_bufType; }
    bool IsInitMessage() const override { return false; }
    const CPlayerBitVec &GetRecipients() const override { return m_recipients; }
    CPlayerSlot GetPredictedByPlayerSlot() const override { return CPlayerSlot(-1); }
private:
    NetChannelBufType_t m_bufType;
    CPlayerBitVec m_recipients;
};

extern "C" {

PLUGIN_API void SendNetMessage(int32_t msgId, const plg::vector<uint8_t> &protoBytes, uint64_t recipientMask, int32_t bufType) {
    if (!dsdk::g_pNetworkMessages || !dsdk::g_pNetworkServerService) return;
    auto *server = dsdk::g_pNetworkServerService->GetNetworkServer();
    if (!server) return;

    char searchBuf[32];
    snprintf(searchBuf, sizeof(searchBuf), "[%d]", msgId);
    auto *serializer = dsdk::g_pNetworkMessages->FindNetworkMessagePartial(searchBuf);
    if (!serializer) return;

    auto *info = dsdk::g_pNetworkMessages->GetNetMessageInfo(serializer);
    if (!info) return;

    CNetMessage *msg = info->AllocateMessage();
    if (!msg) return;

    if (!protoBytes.empty()) {
        bf_read readBuf(protoBytes.data(), static_cast<int>(protoBytes.size()));
        dsdk::g_pNetworkMessages->UnserializeMessageInternal(readBuf, msg);
    }

    CSimpleRecipientFilter filter(recipientMask, bufType);
    server->BroadcastMessage(info, msg, &filter);
    delete msg;
}

PLUGIN_API plg::string GetNetMessageName(int32_t msgId) {
    if (!dsdk::g_pNetworkMessages) return plg::string("NetMessage");
    char searchBuf[32];
    snprintf(searchBuf, sizeof(searchBuf), "[%d]", msgId);
    auto *serializer = dsdk::g_pNetworkMessages->FindNetworkMessagePartial(searchBuf);
    if (serializer) {
        auto *info = dsdk::g_pNetworkMessages->GetNetMessageInfo(serializer);
        if (info && info->GetUnscopedName()) {
            return plg::string(info->GetUnscopedName());
        }
    }
    return plg::string("NetMessage");
}

}
