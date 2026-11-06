#pragma once

#include "shared.h"

extern int64_t (*__dsdk_CreateBeam)(float, float, float, float, float, float, float, uint8_t, uint8_t, uint8_t, uint8_t);

static int64_t CreateBeam(float startX, float startY, float startZ, float endX, float endY, float endZ, float width, uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
	return __dsdk_CreateBeam(startX, startY, startZ, endX, endY, endZ, width, r, g, b, a);
}

extern int64_t (*__dsdk_CreateZone)(String*, float, float, float, float, float, float);

static int64_t CreateZone(String* name, float minX, float minY, float minZ, float maxX, float maxY, float maxZ) {
	return __dsdk_CreateZone(name, minX, minY, minZ, maxX, maxY, maxZ);
}

extern void (*__dsdk_DestroyZone)(int64_t);

static void DestroyZone(int64_t zoneId) {
	__dsdk_DestroyZone(zoneId);
}

