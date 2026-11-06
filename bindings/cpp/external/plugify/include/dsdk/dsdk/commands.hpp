#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from dsdk.pplugin (group: commands)

namespace dsdk {

  using _AddServerCommand = bool (*)(const plg::string&, const plg::string&, int64_t, CommandCallback);
}
extern "C" PLUGIN_API dsdk::_AddServerCommand __dsdk_AddServerCommand;
namespace dsdk {
  /**
   * @brief Register a server-console-only command
   * @param name (string)
   * @param description (string)
   * @param flags (int64)
   * @param callback (function)
   * @return bool
   */
  inline bool AddServerCommand(const plg::string& name, const plg::string& description, int64_t flags, CommandCallback callback) {
    return __dsdk_AddServerCommand(name, description, flags, callback);
  }

  using _AddClientCommand = bool (*)(const plg::string&, const plg::string&, int64_t, CommandCallback);
}
extern "C" PLUGIN_API dsdk::_AddClientCommand __dsdk_AddClientCommand;
namespace dsdk {
  /**
   * @brief Register a client-console-only command
   * @param name (string)
   * @param description (string)
   * @param flags (int64)
   * @param callback (function)
   * @return bool
   */
  inline bool AddClientCommand(const plg::string& name, const plg::string& description, int64_t flags, CommandCallback callback) {
    return __dsdk_AddClientCommand(name, description, flags, callback);
  }

  using _AddChatCommand = bool (*)(const plg::string&, const plg::string&, int64_t, CommandCallback);
}
extern "C" PLUGIN_API dsdk::_AddChatCommand __dsdk_AddChatCommand;
namespace dsdk {
  /**
   * @brief Register a client-chat-only command
   * @param name (string)
   * @param description (string)
   * @param flags (int64)
   * @param callback (function)
   * @return bool
   */
  inline bool AddChatCommand(const plg::string& name, const plg::string& description, int64_t flags, CommandCallback callback) {
    return __dsdk_AddChatCommand(name, description, flags, callback);
  }

  using _AddConsoleCommand = bool (*)(const plg::string&, const plg::string&, int64_t, CommandCallback);
}
extern "C" PLUGIN_API dsdk::_AddConsoleCommand __dsdk_AddConsoleCommand;
namespace dsdk {
  /**
   * @brief Register a server/chat console command
   * @param name (string)
   * @param description (string)
   * @param flags (int64)
   * @param callback (function)
   * @return bool
   */
  inline bool AddConsoleCommand(const plg::string& name, const plg::string& description, int64_t flags, CommandCallback callback) {
    return __dsdk_AddConsoleCommand(name, description, flags, callback);
  }

  using _RemoveCommand = bool (*)(const plg::string&);
}
extern "C" PLUGIN_API dsdk::_RemoveCommand __dsdk_RemoveCommand;
namespace dsdk {
  /**
   * @brief Unregister a console command
   * @param name (string)
   * @return bool
   */
  inline bool RemoveCommand(const plg::string& name) {
    return __dsdk_RemoveCommand(name);
  }

  using _ServerCommand = void (*)(const plg::string&);
}
extern "C" PLUGIN_API dsdk::_ServerCommand __dsdk_ServerCommand;
namespace dsdk {
  /**
   * @brief Execute a command on the server console
   * @param command (string)
   */
  inline void ServerCommand(const plg::string& command) {
    return __dsdk_ServerCommand(command);
  }

  using _ExecuteCommandAsPlayer = bool (*)(int32_t, const plg::string&);
}
extern "C" PLUGIN_API dsdk::_ExecuteCommandAsPlayer __dsdk_ExecuteCommandAsPlayer;
namespace dsdk {
  /**
   * @brief Execute a command on behalf of a player
   * @param playerSlot (int32)
   * @param command (string)
   * @return bool
   */
  inline bool ExecuteCommandAsPlayer(int32_t playerSlot, const plg::string& command) {
    return __dsdk_ExecuteCommandAsPlayer(playerSlot, command);
  }

  using _ClientCommand = void (*)(int32_t, const plg::string&);
}
extern "C" PLUGIN_API dsdk::_ClientCommand __dsdk_ClientCommand;
namespace dsdk {
  /**
   * @brief Execute command on client
   * @param playerSlot (int32)
   * @param command (string)
   */
  inline void ClientCommand(int32_t playerSlot, const plg::string& command) {
    return __dsdk_ClientCommand(playerSlot, command);
  }

} // namespace dsdk
