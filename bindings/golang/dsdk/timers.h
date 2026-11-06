#pragma once

#include "shared.h"

extern int64_t (*__dsdk_CreateTimer)(float, void*, bool);

static int64_t CreateTimer(float interval, void* callback, bool repeating) {
	return __dsdk_CreateTimer(interval, callback, repeating);
}

extern bool (*__dsdk_KillTimer)(int64_t);

static bool KillTimer(int64_t timerId) {
	return __dsdk_KillTimer(timerId);
}

