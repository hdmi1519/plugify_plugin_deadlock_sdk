#pragma once

#include "shared.h"

extern void (*__dsdk_AcceptInput)(int64_t, String*, int64_t, int64_t, String*);

static void AcceptInput(int64_t entity, String* inputName, int64_t activator, int64_t caller, String* value) {
	__dsdk_AcceptInput(entity, inputName, activator, caller, value);
}

