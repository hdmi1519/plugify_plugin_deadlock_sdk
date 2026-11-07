#include "pch.hpp"
#include "core/sdk/CEntitySystem.hpp"
#include "core/sdk/schema/Schema.hpp"
#include "core/memory/data_loader.hpp"
#include <tier1/utlsymbollarge.h>
#include <entityhandle.h>

extern "C" {

PLUGIN_API int64_t CreateParticle(const plg::string &particleName, int32_t attachType, int64_t entity) {
    if (particleName.empty()) return 0;
    auto *inst = EntitySystemHelper::CreateEntityByName("info_particle_system");
    if (!inst) return 0;

    EntitySystemHelper::QueueSpawnEntity(inst->m_pEntity);
    EntitySystemHelper::ExecuteQueuedCreation();

    static int s_effectNameOffset = -1;
    if (s_effectNameOffset == -1) {
        s_effectNameOffset = schema::GetOffset("CParticleSystem", hash_32_fnv1a_const("CParticleSystem"),
                                              "m_iszEffectName", hash_32_fnv1a_const("m_iszEffectName")).Offset;
    }
    if (s_effectNameOffset > 0) {
        auto *sym = reinterpret_cast<CUtlSymbolLarge *>(reinterpret_cast<uintptr_t>(inst) + s_effectNameOffset);
        *sym = CUtlSymbolLarge(particleName.c_str());
    }

    static int s_startActiveOffset = -1;
    if (s_startActiveOffset == -1) {
        s_startActiveOffset = schema::GetOffset("CParticleSystem", hash_32_fnv1a_const("CParticleSystem"),
                                               "m_bStartActive", hash_32_fnv1a_const("m_bStartActive")).Offset;
    }
    if (s_startActiveOffset > 0) {
        *reinterpret_cast<bool *>(reinterpret_cast<uintptr_t>(inst) + s_startActiveOffset) = true;
    }

    if (entity != 0) {
        static int s_cpEntsOffset = -1;
        if (s_cpEntsOffset == -1) {
            s_cpEntsOffset = schema::GetOffset("CParticleSystem", hash_32_fnv1a_const("CParticleSystem"),
                                              "m_hControlPointEnts", hash_32_fnv1a_const("m_hControlPointEnts")).Offset;
        }
        if (s_cpEntsOffset > 0) {
            auto *targetInst = reinterpret_cast<CEntityInstance *>(entity);
            if (targetInst && targetInst->m_pEntity) {
                auto *cpEnts = reinterpret_cast<CEntityHandle *>(reinterpret_cast<uintptr_t>(inst) + s_cpEntsOffset);
                cpEnts[0] = targetInst->GetRefEHandle();
            }
        }
    }

    return reinterpret_cast<int64_t>(inst);
}

PLUGIN_API void DestroyParticle(int64_t particle, bool destroyImmediately) {
    if (!particle) return;
    auto offset = dsdk::MemoryDataLoader::Get().GetOffset("UTIL_Remove");
    if (offset.has_value()) {
        auto fn = reinterpret_cast<void(*)(void *)>(*offset);
        fn(reinterpret_cast<void *>(particle));
    }
}

}
