#include "shared.h"

PLUGIFY_EXPORT int64_t (*__dsdk_KV3Create)() = NULL;


PLUGIFY_EXPORT void (*__dsdk_KV3Destroy)(int64_t) = NULL;


PLUGIFY_EXPORT void (*__dsdk_KV3SetString)(int64_t, String*, String*) = NULL;


PLUGIFY_EXPORT void (*__dsdk_KV3SetBool)(int64_t, String*, bool) = NULL;


PLUGIFY_EXPORT void (*__dsdk_KV3SetInt)(int64_t, String*, int32_t) = NULL;


PLUGIFY_EXPORT void (*__dsdk_KV3SetFloat)(int64_t, String*, float) = NULL;


