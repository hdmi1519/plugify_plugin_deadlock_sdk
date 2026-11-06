#include "shared.h"

PLUGIFY_EXPORT void (*__dsdk_SelectHero)(int64_t, String*) = NULL;


PLUGIFY_EXPORT void (*__dsdk_ResetHero)(int64_t, bool) = NULL;


PLUGIFY_EXPORT void (*__dsdk_PrecacheHero)(String*) = NULL;


PLUGIFY_EXPORT void (*__dsdk_ForceRespawn)(int64_t, bool) = NULL;


PLUGIFY_EXPORT int64_t (*__dsdk_GetHeroData)(String*) = NULL;


PLUGIFY_EXPORT String (*__dsdk_GetHeroName)(int64_t) = NULL;


