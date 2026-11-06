#pragma once

#include <vector>
#include <algorithm>
#include <mutex>

namespace dsdk {

template<typename Func>
class ListenerManager {
public:
    struct Entry {
        Func callback;
        int priority;
    };

    void Register(Func cb, int priority = 0) {
        std::lock_guard lock(m_mutex);
        m_listeners.push_back({cb, priority});
        std::stable_sort(m_listeners.begin(), m_listeners.end(), [](const Entry &a, const Entry &b) {
            return a.priority > b.priority;
        });
    }

    void Unregister(Func cb) {
        std::lock_guard lock(m_mutex);
        std::erase_if(m_listeners, [cb](const Entry &e) { return e.callback == cb; });
    }

    template<typename... Args>
    void Dispatch(Args&&... args) {
        std::vector<Entry> copy;
        {
            std::lock_guard lock(m_mutex);
            copy = m_listeners;
        }
        for (const auto &entry : copy) {
            if (entry.callback) {
                entry.callback(args...);
            }
        }
    }

    template<typename ResultType, typename... Args>
    ResultType DispatchWithResult(ResultType defaultResult, Args&&... args) {
        std::vector<Entry> copy;
        {
            std::lock_guard lock(m_mutex);
            copy = m_listeners;
        }
        ResultType highest = defaultResult;
        for (const auto &entry : copy) {
            if (entry.callback) {
                ResultType res = entry.callback(args...);
                if constexpr (std::is_integral_v<ResultType>) {
                    if (res > highest) {
                        highest = res;
                    }
                    if (static_cast<int>(res) >= 3) {
                        break;
                    }
                } else {
                    highest = res;
                }
            }
        }
        return highest;
    }

    [[nodiscard]] bool Empty() const {
        std::lock_guard lock(m_mutex);
        return m_listeners.empty();
    }

private:
    mutable std::mutex m_mutex;
    std::vector<Entry> m_listeners;
};

} // namespace dsdk
