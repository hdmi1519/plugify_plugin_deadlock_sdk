#include "shared.h"

PLUGIFY_EXPORT int64_t (*__dsdk_CreateEntityByName)(String*) = NULL;


PLUGIFY_EXPORT void (*__dsdk_QueueSpawnEntity)(int64_t, int64_t) = NULL;


PLUGIFY_EXPORT void (*__dsdk_ExecuteQueuedCreation)() = NULL;


PLUGIFY_EXPORT void (*__dsdk_RemoveEntity)(int64_t) = NULL;


PLUGIFY_EXPORT int64_t (*__dsdk_GetEntityByIndex)(int32_t) = NULL;


PLUGIFY_EXPORT int64_t (*__dsdk_GetEntityFromHandle)(uint32_t) = NULL;


PLUGIFY_EXPORT uint32_t (*__dsdk_GetEntityHandle)(int64_t) = NULL;


PLUGIFY_EXPORT int64_t (*__dsdk_FindEntityByName)(int64_t, String*) = NULL;


PLUGIFY_EXPORT String (*__dsdk_GetEntityDesignerName)(int64_t) = NULL;


PLUGIFY_EXPORT String (*__dsdk_GetEntityClassname)(int64_t) = NULL;


PLUGIFY_EXPORT void (*__dsdk_Teleport)(int64_t, float, float, float, float, float, float, float, float, float) = NULL;


PLUGIFY_EXPORT void (*__dsdk_SetModel)(int64_t, String*) = NULL;


PLUGIFY_EXPORT String (*__dsdk_GetModelName)(int64_t) = NULL;


PLUGIFY_EXPORT void (*__dsdk_SetScale)(int64_t, float) = NULL;


PLUGIFY_EXPORT void (*__dsdk_SetMoveType)(int64_t, uint8_t) = NULL;


PLUGIFY_EXPORT void (*__dsdk_SetGravityScale)(int64_t, float) = NULL;


PLUGIFY_EXPORT bool (*__dsdk_EntityDerivesFrom)(int64_t, String*) = NULL;


