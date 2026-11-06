#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from dsdk.pplugin (group: timers)

namespace dsdk {

  using _CreateTimer = int64_t (*)(float, TimerCallback, bool);
}
extern "C" PLUGIN_API dsdk::_CreateTimer __dsdk_CreateTimer;
namespace dsdk {
  /**
   * @brief Create a one-shot or repeating timer
   * @param interval (float)
   * @param callback (function)
   * @param repeating (bool)
   * @return int64
   */
  inline int64_t CreateTimer(float interval, TimerCallback callback, bool repeating) {
    return __dsdk_CreateTimer(interval, callback, repeating);
  }

  using _KillTimer = bool (*)(int64_t);
}
extern "C" PLUGIN_API dsdk::_KillTimer __dsdk_KillTimer;
namespace dsdk {
  /**
   * @brief Stop and delete an active timer
   * @param timerId (int64)
   * @return bool
   */
  inline bool KillTimer(int64_t timerId) {
    return __dsdk_KillTimer(timerId);
  }

} // namespace dsdk
