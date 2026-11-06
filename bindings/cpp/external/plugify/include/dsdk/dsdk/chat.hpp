#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from dsdk.pplugin (group: chat)

namespace dsdk {

  using _PrintToChat = void (*)(int32_t, const plg::string&);
}
extern "C" PLUGIN_API dsdk::_PrintToChat __dsdk_PrintToChat;
namespace dsdk {
  /**
   * @brief Print message to client chat
   * @param playerSlot (int32)
   * @param message (string)
   */
  inline void PrintToChat(int32_t playerSlot, const plg::string& message) {
    return __dsdk_PrintToChat(playerSlot, message);
  }

  using _PrintToChatAll = void (*)(const plg::string&);
}
extern "C" PLUGIN_API dsdk::_PrintToChatAll __dsdk_PrintToChatAll;
namespace dsdk {
  /**
   * @brief Broadcast message to all players
   * @param message (string)
   */
  inline void PrintToChatAll(const plg::string& message) {
    return __dsdk_PrintToChatAll(message);
  }

  using _PrintToConsole = void (*)(int32_t, const plg::string&);
}
extern "C" PLUGIN_API dsdk::_PrintToConsole __dsdk_PrintToConsole;
namespace dsdk {
  /**
   * @brief Print message to client console
   * @param playerSlot (int32)
   * @param message (string)
   */
  inline void PrintToConsole(int32_t playerSlot, const plg::string& message) {
    return __dsdk_PrintToConsole(playerSlot, message);
  }

  using _PrintToConsoleAll = void (*)(const plg::string&);
}
extern "C" PLUGIN_API dsdk::_PrintToConsoleAll __dsdk_PrintToConsoleAll;
namespace dsdk {
  /**
   * @brief Print message to all player consoles
   * @param message (string)
   */
  inline void PrintToConsoleAll(const plg::string& message) {
    return __dsdk_PrintToConsoleAll(message);
  }

  using _HudAnnounce = void (*)(int32_t, const plg::string&, const plg::string&, float);
}
extern "C" PLUGIN_API dsdk::_HudAnnounce __dsdk_HudAnnounce;
namespace dsdk {
  /**
   * @brief Display a HUD game announcement banner to a player
   * @param playerSlot (int32)
   * @param title (string)
   * @param description (string)
   * @param duration (float)
   */
  inline void HudAnnounce(int32_t playerSlot, const plg::string& title, const plg::string& description, float duration) {
    return __dsdk_HudAnnounce(playerSlot, title, description, duration);
  }

  using _HudAnnounceAll = void (*)(const plg::string&, const plg::string&, float);
}
extern "C" PLUGIN_API dsdk::_HudAnnounceAll __dsdk_HudAnnounceAll;
namespace dsdk {
  /**
   * @brief Display a HUD game announcement banner to all players
   * @param title (string)
   * @param description (string)
   * @param duration (float)
   */
  inline void HudAnnounceAll(const plg::string& title, const plg::string& description, float duration) {
    return __dsdk_HudAnnounceAll(title, description, duration);
  }

} // namespace dsdk
