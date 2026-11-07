#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from dsdk.pplugin (group: gamestate)

namespace dsdk {

  using _GetGameState = EGameState (*)();
}
extern "C" PLUGIN_API dsdk::_GetGameState __dsdk_GetGameState;
namespace dsdk {
  /**
   * @brief Get current game state enum
   * @return int32
   */
  inline EGameState GetGameState() {
    return __dsdk_GetGameState();
  }

  using _GetMatchTime = float (*)();
}
extern "C" PLUGIN_API dsdk::_GetMatchTime __dsdk_GetMatchTime;
namespace dsdk {
  /**
   * @brief Get current match clock in seconds
   * @return float
   */
  inline float GetMatchTime() {
    return __dsdk_GetMatchTime();
  }

  using _ChangeGameState = void (*)(EGameState);
}
extern "C" PLUGIN_API dsdk::_ChangeGameState __dsdk_ChangeGameState;
namespace dsdk {
  /**
   * @brief Force Deadlock game state change
   * @param newState (int32)
   */
  inline void ChangeGameState(EGameState newState) {
    return __dsdk_ChangeGameState(newState);
  }

  using _SetWaitingForPlayersRoster = void (*)(uint32_t, uint32_t);
}
extern "C" PLUGIN_API dsdk::_SetWaitingForPlayersRoster __dsdk_SetWaitingForPlayersRoster;
namespace dsdk {
  /**
   * @brief Set waiting for players roster counts
   * @param readyCount (uint32)
   * @param totalCount (uint32)
   */
  inline void SetWaitingForPlayersRoster(uint32_t readyCount, uint32_t totalCount) {
    return __dsdk_SetWaitingForPlayersRoster(readyCount, totalCount);
  }

  using _SetMatchStartOnAnyMap = void (*)(bool);
}
extern "C" PLUGIN_API dsdk::_SetMatchStartOnAnyMap __dsdk_SetMatchStartOnAnyMap;
namespace dsdk {
  /**
   * @brief Enable/disable match start sequence on custom maps
   * @param enabled (bool)
   */
  inline void SetMatchStartOnAnyMap(bool enabled) {
    return __dsdk_SetMatchStartOnAnyMap(enabled);
  }

  using _GetMatchStartOnAnyMap = bool (*)();
}
extern "C" PLUGIN_API dsdk::_GetMatchStartOnAnyMap __dsdk_GetMatchStartOnAnyMap;
namespace dsdk {
  /**
   * @brief Check if match start on custom maps is enabled
   * @return bool
   */
  inline bool GetMatchStartOnAnyMap() {
    return __dsdk_GetMatchStartOnAnyMap();
  }

} // namespace dsdk
