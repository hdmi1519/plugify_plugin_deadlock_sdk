#pragma once

#include "shared.h"

extern void (*__dsdk_PrecacheResource)(String*);

static void PrecacheResource(String* path) {
	__dsdk_PrecacheResource(path);
}

extern void (*__dsdk_PrecacheModel)(String*);

static void PrecacheModel(String* modelPath) {
	__dsdk_PrecacheModel(modelPath);
}

