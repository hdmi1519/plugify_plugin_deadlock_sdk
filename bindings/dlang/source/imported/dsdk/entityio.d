module imported.dsdk.entityio;

import plugify.internals;
public import plugify;
public import imported.dsdk.enums;
public import imported.dsdk.aliases;
public import imported.dsdk.delegates;
import std.exception : enforce;
import std.algorithm.mutation : swap;

/++
	Fire input on target entity

	Params:
		entity = 
		inputName = 
		activator = 
		caller = 
		value = 
+/
void AcceptInput(long entity, string inputName, long activator, long caller, string value) {
	PlgS _var1 = (inputName);

	PlgS _var4 = (value);

	__dsdk_AcceptInput(entity, _var1, activator, caller, _var4);
}
alias _AcceptInput = extern (C) void function(long entity, const ref PlgS inputName, long activator, long caller, const ref PlgS value);
export __gshared _AcceptInput __dsdk_AcceptInput = null;

