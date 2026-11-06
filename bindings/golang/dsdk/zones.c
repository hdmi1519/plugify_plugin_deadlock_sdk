#include "shared.h"

PLUGIFY_EXPORT int64_t (*__dsdk_CreateBeam)(float, float, float, float, float, float, float, uint8_t, uint8_t, uint8_t, uint8_t) = NULL;


PLUGIFY_EXPORT int64_t (*__dsdk_CreateZone)(String*, float, float, float, float, float, float) = NULL;


PLUGIFY_EXPORT void (*__dsdk_DestroyZone)(int64_t) = NULL;


