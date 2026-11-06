#pragma once

#include "shared.h"

extern void (*__dsdk_PrintToChat)(int32_t, String*);

static void PrintToChat(int32_t playerSlot, String* message) {
	__dsdk_PrintToChat(playerSlot, message);
}

extern void (*__dsdk_PrintToChatAll)(String*);

static void PrintToChatAll(String* message) {
	__dsdk_PrintToChatAll(message);
}

extern void (*__dsdk_PrintToConsole)(int32_t, String*);

static void PrintToConsole(int32_t playerSlot, String* message) {
	__dsdk_PrintToConsole(playerSlot, message);
}

extern void (*__dsdk_PrintToConsoleAll)(String*);

static void PrintToConsoleAll(String* message) {
	__dsdk_PrintToConsoleAll(message);
}

extern void (*__dsdk_HudAnnounce)(int32_t, String*, String*, float);

static void HudAnnounce(int32_t playerSlot, String* title, String* description, float duration) {
	__dsdk_HudAnnounce(playerSlot, title, description, duration);
}

extern void (*__dsdk_HudAnnounceAll)(String*, String*, float);

static void HudAnnounceAll(String* title, String* description, float duration) {
	__dsdk_HudAnnounceAll(title, description, duration);
}

