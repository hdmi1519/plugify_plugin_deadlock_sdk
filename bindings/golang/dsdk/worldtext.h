#pragma once

#include "shared.h"

extern int64_t (*__dsdk_CreateWorldText)(String*, float, float, float, float, uint8_t, uint8_t, uint8_t, uint8_t);

static int64_t CreateWorldText(String* message, float x, float y, float z, float fontSize, uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
	return __dsdk_CreateWorldText(message, x, y, z, fontSize, r, g, b, a);
}

extern void (*__dsdk_SetWorldTextMessage)(int64_t, String*);

static void SetWorldTextMessage(int64_t worldText, String* text) {
	__dsdk_SetWorldTextMessage(worldText, text);
}

