#pragma once

#include "shared.h"

extern String (*__dsdk_GetMapName)();

static String GetMapName() {
	return __dsdk_GetMapName();
}

extern bool (*__dsdk_IsMapValid)(String*);

static bool IsMapValid(String* map_) {
	return __dsdk_IsMapValid(map_);
}

extern bool (*__dsdk_SetServerKeyValue)(String*, String*);

static bool SetServerKeyValue(String* key, String* value) {
	return __dsdk_SetServerKeyValue(key, value);
}

extern bool (*__dsdk_ClearServerKeyValues)();

static bool ClearServerKeyValues() {
	return __dsdk_ClearServerKeyValues();
}

extern void (*__dsdk_SetServerAddons)(String*);

static void SetServerAddons(String* addons) {
	__dsdk_SetServerAddons(addons);
}

extern bool (*__dsdk_AddFileSystemSearchPath)(String*, String*, int32_t);

static bool AddFileSystemSearchPath(String* path, String* pathId, int32_t addType) {
	return __dsdk_AddFileSystemSearchPath(path, pathId, addType);
}

extern bool (*__dsdk_HasCommandLineParm)(String*);

static bool HasCommandLineParm(String* parm) {
	return __dsdk_HasCommandLineParm(parm);
}

extern void (*__dsdk_SetConnectRejectReason)(String*);

static void SetConnectRejectReason(String* reason) {
	__dsdk_SetConnectRejectReason(reason);
}

extern int64_t (*__dsdk_GetGlobalVars)();

static int64_t GetGlobalVars() {
	return __dsdk_GetGlobalVars();
}

extern float (*__dsdk_GetGameTime)();

static float GetGameTime() {
	return __dsdk_GetGameTime();
}

extern int32_t (*__dsdk_GetGameTickCount)();

static int32_t GetGameTickCount() {
	return __dsdk_GetGameTickCount();
}

