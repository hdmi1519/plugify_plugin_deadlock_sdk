#include "pch.hpp"
#include "core/memory/data_loader.hpp"
#include "core/memory/virtual.hpp"
#include "core/logger.hpp"
#include "core/sdk/schema/Schema.hpp"

static int GetCTakeDamageInfoSize() {
    static int size = schema::GetClassSize("CTakeDamageInfo");
    return size ? size : 0x100;
}

using CTakeDamageInfoCtorFn = void *(__fastcall *)(void *info, void *inflictor, void *attacker, void *ability, float damage, int damageType, int customDamage);
using CTakeDamageInfoDtorFn = void(__fastcall *)(void *info);
using TakeDamageFn = void(__fastcall *)(void *victim, void *info, void *result);
using ApplyDamageFn = void(__fastcall *)(void *victim, void *info, void *result);

extern "C" {

PLUGIN_API int64_t CreateDamageInfo(int64_t inflictor, int64_t attacker, int64_t ability, float damage, int32_t damageType) {
    auto ctorOpt = dsdk::MemoryDataLoader::Get().GetOffset("CTakeDamageInfo::Ctor");
    if (!ctorOpt.has_value()) return 0;
    auto ctor = reinterpret_cast<CTakeDamageInfoCtorFn>(*ctorOpt);

    auto size = GetCTakeDamageInfoSize();
    auto *info = static_cast<uint8_t *>(_aligned_malloc(size, 16));
    if (!info) return 0;
    std::memset(info, 0, size);

    void *pInflictor = reinterpret_cast<void *>(inflictor);
    void *pAttacker = attacker ? reinterpret_cast<void *>(attacker) : pInflictor;
    void *pAbility = reinterpret_cast<void *>(ability);

    ctor(info, pInflictor, pAttacker, pAbility, damage, damageType, 0);
    return reinterpret_cast<int64_t>(info);
}

PLUGIN_API void DestroyDamageInfo(int64_t info) {
    if (!info) return;
    auto dtorOpt = dsdk::MemoryDataLoader::Get().GetOffset("CTakeDamageInfo::Dtor");
    if (dtorOpt.has_value()) {
        auto dtor = reinterpret_cast<CTakeDamageInfoDtorFn>(*dtorOpt);
        dtor(reinterpret_cast<void *>(info));
    }
    _aligned_free(reinterpret_cast<void *>(info));
}

PLUGIN_API void TakeDamage(int64_t victim, int64_t info) {
    if (!victim || !info) return;
    auto offset = dsdk::MemoryDataLoader::Get().GetOffset("CBaseEntity::TakeDamageOld");
    if (offset.has_value()) {
        auto fn = reinterpret_cast<TakeDamageFn>(*offset);
        fn(reinterpret_cast<void *>(victim), reinterpret_cast<void *>(info), nullptr);
    }
}

PLUGIN_API void ApplyDamage(int64_t victim, int64_t info) {
    if (!victim || !info) return;
    auto offset = dsdk::MemoryDataLoader::Get().GetOffset("CBaseEntity::ApplyDamage");
    if (offset.has_value()) {
        auto fn = reinterpret_cast<ApplyDamageFn>(*offset);
        fn(reinterpret_cast<void *>(victim), reinterpret_cast<void *>(info), nullptr);
    }
}

PLUGIN_API int32_t GetMaxHealth(int64_t entity) {
    if (!entity) return 0;
    auto idxOpt = dsdk::MemoryDataLoader::Get().GetVirtual("CBaseEntity::GetMaxHealth");
    if (idxOpt.has_value()) {
        return dsdk::CallVirtual<int>(reinterpret_cast<void *>(entity), static_cast<uint32_t>(*idxOpt));
    }
    return 1000;
}

PLUGIN_API int32_t Heal(int64_t entity, float amount) {
    if (!entity) return 0;
    auto idxOpt = dsdk::MemoryDataLoader::Get().GetVirtual("CBaseEntity::Heal");
    if (idxOpt.has_value()) {
        return dsdk::CallVirtual<int>(reinterpret_cast<void *>(entity), static_cast<uint32_t>(*idxOpt), amount);
    }
    return static_cast<int32_t>(amount);
}

}
