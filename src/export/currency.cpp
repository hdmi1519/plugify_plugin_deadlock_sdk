#include "pch.hpp"
#include "core/memory/data_loader.hpp"
#include "core/logger.hpp"
#include "core/sdk/schema/Schema.hpp"

using ModifyCurrencyFn = void(__fastcall *)(void *pawn, uint32_t nCurrencyType, int32_t nAmount,
                                            uint32_t nSource, int32_t bSilent, int32_t bForceGain, int32_t bSpendOnly,
                                            void *pSourceAbility, void *pSourceEntity);

extern "C" {

PLUGIN_API void ModifyCurrency(int64_t pawn, uint32_t currencyType, int32_t amount, uint32_t source,
                               bool silent, bool forceGain, bool spendOnly, int64_t sourceAbility, int64_t sourceEntity) {
    if (!pawn) return;
    auto offset = dsdk::MemoryDataLoader::Get().GetOffset("CCitadelPlayerPawn::ModifyCurrency");
    if (!offset.has_value()) {
        dsdk::Logger::Warning("ModifyCurrency signature not resolved");
        return;
    }
    auto fn = reinterpret_cast<ModifyCurrencyFn>(*offset);
    fn(reinterpret_cast<void *>(pawn), currencyType, amount, source,
       silent ? 1 : 0, forceGain ? 1 : 0, spendOnly ? 1 : 0,
       reinterpret_cast<void *>(sourceAbility), reinterpret_cast<void *>(sourceEntity));
}

PLUGIN_API int32_t GetCurrency(int64_t pawn, uint32_t currencyType) {
    if (!pawn || currencyType >= 6) return 0;
    static int s_offset = -1;
    if (s_offset == -1) {
        s_offset = schema::GetOffset("CCitadelPlayerPawn", hash_32_fnv1a_const("CCitadelPlayerPawn"),
                                     "m_nCurrencies", hash_32_fnv1a_const("m_nCurrencies")).Offset;
    }
    if (s_offset > 0) {
        auto *currencies = reinterpret_cast<int32_t *>(pawn + s_offset);
        return currencies[currencyType];
    }
    return 0;
}

}
