#include "shared.h"

PLUGIFY_EXPORT int32_t (*__dsdk_GetSchemaFieldOffset)(String*, String*) = NULL;


PLUGIFY_EXPORT void (*__dsdk_NotifyStateChanged)(int64_t, int32_t, int16_t, int32_t) = NULL;


PLUGIFY_EXPORT void (*__dsdk_SetSchemaString)(int64_t, String*, String*, String*) = NULL;


PLUGIFY_EXPORT int32_t (*__dsdk_GetSchemaClassSize)(String*) = NULL;


