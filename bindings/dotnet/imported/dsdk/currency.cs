using System;
using System.Numerics;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using Plugify;

// Generated from dsdk.pplugin (group: currency)

namespace dsdk {
#pragma warning disable CS0649

	internal static unsafe partial class dsdk {

#region ModifyCurrency
		private static delegate*<long, ECurrencyType, int, ECurrencySource, Bool8, Bool8, Bool8, long, long, void> _ModifyCurrency = &___ModifyCurrency;
		private static delegate* unmanaged[Cdecl]<long, ECurrencyType, int, ECurrencySource, Bool8, Bool8, Bool8, long, long, void> __ModifyCurrency;
		private static void ___ModifyCurrency(long pawn, ECurrencyType currencyType, int amount, ECurrencySource source, Bool8 silent, Bool8 forceGain, Bool8 spendOnly, long sourceAbility, long sourceEntity)
		{
			__ModifyCurrency(pawn, currencyType, amount, source, silent, forceGain, spendOnly, sourceAbility, sourceEntity);
		}
#endregion ModifyCurrency
		/// <summary>
		/// Modify currency (souls/gold) for player pawn
		/// </summary>
		/// <param name="pawn">pawn</param>
		/// <param name="currencyType">currencyType</param>
		/// <param name="amount">amount</param>
		/// <param name="source">source</param>
		/// <param name="silent">silent</param>
		/// <param name="forceGain">forceGain</param>
		/// <param name="spendOnly">spendOnly</param>
		/// <param name="sourceAbility">sourceAbility</param>
		/// <param name="sourceEntity">sourceEntity</param>
		internal static void ModifyCurrency(long pawn, ECurrencyType currencyType, int amount, ECurrencySource source, Bool8 silent, Bool8 forceGain, Bool8 spendOnly, long sourceAbility, long sourceEntity)
		{
			_ModifyCurrency(pawn, currencyType, amount, source, silent, forceGain, spendOnly, sourceAbility, sourceEntity);
		}

#region GetCurrency
		private static delegate*<long, ECurrencyType, int> _GetCurrency = &___GetCurrency;
		private static delegate* unmanaged[Cdecl]<long, ECurrencyType, int> __GetCurrency;
		private static int ___GetCurrency(long pawn, ECurrencyType currencyType)
		{
			int __retVal = __GetCurrency(pawn, currencyType);
			return __retVal;
		}
#endregion GetCurrency
		/// <summary>
		/// Get current currency value of pawn
		/// </summary>
		/// <param name="pawn">pawn</param>
		/// <param name="currencyType">currencyType</param>
		internal static int GetCurrency(long pawn, ECurrencyType currencyType)
		{
			return _GetCurrency(pawn, currencyType);
		}

	}

#pragma warning restore CS0649
}
