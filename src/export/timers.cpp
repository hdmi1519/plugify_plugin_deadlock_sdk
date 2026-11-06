#include "pch.hpp"
#include "core/timers/timer_system.hpp"

extern "C" {

PLUGIN_API int64_t CreateTimer(float interval, dsdk::TimerCallback callback, bool repeating) {
    return dsdk::TimerSystem::Get().CreateTimer(interval, callback, repeating);
}

PLUGIN_API bool KillTimer(int64_t timerId) {
    return dsdk::TimerSystem::Get().KillTimer(timerId);
}

}
