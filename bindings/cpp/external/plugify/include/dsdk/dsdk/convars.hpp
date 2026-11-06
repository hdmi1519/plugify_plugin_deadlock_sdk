#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from dsdk.pplugin (group: convars)

namespace dsdk {

  using _FindConVar = uint64_t (*)(const plg::string&);
}
extern "C" PLUGIN_API dsdk::_FindConVar __dsdk_FindConVar;
namespace dsdk {
  /**
   * @brief Find ConVar by name
   * @param name (string)
   * @return uint64
   */
  inline uint64_t FindConVar(const plg::string& name) {
    return __dsdk_FindConVar(name);
  }

  using _CreateConVar = uint64_t (*)(const plg::string&, const plg::string&, const plg::string&, uint64_t);
}
extern "C" PLUGIN_API dsdk::_CreateConVar __dsdk_CreateConVar;
namespace dsdk {
  /**
   * @brief Create custom ConVar
   * @param name (string)
   * @param defaultValue (string)
   * @param description (string)
   * @param flags (uint64)
   * @return uint64
   */
  inline uint64_t CreateConVar(const plg::string& name, const plg::string& defaultValue, const plg::string& description, uint64_t flags) {
    return __dsdk_CreateConVar(name, defaultValue, description, flags);
  }

  using _GetConVarInt = int32_t (*)(uint64_t);
}
extern "C" PLUGIN_API dsdk::_GetConVarInt __dsdk_GetConVarInt;
namespace dsdk {
  /**
   * @brief Get ConVar integer value
   * @param handle (uint64)
   * @return int32
   */
  inline int32_t GetConVarInt(uint64_t handle) {
    return __dsdk_GetConVarInt(handle);
  }

  using _GetConVarFloat = float (*)(uint64_t);
}
extern "C" PLUGIN_API dsdk::_GetConVarFloat __dsdk_GetConVarFloat;
namespace dsdk {
  /**
   * @brief Get ConVar float value
   * @param handle (uint64)
   * @return float
   */
  inline float GetConVarFloat(uint64_t handle) {
    return __dsdk_GetConVarFloat(handle);
  }

  using _GetConVarString = plg::string (*)(uint64_t);
}
extern "C" PLUGIN_API dsdk::_GetConVarString __dsdk_GetConVarString;
namespace dsdk {
  /**
   * @brief Get ConVar string value
   * @param handle (uint64)
   * @return string
   */
  inline plg::string GetConVarString(uint64_t handle) {
    return __dsdk_GetConVarString(handle);
  }

  using _GetConVarBool = bool (*)(uint64_t);
}
extern "C" PLUGIN_API dsdk::_GetConVarBool __dsdk_GetConVarBool;
namespace dsdk {
  /**
   * @brief Get ConVar bool value
   * @param handle (uint64)
   * @return bool
   */
  inline bool GetConVarBool(uint64_t handle) {
    return __dsdk_GetConVarBool(handle);
  }

  using _SetConVarInt = void (*)(uint64_t, int32_t);
}
extern "C" PLUGIN_API dsdk::_SetConVarInt __dsdk_SetConVarInt;
namespace dsdk {
  /**
   * @brief Set ConVar int value
   * @param handle (uint64)
   * @param value (int32)
   */
  inline void SetConVarInt(uint64_t handle, int32_t value) {
    return __dsdk_SetConVarInt(handle, value);
  }

  using _SetConVarFloat = void (*)(uint64_t, float);
}
extern "C" PLUGIN_API dsdk::_SetConVarFloat __dsdk_SetConVarFloat;
namespace dsdk {
  /**
   * @brief Set ConVar float value
   * @param handle (uint64)
   * @param value (float)
   */
  inline void SetConVarFloat(uint64_t handle, float value) {
    return __dsdk_SetConVarFloat(handle, value);
  }

  using _SetConVarString = bool (*)(uint64_t, const plg::string&);
}
extern "C" PLUGIN_API dsdk::_SetConVarString __dsdk_SetConVarString;
namespace dsdk {
  /**
   * @brief Set ConVar string value
   * @param handle (uint64)
   * @param value (string)
   * @return bool
   */
  inline bool SetConVarString(uint64_t handle, const plg::string& value) {
    return __dsdk_SetConVarString(handle, value);
  }

} // namespace dsdk
