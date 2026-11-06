#include "shared.h"

PLUGIFY_EXPORT String (*__dsdk_GetMapName)() = NULL;


PLUGIFY_EXPORT bool (*__dsdk_IsMapValid)(String*) = NULL;


PLUGIFY_EXPORT bool (*__dsdk_SetServerKeyValue)(String*, String*) = NULL;


PLUGIFY_EXPORT bool (*__dsdk_ClearServerKeyValues)() = NULL;


PLUGIFY_EXPORT void (*__dsdk_SetServerAddons)(String*) = NULL;


PLUGIFY_EXPORT bool (*__dsdk_AddFileSystemSearchPath)(String*, String*, int32_t) = NULL;


PLUGIFY_EXPORT bool (*__dsdk_HasCommandLineParm)(String*) = NULL;


PLUGIFY_EXPORT void (*__dsdk_SetConnectRejectReason)(String*) = NULL;


PLUGIFY_EXPORT int64_t (*__dsdk_GetGlobalVars)() = NULL;


PLUGIFY_EXPORT float (*__dsdk_GetGameTime)() = NULL;


PLUGIFY_EXPORT int32_t (*__dsdk_GetGameTickCount)() = NULL;


