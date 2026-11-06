#pragma once

#include <cstdint>

namespace dsdk {

template <typename Fn>
inline Fn GetVirtual(void *base, int index) {
    auto **pvft = *static_cast<void ***>(base);
    return reinterpret_cast<Fn>(pvft[index]);
}

template <typename T, typename... Args>
inline T CallVirtual(void *base, uint32_t index, Args... args) {
#ifdef _WIN32
    auto pfn = GetVirtual<T(__thiscall *)(void *, Args...)>(base, index);
#else
    auto pfn = GetVirtual<T(*)(void *, Args...)>(base, index);
#endif
    return pfn(base, args...);
}

} // namespace dsdk
