#pragma once

#include "shared.h"

extern bool (*__dsdk_NavGetNearestPoint)(float, float, float, float, int32_t);

static bool NavGetNearestPoint(float x, float y, float z, float maxDistance, int32_t hull) {
	return __dsdk_NavGetNearestPoint(x, y, z, maxDistance, hull);
}

extern float (*__dsdk_NavGetGroundHeight)(float, float, float, float, int32_t);

static float NavGetGroundHeight(float x, float y, float z, float maxDistance, int32_t hull) {
	return __dsdk_NavGetGroundHeight(x, y, z, maxDistance, hull);
}

