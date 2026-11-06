#pragma once

#include "shared.h"

extern int64_t (*__dsdk_CreateParticle)(String*, int32_t, int64_t);

static int64_t CreateParticle(String* particleName, int32_t attachType, int64_t entity) {
	return __dsdk_CreateParticle(particleName, attachType, entity);
}

extern void (*__dsdk_DestroyParticle)(int64_t, bool);

static void DestroyParticle(int64_t particle, bool destroyImmediately) {
	__dsdk_DestroyParticle(particle, destroyImmediately);
}

