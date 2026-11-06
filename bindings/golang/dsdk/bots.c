#include "shared.h"

PLUGIFY_EXPORT int64_t (*__dsdk_BotCreate)(String*, int32_t, float, float, float, bool) = NULL;


PLUGIFY_EXPORT int64_t (*__dsdk_BotGetBrain)(int64_t) = NULL;


PLUGIFY_EXPORT int64_t (*__dsdk_BotGetPawn)(int64_t) = NULL;


PLUGIFY_EXPORT bool (*__dsdk_BotSetLane)(int64_t, int32_t) = NULL;


PLUGIFY_EXPORT int32_t (*__dsdk_BotGetLane)(int64_t) = NULL;


