module imported.dsdk.items;

import plugify.internals;
public import plugify;
public import imported.dsdk.enums;
public import imported.dsdk.aliases;
public import imported.dsdk.delegates;
import std.exception : enforce;
import std.algorithm.mutation : swap;

/++
	Add an item to player pawn

	Params:
		pawn = 
		itemName = 
		upgradeTier = 

	Returns:
		Return value
+/
long AddItem(long pawn, string itemName, int upgradeTier) {
	PlgS _var1 = (itemName);

	return __dsdk_AddItem(pawn, _var1, upgradeTier);
}
alias _AddItem = extern (C) long function(long pawn, const ref PlgS itemName, int upgradeTier);
export __gshared _AddItem __dsdk_AddItem = null;

/++
	Sell an item from pawn

	Params:
		pawn = 
		itemName = 
		fullRefund = 
		forceSellPrice = 

	Returns:
		Return value
+/
bool SellItem(long pawn, string itemName, bool fullRefund, bool forceSellPrice) {
	PlgS _var1 = (itemName);

	return __dsdk_SellItem(pawn, _var1, fullRefund, forceSellPrice);
}
alias _SellItem = extern (C) bool function(long pawn, const ref PlgS itemName, bool fullRefund, bool forceSellPrice);
export __gshared _SellItem __dsdk_SellItem = null;

/++
	Get item imbue effect flags

	Params:
		itemName = 

	Returns:
		Return value
+/
int GetItemImbueEffects(string itemName) {
	PlgS _var0 = (itemName);

	return __dsdk_GetItemImbueEffects(_var0);
}
alias _GetItemImbueEffects = extern (C) int function(const ref PlgS itemName);
export __gshared _GetItemImbueEffects __dsdk_GetItemImbueEffects = null;

/++
	Check if ability can receive imbue

	Params:
		targetAbility = 
		itemName = 

	Returns:
		Return value
+/
bool CanImbueAbility(long targetAbility, string itemName) {
	PlgS _var1 = (itemName);

	return __dsdk_CanImbueAbility(targetAbility, _var1);
}
alias _CanImbueAbility = extern (C) bool function(long targetAbility, const ref PlgS itemName);
export __gshared _CanImbueAbility __dsdk_CanImbueAbility = null;

/++
	Imbue item onto target ability

	Params:
		item = 
		targetAbility = 

	Returns:
		Return value
+/
bool ImbueAbility(long item, long targetAbility) {
	return __dsdk_ImbueAbility(item, targetAbility);
}
alias _ImbueAbility = extern (C) bool function(long item, long targetAbility);
export __gshared _ImbueAbility __dsdk_ImbueAbility = null;

