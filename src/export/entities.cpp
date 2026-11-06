#include "pch.hpp"
#include "core/memory/data_loader.hpp"
#include "core/logger.hpp"
#include "core/sdk/Util.hpp"
#include "core/sdk/Core.hpp"
#include "core/sdk/CEntitySystem.hpp"
#include "core/sdk/CBaseEntity.hpp"
#include <entityinstance.h>
#include <entityhandle.h>
#include <entity2/entityclass.h>
#include <server_class.h>

using CreateEntityByNameFn = void *(*)(void *pThis, const char *name, int forceIndex);
using RemoveEntityFn = void(*)(void *entity);
using TeleportFn = void(*)(void *entity, const float *pos, const float *angles, const float *vel);

extern "C" {

PLUGIN_API int64_t CreateEntityByName(const plg::string &className) {
    if (className.empty()) return 0;
    auto *inst = EntitySystemHelper::CreateEntityByName(className.c_str());
    return reinterpret_cast<int64_t>(inst);
}

PLUGIN_API void QueueSpawnEntity(int64_t entity, int64_t ekv) {
    if (!entity) return;
    auto *inst = reinterpret_cast<CEntityInstance *>(entity);
    if (!inst || !inst->m_pEntity) return;
    EntitySystemHelper::QueueSpawnEntity(inst->m_pEntity, reinterpret_cast<CEntityKeyValues *>(ekv));
}

PLUGIN_API void ExecuteQueuedCreation() {
    EntitySystemHelper::ExecuteQueuedCreation();
}

PLUGIN_API void RemoveEntity(int64_t entity) {
    if (!entity) return;
    auto offset = dsdk::MemoryDataLoader::Get().GetOffset("UTIL_Remove");
    if (offset.has_value()) {
        auto fn = reinterpret_cast<RemoveEntityFn>(*offset);
        fn(reinterpret_cast<void *>(entity));
    }
}

PLUGIN_API int64_t GetEntityByIndex(int32_t index) {
    auto *sys = GameEntitySystem();
    if (!sys) return 0;
    return reinterpret_cast<int64_t>(sys->GetEntityInstance(CEntityIndex(index)));
}

PLUGIN_API int64_t GetEntityFromHandle(uint32_t handle) {
    CEntityHandle eh(handle);
    if (!eh.IsValid()) return 0;
    return reinterpret_cast<int64_t>(eh.Get());
}

PLUGIN_API uint32_t GetEntityHandle(int64_t entity) {
    if (!entity) return 0xFFFFFFFF;
    auto *inst = reinterpret_cast<CEntityInstance *>(entity);
    return inst->GetRefEHandle().GetEntryIndex();
}

PLUGIN_API int64_t FindEntityByName(int64_t startEntity, const plg::string &name) {
    if (name.empty()) return 0;
    auto *sys = GameEntitySystem();
    if (!sys) return 0;

    CEntityIdentity *ident = nullptr;
    if (startEntity) {
        auto *prev = reinterpret_cast<CEntityInstance *>(startEntity)->m_pEntity;
        ident = prev ? prev->m_pNext : nullptr;
    } else {
        ident = sys->m_EntityList.m_pFirstActiveEntity;
    }

    for (; ident; ident = ident->m_pNext) {
        const char *entName = ident->GetName();
        if (entName && strcmp(entName, name.c_str()) == 0) {
            return reinterpret_cast<int64_t>(ident->m_pInstance);
        }
    }
    return 0;
}

PLUGIN_API plg::string GetEntityDesignerName(int64_t entity) {
    if (!entity) return plg::string("");
    auto *inst = reinterpret_cast<CEntityInstance *>(entity);
    if (inst && inst->m_pEntity) {
        const char *name = inst->m_pEntity->GetClassname();
        if (name && *name) return plg::string(name);
    }
    return plg::string("");
}

PLUGIN_API plg::string GetEntityClassname(int64_t entity) {
    if (!entity) return plg::string("CBaseEntity");
    auto *inst = reinterpret_cast<CEntityInstance *>(entity);
    if (inst && inst->m_pEntity && inst->m_pEntity->m_pClass &&
        inst->m_pEntity->m_pClass->m_pServerClass &&
        inst->m_pEntity->m_pClass->m_pServerClass->m_pDLLClassName) {
        const char *name = inst->m_pEntity->m_pClass->m_pServerClass->m_pDLLClassName;
        if (name && *name) return plg::string(name);
    }
    return plg::string("CBaseEntity");
}

PLUGIN_API bool EntityDerivesFrom(int64_t entity, const plg::string &baseClassName) {
    if (!entity || baseClassName.empty()) return false;
    plg::string cls = GetEntityClassname(entity);
    if (cls.empty()) return false;
    return schema::IsDerivedFrom(cls.c_str(), baseClassName.c_str());
}

PLUGIN_API void Teleport(int64_t entity, float posX, float posY, float posZ,
                         float angPitch, float angYaw, float angRoll,
                         float velX, float velY, float velZ) {
    if (!entity) return;
    float pos[3] = {posX, posY, posZ};
    float ang[3] = {angPitch, angYaw, angRoll};
    float vel[3] = {velX, velY, velZ};
    auto optIdx = dsdk::MemoryDataLoader::Get().GetVirtual("CBaseEntity::Teleport");
    if (optIdx.has_value()) {
        auto fn = deadworks::GetVFunc<TeleportFn>(reinterpret_cast<void *>(entity), *optIdx);
        fn(reinterpret_cast<void *>(entity), pos, ang, vel);
    } else {
        auto offset = dsdk::MemoryDataLoader::Get().GetOffset("CBaseEntity::Teleport");
        if (offset.has_value()) {
            auto fn = reinterpret_cast<TeleportFn>(*offset);
            fn(reinterpret_cast<void *>(entity), pos, ang, vel);
        }
    }
}

PLUGIN_API void SetModel(int64_t entity, const plg::string &modelName) {
    if (!entity || modelName.empty()) return;
    auto offset = dsdk::MemoryDataLoader::Get().GetOffset("CBaseModelEntity::SetModel");
    if (offset.has_value()) {
        using SetModelFn = void(__thiscall *)(void *, const char *);
        auto fn = reinterpret_cast<SetModelFn>(*offset);
        fn(reinterpret_cast<void *>(entity), modelName.c_str());
    }
}

PLUGIN_API plg::string GetModelName(int64_t entity) {
    if (!entity) return plg::string("");
    auto offset = dsdk::MemoryDataLoader::Get().GetOffset("CBaseModelEntity::GetModelName");
    if (offset.has_value()) {
        using GetModelNameFn = void(__thiscall *)(void *, const char **);
        auto fn = reinterpret_cast<GetModelNameFn>(*offset);
        const char *out = nullptr;
        fn(reinterpret_cast<void *>(entity), &out);
        return plg::string(out ? out : "");
    }
    return plg::string("");
}

PLUGIN_API void SetScale(int64_t entity, float scale) {
    if (!entity) return;
    auto optIdx = dsdk::MemoryDataLoader::Get().GetVirtual("CBaseModelEntity::SetScale");
    if (optIdx.has_value()) {
        deadworks::GetVFunc<void(__thiscall *)(void *, float)>(reinterpret_cast<void *>(entity), *optIdx)(reinterpret_cast<void *>(entity), scale);
    }
}

PLUGIN_API void SetMoveType(int64_t entity, uint8_t moveType) {
    if (!entity) return;
    auto offset = dsdk::MemoryDataLoader::Get().GetOffset("CBaseEntity::SetMoveType");
    if (offset.has_value()) {
        using SetMoveTypeFn = void(__fastcall *)(void *, uint8_t, uint8_t);
        auto fn = reinterpret_cast<SetMoveTypeFn>(*offset);
        auto *pEnt = reinterpret_cast<CBaseEntity *>(entity);
        fn(reinterpret_cast<void *>(entity), moveType, pEnt->m_MoveCollide.Get());
    }
}

PLUGIN_API void SetGravityScale(int64_t entity, float scale) {
    if (!entity) return;
    auto offset = dsdk::MemoryDataLoader::Get().GetOffset("CBaseEntity::SetGravityScale");
    if (offset.has_value()) {
        using SetGravityScaleFn = void(__fastcall *)(void *, float);
        auto fn = reinterpret_cast<SetGravityScaleFn>(*offset);
        fn(reinterpret_cast<void *>(entity), scale);
    }
}

}
