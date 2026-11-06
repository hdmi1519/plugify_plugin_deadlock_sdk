#include "pch.hpp"
#include "core/globals.hpp"
#include "core/net/net_messages.hpp"
#include <eiface.h>
#include <tier0/dbg.h>

extern "C" {

PLUGIN_API void PrintToChat(int32_t playerSlot, const plg::string &message) {
    dsdk::SendChatMsg(playerSlot, message.c_str());
}

PLUGIN_API void PrintToChatAll(const plg::string &message) {
    dsdk::SendChatMsgAll(message.c_str());
}

PLUGIN_API void PrintToConsole(int32_t playerSlot, const plg::string &message) {
    if (playerSlot < 0) {
        Msg("%s\n", message.c_str());
        return;
    }
    dsdk::SendTextMsg(playerSlot, 2, message.c_str());
}

PLUGIN_API void PrintToConsoleAll(const plg::string &message) {
    Msg("%s\n", message.c_str());
    dsdk::SendTextMsgAll(2, message.c_str());
}

PLUGIN_API void HudAnnounce(int32_t playerSlot, const plg::string &title, const plg::string &description, float duration) {
    dsdk::SendHudAnnouncement(playerSlot, title.c_str(), description.c_str(), duration);
}

PLUGIN_API void HudAnnounceAll(const plg::string &title, const plg::string &description, float duration) {
    dsdk::SendHudAnnouncementAll(title.c_str(), description.c_str(), duration);
}

}
