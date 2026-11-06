#include "shared.h"

PLUGIFY_EXPORT int64_t (*__dsdk_AddAbility)(int64_t, String*, uint16_t) = NULL;


PLUGIFY_EXPORT bool (*__dsdk_RemoveAbility)(int64_t, String*) = NULL;


PLUGIFY_EXPORT bool (*__dsdk_RemoveAbilityByEntity)(int64_t, int64_t) = NULL;


PLUGIFY_EXPORT int64_t (*__dsdk_FindAbilityByName)(int64_t, String*) = NULL;


PLUGIFY_EXPORT int64_t (*__dsdk_GetAbilityBySlot)(int64_t, int16_t) = NULL;


PLUGIFY_EXPORT int32_t (*__dsdk_ExecuteAbility)(int64_t, int64_t, bool, uint8_t) = NULL;


PLUGIFY_EXPORT void (*__dsdk_ToggleActivate)(int64_t, bool) = NULL;


PLUGIFY_EXPORT void (*__dsdk_ResetAbilityCooldown)(int64_t) = NULL;


PLUGIFY_EXPORT int32_t (*__dsdk_GetAbilityMaxCharges)(int64_t) = NULL;


PLUGIFY_EXPORT void (*__dsdk_SetUpgradeBits)(int64_t, int32_t) = NULL;


