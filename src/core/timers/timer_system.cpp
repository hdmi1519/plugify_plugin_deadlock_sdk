#include "pch.hpp"
#include "core/timers/timer_system.hpp"

namespace dsdk {

int64_t TimerSystem::CreateTimer(float interval, TimerCallback callback, bool repeating) {
    if (!callback || interval <= 0.0f) return 0;
    std::lock_guard lock(m_mutex);
    int64_t id = m_nextId++;
    m_timers.push_back({id, interval, callback, repeating, 0.0f});
    return id;
}

bool TimerSystem::KillTimer(int64_t timerId) {
    std::lock_guard lock(m_mutex);
    auto it = std::find_if(m_timers.begin(), m_timers.end(), [timerId](const TimerEntry &t) {
        return t.id == timerId;
    });
    if (it != m_timers.end()) {
        m_timers.erase(it);
        return true;
    }
    return false;
}

void TimerSystem::Update(float dt) {
    std::vector<TimerCallback> toCall;
    {
        std::lock_guard lock(m_mutex);
        for (auto it = m_timers.begin(); it != m_timers.end();) {
            it->elapsed += dt;
            if (it->elapsed >= it->interval) {
                if (it->callback) {
                    toCall.push_back(it->callback);
                }
                if (it->repeating) {
                    it->elapsed = 0.0f;
                    ++it;
                } else {
                    it = m_timers.erase(it);
                }
            } else {
                ++it;
            }
        }
    }

    for (auto cb : toCall) {
        cb();
    }
}

} // namespace dsdk
