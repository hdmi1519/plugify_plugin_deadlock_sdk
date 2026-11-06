// Generated from dsdk.pplugin (group: events)

export module dsdk.events;
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

  using _RegisterGameEvent = void (*)(const plg::string&);
  PLUGIFY_EXPORT _RegisterGameEvent __dsdk_RegisterGameEvent = nullptr;
  /**
   * @brief Register game event listener for engine event
   * @param name (string)
   */

  void RegisterGameEvent(const plg::string& name) {
    return __dsdk_RegisterGameEvent(name);
  }

  using _CreateGameEvent = int64_t (*)(const plg::string&, bool);
  PLUGIFY_EXPORT _CreateGameEvent __dsdk_CreateGameEvent = nullptr;
  /**
   * @brief Create a new game event
   * @param name (string)
   * @param force (bool)
   * @return int64
   */

  int64_t CreateGameEvent(const plg::string& name, bool force) {
    return __dsdk_CreateGameEvent(name, force);
  }

  using _FireGameEvent = bool (*)(int64_t, bool);
  PLUGIFY_EXPORT _FireGameEvent __dsdk_FireGameEvent = nullptr;
  /**
   * @brief Fire game event
   * @param event (int64)
   * @param dontBroadcast (bool)
   * @return bool
   */

  bool FireGameEvent(int64_t event, bool dontBroadcast) {
    return __dsdk_FireGameEvent(event, dontBroadcast);
  }

  using _FreeGameEvent = void (*)(int64_t);
  PLUGIFY_EXPORT _FreeGameEvent __dsdk_FreeGameEvent = nullptr;
  /**
   * @brief Free game event object
   * @param event (int64)
   */

  void FreeGameEvent(int64_t event) {
    return __dsdk_FreeGameEvent(event);
  }

  using _GameEventGetBool = bool (*)(int64_t, const plg::string&, bool);
  PLUGIFY_EXPORT _GameEventGetBool __dsdk_GameEventGetBool = nullptr;
  /**
   * @brief Get boolean key from game event
   * @param event (int64)
   * @param key (string)
   * @param def (bool)
   * @return bool
   */

  bool GameEventGetBool(int64_t event, const plg::string& key, bool def) {
    return __dsdk_GameEventGetBool(event, key, def);
  }

  using _GameEventGetInt = int32_t (*)(int64_t, const plg::string&, int32_t);
  PLUGIFY_EXPORT _GameEventGetInt __dsdk_GameEventGetInt = nullptr;
  /**
   * @brief Get int32 key from game event
   * @param event (int64)
   * @param key (string)
   * @param def (int32)
   * @return int32
   */

  int32_t GameEventGetInt(int64_t event, const plg::string& key, int32_t def) {
    return __dsdk_GameEventGetInt(event, key, def);
  }

  using _GameEventGetFloat = float (*)(int64_t, const plg::string&, float);
  PLUGIFY_EXPORT _GameEventGetFloat __dsdk_GameEventGetFloat = nullptr;
  /**
   * @brief Get float key from game event
   * @param event (int64)
   * @param key (string)
   * @param def (float)
   * @return float
   */

  float GameEventGetFloat(int64_t event, const plg::string& key, float def) {
    return __dsdk_GameEventGetFloat(event, key, def);
  }

  using _GameEventGetString = plg::string (*)(int64_t, const plg::string&, const plg::string&);
  PLUGIFY_EXPORT _GameEventGetString __dsdk_GameEventGetString = nullptr;
  /**
   * @brief Get string key from game event
   * @param event (int64)
   * @param key (string)
   * @param def (string)
   * @return string
   */

  plg::string GameEventGetString(int64_t event, const plg::string& key, const plg::string& def) {
    return __dsdk_GameEventGetString(event, key, def);
  }

  using _GameEventGetUint64 = uint64_t (*)(int64_t, const plg::string&, uint64_t);
  PLUGIFY_EXPORT _GameEventGetUint64 __dsdk_GameEventGetUint64 = nullptr;
  /**
   * @brief Get uint64 key from game event
   * @param event (int64)
   * @param key (string)
   * @param def (uint64)
   * @return uint64
   */

  uint64_t GameEventGetUint64(int64_t event, const plg::string& key, uint64_t def) {
    return __dsdk_GameEventGetUint64(event, key, def);
  }

  using _GameEventSetBool = void (*)(int64_t, const plg::string&, bool);
  PLUGIFY_EXPORT _GameEventSetBool __dsdk_GameEventSetBool = nullptr;
  /**
   * @brief Set boolean key in game event
   * @param event (int64)
   * @param key (string)
   * @param val (bool)
   */

  void GameEventSetBool(int64_t event, const plg::string& key, bool val) {
    return __dsdk_GameEventSetBool(event, key, val);
  }

  using _GameEventSetInt = void (*)(int64_t, const plg::string&, int32_t);
  PLUGIFY_EXPORT _GameEventSetInt __dsdk_GameEventSetInt = nullptr;
  /**
   * @brief Set int32 key in game event
   * @param event (int64)
   * @param key (string)
   * @param val (int32)
   */

  void GameEventSetInt(int64_t event, const plg::string& key, int32_t val) {
    return __dsdk_GameEventSetInt(event, key, val);
  }

  using _GameEventSetFloat = void (*)(int64_t, const plg::string&, float);
  PLUGIFY_EXPORT _GameEventSetFloat __dsdk_GameEventSetFloat = nullptr;
  /**
   * @brief Set float key in game event
   * @param event (int64)
   * @param key (string)
   * @param val (float)
   */

  void GameEventSetFloat(int64_t event, const plg::string& key, float val) {
    return __dsdk_GameEventSetFloat(event, key, val);
  }

  using _GameEventSetString = void (*)(int64_t, const plg::string&, const plg::string&);
  PLUGIFY_EXPORT _GameEventSetString __dsdk_GameEventSetString = nullptr;
  /**
   * @brief Set string key in game event
   * @param event (int64)
   * @param key (string)
   * @param val (string)
   */

  void GameEventSetString(int64_t event, const plg::string& key, const plg::string& val) {
    return __dsdk_GameEventSetString(event, key, val);
  }

  using _GameEventGetPlayerSlot = int32_t (*)(int64_t, const plg::string&);
  PLUGIFY_EXPORT _GameEventGetPlayerSlot __dsdk_GameEventGetPlayerSlot = nullptr;
  /**
   * @brief Gets player slot from an event key (e.g. userid)
   * @param event (int64)
   * @param key (string)
   * @return int32
   */

  int32_t GameEventGetPlayerSlot(int64_t event, const plg::string& key) {
    return __dsdk_GameEventGetPlayerSlot(event, key);
  }

  using _GameEventGetPlayerPawn = int64_t (*)(int64_t, const plg::string&);
  PLUGIFY_EXPORT _GameEventGetPlayerPawn __dsdk_GameEventGetPlayerPawn = nullptr;
  /**
   * @brief Gets player pawn pointer from an event key (e.g. userid)
   * @param event (int64)
   * @param key (string)
   * @return int64
   */

  int64_t GameEventGetPlayerPawn(int64_t event, const plg::string& key) {
    return __dsdk_GameEventGetPlayerPawn(event, key);
  }

  using _GameEventGetPlayerController = int64_t (*)(int64_t, const plg::string&);
  PLUGIFY_EXPORT _GameEventGetPlayerController __dsdk_GameEventGetPlayerController = nullptr;
  /**
   * @brief Gets player controller pointer from an event key (e.g. userid)
   * @param event (int64)
   * @param key (string)
   * @return int64
   */

  int64_t GameEventGetPlayerController(int64_t event, const plg::string& key) {
    return __dsdk_GameEventGetPlayerController(event, key);
  }

} // namespace dsdk
