#include "shared.h"

PLUGIFY_EXPORT void (*__dsdk_PrintToChat)(int32_t, String*) = NULL;


PLUGIFY_EXPORT void (*__dsdk_PrintToChatAll)(String*) = NULL;


PLUGIFY_EXPORT void (*__dsdk_PrintToConsole)(int32_t, String*) = NULL;


PLUGIFY_EXPORT void (*__dsdk_PrintToConsoleAll)(String*) = NULL;


PLUGIFY_EXPORT void (*__dsdk_HudAnnounce)(int32_t, String*, String*, float) = NULL;


PLUGIFY_EXPORT void (*__dsdk_HudAnnounceAll)(String*, String*, float) = NULL;


