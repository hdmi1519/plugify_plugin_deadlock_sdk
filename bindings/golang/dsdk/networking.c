#include "shared.h"

PLUGIFY_EXPORT void (*__dsdk_SendNetMessage)(int32_t, Vector*, uint64_t, int32_t) = NULL;


PLUGIFY_EXPORT String (*__dsdk_GetNetMessageName)(int32_t) = NULL;


