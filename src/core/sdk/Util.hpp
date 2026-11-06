#pragma once

#include "core/memory/data_loader.hpp"

#include <Windows.h>

class CEntityInstance;

namespace deadworks {

template <typename T>
inline T GetVFunc(void *instance, int index) {
    auto *vtable = *reinterpret_cast<void ***>(instance);
    return reinterpret_cast<T>(vtable[index]);
}

inline void UTIL_Remove(CEntityInstance *inst) {
    static const auto offset = dsdk::MemoryDataLoader::Get().GetOffset("UTIL_Remove").value();

    return reinterpret_cast<decltype(&UTIL_Remove)>(offset)(inst);
}

} // namespace deadworks
