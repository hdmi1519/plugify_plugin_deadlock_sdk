#pragma once

#include "shared.h"

extern void (*__dsdk_EmitSound)(int64_t, String*, int32_t, float, float);

static void EmitSound(int64_t entity, String* soundName, int32_t pitch, float volume, float delay) {
	__dsdk_EmitSound(entity, soundName, pitch, volume, delay);
}

extern uint32_t (*__dsdk_TakeSoundEventGuid)();

static uint32_t TakeSoundEventGuid() {
	return __dsdk_TakeSoundEventGuid();
}

