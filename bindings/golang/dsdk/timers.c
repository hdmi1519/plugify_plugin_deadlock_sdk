#include "shared.h"

PLUGIFY_EXPORT int64_t (*__dsdk_CreateTimer)(float, void*, bool) = NULL;


PLUGIFY_EXPORT bool (*__dsdk_KillTimer)(int64_t) = NULL;


