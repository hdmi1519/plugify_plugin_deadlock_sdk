#include "shared.h"

PLUGIFY_EXPORT bool (*__dsdk_AddServerCommand)(String*, String*, int64_t, void*) = NULL;


PLUGIFY_EXPORT bool (*__dsdk_AddClientCommand)(String*, String*, int64_t, void*) = NULL;


PLUGIFY_EXPORT bool (*__dsdk_AddChatCommand)(String*, String*, int64_t, void*) = NULL;


PLUGIFY_EXPORT bool (*__dsdk_AddConsoleCommand)(String*, String*, int64_t, void*) = NULL;


PLUGIFY_EXPORT bool (*__dsdk_RemoveCommand)(String*) = NULL;


PLUGIFY_EXPORT void (*__dsdk_ServerCommand)(String*) = NULL;


PLUGIFY_EXPORT bool (*__dsdk_ExecuteCommandAsPlayer)(int32_t, String*) = NULL;


PLUGIFY_EXPORT void (*__dsdk_ClientCommand)(int32_t, String*) = NULL;


