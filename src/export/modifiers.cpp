#include "pch.hpp"
#include "core/memory/data_loader.hpp"
#include "core/memory/virtual.hpp"
#include "core/logger.hpp"
#include "core/sdk/CBaseEntity.hpp"
#include "core/sdk/CModifierProperty.hpp"

enum class EntitySubclassScope_t : uint32_t {
    SUBCLASS_SCOPE_NONE = 0xFFFFFFFF,
    SUBCLASS_SCOPE_MISC = 0x0,
    SUBCLASS_SCOPE_PRECIPITATION = 0x1,
    SUBCLASS_SCOPE_MODIFIERS = 0x2,
    SUBCLASS_SCOPE_NPC_UNITS = 0x3,
    SUBCLASS_SCOPE_ABILITIES = 0x4,
    SUBCLASS_SCOPE_SCALE_FUNCTIONS = 0x5,
    SUBCLASS_SCOPE_LOOT_TABLES = 0x6,
    SUBCLASS_SCOPE_COUNT = 0x7,
};

using LookupSubclassDefFn = void *(__fastcall *)(int typeIndex, const char *name);

static void *LookupSubclassDefinitionByName(EntitySubclassScope_t scope, const char *name) {
    static const auto opt = dsdk::MemoryDataLoader::Get().GetOffset("GetVDataInstanceByName");
    if (!opt.has_value()) return nullptr;
    auto fn = reinterpret_cast<LookupSubclassDefFn>(*opt);
    return fn(static_cast<int>(scope), name);
}

extern "C" {

PLUGIN_API int64_t AddModifier(int64_t entity, const plg::string &modifierName, int64_t kv3, int64_t caster, int64_t ability, int32_t team) {
    if (!entity || modifierName.empty()) return 0;
    auto *vdata = reinterpret_cast<CModifierVData *>(
        LookupSubclassDefinitionByName(EntitySubclassScope_t::SUBCLASS_SCOPE_MODIFIERS, modifierName.c_str()));
    if (!vdata) {
        dsdk::Logger::Warning("AddModifier: VData not found for '{}'", modifierName.c_str());
        return 0;
    }

    auto *ent = reinterpret_cast<CBaseEntity *>(entity);
    CModifierProperty *modProp = ent->m_pModifierProp.Get();
    if (!modProp) {
        dsdk::Logger::Warning("AddModifier: Entity has no modifier property");
        return 0;
    }

    bool savedPredictedOwner = modProp->m_bPredictedOwner.Get();
    modProp->m_bPredictedOwner = true;

    auto *pCaster = caster ? reinterpret_cast<CBaseEntity *>(caster) : ent;
    uint32_t hAbility = 0xFFFFFFFF;
    if (ability) {
        auto *pAbility = reinterpret_cast<CBaseEntity *>(ability);
        hAbility = static_cast<uint32_t>(pAbility->GetRefEHandle().ToInt());
    }

    void *result = modProp->AddModifier(pCaster, hAbility, team, vdata, reinterpret_cast<KeyValues3 *>(kv3));
    modProp->m_bPredictedOwner = savedPredictedOwner;

    return reinterpret_cast<int64_t>(result);
}

PLUGIN_API bool RemoveModifier(int64_t entity, int64_t modifier) {
    if (!entity || !modifier) return false;
    auto *ent = reinterpret_cast<CBaseEntity *>(entity);
    CModifierProperty *modProp = ent->m_pModifierProp.Get();
    if (!modProp) return false;

    auto vIdx = dsdk::MemoryDataLoader::Get().GetVirtual("CBaseModifier::Destroy");
    if (!vIdx.has_value()) return false;

    auto destroyFn = dsdk::GetVirtual<void(__fastcall *)(void *, uint32_t, void *, void *)>(
        reinterpret_cast<void *>(modifier), *vIdx);
    destroyFn(reinterpret_cast<void *>(modifier), 6, nullptr, nullptr);
    return true;
}

}
