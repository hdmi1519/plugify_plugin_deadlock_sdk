#pragma once

#include <cstdint>
#include <string_view>
#include <vector>
#include <plg/string.hpp>

namespace dsdk {

bool SendNetMessage(int msgId, const char *partialName, const uint8_t *protoBytes, int protoLen, uint64_t recipientMask, bool reliable = true);

// NetMessage Helpers
void SendTextMsg(int32_t playerSlot, uint32_t dest, std::string_view text);
void SendTextMsgAll(uint32_t dest, std::string_view text);
void SendChatMsg(int32_t playerSlot, std::string_view text, bool allChat = true);
void SendChatMsgAll(std::string_view text);
void SendHudAnnouncement(int32_t playerSlot, std::string_view title, std::string_view description, float duration = 5.0f);
void SendHudAnnouncementAll(std::string_view title, std::string_view description, float duration = 5.0f);

} // namespace dsdk
