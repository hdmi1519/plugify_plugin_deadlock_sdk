#include "shared.h"

PLUGIFY_EXPORT uint64_t (*__dsdk_FindConVar)(String*) = NULL;


PLUGIFY_EXPORT uint64_t (*__dsdk_CreateConVar)(String*, String*, String*, uint64_t) = NULL;


PLUGIFY_EXPORT int32_t (*__dsdk_GetConVarInt)(uint64_t) = NULL;


PLUGIFY_EXPORT float (*__dsdk_GetConVarFloat)(uint64_t) = NULL;


PLUGIFY_EXPORT String (*__dsdk_GetConVarString)(uint64_t) = NULL;


PLUGIFY_EXPORT bool (*__dsdk_GetConVarBool)(uint64_t) = NULL;


PLUGIFY_EXPORT void (*__dsdk_SetConVarInt)(uint64_t, int32_t) = NULL;


PLUGIFY_EXPORT void (*__dsdk_SetConVarFloat)(uint64_t, float) = NULL;


PLUGIFY_EXPORT bool (*__dsdk_SetConVarString)(uint64_t, String*) = NULL;


