#pragma once

#include "shared.h"

extern int32_t (*__dsdk_GetGameState)();

static int32_t GetGameState() {
	return __dsdk_GetGameState();
}

extern void (*__dsdk_ChangeGameState)(int32_t);

static void ChangeGameState(int32_t newState) {
	__dsdk_ChangeGameState(newState);
}

extern void (*__dsdk_SetWaitingForPlayersRoster)(uint32_t, uint32_t);

static void SetWaitingForPlayersRoster(uint32_t readyCount, uint32_t totalCount) {
	__dsdk_SetWaitingForPlayersRoster(readyCount, totalCount);
}

extern void (*__dsdk_SetMatchStartOnAnyMap)(bool);

static void SetMatchStartOnAnyMap(bool enabled) {
	__dsdk_SetMatchStartOnAnyMap(enabled);
}

extern bool (*__dsdk_GetMatchStartOnAnyMap)();

static bool GetMatchStartOnAnyMap() {
	return __dsdk_GetMatchStartOnAnyMap();
}

