using System;
using System.Numerics;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using Plugify;

// Generated from dsdk.pplugin (group: abilities)

namespace dsdk {
#pragma warning disable CS0649

	internal static unsafe partial class dsdk {

#region AddAbility
		private static delegate*<long, string, ushort, long> _AddAbility = &___AddAbility;
		private static delegate* unmanaged[Cdecl]<long, String192*, ushort, long> __AddAbility;
		private static long ___AddAbility(long pawn, string abilityName, ushort slot)
		{
			long __retVal;
			var __abilityName = NativeMethods.ConstructString(abilityName);
			try {
				__retVal = __AddAbility(pawn, &__abilityName, slot);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__abilityName);
			}
			return __retVal;
		}
#endregion AddAbility
		/// <summary>
		/// Add an ability to player pawn
		/// </summary>
		/// <param name="pawn">pawn</param>
		/// <param name="abilityName">abilityName</param>
		/// <param name="slot">slot</param>
		internal static long AddAbility(long pawn, string abilityName, ushort slot)
		{
			return _AddAbility(pawn, abilityName, slot);
		}

#region RemoveAbility
		private static delegate*<long, string, Bool8> _RemoveAbility = &___RemoveAbility;
		private static delegate* unmanaged[Cdecl]<long, String192*, Bool8> __RemoveAbility;
		private static Bool8 ___RemoveAbility(long pawn, string abilityName)
		{
			Bool8 __retVal;
			var __abilityName = NativeMethods.ConstructString(abilityName);
			try {
				__retVal = __RemoveAbility(pawn, &__abilityName);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__abilityName);
			}
			return __retVal;
		}
#endregion RemoveAbility
		/// <summary>
		/// Remove ability by name from pawn
		/// </summary>
		/// <param name="pawn">pawn</param>
		/// <param name="abilityName">abilityName</param>
		internal static Bool8 RemoveAbility(long pawn, string abilityName)
		{
			return _RemoveAbility(pawn, abilityName);
		}

#region RemoveAbilityByEntity
		private static delegate*<long, long, Bool8> _RemoveAbilityByEntity = &___RemoveAbilityByEntity;
		private static delegate* unmanaged[Cdecl]<long, long, Bool8> __RemoveAbilityByEntity;
		private static Bool8 ___RemoveAbilityByEntity(long pawn, long ability)
		{
			Bool8 __retVal = __RemoveAbilityByEntity(pawn, ability);
			return __retVal;
		}
#endregion RemoveAbilityByEntity
		/// <summary>
		/// Remove ability by entity pointer
		/// </summary>
		/// <param name="pawn">pawn</param>
		/// <param name="ability">ability</param>
		internal static Bool8 RemoveAbilityByEntity(long pawn, long ability)
		{
			return _RemoveAbilityByEntity(pawn, ability);
		}

#region FindAbilityByName
		private static delegate*<long, string, long> _FindAbilityByName = &___FindAbilityByName;
		private static delegate* unmanaged[Cdecl]<long, String192*, long> __FindAbilityByName;
		private static long ___FindAbilityByName(long abilityComponent, string abilityName)
		{
			long __retVal;
			var __abilityName = NativeMethods.ConstructString(abilityName);
			try {
				__retVal = __FindAbilityByName(abilityComponent, &__abilityName);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__abilityName);
			}
			return __retVal;
		}
#endregion FindAbilityByName
		/// <summary>
		/// Find ability in ability component
		/// </summary>
		/// <param name="abilityComponent">abilityComponent</param>
		/// <param name="abilityName">abilityName</param>
		internal static long FindAbilityByName(long abilityComponent, string abilityName)
		{
			return _FindAbilityByName(abilityComponent, abilityName);
		}

#region GetAbilityBySlot
		private static delegate*<long, short, long> _GetAbilityBySlot = &___GetAbilityBySlot;
		private static delegate* unmanaged[Cdecl]<long, short, long> __GetAbilityBySlot;
		private static long ___GetAbilityBySlot(long abilityComponent, short slot)
		{
			long __retVal = __GetAbilityBySlot(abilityComponent, slot);
			return __retVal;
		}
#endregion GetAbilityBySlot
		/// <summary>
		/// Get ability at slot index
		/// </summary>
		/// <param name="abilityComponent">abilityComponent</param>
		/// <param name="slot">slot</param>
		internal static long GetAbilityBySlot(long abilityComponent, short slot)
		{
			return _GetAbilityBySlot(abilityComponent, slot);
		}

#region ExecuteAbility
		private static delegate*<long, long, Bool8, byte, int> _ExecuteAbility = &___ExecuteAbility;
		private static delegate* unmanaged[Cdecl]<long, long, Bool8, byte, int> __ExecuteAbility;
		private static int ___ExecuteAbility(long abilityComponent, long ability, Bool8 altCast, byte flags)
		{
			int __retVal = __ExecuteAbility(abilityComponent, ability, altCast, flags);
			return __retVal;
		}
#endregion ExecuteAbility
		/// <summary>
		/// Cast/execute an ability
		/// </summary>
		/// <param name="abilityComponent">abilityComponent</param>
		/// <param name="ability">ability</param>
		/// <param name="altCast">altCast</param>
		/// <param name="flags">flags</param>
		internal static int ExecuteAbility(long abilityComponent, long ability, Bool8 altCast, byte flags)
		{
			return _ExecuteAbility(abilityComponent, ability, altCast, flags);
		}

#region ToggleActivate
		private static delegate*<long, Bool8, void> _ToggleActivate = &___ToggleActivate;
		private static delegate* unmanaged[Cdecl]<long, Bool8, void> __ToggleActivate;
		private static void ___ToggleActivate(long ability, Bool8 activate)
		{
			__ToggleActivate(ability, activate);
		}
#endregion ToggleActivate
		/// <summary>
		/// Toggle ability active status
		/// </summary>
		/// <param name="ability">ability</param>
		/// <param name="activate">activate</param>
		internal static void ToggleActivate(long ability, Bool8 activate)
		{
			_ToggleActivate(ability, activate);
		}

#region ResetAbilityCooldown
		private static delegate*<long, void> _ResetAbilityCooldown = &___ResetAbilityCooldown;
		private static delegate* unmanaged[Cdecl]<long, void> __ResetAbilityCooldown;
		private static void ___ResetAbilityCooldown(long ability)
		{
			__ResetAbilityCooldown(ability);
		}
#endregion ResetAbilityCooldown
		/// <summary>
		/// Reset ability cooldown and refill charges
		/// </summary>
		/// <param name="ability">ability</param>
		internal static void ResetAbilityCooldown(long ability)
		{
			_ResetAbilityCooldown(ability);
		}

#region GetAbilityMaxCharges
		private static delegate*<long, int> _GetAbilityMaxCharges = &___GetAbilityMaxCharges;
		private static delegate* unmanaged[Cdecl]<long, int> __GetAbilityMaxCharges;
		private static int ___GetAbilityMaxCharges(long ability)
		{
			int __retVal = __GetAbilityMaxCharges(ability);
			return __retVal;
		}
#endregion GetAbilityMaxCharges
		/// <summary>
		/// Get maximum charges of an ability
		/// </summary>
		/// <param name="ability">ability</param>
		internal static int GetAbilityMaxCharges(long ability)
		{
			return _GetAbilityMaxCharges(ability);
		}

#region SetUpgradeBits
		private static delegate*<long, int, void> _SetUpgradeBits = &___SetUpgradeBits;
		private static delegate* unmanaged[Cdecl]<long, int, void> __SetUpgradeBits;
		private static void ___SetUpgradeBits(long ability, int newBits)
		{
			__SetUpgradeBits(ability, newBits);
		}
#endregion SetUpgradeBits
		/// <summary>
		/// Set upgrade bits on ability
		/// </summary>
		/// <param name="ability">ability</param>
		/// <param name="newBits">newBits</param>
		internal static void SetUpgradeBits(long ability, int newBits)
		{
			_SetUpgradeBits(ability, newBits);
		}

	}

#pragma warning restore CS0649
}
