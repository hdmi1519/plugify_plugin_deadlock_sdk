#include "pch.hpp"
#include "core/memory/data_loader.hpp"
#include "core/logger.hpp"
#include "core/sdk/CCitadelPlayerPawn.hpp"
#include "core/sdk/CitadelAbilityVData.hpp"
#include "core/sdk/CCitadelBaseAbility.hpp"

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

static CitadelAbilityVData *LookupItemVData(const char *itemName) {
    return reinterpret_cast<CitadelAbilityVData *>(
        LookupSubclassDefinitionByName(EntitySubclassScope_t::SUBCLASS_SCOPE_ABILITIES, itemName));
}

static CitadelAbilityVData *GetAbilityVData(void *ability) {
    if (!ability) return nullptr;
    return reinterpret_cast<CitadelAbilityVData *>(static_cast<CBaseEntity *>(ability)->GetSubclassVData());
}

extern "C" {

PLUGIN_API int64_t AddItem(int64_t pawn, const plg::string &itemName, int32_t upgradeTier) {
    if (!pawn || itemName.empty()) return 0;
    auto *pPawn = reinterpret_cast<CCitadelPlayerPawn *>(pawn);
    void *item = pPawn->AddItem(itemName.c_str(), static_cast<uint16_t>(upgradeTier));
    return reinterpret_cast<int64_t>(item);
}

PLUGIN_API bool SellItem(int64_t pawn, const plg::string &itemName, bool fullRefund, bool forceSellPrice) {
    if (!pawn || itemName.empty()) return false;
    auto *pPawn = reinterpret_cast<CCitadelPlayerPawn *>(pawn);
    return pPawn->SellItem(itemName.c_str(), fullRefund ? 1 : 0, forceSellPrice ? 1 : 0) != 0;
}

PLUGIN_API int32_t GetItemImbueEffects(const plg::string &itemName) {
    if (itemName.empty()) return -1;
    auto *vdata = LookupItemVData(itemName.c_str());
    if (!vdata) return -1;
    return static_cast<int32_t>(vdata->m_TargetAbilityEffectsToApply.Get());
}

PLUGIN_API bool CanImbueAbility(int64_t targetAbility, const plg::string &itemName) {
    if (!targetAbility || itemName.empty()) return false;
    auto *itemVData = LookupItemVData(itemName.c_str());
    if (!itemVData || !itemVData->CanBeImbued()) return false;
    auto *targetVData = GetAbilityVData(reinterpret_cast<void *>(targetAbility));
    if (!targetVData) return false;
    return targetVData->CanImbueAbility(itemVData);
}

PLUGIN_API bool ImbueAbility(int64_t item, int64_t targetAbility) {
    if (!item || !targetAbility) return false;
    auto *itemVData = GetAbilityVData(reinterpret_cast<void *>(item));
    auto *targetVData = GetAbilityVData(reinterpret_cast<void *>(targetAbility));
    if (!itemVData || !targetVData) return false;
    if (!itemVData->CanBeImbued()) return false;
    if (!targetVData->CanImbueAbility(itemVData)) return false;

    reinterpret_cast<CCitadelBaseAbility *>(item)->ImbueAbility(reinterpret_cast<void *>(targetAbility));
    return true;
}

}
