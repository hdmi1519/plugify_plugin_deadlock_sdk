#pragma once

#include <cstdint>
#include <chrono>
#include <vector>
#include <mutex>

namespace dsdk {

using TimerCallback = void (*)();

struct TimerEntry {
    int64_t id;
    float interval;
    TimerCallback callback;
    bool repeating;
    float elapsed;
};

class TimerSystem {
public:
    static TimerSystem &Get() {
        static TimerSystem instance;
        return instance;
    }

    int64_t CreateTimer(float interval, TimerCallback callback, bool repeating);
    bool KillTimer(int64_t timerId);
    void Update(float dt);

private:
    std::mutex m_mutex;
    int64_t m_nextId = 1;
    std::vector<TimerEntry> m_timers;
};

} // namespace dsdk
