module imported.dsdk.modifiers;

import plugify.internals;
public import plugify;
public import imported.dsdk.enums;
public import imported.dsdk.aliases;
public import imported.dsdk.delegates;
import std.exception : enforce;
import std.algorithm.mutation : swap;

/++
	Add modifier to entity

	Params:
		entity = 
		modifierName = 
		kv3 = 
		caster = 
		ability = 
		team = 

	Returns:
		Return value
+/
long AddModifier(long entity, string modifierName, long kv3, long caster, long ability, int team) {
	PlgS _var1 = (modifierName);

	return __dsdk_AddModifier(entity, _var1, kv3, caster, ability, team);
}
alias _AddModifier = extern (C) long function(long entity, const ref PlgS modifierName, long kv3, long caster, long ability, int team);
export __gshared _AddModifier __dsdk_AddModifier = null;

/++
	Remove modifier instance from entity

	Params:
		entity = 
		modifier = 

	Returns:
		Return value
+/
bool RemoveModifier(long entity, long modifier) {
	return __dsdk_RemoveModifier(entity, modifier);
}
alias _RemoveModifier = extern (C) bool function(long entity, long modifier);
export __gshared _RemoveModifier __dsdk_RemoveModifier = null;

