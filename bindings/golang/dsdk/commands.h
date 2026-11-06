#pragma once

#include "shared.h"

extern bool (*__dsdk_AddServerCommand)(String*, String*, int64_t, void*);

static bool AddServerCommand(String* name, String* description, int64_t flags, void* callback) {
	return __dsdk_AddServerCommand(name, description, flags, callback);
}

extern bool (*__dsdk_AddClientCommand)(String*, String*, int64_t, void*);

static bool AddClientCommand(String* name, String* description, int64_t flags, void* callback) {
	return __dsdk_AddClientCommand(name, description, flags, callback);
}

extern bool (*__dsdk_AddChatCommand)(String*, String*, int64_t, void*);

static bool AddChatCommand(String* name, String* description, int64_t flags, void* callback) {
	return __dsdk_AddChatCommand(name, description, flags, callback);
}

extern bool (*__dsdk_AddConsoleCommand)(String*, String*, int64_t, void*);

static bool AddConsoleCommand(String* name, String* description, int64_t flags, void* callback) {
	return __dsdk_AddConsoleCommand(name, description, flags, callback);
}

extern bool (*__dsdk_RemoveCommand)(String*);

static bool RemoveCommand(String* name) {
	return __dsdk_RemoveCommand(name);
}

extern void (*__dsdk_ServerCommand)(String*);

static void ServerCommand(String* command) {
	__dsdk_ServerCommand(command);
}

extern bool (*__dsdk_ExecuteCommandAsPlayer)(int32_t, String*);

static bool ExecuteCommandAsPlayer(int32_t playerSlot, String* command) {
	return __dsdk_ExecuteCommandAsPlayer(playerSlot, command);
}

extern void (*__dsdk_ClientCommand)(int32_t, String*);

static void ClientCommand(int32_t playerSlot, String* command) {
	__dsdk_ClientCommand(playerSlot, command);
}

