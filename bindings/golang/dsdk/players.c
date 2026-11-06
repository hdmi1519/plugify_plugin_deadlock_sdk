#include "shared.h"

PLUGIFY_EXPORT int64_t (*__dsdk_GetPlayerController)(int32_t) = NULL;


PLUGIFY_EXPORT int64_t (*__dsdk_GetPlayerPawn)(int32_t) = NULL;


PLUGIFY_EXPORT int32_t (*__dsdk_GetPlayerSlot)(int64_t) = NULL;


PLUGIFY_EXPORT String (*__dsdk_GetPlayerName)(int32_t) = NULL;


PLUGIFY_EXPORT uint64_t (*__dsdk_GetSteamID)(int32_t) = NULL;


PLUGIFY_EXPORT bool (*__dsdk_IsClientAuthenticated)(int32_t) = NULL;


PLUGIFY_EXPORT bool (*__dsdk_IsClientConnected)(int32_t) = NULL;


PLUGIFY_EXPORT bool (*__dsdk_IsFakeClient)(int32_t) = NULL;


PLUGIFY_EXPORT int32_t (*__dsdk_CreateFakeClient)(String*) = NULL;


PLUGIFY_EXPORT void (*__dsdk_DisconnectClient)(int32_t, int32_t) = NULL;


PLUGIFY_EXPORT void (*__dsdk_KickClient)(int32_t, String*, int32_t) = NULL;


PLUGIFY_EXPORT void (*__dsdk_ChangeTeam)(int64_t, int32_t, bool) = NULL;


PLUGIFY_EXPORT int32_t (*__dsdk_GetPlayerPing)(int32_t) = NULL;


