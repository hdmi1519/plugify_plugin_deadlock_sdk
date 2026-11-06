#pragma once

#include "shared.h"

extern void (*__dsdk_ModifyCurrency)(int64_t, uint32_t, int32_t, uint32_t, bool, bool, bool, int64_t, int64_t);

static void ModifyCurrency(int64_t pawn, uint32_t currencyType, int32_t amount, uint32_t source, bool silent, bool forceGain, bool spendOnly, int64_t sourceAbility, int64_t sourceEntity) {
	__dsdk_ModifyCurrency(pawn, currencyType, amount, source, silent, forceGain, spendOnly, sourceAbility, sourceEntity);
}

extern int32_t (*__dsdk_GetCurrency)(int64_t, uint32_t);

static int32_t GetCurrency(int64_t pawn, uint32_t currencyType) {
	return __dsdk_GetCurrency(pawn, currencyType);
}

