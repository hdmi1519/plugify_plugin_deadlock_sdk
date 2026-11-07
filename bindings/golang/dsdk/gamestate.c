#include "shared.h"

PLUGIFY_EXPORT int32_t (*__dsdk_GetGameState)() = NULL;


PLUGIFY_EXPORT float (*__dsdk_GetMatchTime)() = NULL;


PLUGIFY_EXPORT void (*__dsdk_ChangeGameState)(int32_t) = NULL;


PLUGIFY_EXPORT void (*__dsdk_SetWaitingForPlayersRoster)(uint32_t, uint32_t) = NULL;


PLUGIFY_EXPORT void (*__dsdk_SetMatchStartOnAnyMap)(bool) = NULL;


PLUGIFY_EXPORT bool (*__dsdk_GetMatchStartOnAnyMap)() = NULL;


