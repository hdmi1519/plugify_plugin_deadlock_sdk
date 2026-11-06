// Generated from dsdk.pplugin (group: convars)

export module dsdk.convars;
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

  using _FindConVar = uint64_t (*)(const plg::string&);
  PLUGIFY_EXPORT _FindConVar __dsdk_FindConVar = nullptr;
  /**
   * @brief Find ConVar by name
   * @param name (string)
   * @return uint64
   */

  uint64_t FindConVar(const plg::string& name) {
    return __dsdk_FindConVar(name);
  }

  using _CreateConVar = uint64_t (*)(const plg::string&, const plg::string&, const plg::string&, uint64_t);
  PLUGIFY_EXPORT _CreateConVar __dsdk_CreateConVar = nullptr;
  /**
   * @brief Create custom ConVar
   * @param name (string)
   * @param defaultValue (string)
   * @param description (string)
   * @param flags (uint64)
   * @return uint64
   */

  uint64_t CreateConVar(const plg::string& name, const plg::string& defaultValue, const plg::string& description, uint64_t flags) {
    return __dsdk_CreateConVar(name, defaultValue, description, flags);
  }

  using _GetConVarInt = int32_t (*)(uint64_t);
  PLUGIFY_EXPORT _GetConVarInt __dsdk_GetConVarInt = nullptr;
  /**
   * @brief Get ConVar integer value
   * @param handle (uint64)
   * @return int32
   */

  int32_t GetConVarInt(uint64_t handle) {
    return __dsdk_GetConVarInt(handle);
  }

  using _GetConVarFloat = float (*)(uint64_t);
  PLUGIFY_EXPORT _GetConVarFloat __dsdk_GetConVarFloat = nullptr;
  /**
   * @brief Get ConVar float value
   * @param handle (uint64)
   * @return float
   */

  float GetConVarFloat(uint64_t handle) {
    return __dsdk_GetConVarFloat(handle);
  }

  using _GetConVarString = plg::string (*)(uint64_t);
  PLUGIFY_EXPORT _GetConVarString __dsdk_GetConVarString = nullptr;
  /**
   * @brief Get ConVar string value
   * @param handle (uint64)
   * @return string
   */

  plg::string GetConVarString(uint64_t handle) {
    return __dsdk_GetConVarString(handle);
  }

  using _GetConVarBool = bool (*)(uint64_t);
  PLUGIFY_EXPORT _GetConVarBool __dsdk_GetConVarBool = nullptr;
  /**
   * @brief Get ConVar bool value
   * @param handle (uint64)
   * @return bool
   */

  bool GetConVarBool(uint64_t handle) {
    return __dsdk_GetConVarBool(handle);
  }

  using _SetConVarInt = void (*)(uint64_t, int32_t);
  PLUGIFY_EXPORT _SetConVarInt __dsdk_SetConVarInt = nullptr;
  /**
   * @brief Set ConVar int value
   * @param handle (uint64)
   * @param value (int32)
   */

  void SetConVarInt(uint64_t handle, int32_t value) {
    return __dsdk_SetConVarInt(handle, value);
  }

  using _SetConVarFloat = void (*)(uint64_t, float);
  PLUGIFY_EXPORT _SetConVarFloat __dsdk_SetConVarFloat = nullptr;
  /**
   * @brief Set ConVar float value
   * @param handle (uint64)
   * @param value (float)
   */

  void SetConVarFloat(uint64_t handle, float value) {
    return __dsdk_SetConVarFloat(handle, value);
  }

  using _SetConVarString = bool (*)(uint64_t, const plg::string&);
  PLUGIFY_EXPORT _SetConVarString __dsdk_SetConVarString = nullptr;
  /**
   * @brief Set ConVar string value
   * @param handle (uint64)
   * @param value (string)
   * @return bool
   */

  bool SetConVarString(uint64_t handle, const plg::string& value) {
    return __dsdk_SetConVarString(handle, value);
  }

} // namespace dsdk
