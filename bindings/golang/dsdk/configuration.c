#include "shared.h"

PLUGIFY_EXPORT String (*__dsdk_GetConfigString)(String*, String*) = NULL;


PLUGIFY_EXPORT int32_t (*__dsdk_GetConfigInt)(String*, int32_t) = NULL;


PLUGIFY_EXPORT bool (*__dsdk_GetConfigBool)(String*, bool) = NULL;


PLUGIFY_EXPORT float (*__dsdk_GetConfigFloat)(String*, float) = NULL;


