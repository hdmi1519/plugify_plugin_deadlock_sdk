#include "shared.h"

PLUGIFY_EXPORT int64_t (*__dsdk_CreateParticle)(String*, int32_t, int64_t) = NULL;


PLUGIFY_EXPORT void (*__dsdk_DestroyParticle)(int64_t, bool) = NULL;


