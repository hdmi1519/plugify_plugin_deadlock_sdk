// Generated from dsdk.pplugin (group: commands)

export module dsdk.commands;
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

  using _AddServerCommand = bool (*)(const plg::string&, const plg::string&, int64_t, CommandCallback);
  PLUGIFY_EXPORT _AddServerCommand __dsdk_AddServerCommand = nullptr;
  /**
   * @brief Register a server-console-only command
   * @param name (string)
   * @param description (string)
   * @param flags (int64)
   * @param callback (function)
   * @return bool
   */

  bool AddServerCommand(const plg::string& name, const plg::string& description, int64_t flags, CommandCallback callback) {
    return __dsdk_AddServerCommand(name, description, flags, callback);
  }

  using _AddClientCommand = bool (*)(const plg::string&, const plg::string&, int64_t, CommandCallback);
  PLUGIFY_EXPORT _AddClientCommand __dsdk_AddClientCommand = nullptr;
  /**
   * @brief Register a client-console-only command
   * @param name (string)
   * @param description (string)
   * @param flags (int64)
   * @param callback (function)
   * @return bool
   */

  bool AddClientCommand(const plg::string& name, const plg::string& description, int64_t flags, CommandCallback callback) {
    return __dsdk_AddClientCommand(name, description, flags, callback);
  }

  using _AddChatCommand = bool (*)(const plg::string&, const plg::string&, int64_t, CommandCallback);
  PLUGIFY_EXPORT _AddChatCommand __dsdk_AddChatCommand = nullptr;
  /**
   * @brief Register a client-chat-only command
   * @param name (string)
   * @param description (string)
   * @param flags (int64)
   * @param callback (function)
   * @return bool
   */

  bool AddChatCommand(const plg::string& name, const plg::string& description, int64_t flags, CommandCallback callback) {
    return __dsdk_AddChatCommand(name, description, flags, callback);
  }

  using _AddConsoleCommand = bool (*)(const plg::string&, const plg::string&, int64_t, CommandCallback);
  PLUGIFY_EXPORT _AddConsoleCommand __dsdk_AddConsoleCommand = nullptr;
  /**
   * @brief Register a server/chat console command
   * @param name (string)
   * @param description (string)
   * @param flags (int64)
   * @param callback (function)
   * @return bool
   */

  bool AddConsoleCommand(const plg::string& name, const plg::string& description, int64_t flags, CommandCallback callback) {
    return __dsdk_AddConsoleCommand(name, description, flags, callback);
  }

  using _RemoveCommand = bool (*)(const plg::string&);
  PLUGIFY_EXPORT _RemoveCommand __dsdk_RemoveCommand = nullptr;
  /**
   * @brief Unregister a console command
   * @param name (string)
   * @return bool
   */

  bool RemoveCommand(const plg::string& name) {
    return __dsdk_RemoveCommand(name);
  }

  using _ServerCommand = void (*)(const plg::string&);
  PLUGIFY_EXPORT _ServerCommand __dsdk_ServerCommand = nullptr;
  /**
   * @brief Execute a command on the server console
   * @param command (string)
   */

  void ServerCommand(const plg::string& command) {
    return __dsdk_ServerCommand(command);
  }

  using _ExecuteCommandAsPlayer = bool (*)(int32_t, const plg::string&);
  PLUGIFY_EXPORT _ExecuteCommandAsPlayer __dsdk_ExecuteCommandAsPlayer = nullptr;
  /**
   * @brief Execute a command on behalf of a player
   * @param playerSlot (int32)
   * @param command (string)
   * @return bool
   */

  bool ExecuteCommandAsPlayer(int32_t playerSlot, const plg::string& command) {
    return __dsdk_ExecuteCommandAsPlayer(playerSlot, command);
  }

  using _ClientCommand = void (*)(int32_t, const plg::string&);
  PLUGIFY_EXPORT _ClientCommand __dsdk_ClientCommand = nullptr;
  /**
   * @brief Execute command on client
   * @param playerSlot (int32)
   * @param command (string)
   */

  void ClientCommand(int32_t playerSlot, const plg::string& command) {
    return __dsdk_ClientCommand(playerSlot, command);
  }

} // namespace dsdk
