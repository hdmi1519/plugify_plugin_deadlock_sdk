#pragma once

#include "shared.h"

extern bool (*__dsdk_LineTrace)(float, float, float, float, float, float, uint32_t, int64_t);

static bool LineTrace(float startX, float startY, float startZ, float endX, float endY, float endZ, uint32_t mask, int64_t ignoreEntity) {
	return __dsdk_LineTrace(startX, startY, startZ, endX, endY, endZ, mask, ignoreEntity);
}

