#include "pch.hpp"
#include "core/memory/data_loader.hpp"
#include <variant.h>

using AcceptInputFn = bool(__thiscall *)(void *thisptr, const char *pInputName, void *pActivator, void *pCaller, variant_t *pValue);

extern "C" {

PLUGIN_API void AcceptInput(int64_t entity, const plg::string &inputName, int64_t activator, int64_t caller, const plg::string &value) {
    if (!entity) return;
    auto offset = dsdk::MemoryDataLoader::Get().GetOffset("CEntityInstance::AcceptInput");
    if (!offset.has_value()) {
        offset = dsdk::MemoryDataLoader::Get().GetOffset("CBaseEntity::AcceptInput");
    }
    if (offset.has_value()) {
        auto fn = reinterpret_cast<AcceptInputFn>(*offset);
        variant_t val(value.c_str());
        fn(reinterpret_cast<void *>(entity), inputName.c_str(), reinterpret_cast<void *>(activator), reinterpret_cast<void *>(caller), &val);
    }
}

}
