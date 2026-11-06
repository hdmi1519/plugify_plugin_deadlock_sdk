#include "shared.h"

PLUGIFY_EXPORT int64_t (*__dsdk_CreateDamageInfo)(int64_t, int64_t, int64_t, float, int32_t) = NULL;


PLUGIFY_EXPORT void (*__dsdk_DestroyDamageInfo)(int64_t) = NULL;


PLUGIFY_EXPORT void (*__dsdk_TakeDamage)(int64_t, int64_t) = NULL;


PLUGIFY_EXPORT void (*__dsdk_ApplyDamage)(int64_t, int64_t) = NULL;


PLUGIFY_EXPORT int32_t (*__dsdk_GetMaxHealth)(int64_t) = NULL;


PLUGIFY_EXPORT int32_t (*__dsdk_Heal)(int64_t, float) = NULL;


