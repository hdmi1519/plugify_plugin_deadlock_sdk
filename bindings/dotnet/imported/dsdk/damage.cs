using System;
using System.Numerics;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using Plugify;

// Generated from dsdk.pplugin (group: damage)

namespace dsdk {
#pragma warning disable CS0649

	internal static unsafe partial class dsdk {

#region CreateDamageInfo
		private static delegate*<long, long, long, float, int, long> _CreateDamageInfo = &___CreateDamageInfo;
		private static delegate* unmanaged[Cdecl]<long, long, long, float, int, long> __CreateDamageInfo;
		private static long ___CreateDamageInfo(long inflictor, long attacker, long ability, float damage, int damageType)
		{
			long __retVal = __CreateDamageInfo(inflictor, attacker, ability, damage, damageType);
			return __retVal;
		}
#endregion CreateDamageInfo
		/// <summary>
		/// Create CTakeDamageInfo instance
		/// </summary>
		/// <param name="inflictor">inflictor</param>
		/// <param name="attacker">attacker</param>
		/// <param name="ability">ability</param>
		/// <param name="damage">damage</param>
		/// <param name="damageType">damageType</param>
		internal static long CreateDamageInfo(long inflictor, long attacker, long ability, float damage, int damageType)
		{
			return _CreateDamageInfo(inflictor, attacker, ability, damage, damageType);
		}

#region DestroyDamageInfo
		private static delegate*<long, void> _DestroyDamageInfo = &___DestroyDamageInfo;
		private static delegate* unmanaged[Cdecl]<long, void> __DestroyDamageInfo;
		private static void ___DestroyDamageInfo(long info)
		{
			__DestroyDamageInfo(info);
		}
#endregion DestroyDamageInfo
		/// <summary>
		/// Free CTakeDamageInfo instance
		/// </summary>
		/// <param name="info">info</param>
		internal static void DestroyDamageInfo(long info)
		{
			_DestroyDamageInfo(info);
		}

#region TakeDamage
		private static delegate*<long, long, void> _TakeDamage = &___TakeDamage;
		private static delegate* unmanaged[Cdecl]<long, long, void> __TakeDamage;
		private static void ___TakeDamage(long victim, long info)
		{
			__TakeDamage(victim, info);
		}
#endregion TakeDamage
		/// <summary>
		/// Inflict damage on victim entity
		/// </summary>
		/// <param name="victim">victim</param>
		/// <param name="info">info</param>
		internal static void TakeDamage(long victim, long info)
		{
			_TakeDamage(victim, info);
		}

#region ApplyDamage
		private static delegate*<long, long, void> _ApplyDamage = &___ApplyDamage;
		private static delegate* unmanaged[Cdecl]<long, long, void> __ApplyDamage;
		private static void ___ApplyDamage(long victim, long info)
		{
			__ApplyDamage(victim, info);
		}
#endregion ApplyDamage
		/// <summary>
		/// Apply damage bypassing damage filters
		/// </summary>
		/// <param name="victim">victim</param>
		/// <param name="info">info</param>
		internal static void ApplyDamage(long victim, long info)
		{
			_ApplyDamage(victim, info);
		}

#region GetMaxHealth
		private static delegate*<long, int> _GetMaxHealth = &___GetMaxHealth;
		private static delegate* unmanaged[Cdecl]<long, int> __GetMaxHealth;
		private static int ___GetMaxHealth(long entity)
		{
			int __retVal = __GetMaxHealth(entity);
			return __retVal;
		}
#endregion GetMaxHealth
		/// <summary>
		/// Get maximum health of entity
		/// </summary>
		/// <param name="entity">entity</param>
		internal static int GetMaxHealth(long entity)
		{
			return _GetMaxHealth(entity);
		}

#region Heal
		private static delegate*<long, float, int> _Heal = &___Heal;
		private static delegate* unmanaged[Cdecl]<long, float, int> __Heal;
		private static int ___Heal(long entity, float amount)
		{
			int __retVal = __Heal(entity, amount);
			return __retVal;
		}
#endregion Heal
		/// <summary>
		/// Heal entity by amount
		/// </summary>
		/// <param name="entity">entity</param>
		/// <param name="amount">amount</param>
		internal static int Heal(long entity, float amount)
		{
			return _Heal(entity, amount);
		}

	}

#pragma warning restore CS0649
}
