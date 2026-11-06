#include "shared.h"

PLUGIFY_EXPORT void (*__dsdk_NpcMoveTo)(int64_t, float, float, float, bool, float) = NULL;


PLUGIFY_EXPORT void (*__dsdk_NpcStopMoving)(int64_t, bool) = NULL;


PLUGIFY_EXPORT void (*__dsdk_NpcSetEnemy)(int64_t, int64_t) = NULL;


PLUGIFY_EXPORT void (*__dsdk_NpcSetState)(int64_t, int32_t) = NULL;


PLUGIFY_EXPORT int64_t (*__dsdk_NpcCreateTrooper)(float, float, float, float, float, float, int32_t, int32_t, int32_t, bool) = NULL;


