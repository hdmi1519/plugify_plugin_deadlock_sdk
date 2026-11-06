#include "pch.hpp"
#include "core/memory/data_loader.hpp"
#include "core/logger.hpp"
#include "core/sdk/CCitadelPlayerPawn.hpp"
#include "core/sdk/CCitadelAbilityComponent.hpp"
#include "core/sdk/CCitadelBaseAbility.hpp"
#include <entity2/entitynetwork.h>

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
using FindSlotEntryFn = int(__fastcall *)(void *slotTable, uint16_t *slot);
using RemoveSlotEntryFn = void(__fastcall *)(void *slotTable, int entryIndex);
using UTIL_RemoveFn = void(*)(void *entity);

static void *LookupSubclassDefinitionByName(EntitySubclassScope_t scope, const char *name) {
    static const auto opt = dsdk::MemoryDataLoader::Get().GetOffset("GetVDataInstanceByName");
    if (!opt.has_value()) return nullptr;
    auto fn = reinterpret_cast<LookupSubclassDefFn>(*opt);
    return fn(static_cast<int>(scope), name);
}

static inline uintptr_t ResolveE8Call(uintptr_t callInstructionAddr) {
    auto rel = *reinterpret_cast<const int32_t *>(callInstructionAddr + 1);
    return callInstructionAddr + 5 + rel;
}

static void ResolveSlotTableFns(FindSlotEntryFn &findFn, RemoveSlotEntryFn &removeFn) {
    auto addrOpt = dsdk::MemoryDataLoader::Get().GetOffset("CCitadelAbilityComponent::OnAbilityRemoved");
    if (!addrOpt.has_value()) return;
    auto addr = *addrOpt;
    findFn = reinterpret_cast<FindSlotEntryFn>(ResolveE8Call(addr + 0x7B));
    removeFn = reinterpret_cast<RemoveSlotEntryFn>(ResolveE8Call(addr + 0x8B));
}

static uint8_t RemoveAbilityImpl(CCitadelPlayerPawn *pPawn, CCitadelBaseAbility *ability) {
    if (!pPawn || !ability) return 0;
    auto *comp = pPawn->m_CCitadelAbilityComponent.Get();
    if (!comp) return 0;

    auto compAddr = reinterpret_cast<uintptr_t>(comp);
    uint32_t rawHandle = static_cast<uint32_t>(ability->GetRefEHandle().ToInt());

    static FindSlotEntryFn findSlotFn = nullptr;
    static RemoveSlotEntryFn removeSlotFn = nullptr;
    if (!findSlotFn) {
        ResolveSlotTableFns(findSlotFn, removeSlotFn);
    }
    if (findSlotFn && removeSlotFn) {
        uint16_t slot = ability->m_eAbilitySlot.Get();
        auto *slotTable = reinterpret_cast<void *>(compAddr + 0x30);
        int entryIdx = findSlotFn(slotTable, &slot);
        if (entryIdx != -1)
            removeSlotFn(slotTable, entryIdx);
    }

    auto &vecAbilities = comp->m_vecAbilities.Get();
    int removedIdx = -1;
    for (int i = 0; i < vecAbilities.Count(); i++) {
        if (vecAbilities[i] == rawHandle) {
            vecAbilities.Remove(i);
            removedIdx = i;
            break;
        }
    }

    if (removedIdx != -1) {
        auto vecOffset = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&vecAbilities) - reinterpret_cast<uintptr_t>(pPawn));
        pPawn->NetworkStateChanged(NetworkStateChanged_t(vecOffset));
        for (int i = removedIdx; i < vecAbilities.Count(); i++)
            pPawn->NetworkStateChanged(NetworkStateChanged_t(vecOffset, i));
    }

    comp->m_bThinkableAbilitiesDirty.Get() = true;

    auto utilRemoveOpt = dsdk::MemoryDataLoader::Get().GetOffset("UTIL_Remove");
    if (utilRemoveOpt.has_value()) {
        auto utilRemove = reinterpret_cast<UTIL_RemoveFn>(*utilRemoveOpt);
        utilRemove(static_cast<CEntityInstance *>(ability));
    }
    return 1;
}

static CCitadelAbilityComponent *ResolveAbilityComponent(int64_t ptr) {
    if (!ptr) return nullptr;
    auto *inst = reinterpret_cast<CEntityInstance *>(ptr);
    if (inst && inst->m_pEntity != nullptr) {
        auto *pPawn = reinterpret_cast<CCitadelPlayerPawn *>(ptr);
        auto *comp = pPawn->m_CCitadelAbilityComponent.Get();
        if (comp) return comp;
    }
    return reinterpret_cast<CCitadelAbilityComponent *>(ptr);
}

extern "C" {

PLUGIN_API int64_t AddAbility(int64_t pawn, const plg::string &abilityName, uint16_t slot) {
    if (!pawn || abilityName.empty()) return 0;
    auto *pPawn = reinterpret_cast<CCitadelPlayerPawn *>(pawn);
    auto *comp = pPawn->m_CCitadelAbilityComponent.Get();
    if (!comp) return 0;

    auto *def = LookupSubclassDefinitionByName(EntitySubclassScope_t::SUBCLASS_SCOPE_ABILITIES, abilityName.c_str());
    if (!def) {
        dsdk::Logger::Warning("AddAbility: definition not found for '{}'", abilityName.c_str());
        return 0;
    }

    constexpr uintptr_t kSubclassDefDisabled = 0x2A;
    if (*reinterpret_cast<uint8_t *>(reinterpret_cast<uintptr_t>(def) + kSubclassDefDisabled)) {
        dsdk::Logger::Warning("AddAbility: ability '{}' is disabled", abilityName.c_str());
        return 0;
    }

    void *result = comp->CreateAndRegisterAbility(def, slot);
    return reinterpret_cast<int64_t>(result);
}

PLUGIN_API bool RemoveAbility(int64_t pawn, const plg::string &abilityName) {
    if (!pawn || abilityName.empty()) return false;
    auto *pPawn = reinterpret_cast<CCitadelPlayerPawn *>(pawn);
    auto *comp = pPawn->m_CCitadelAbilityComponent.Get();
    if (!comp) return false;

    auto *ability = static_cast<CCitadelBaseAbility *>(comp->FindAbilityByName(abilityName.c_str()));
    if (!ability) return false;

    return RemoveAbilityImpl(pPawn, ability) != 0;
}

PLUGIN_API bool RemoveAbilityByEntity(int64_t pawn, int64_t ability) {
    if (!pawn || !ability) return false;
    return RemoveAbilityImpl(reinterpret_cast<CCitadelPlayerPawn *>(pawn), reinterpret_cast<CCitadelBaseAbility *>(ability)) != 0;
}

PLUGIN_API int64_t FindAbilityByName(int64_t abilityComponent, const plg::string &abilityName) {
    if (!abilityComponent || abilityName.empty()) return 0;
    auto *comp = ResolveAbilityComponent(abilityComponent);
    if (!comp) return 0;
    return reinterpret_cast<int64_t>(comp->FindAbilityByName(abilityName.c_str()));
}

PLUGIN_API int64_t GetAbilityBySlot(int64_t abilityComponent, int16_t slot) {
    if (!abilityComponent) return 0;
    auto *comp = ResolveAbilityComponent(abilityComponent);
    if (!comp) return 0;
    return reinterpret_cast<int64_t>(comp->GetAbilityBySlot(slot));
}

PLUGIN_API int32_t ExecuteAbility(int64_t abilityComponent, int64_t ability, bool altCast, uint8_t flags) {
    if (!abilityComponent || !ability) return -1;
    auto *comp = ResolveAbilityComponent(abilityComponent);
    if (!comp) return -1;
    return comp->ExecuteAbility(reinterpret_cast<void *>(ability), altCast ? 1 : 0, flags);
}

PLUGIN_API void ToggleActivate(int64_t ability, bool activate) {
    if (!ability) return;
    reinterpret_cast<CCitadelBaseAbility *>(ability)->ToggleActivate(activate ? 1 : 0);
}

PLUGIN_API void ResetAbilityCooldown(int64_t ability) {
    if (!ability) return;
    auto *pAbility = reinterpret_cast<CCitadelBaseAbility *>(ability);
    pAbility->EndCooldown();
    if (pAbility->UsesCharges()) {
        pAbility->AddCharges(pAbility->GetMaxCharges());
    }
}

PLUGIN_API int32_t GetAbilityMaxCharges(int64_t ability) {
    if (!ability) return 0;
    auto *pAbility = reinterpret_cast<CCitadelBaseAbility *>(ability);
    return pAbility->UsesCharges() ? pAbility->GetMaxCharges() : 0;
}

PLUGIN_API void SetUpgradeBits(int64_t ability, int32_t newBits) {
    if (!ability) return;
    reinterpret_cast<CCitadelBaseAbility *>(ability)->SetUpgradeBits(newBits);
}

}
