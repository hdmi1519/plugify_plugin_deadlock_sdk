#pragma once

#include "shared.h"

extern void (*__dsdk_RegisterGameEvent)(String*);

static void RegisterGameEvent(String* name) {
	__dsdk_RegisterGameEvent(name);
}

extern int64_t (*__dsdk_CreateGameEvent)(String*, bool);

static int64_t CreateGameEvent(String* name, bool force) {
	return __dsdk_CreateGameEvent(name, force);
}

extern bool (*__dsdk_FireGameEvent)(int64_t, bool);

static bool FireGameEvent(int64_t event, bool dontBroadcast) {
	return __dsdk_FireGameEvent(event, dontBroadcast);
}

extern void (*__dsdk_FreeGameEvent)(int64_t);

static void FreeGameEvent(int64_t event) {
	__dsdk_FreeGameEvent(event);
}

extern bool (*__dsdk_GameEventGetBool)(int64_t, String*, bool);

static bool GameEventGetBool(int64_t event, String* key, bool def) {
	return __dsdk_GameEventGetBool(event, key, def);
}

extern int32_t (*__dsdk_GameEventGetInt)(int64_t, String*, int32_t);

static int32_t GameEventGetInt(int64_t event, String* key, int32_t def) {
	return __dsdk_GameEventGetInt(event, key, def);
}

extern float (*__dsdk_GameEventGetFloat)(int64_t, String*, float);

static float GameEventGetFloat(int64_t event, String* key, float def) {
	return __dsdk_GameEventGetFloat(event, key, def);
}

extern String (*__dsdk_GameEventGetString)(int64_t, String*, String*);

static String GameEventGetString(int64_t event, String* key, String* def) {
	return __dsdk_GameEventGetString(event, key, def);
}

extern uint64_t (*__dsdk_GameEventGetUint64)(int64_t, String*, uint64_t);

static uint64_t GameEventGetUint64(int64_t event, String* key, uint64_t def) {
	return __dsdk_GameEventGetUint64(event, key, def);
}

extern void (*__dsdk_GameEventSetBool)(int64_t, String*, bool);

static void GameEventSetBool(int64_t event, String* key, bool val) {
	__dsdk_GameEventSetBool(event, key, val);
}

extern void (*__dsdk_GameEventSetInt)(int64_t, String*, int32_t);

static void GameEventSetInt(int64_t event, String* key, int32_t val) {
	__dsdk_GameEventSetInt(event, key, val);
}

extern void (*__dsdk_GameEventSetFloat)(int64_t, String*, float);

static void GameEventSetFloat(int64_t event, String* key, float val) {
	__dsdk_GameEventSetFloat(event, key, val);
}

extern void (*__dsdk_GameEventSetString)(int64_t, String*, String*);

static void GameEventSetString(int64_t event, String* key, String* val) {
	__dsdk_GameEventSetString(event, key, val);
}

extern int32_t (*__dsdk_GameEventGetPlayerSlot)(int64_t, String*);

static int32_t GameEventGetPlayerSlot(int64_t event, String* key) {
	return __dsdk_GameEventGetPlayerSlot(event, key);
}

extern int64_t (*__dsdk_GameEventGetPlayerPawn)(int64_t, String*);

static int64_t GameEventGetPlayerPawn(int64_t event, String* key) {
	return __dsdk_GameEventGetPlayerPawn(event, key);
}

extern int64_t (*__dsdk_GameEventGetPlayerController)(int64_t, String*);

static int64_t GameEventGetPlayerController(int64_t event, String* key) {
	return __dsdk_GameEventGetPlayerController(event, key);
}

