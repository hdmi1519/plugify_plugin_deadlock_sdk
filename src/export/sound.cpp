#include "pch.hpp"
#include "core/memory/data_loader.hpp"
#include "core/memory/virtual.hpp"
#include "core/memory/module.hpp"

using EmitSoundParamsFn = void(__fastcall *)(void *entity, const char *soundName, int pitch, float volume, float delay);
using CreateInterfaceFn = void *(*)(const char *pName, int *pReturnCode);

static void *GetSoundSystem() {
    static void *s_pSoundSystem = nullptr;
    if (!s_pSoundSystem) {
        dsdk::Module mod("soundsystem.dll");
        if (mod.IsValid()) {
            auto createInterface = mod.GetSymbol<CreateInterfaceFn>("CreateInterface");
            if (createInterface) {
                int code = 0;
                s_pSoundSystem = createInterface("SoundSystem001", &code);
            }
        }
    }
    return s_pSoundSystem;
}

extern "C" {

PLUGIN_API void EmitSound(int64_t entity, const plg::string &soundName, int32_t pitch, float volume, float delay) {
    if (!entity || soundName.empty()) return;
    auto offset = dsdk::MemoryDataLoader::Get().GetOffset("CBaseEntity::EmitSoundParams");
    if (offset.has_value()) {
        auto fn = reinterpret_cast<EmitSoundParamsFn>(*offset);
        fn(reinterpret_cast<void *>(entity), soundName.c_str(), pitch, volume, delay);
    }
}

PLUGIN_API uint32_t TakeSoundEventGuid() {
    void *soundSystem = GetSoundSystem();
    if (!soundSystem) {
        static uint32_t s_fallback = 1000;
        return s_fallback++;
    }
    auto idxOpt = dsdk::MemoryDataLoader::Get().GetVirtual("CSoundSystem::TakeGuid");
    if (idxOpt.has_value()) {
        uint32_t guid = 0;
        dsdk::CallVirtual<void>(soundSystem, static_cast<uint32_t>(*idxOpt), &guid);
        return guid;
    }
    static uint32_t s_fallback = 1000;
    return s_fallback++;
}

}
