#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from dsdk.pplugin (group: events)

namespace dsdk {

  using _RegisterGameEvent = void (*)(const plg::string&);
}
extern "C" PLUGIN_API dsdk::_RegisterGameEvent __dsdk_RegisterGameEvent;
namespace dsdk {
  /**
   * @brief Register game event listener for engine event
   * @param name (string)
   */
  inline void RegisterGameEvent(const plg::string& name) {
    return __dsdk_RegisterGameEvent(name);
  }

  using _CreateGameEvent = int64_t (*)(const plg::string&, bool);
}
extern "C" PLUGIN_API dsdk::_CreateGameEvent __dsdk_CreateGameEvent;
namespace dsdk {
  /**
   * @brief Create a new game event
   * @param name (string)
   * @param force (bool)
   * @return int64
   */
  inline int64_t CreateGameEvent(const plg::string& name, bool force) {
    return __dsdk_CreateGameEvent(name, force);
  }

  using _FireGameEvent = bool (*)(int64_t, bool);
}
extern "C" PLUGIN_API dsdk::_FireGameEvent __dsdk_FireGameEvent;
namespace dsdk {
  /**
   * @brief Fire game event
   * @param event (int64)
   * @param dontBroadcast (bool)
   * @return bool
   */
  inline bool FireGameEvent(int64_t event, bool dontBroadcast) {
    return __dsdk_FireGameEvent(event, dontBroadcast);
  }

  using _FreeGameEvent = void (*)(int64_t);
}
extern "C" PLUGIN_API dsdk::_FreeGameEvent __dsdk_FreeGameEvent;
namespace dsdk {
  /**
   * @brief Free game event object
   * @param event (int64)
   */
  inline void FreeGameEvent(int64_t event) {
    return __dsdk_FreeGameEvent(event);
  }

  using _GameEventGetBool = bool (*)(int64_t, const plg::string&, bool);
}
extern "C" PLUGIN_API dsdk::_GameEventGetBool __dsdk_GameEventGetBool;
namespace dsdk {
  /**
   * @brief Get boolean key from game event
   * @param event (int64)
   * @param key (string)
   * @param def (bool)
   * @return bool
   */
  inline bool GameEventGetBool(int64_t event, const plg::string& key, bool def) {
    return __dsdk_GameEventGetBool(event, key, def);
  }

  using _GameEventGetInt = int32_t (*)(int64_t, const plg::string&, int32_t);
}
extern "C" PLUGIN_API dsdk::_GameEventGetInt __dsdk_GameEventGetInt;
namespace dsdk {
  /**
   * @brief Get int32 key from game event
   * @param event (int64)
   * @param key (string)
   * @param def (int32)
   * @return int32
   */
  inline int32_t GameEventGetInt(int64_t event, const plg::string& key, int32_t def) {
    return __dsdk_GameEventGetInt(event, key, def);
  }

  using _GameEventGetFloat = float (*)(int64_t, const plg::string&, float);
}
extern "C" PLUGIN_API dsdk::_GameEventGetFloat __dsdk_GameEventGetFloat;
namespace dsdk {
  /**
   * @brief Get float key from game event
   * @param event (int64)
   * @param key (string)
   * @param def (float)
   * @return float
   */
  inline float GameEventGetFloat(int64_t event, const plg::string& key, float def) {
    return __dsdk_GameEventGetFloat(event, key, def);
  }

  using _GameEventGetString = plg::string (*)(int64_t, const plg::string&, const plg::string&);
}
extern "C" PLUGIN_API dsdk::_GameEventGetString __dsdk_GameEventGetString;
namespace dsdk {
  /**
   * @brief Get string key from game event
   * @param event (int64)
   * @param key (string)
   * @param def (string)
   * @return string
   */
  inline plg::string GameEventGetString(int64_t event, const plg::string& key, const plg::string& def) {
    return __dsdk_GameEventGetString(event, key, def);
  }

  using _GameEventGetUint64 = uint64_t (*)(int64_t, const plg::string&, uint64_t);
}
extern "C" PLUGIN_API dsdk::_GameEventGetUint64 __dsdk_GameEventGetUint64;
namespace dsdk {
  /**
   * @brief Get uint64 key from game event
   * @param event (int64)
   * @param key (string)
   * @param def (uint64)
   * @return uint64
   */
  inline uint64_t GameEventGetUint64(int64_t event, const plg::string& key, uint64_t def) {
    return __dsdk_GameEventGetUint64(event, key, def);
  }

  using _GameEventSetBool = void (*)(int64_t, const plg::string&, bool);
}
extern "C" PLUGIN_API dsdk::_GameEventSetBool __dsdk_GameEventSetBool;
namespace dsdk {
  /**
   * @brief Set boolean key in game event
   * @param event (int64)
   * @param key (string)
   * @param val (bool)
   */
  inline void GameEventSetBool(int64_t event, const plg::string& key, bool val) {
    return __dsdk_GameEventSetBool(event, key, val);
  }

  using _GameEventSetInt = void (*)(int64_t, const plg::string&, int32_t);
}
extern "C" PLUGIN_API dsdk::_GameEventSetInt __dsdk_GameEventSetInt;
namespace dsdk {
  /**
   * @brief Set int32 key in game event
   * @param event (int64)
   * @param key (string)
   * @param val (int32)
   */
  inline void GameEventSetInt(int64_t event, const plg::string& key, int32_t val) {
    return __dsdk_GameEventSetInt(event, key, val);
  }

  using _GameEventSetFloat = void (*)(int64_t, const plg::string&, float);
}
extern "C" PLUGIN_API dsdk::_GameEventSetFloat __dsdk_GameEventSetFloat;
namespace dsdk {
  /**
   * @brief Set float key in game event
   * @param event (int64)
   * @param key (string)
   * @param val (float)
   */
  inline void GameEventSetFloat(int64_t event, const plg::string& key, float val) {
    return __dsdk_GameEventSetFloat(event, key, val);
  }

  using _GameEventSetString = void (*)(int64_t, const plg::string&, const plg::string&);
}
extern "C" PLUGIN_API dsdk::_GameEventSetString __dsdk_GameEventSetString;
namespace dsdk {
  /**
   * @brief Set string key in game event
   * @param event (int64)
   * @param key (string)
   * @param val (string)
   */
  inline void GameEventSetString(int64_t event, const plg::string& key, const plg::string& val) {
    return __dsdk_GameEventSetString(event, key, val);
  }

  using _GameEventGetPlayerSlot = int32_t (*)(int64_t, const plg::string&);
}
extern "C" PLUGIN_API dsdk::_GameEventGetPlayerSlot __dsdk_GameEventGetPlayerSlot;
namespace dsdk {
  /**
   * @brief Gets player slot from an event key (e.g. userid)
   * @param event (int64)
   * @param key (string)
   * @return int32
   */
  inline int32_t GameEventGetPlayerSlot(int64_t event, const plg::string& key) {
    return __dsdk_GameEventGetPlayerSlot(event, key);
  }

  using _GameEventGetPlayerPawn = int64_t (*)(int64_t, const plg::string&);
}
extern "C" PLUGIN_API dsdk::_GameEventGetPlayerPawn __dsdk_GameEventGetPlayerPawn;
namespace dsdk {
  /**
   * @brief Gets player pawn pointer from an event key (e.g. userid)
   * @param event (int64)
   * @param key (string)
   * @return int64
   */
  inline int64_t GameEventGetPlayerPawn(int64_t event, const plg::string& key) {
    return __dsdk_GameEventGetPlayerPawn(event, key);
  }

  using _GameEventGetPlayerController = int64_t (*)(int64_t, const plg::string&);
}
extern "C" PLUGIN_API dsdk::_GameEventGetPlayerController __dsdk_GameEventGetPlayerController;
namespace dsdk {
  /**
   * @brief Gets player controller pointer from an event key (e.g. userid)
   * @param event (int64)
   * @param key (string)
   * @return int64
   */
  inline int64_t GameEventGetPlayerController(int64_t event, const plg::string& key) {
    return __dsdk_GameEventGetPlayerController(event, key);
  }

} // namespace dsdk
