module imported.dsdk.commands;

import plugify.internals;
public import plugify;
public import imported.dsdk.enums;
public import imported.dsdk.aliases;
public import imported.dsdk.delegates;
import std.exception : enforce;
import std.algorithm.mutation : swap;

/++
	Register a server-console-only command

	Params:
		name = 
		description = 
		flags = 
		callback = 

	Returns:
		Return value
+/
bool AddServerCommand(string name, string description, long flags, CommandCallback callback) {
	PlgS _var0 = (name);

	PlgS _var1 = (description);

	return __dsdk_AddServerCommand(_var0, _var1, flags, callback);
}
alias _AddServerCommand = extern (C) bool function(const ref PlgS name, const ref PlgS description, long flags, CommandCallback callback);
export __gshared _AddServerCommand __dsdk_AddServerCommand = null;

/++
	Register a client-console-only command

	Params:
		name = 
		description = 
		flags = 
		callback = 

	Returns:
		Return value
+/
bool AddClientCommand(string name, string description, long flags, CommandCallback callback) {
	PlgS _var0 = (name);

	PlgS _var1 = (description);

	return __dsdk_AddClientCommand(_var0, _var1, flags, callback);
}
alias _AddClientCommand = extern (C) bool function(const ref PlgS name, const ref PlgS description, long flags, CommandCallback callback);
export __gshared _AddClientCommand __dsdk_AddClientCommand = null;

/++
	Register a client-chat-only command

	Params:
		name = 
		description = 
		flags = 
		callback = 

	Returns:
		Return value
+/
bool AddChatCommand(string name, string description, long flags, CommandCallback callback) {
	PlgS _var0 = (name);

	PlgS _var1 = (description);

	return __dsdk_AddChatCommand(_var0, _var1, flags, callback);
}
alias _AddChatCommand = extern (C) bool function(const ref PlgS name, const ref PlgS description, long flags, CommandCallback callback);
export __gshared _AddChatCommand __dsdk_AddChatCommand = null;

/++
	Register a server/chat console command

	Params:
		name = 
		description = 
		flags = 
		callback = 

	Returns:
		Return value
+/
bool AddConsoleCommand(string name, string description, long flags, CommandCallback callback) {
	PlgS _var0 = (name);

	PlgS _var1 = (description);

	return __dsdk_AddConsoleCommand(_var0, _var1, flags, callback);
}
alias _AddConsoleCommand = extern (C) bool function(const ref PlgS name, const ref PlgS description, long flags, CommandCallback callback);
export __gshared _AddConsoleCommand __dsdk_AddConsoleCommand = null;

/++
	Unregister a console command

	Params:
		name = 

	Returns:
		Return value
+/
bool RemoveCommand(string name) {
	PlgS _var0 = (name);

	return __dsdk_RemoveCommand(_var0);
}
alias _RemoveCommand = extern (C) bool function(const ref PlgS name);
export __gshared _RemoveCommand __dsdk_RemoveCommand = null;

/++
	Execute a command on the server console

	Params:
		command = 
+/
void ServerCommand(string command) {
	PlgS _var0 = (command);

	__dsdk_ServerCommand(_var0);
}
alias _ServerCommand = extern (C) void function(const ref PlgS command);
export __gshared _ServerCommand __dsdk_ServerCommand = null;

/++
	Execute a command on behalf of a player

	Params:
		playerSlot = 
		command = 

	Returns:
		Return value
+/
bool ExecuteCommandAsPlayer(int playerSlot, string command) {
	PlgS _var1 = (command);

	return __dsdk_ExecuteCommandAsPlayer(playerSlot, _var1);
}
alias _ExecuteCommandAsPlayer = extern (C) bool function(int playerSlot, const ref PlgS command);
export __gshared _ExecuteCommandAsPlayer __dsdk_ExecuteCommandAsPlayer = null;

/++
	Execute command on client

	Params:
		playerSlot = 
		command = 
+/
void ClientCommand(int playerSlot, string command) {
	PlgS _var1 = (command);

	__dsdk_ClientCommand(playerSlot, _var1);
}
alias _ClientCommand = extern (C) void function(int playerSlot, const ref PlgS command);
export __gshared _ClientCommand __dsdk_ClientCommand = null;

