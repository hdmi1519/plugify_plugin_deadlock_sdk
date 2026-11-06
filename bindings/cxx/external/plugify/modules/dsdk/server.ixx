// Generated from dsdk.pplugin (group: server)

export module dsdk.server;
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

  using _GetMapName = plg::string (*)();
  PLUGIFY_EXPORT _GetMapName __dsdk_GetMapName = nullptr;
  /**
   * @brief Get currently loaded map name
   * @return string
   */

  plg::string GetMapName() {
    return __dsdk_GetMapName();
  }

  using _IsMapValid = bool (*)(const plg::string&);
  PLUGIFY_EXPORT _IsMapValid __dsdk_IsMapValid = nullptr;
  /**
   * @brief Check if map exists and can be loaded
   * @param map (string)
   * @return bool
   */

  bool IsMapValid(const plg::string& map) {
    return __dsdk_IsMapValid(map);
  }

  using _SetServerKeyValue = bool (*)(const plg::string&, const plg::string&);
  PLUGIFY_EXPORT _SetServerKeyValue __dsdk_SetServerKeyValue = nullptr;
  /**
   * @brief Set Steam A2S rule key-value
   * @param key (string)
   * @param value (string)
   * @return bool
   */

  bool SetServerKeyValue(const plg::string& key, const plg::string& value) {
    return __dsdk_SetServerKeyValue(key, value);
  }

  using _ClearServerKeyValues = bool (*)();
  PLUGIFY_EXPORT _ClearServerKeyValues __dsdk_ClearServerKeyValues = nullptr;
  /**
   * @brief Clear Steam A2S rules
   * @return bool
   */

  bool ClearServerKeyValues() {
    return __dsdk_ClearServerKeyValues();
  }

  using _SetServerAddons = void (*)(const plg::string&);
  PLUGIFY_EXPORT _SetServerAddons __dsdk_SetServerAddons = nullptr;
  /**
   * @brief Set active server workshop addons
   * @param addons (string)
   */

  void SetServerAddons(const plg::string& addons) {
    return __dsdk_SetServerAddons(addons);
  }

  using _AddFileSystemSearchPath = bool (*)(const plg::string&, const plg::string&, int32_t);
  PLUGIFY_EXPORT _AddFileSystemSearchPath __dsdk_AddFileSystemSearchPath = nullptr;
  /**
   * @brief Add file search path
   * @param path (string)
   * @param pathId (string)
   * @param addType (int32)
   * @return bool
   */

  bool AddFileSystemSearchPath(const plg::string& path, const plg::string& pathId, int32_t addType) {
    return __dsdk_AddFileSystemSearchPath(path, pathId, addType);
  }

  using _HasCommandLineParm = bool (*)(const plg::string&);
  PLUGIFY_EXPORT _HasCommandLineParm __dsdk_HasCommandLineParm = nullptr;
  /**
   * @brief Check if command line argument exists
   * @param parm (string)
   * @return bool
   */

  bool HasCommandLineParm(const plg::string& parm) {
    return __dsdk_HasCommandLineParm(parm);
  }

  using _SetConnectRejectReason = void (*)(const plg::string&);
  PLUGIFY_EXPORT _SetConnectRejectReason __dsdk_SetConnectRejectReason = nullptr;
  /**
   * @brief Set reject reason for connection rejection
   * @param reason (string)
   */

  void SetConnectRejectReason(const plg::string& reason) {
    return __dsdk_SetConnectRejectReason(reason);
  }

  using _GetGlobalVars = int64_t (*)();
  PLUGIFY_EXPORT _GetGlobalVars __dsdk_GetGlobalVars = nullptr;
  /**
   * @brief Get CGlobalVars pointer
   * @return int64
   */

  int64_t GetGlobalVars() {
    return __dsdk_GetGlobalVars();
  }

  using _GetGameTime = float (*)();
  PLUGIFY_EXPORT _GetGameTime __dsdk_GetGameTime = nullptr;
  /**
   * @brief Get current engine game time in seconds
   * @return float
   */

  float GetGameTime() {
    return __dsdk_GetGameTime();
  }

  using _GetGameTickCount = int32_t (*)();
  PLUGIFY_EXPORT _GetGameTickCount __dsdk_GetGameTickCount = nullptr;
  /**
   * @brief Get current engine tick count
   * @return int32
   */

  int32_t GetGameTickCount() {
    return __dsdk_GetGameTickCount();
  }

} // namespace dsdk
