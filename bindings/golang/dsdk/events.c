#include "shared.h"

PLUGIFY_EXPORT void (*__dsdk_RegisterGameEvent)(String*) = NULL;


PLUGIFY_EXPORT int64_t (*__dsdk_CreateGameEvent)(String*, bool) = NULL;


PLUGIFY_EXPORT bool (*__dsdk_FireGameEvent)(int64_t, bool) = NULL;


PLUGIFY_EXPORT void (*__dsdk_FreeGameEvent)(int64_t) = NULL;


PLUGIFY_EXPORT bool (*__dsdk_GameEventGetBool)(int64_t, String*, bool) = NULL;


PLUGIFY_EXPORT int32_t (*__dsdk_GameEventGetInt)(int64_t, String*, int32_t) = NULL;


PLUGIFY_EXPORT float (*__dsdk_GameEventGetFloat)(int64_t, String*, float) = NULL;


PLUGIFY_EXPORT String (*__dsdk_GameEventGetString)(int64_t, String*, String*) = NULL;


PLUGIFY_EXPORT uint64_t (*__dsdk_GameEventGetUint64)(int64_t, String*, uint64_t) = NULL;


PLUGIFY_EXPORT void (*__dsdk_GameEventSetBool)(int64_t, String*, bool) = NULL;


PLUGIFY_EXPORT void (*__dsdk_GameEventSetInt)(int64_t, String*, int32_t) = NULL;


PLUGIFY_EXPORT void (*__dsdk_GameEventSetFloat)(int64_t, String*, float) = NULL;


PLUGIFY_EXPORT void (*__dsdk_GameEventSetString)(int64_t, String*, String*) = NULL;


PLUGIFY_EXPORT int32_t (*__dsdk_GameEventGetPlayerSlot)(int64_t, String*) = NULL;


PLUGIFY_EXPORT int64_t (*__dsdk_GameEventGetPlayerPawn)(int64_t, String*) = NULL;


PLUGIFY_EXPORT int64_t (*__dsdk_GameEventGetPlayerController)(int64_t, String*) = NULL;


