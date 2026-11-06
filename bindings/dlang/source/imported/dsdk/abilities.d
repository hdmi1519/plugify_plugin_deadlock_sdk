module imported.dsdk.abilities;

import plugify.internals;
public import plugify;
public import imported.dsdk.enums;
public import imported.dsdk.aliases;
public import imported.dsdk.delegates;
import std.exception : enforce;
import std.algorithm.mutation : swap;

/++
	Add an ability to player pawn

	Params:
		pawn = 
		abilityName = 
		slot = 

	Returns:
		Return value
+/
long AddAbility(long pawn, string abilityName, ushort slot) {
	PlgS _var1 = (abilityName);

	return __dsdk_AddAbility(pawn, _var1, slot);
}
alias _AddAbility = extern (C) long function(long pawn, const ref PlgS abilityName, ushort slot);
export __gshared _AddAbility __dsdk_AddAbility = null;

/++
	Remove ability by name from pawn

	Params:
		pawn = 
		abilityName = 

	Returns:
		Return value
+/
bool RemoveAbility(long pawn, string abilityName) {
	PlgS _var1 = (abilityName);

	return __dsdk_RemoveAbility(pawn, _var1);
}
alias _RemoveAbility = extern (C) bool function(long pawn, const ref PlgS abilityName);
export __gshared _RemoveAbility __dsdk_RemoveAbility = null;

/++
	Remove ability by entity pointer

	Params:
		pawn = 
		ability = 

	Returns:
		Return value
+/
bool RemoveAbilityByEntity(long pawn, long ability) {
	return __dsdk_RemoveAbilityByEntity(pawn, ability);
}
alias _RemoveAbilityByEntity = extern (C) bool function(long pawn, long ability);
export __gshared _RemoveAbilityByEntity __dsdk_RemoveAbilityByEntity = null;

/++
	Find ability in ability component

	Params:
		abilityComponent = 
		abilityName = 

	Returns:
		Return value
+/
long FindAbilityByName(long abilityComponent, string abilityName) {
	PlgS _var1 = (abilityName);

	return __dsdk_FindAbilityByName(abilityComponent, _var1);
}
alias _FindAbilityByName = extern (C) long function(long abilityComponent, const ref PlgS abilityName);
export __gshared _FindAbilityByName __dsdk_FindAbilityByName = null;

/++
	Get ability at slot index

	Params:
		abilityComponent = 
		slot = 

	Returns:
		Return value
+/
long GetAbilityBySlot(long abilityComponent, short slot) {
	return __dsdk_GetAbilityBySlot(abilityComponent, slot);
}
alias _GetAbilityBySlot = extern (C) long function(long abilityComponent, short slot);
export __gshared _GetAbilityBySlot __dsdk_GetAbilityBySlot = null;

/++
	Cast/execute an ability

	Params:
		abilityComponent = 
		ability = 
		altCast = 
		flags = 

	Returns:
		Return value
+/
int ExecuteAbility(long abilityComponent, long ability, bool altCast, ubyte flags) {
	return __dsdk_ExecuteAbility(abilityComponent, ability, altCast, flags);
}
alias _ExecuteAbility = extern (C) int function(long abilityComponent, long ability, bool altCast, ubyte flags);
export __gshared _ExecuteAbility __dsdk_ExecuteAbility = null;

/++
	Toggle ability active status

	Params:
		ability = 
		activate = 
+/
void ToggleActivate(long ability, bool activate) {
	__dsdk_ToggleActivate(ability, activate);
}
alias _ToggleActivate = extern (C) void function(long ability, bool activate);
export __gshared _ToggleActivate __dsdk_ToggleActivate = null;

/++
	Reset ability cooldown and refill charges

	Params:
		ability = 
+/
void ResetAbilityCooldown(long ability) {
	__dsdk_ResetAbilityCooldown(ability);
}
alias _ResetAbilityCooldown = extern (C) void function(long ability);
export __gshared _ResetAbilityCooldown __dsdk_ResetAbilityCooldown = null;

/++
	Get maximum charges of an ability

	Params:
		ability = 

	Returns:
		Return value
+/
int GetAbilityMaxCharges(long ability) {
	return __dsdk_GetAbilityMaxCharges(ability);
}
alias _GetAbilityMaxCharges = extern (C) int function(long ability);
export __gshared _GetAbilityMaxCharges __dsdk_GetAbilityMaxCharges = null;

/++
	Set upgrade bits on ability

	Params:
		ability = 
		newBits = 
+/
void SetUpgradeBits(long ability, int newBits) {
	__dsdk_SetUpgradeBits(ability, newBits);
}
alias _SetUpgradeBits = extern (C) void function(long ability, int newBits);
export __gshared _SetUpgradeBits __dsdk_SetUpgradeBits = null;

