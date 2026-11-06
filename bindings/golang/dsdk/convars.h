#pragma once

#include "shared.h"

extern uint64_t (*__dsdk_FindConVar)(String*);

static uint64_t FindConVar(String* name) {
	return __dsdk_FindConVar(name);
}

extern uint64_t (*__dsdk_CreateConVar)(String*, String*, String*, uint64_t);

static uint64_t CreateConVar(String* name, String* defaultValue, String* description, uint64_t flags) {
	return __dsdk_CreateConVar(name, defaultValue, description, flags);
}

extern int32_t (*__dsdk_GetConVarInt)(uint64_t);

static int32_t GetConVarInt(uint64_t handle) {
	return __dsdk_GetConVarInt(handle);
}

extern float (*__dsdk_GetConVarFloat)(uint64_t);

static float GetConVarFloat(uint64_t handle) {
	return __dsdk_GetConVarFloat(handle);
}

extern String (*__dsdk_GetConVarString)(uint64_t);

static String GetConVarString(uint64_t handle) {
	return __dsdk_GetConVarString(handle);
}

extern bool (*__dsdk_GetConVarBool)(uint64_t);

static bool GetConVarBool(uint64_t handle) {
	return __dsdk_GetConVarBool(handle);
}

extern void (*__dsdk_SetConVarInt)(uint64_t, int32_t);

static void SetConVarInt(uint64_t handle, int32_t value) {
	__dsdk_SetConVarInt(handle, value);
}

extern void (*__dsdk_SetConVarFloat)(uint64_t, float);

static void SetConVarFloat(uint64_t handle, float value) {
	__dsdk_SetConVarFloat(handle, value);
}

extern bool (*__dsdk_SetConVarString)(uint64_t, String*);

static bool SetConVarString(uint64_t handle, String* value) {
	return __dsdk_SetConVarString(handle, value);
}

