// Generated from dsdk.pplugin (group: timers)

export module dsdk.timers;
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

  using _CreateTimer = int64_t (*)(float, TimerCallback, bool);
  PLUGIFY_EXPORT _CreateTimer __dsdk_CreateTimer = nullptr;
  /**
   * @brief Create a one-shot or repeating timer
   * @param interval (float)
   * @param callback (function)
   * @param repeating (bool)
   * @return int64
   */

  int64_t CreateTimer(float interval, TimerCallback callback, bool repeating) {
    return __dsdk_CreateTimer(interval, callback, repeating);
  }

  using _KillTimer = bool (*)(int64_t);
  PLUGIFY_EXPORT _KillTimer __dsdk_KillTimer = nullptr;
  /**
   * @brief Stop and delete an active timer
   * @param timerId (int64)
   * @return bool
   */

  bool KillTimer(int64_t timerId) {
    return __dsdk_KillTimer(timerId);
  }

} // namespace dsdk
