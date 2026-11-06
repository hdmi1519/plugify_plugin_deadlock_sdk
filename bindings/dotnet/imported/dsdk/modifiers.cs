using System;
using System.Numerics;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using Plugify;

// Generated from dsdk.pplugin (group: modifiers)

namespace dsdk {
#pragma warning disable CS0649

	internal static unsafe partial class dsdk {

#region AddModifier
		private static delegate*<long, string, long, long, long, int, long> _AddModifier = &___AddModifier;
		private static delegate* unmanaged[Cdecl]<long, String192*, long, long, long, int, long> __AddModifier;
		private static long ___AddModifier(long entity, string modifierName, long kv3, long caster, long ability, int team)
		{
			long __retVal;
			var __modifierName = NativeMethods.ConstructString(modifierName);
			try {
				__retVal = __AddModifier(entity, &__modifierName, kv3, caster, ability, team);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__modifierName);
			}
			return __retVal;
		}
#endregion AddModifier
		/// <summary>
		/// Add modifier to entity
		/// </summary>
		/// <param name="entity">entity</param>
		/// <param name="modifierName">modifierName</param>
		/// <param name="kv3">kv3</param>
		/// <param name="caster">caster</param>
		/// <param name="ability">ability</param>
		/// <param name="team">team</param>
		internal static long AddModifier(long entity, string modifierName, long kv3, long caster, long ability, int team)
		{
			return _AddModifier(entity, modifierName, kv3, caster, ability, team);
		}

#region RemoveModifier
		private static delegate*<long, long, Bool8> _RemoveModifier = &___RemoveModifier;
		private static delegate* unmanaged[Cdecl]<long, long, Bool8> __RemoveModifier;
		private static Bool8 ___RemoveModifier(long entity, long modifier)
		{
			Bool8 __retVal = __RemoveModifier(entity, modifier);
			return __retVal;
		}
#endregion RemoveModifier
		/// <summary>
		/// Remove modifier instance from entity
		/// </summary>
		/// <param name="entity">entity</param>
		/// <param name="modifier">modifier</param>
		internal static Bool8 RemoveModifier(long entity, long modifier)
		{
			return _RemoveModifier(entity, modifier);
		}

	}

#pragma warning restore CS0649
}
