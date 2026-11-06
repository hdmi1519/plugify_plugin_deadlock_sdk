#pragma once

#include "shared.h"

extern int64_t (*__dsdk_BotCreate)(String*, int32_t, float, float, float, bool);

static int64_t BotCreate(String* heroName, int32_t team, float posX, float posY, float posZ, bool assignLane) {
	return __dsdk_BotCreate(heroName, team, posX, posY, posZ, assignLane);
}

extern int64_t (*__dsdk_BotGetBrain)(int64_t);

static int64_t BotGetBrain(int64_t pawn) {
	return __dsdk_BotGetBrain(pawn);
}

extern int64_t (*__dsdk_BotGetPawn)(int64_t);

static int64_t BotGetPawn(int64_t brain) {
	return __dsdk_BotGetPawn(brain);
}

extern bool (*__dsdk_BotSetLane)(int64_t, int32_t);

static bool BotSetLane(int64_t pawn, int32_t lane) {
	return __dsdk_BotSetLane(pawn, lane);
}

extern int32_t (*__dsdk_BotGetLane)(int64_t);

static int32_t BotGetLane(int64_t pawn) {
	return __dsdk_BotGetLane(pawn);
}

