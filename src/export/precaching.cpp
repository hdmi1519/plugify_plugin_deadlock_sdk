#include "pch.hpp"
#include "core/memory/data_loader.hpp"
#include "core/logger.hpp"
#include "core/globals.hpp"
#include "core/sdk/Core.hpp"
#include <entity2/entitysystem.h>

extern "C" {

PLUGIN_API void PrecacheResource(const plg::string &path) {
    if (path.empty()) return;
    auto offset = dsdk::MemoryDataLoader::Get().GetOffset("AddResource");
    if (!offset.has_value()) return;
    auto fn = reinterpret_cast<void(*)(const char *, void *)>(*offset);

    void *manifest = dsdk::g_pCurrentManifest;
    if (!manifest) {
        auto *sys = GameEntitySystem();
        if (sys) manifest = sys->m_pCurrentManifest;
    }
    if (manifest) {
        fn(path.c_str(), manifest);
    }
}

PLUGIN_API void PrecacheModel(const plg::string &modelPath) {
    PrecacheResource(modelPath);
}

}
