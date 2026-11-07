// Generated from dsdk.pplugin (group: gamestate)

export module dsdk.gamestate;
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

  using _GetGameState = EGameState (*)();
  PLUGIFY_EXPORT _GetGameState __dsdk_GetGameState = nullptr;
  /**
   * @brief Get current game state enum
   * @return int32
   */

  EGameState GetGameState() {
    return __dsdk_GetGameState();
  }

  using _GetMatchTime = float (*)();
  PLUGIFY_EXPORT _GetMatchTime __dsdk_GetMatchTime = nullptr;
  /**
   * @brief Get current match clock in seconds
   * @return float
   */

  float GetMatchTime() {
    return __dsdk_GetMatchTime();
  }

  using _ChangeGameState = void (*)(EGameState);
  PLUGIFY_EXPORT _ChangeGameState __dsdk_ChangeGameState = nullptr;
  /**
   * @brief Force Deadlock game state change
   * @param newState (int32)
   */

  void ChangeGameState(EGameState newState) {
    return __dsdk_ChangeGameState(newState);
  }

  using _SetWaitingForPlayersRoster = void (*)(uint32_t, uint32_t);
  PLUGIFY_EXPORT _SetWaitingForPlayersRoster __dsdk_SetWaitingForPlayersRoster = nullptr;
  /**
   * @brief Set waiting for players roster counts
   * @param readyCount (uint32)
   * @param totalCount (uint32)
   */

  void SetWaitingForPlayersRoster(uint32_t readyCount, uint32_t totalCount) {
    return __dsdk_SetWaitingForPlayersRoster(readyCount, totalCount);
  }

  using _SetMatchStartOnAnyMap = void (*)(bool);
  PLUGIFY_EXPORT _SetMatchStartOnAnyMap __dsdk_SetMatchStartOnAnyMap = nullptr;
  /**
   * @brief Enable/disable match start sequence on custom maps
   * @param enabled (bool)
   */

  void SetMatchStartOnAnyMap(bool enabled) {
    return __dsdk_SetMatchStartOnAnyMap(enabled);
  }

  using _GetMatchStartOnAnyMap = bool (*)();
  PLUGIFY_EXPORT _GetMatchStartOnAnyMap __dsdk_GetMatchStartOnAnyMap = nullptr;
  /**
   * @brief Check if match start on custom maps is enabled
   * @return bool
   */

  bool GetMatchStartOnAnyMap() {
    return __dsdk_GetMatchStartOnAnyMap();
  }

} // namespace dsdk
