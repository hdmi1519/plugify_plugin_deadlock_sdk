// Generated from dsdk.pplugin (group: chat)

export module dsdk.chat;
export import dsdk.enums;
export import dsdk.aliases;
export import dsdk.delegates;

import <cstdint>;
import <plg>;

#if defined(_WIN32)
#define PLUGIFY_EXPORT __declspec(dllexport)
#else
#define PLUGIFY_EXPORT __attribute__((visibility("default")))
#endif

export namespace dsdk {

  using _PrintToChat = void (*)(int32_t, const plg::string&);
  PLUGIFY_EXPORT _PrintToChat __dsdk_PrintToChat = nullptr;
  /**
   * @brief Print message to client chat
   * @param playerSlot (int32)
   * @param message (string)
   */

  void PrintToChat(int32_t playerSlot, const plg::string& message) {
    return __dsdk_PrintToChat(playerSlot, message);
  }

  using _PrintToChatAll = void (*)(const plg::string&);
  PLUGIFY_EXPORT _PrintToChatAll __dsdk_PrintToChatAll = nullptr;
  /**
   * @brief Broadcast message to all players
   * @param message (string)
   */

  void PrintToChatAll(const plg::string& message) {
    return __dsdk_PrintToChatAll(message);
  }

  using _PrintToConsole = void (*)(int32_t, const plg::string&);
  PLUGIFY_EXPORT _PrintToConsole __dsdk_PrintToConsole = nullptr;
  /**
   * @brief Print message to client console
   * @param playerSlot (int32)
   * @param message (string)
   */

  void PrintToConsole(int32_t playerSlot, const plg::string& message) {
    return __dsdk_PrintToConsole(playerSlot, message);
  }

  using _PrintToConsoleAll = void (*)(const plg::string&);
  PLUGIFY_EXPORT _PrintToConsoleAll __dsdk_PrintToConsoleAll = nullptr;
  /**
   * @brief Print message to all player consoles
   * @param message (string)
   */

  void PrintToConsoleAll(const plg::string& message) {
    return __dsdk_PrintToConsoleAll(message);
  }

  using _HudAnnounce = void (*)(int32_t, const plg::string&, const plg::string&, float);
  PLUGIFY_EXPORT _HudAnnounce __dsdk_HudAnnounce = nullptr;
  /**
   * @brief Display a HUD game announcement banner to a player
   * @param playerSlot (int32)
   * @param title (string)
   * @param description (string)
   * @param duration (float)
   */

  void HudAnnounce(int32_t playerSlot, const plg::string& title, const plg::string& description, float duration) {
    return __dsdk_HudAnnounce(playerSlot, title, description, duration);
  }

  using _HudAnnounceAll = void (*)(const plg::string&, const plg::string&, float);
  PLUGIFY_EXPORT _HudAnnounceAll __dsdk_HudAnnounceAll = nullptr;
  /**
   * @brief Display a HUD game announcement banner to all players
   * @param title (string)
   * @param description (string)
   * @param duration (float)
   */

  void HudAnnounceAll(const plg::string& title, const plg::string& description, float duration) {
    return __dsdk_HudAnnounceAll(title, description, duration);
  }

} // namespace dsdk
