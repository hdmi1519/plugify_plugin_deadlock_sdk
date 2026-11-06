#include "shared.h"

PLUGIFY_EXPORT void (*__dsdk_ModifyCurrency)(int64_t, uint32_t, int32_t, uint32_t, bool, bool, bool, int64_t, int64_t) = NULL;


PLUGIFY_EXPORT int32_t (*__dsdk_GetCurrency)(int64_t, uint32_t) = NULL;


