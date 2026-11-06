#pragma once

#include "shared.h"

extern int64_t (*__dsdk_GetPlayerController)(int32_t);

static int64_t GetPlayerController(int32_t playerSlot) {
	return __dsdk_GetPlayerController(playerSlot);
}

extern int64_t (*__dsdk_GetPlayerPawn)(int32_t);

static int64_t GetPlayerPawn(int32_t playerSlot) {
	return __dsdk_GetPlayerPawn(playerSlot);
}

extern int32_t (*__dsdk_GetPlayerSlot)(int64_t);

static int32_t GetPlayerSlot(int64_t controller) {
	return __dsdk_GetPlayerSlot(controller);
}

extern String (*__dsdk_GetPlayerName)(int32_t);

static String GetPlayerName(int32_t playerSlot) {
	return __dsdk_GetPlayerName(playerSlot);
}

extern uint64_t (*__dsdk_GetSteamID)(int32_t);

static uint64_t GetSteamID(int32_t playerSlot) {
	return __dsdk_GetSteamID(playerSlot);
}

extern bool (*__dsdk_IsClientAuthenticated)(int32_t);

static bool IsClientAuthenticated(int32_t playerSlot) {
	return __dsdk_IsClientAuthenticated(playerSlot);
}

extern bool (*__dsdk_IsClientConnected)(int32_t);

static bool IsClientConnected(int32_t playerSlot) {
	return __dsdk_IsClientConnected(playerSlot);
}

extern bool (*__dsdk_IsFakeClient)(int32_t);

static bool IsFakeClient(int32_t playerSlot) {
	return __dsdk_IsFakeClient(playerSlot);
}

extern int32_t (*__dsdk_CreateFakeClient)(String*);

static int32_t CreateFakeClient(String* name) {
	return __dsdk_CreateFakeClient(name);
}

extern void (*__dsdk_DisconnectClient)(int32_t, int32_t);

static void DisconnectClient(int32_t playerSlot, int32_t reason) {
	__dsdk_DisconnectClient(playerSlot, reason);
}

extern void (*__dsdk_KickClient)(int32_t, String*, int32_t);

static void KickClient(int32_t playerSlot, String* reason, int32_t code) {
	__dsdk_KickClient(playerSlot, reason, code);
}

extern void (*__dsdk_ChangeTeam)(int64_t, int32_t, bool);

static void ChangeTeam(int64_t controller, int32_t teamNum, bool keepHero) {
	__dsdk_ChangeTeam(controller, teamNum, keepHero);
}

extern int32_t (*__dsdk_GetPlayerPing)(int32_t);

static int32_t GetPlayerPing(int32_t playerSlot) {
	return __dsdk_GetPlayerPing(playerSlot);
}

