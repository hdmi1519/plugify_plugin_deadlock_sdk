module imported.dsdk.currency;

import plugify.internals;
public import plugify;
public import imported.dsdk.enums;
public import imported.dsdk.aliases;
public import imported.dsdk.delegates;
import std.exception : enforce;
import std.algorithm.mutation : swap;

/++
	Modify currency (souls/gold) for player pawn

	Params:
		pawn = 
		currencyType = 
		amount = 
		source = 
		silent = 
		forceGain = 
		spendOnly = 
		sourceAbility = 
		sourceEntity = 
+/
void ModifyCurrency(long pawn, ECurrencyType currencyType, int amount, ECurrencySource source, bool silent, bool forceGain, bool spendOnly, long sourceAbility, long sourceEntity) {
	__dsdk_ModifyCurrency(pawn, currencyType, amount, source, silent, forceGain, spendOnly, sourceAbility, sourceEntity);
}
alias _ModifyCurrency = extern (C) void function(long pawn, ECurrencyType currencyType, int amount, ECurrencySource source, bool silent, bool forceGain, bool spendOnly, long sourceAbility, long sourceEntity);
export __gshared _ModifyCurrency __dsdk_ModifyCurrency = null;

/++
	Get current currency value of pawn

	Params:
		pawn = 
		currencyType = 

	Returns:
		Return value
+/
int GetCurrency(long pawn, ECurrencyType currencyType) {
	return __dsdk_GetCurrency(pawn, currencyType);
}
alias _GetCurrency = extern (C) int function(long pawn, ECurrencyType currencyType);
export __gshared _GetCurrency __dsdk_GetCurrency = null;

