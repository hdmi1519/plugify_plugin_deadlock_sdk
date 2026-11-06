#pragma once

#include "shared.h"

extern int64_t (*__dsdk_AddItem)(int64_t, String*, int32_t);

static int64_t AddItem(int64_t pawn, String* itemName, int32_t upgradeTier) {
	return __dsdk_AddItem(pawn, itemName, upgradeTier);
}

extern bool (*__dsdk_SellItem)(int64_t, String*, bool, bool);

static bool SellItem(int64_t pawn, String* itemName, bool fullRefund, bool forceSellPrice) {
	return __dsdk_SellItem(pawn, itemName, fullRefund, forceSellPrice);
}

extern int32_t (*__dsdk_GetItemImbueEffects)(String*);

static int32_t GetItemImbueEffects(String* itemName) {
	return __dsdk_GetItemImbueEffects(itemName);
}

extern bool (*__dsdk_CanImbueAbility)(int64_t, String*);

static bool CanImbueAbility(int64_t targetAbility, String* itemName) {
	return __dsdk_CanImbueAbility(targetAbility, itemName);
}

extern bool (*__dsdk_ImbueAbility)(int64_t, int64_t);

static bool ImbueAbility(int64_t item, int64_t targetAbility) {
	return __dsdk_ImbueAbility(item, targetAbility);
}

