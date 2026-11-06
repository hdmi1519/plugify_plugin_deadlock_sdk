using System;
using System.Numerics;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using Plugify;

// Generated from dsdk.pplugin (group: items)

namespace dsdk {
#pragma warning disable CS0649

	internal static unsafe partial class dsdk {

#region AddItem
		private static delegate*<long, string, int, long> _AddItem = &___AddItem;
		private static delegate* unmanaged[Cdecl]<long, String192*, int, long> __AddItem;
		private static long ___AddItem(long pawn, string itemName, int upgradeTier)
		{
			long __retVal;
			var __itemName = NativeMethods.ConstructString(itemName);
			try {
				__retVal = __AddItem(pawn, &__itemName, upgradeTier);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__itemName);
			}
			return __retVal;
		}
#endregion AddItem
		/// <summary>
		/// Add an item to player pawn
		/// </summary>
		/// <param name="pawn">pawn</param>
		/// <param name="itemName">itemName</param>
		/// <param name="upgradeTier">upgradeTier</param>
		internal static long AddItem(long pawn, string itemName, int upgradeTier)
		{
			return _AddItem(pawn, itemName, upgradeTier);
		}

#region SellItem
		private static delegate*<long, string, Bool8, Bool8, Bool8> _SellItem = &___SellItem;
		private static delegate* unmanaged[Cdecl]<long, String192*, Bool8, Bool8, Bool8> __SellItem;
		private static Bool8 ___SellItem(long pawn, string itemName, Bool8 fullRefund, Bool8 forceSellPrice)
		{
			Bool8 __retVal;
			var __itemName = NativeMethods.ConstructString(itemName);
			try {
				__retVal = __SellItem(pawn, &__itemName, fullRefund, forceSellPrice);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__itemName);
			}
			return __retVal;
		}
#endregion SellItem
		/// <summary>
		/// Sell an item from pawn
		/// </summary>
		/// <param name="pawn">pawn</param>
		/// <param name="itemName">itemName</param>
		/// <param name="fullRefund">fullRefund</param>
		/// <param name="forceSellPrice">forceSellPrice</param>
		internal static Bool8 SellItem(long pawn, string itemName, Bool8 fullRefund, Bool8 forceSellPrice)
		{
			return _SellItem(pawn, itemName, fullRefund, forceSellPrice);
		}

#region GetItemImbueEffects
		private static delegate*<string, int> _GetItemImbueEffects = &___GetItemImbueEffects;
		private static delegate* unmanaged[Cdecl]<String192*, int> __GetItemImbueEffects;
		private static int ___GetItemImbueEffects(string itemName)
		{
			int __retVal;
			var __itemName = NativeMethods.ConstructString(itemName);
			try {
				__retVal = __GetItemImbueEffects(&__itemName);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__itemName);
			}
			return __retVal;
		}
#endregion GetItemImbueEffects
		/// <summary>
		/// Get item imbue effect flags
		/// </summary>
		/// <param name="itemName">itemName</param>
		internal static int GetItemImbueEffects(string itemName)
		{
			return _GetItemImbueEffects(itemName);
		}

#region CanImbueAbility
		private static delegate*<long, string, Bool8> _CanImbueAbility = &___CanImbueAbility;
		private static delegate* unmanaged[Cdecl]<long, String192*, Bool8> __CanImbueAbility;
		private static Bool8 ___CanImbueAbility(long targetAbility, string itemName)
		{
			Bool8 __retVal;
			var __itemName = NativeMethods.ConstructString(itemName);
			try {
				__retVal = __CanImbueAbility(targetAbility, &__itemName);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__itemName);
			}
			return __retVal;
		}
#endregion CanImbueAbility
		/// <summary>
		/// Check if ability can receive imbue
		/// </summary>
		/// <param name="targetAbility">targetAbility</param>
		/// <param name="itemName">itemName</param>
		internal static Bool8 CanImbueAbility(long targetAbility, string itemName)
		{
			return _CanImbueAbility(targetAbility, itemName);
		}

#region ImbueAbility
		private static delegate*<long, long, Bool8> _ImbueAbility = &___ImbueAbility;
		private static delegate* unmanaged[Cdecl]<long, long, Bool8> __ImbueAbility;
		private static Bool8 ___ImbueAbility(long item, long targetAbility)
		{
			Bool8 __retVal = __ImbueAbility(item, targetAbility);
			return __retVal;
		}
#endregion ImbueAbility
		/// <summary>
		/// Imbue item onto target ability
		/// </summary>
		/// <param name="item">item</param>
		/// <param name="targetAbility">targetAbility</param>
		internal static Bool8 ImbueAbility(long item, long targetAbility)
		{
			return _ImbueAbility(item, targetAbility);
		}

	}

#pragma warning restore CS0649
}
