module imported.dsdk.damage;

import plugify.internals;
public import plugify;
public import imported.dsdk.enums;
public import imported.dsdk.aliases;
public import imported.dsdk.delegates;
import std.exception : enforce;
import std.algorithm.mutation : swap;

/++
	Create CTakeDamageInfo instance

	Params:
		inflictor = 
		attacker = 
		ability = 
		damage = 
		damageType = 

	Returns:
		Return value
+/
long CreateDamageInfo(long inflictor, long attacker, long ability, float damage, int damageType) {
	return __dsdk_CreateDamageInfo(inflictor, attacker, ability, damage, damageType);
}
alias _CreateDamageInfo = extern (C) long function(long inflictor, long attacker, long ability, float damage, int damageType);
export __gshared _CreateDamageInfo __dsdk_CreateDamageInfo = null;

/++
	Free CTakeDamageInfo instance

	Params:
		info = 
+/
void DestroyDamageInfo(long info) {
	__dsdk_DestroyDamageInfo(info);
}
alias _DestroyDamageInfo = extern (C) void function(long info);
export __gshared _DestroyDamageInfo __dsdk_DestroyDamageInfo = null;

/++
	Inflict damage on victim entity

	Params:
		victim = 
		info = 
+/
void TakeDamage(long victim, long info) {
	__dsdk_TakeDamage(victim, info);
}
alias _TakeDamage = extern (C) void function(long victim, long info);
export __gshared _TakeDamage __dsdk_TakeDamage = null;

/++
	Apply damage bypassing damage filters

	Params:
		victim = 
		info = 
+/
void ApplyDamage(long victim, long info) {
	__dsdk_ApplyDamage(victim, info);
}
alias _ApplyDamage = extern (C) void function(long victim, long info);
export __gshared _ApplyDamage __dsdk_ApplyDamage = null;

/++
	Get maximum health of entity

	Params:
		entity = 

	Returns:
		Return value
+/
int GetMaxHealth(long entity) {
	return __dsdk_GetMaxHealth(entity);
}
alias _GetMaxHealth = extern (C) int function(long entity);
export __gshared _GetMaxHealth __dsdk_GetMaxHealth = null;

/++
	Heal entity by amount

	Params:
		entity = 
		amount = 

	Returns:
		Return value
+/
int Heal(long entity, float amount) {
	return __dsdk_Heal(entity, amount);
}
alias _Heal = extern (C) int function(long entity, float amount);
export __gshared _Heal __dsdk_Heal = null;

