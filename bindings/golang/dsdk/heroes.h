#pragma once

#include "shared.h"

extern void (*__dsdk_SelectHero)(int64_t, String*);

static void SelectHero(int64_t controller, String* heroName) {
	__dsdk_SelectHero(controller, heroName);
}

extern void (*__dsdk_ResetHero)(int64_t, bool);

static void ResetHero(int64_t pawn, bool reset) {
	__dsdk_ResetHero(pawn, reset);
}

extern void (*__dsdk_PrecacheHero)(String*);

static void PrecacheHero(String* heroName) {
	__dsdk_PrecacheHero(heroName);
}

extern void (*__dsdk_ForceRespawn)(int64_t, bool);

static void ForceRespawn(int64_t pawn, bool releaseButtons) {
	__dsdk_ForceRespawn(pawn, releaseButtons);
}

extern int64_t (*__dsdk_GetHeroData)(String*);

static int64_t GetHeroData(String* heroName) {
	return __dsdk_GetHeroData(heroName);
}

extern String (*__dsdk_GetHeroName)(int64_t);

static String GetHeroName(int64_t pawn) {
	return __dsdk_GetHeroName(pawn);
}

