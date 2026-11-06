#pragma once

#include "shared.h"

extern String (*__dsdk_GetConfigString)(String*, String*);

static String GetConfigString(String* key, String* defaultValue) {
	return __dsdk_GetConfigString(key, defaultValue);
}

extern int32_t (*__dsdk_GetConfigInt)(String*, int32_t);

static int32_t GetConfigInt(String* key, int32_t defaultValue) {
	return __dsdk_GetConfigInt(key, defaultValue);
}

extern bool (*__dsdk_GetConfigBool)(String*, bool);

static bool GetConfigBool(String* key, bool defaultValue) {
	return __dsdk_GetConfigBool(key, defaultValue);
}

extern float (*__dsdk_GetConfigFloat)(String*, float);

static float GetConfigFloat(String* key, float defaultValue) {
	return __dsdk_GetConfigFloat(key, defaultValue);
}

