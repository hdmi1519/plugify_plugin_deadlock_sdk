using System;
using System.Numerics;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using Plugify;

// Generated from dsdk.pplugin (group: particles)

namespace dsdk {
#pragma warning disable CS0649

	internal static unsafe partial class dsdk {

#region CreateParticle
		private static delegate*<string, int, long, long> _CreateParticle = &___CreateParticle;
		private static delegate* unmanaged[Cdecl]<String192*, int, long, long> __CreateParticle;
		private static long ___CreateParticle(string particleName, int attachType, long entity)
		{
			long __retVal;
			var __particleName = NativeMethods.ConstructString(particleName);
			try {
				__retVal = __CreateParticle(&__particleName, attachType, entity);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__particleName);
			}
			return __retVal;
		}
#endregion CreateParticle
		/// <summary>
		/// Create and dispatch particle effect
		/// </summary>
		/// <param name="particleName">particleName</param>
		/// <param name="attachType">attachType</param>
		/// <param name="entity">entity</param>
		internal static long CreateParticle(string particleName, int attachType, long entity)
		{
			return _CreateParticle(particleName, attachType, entity);
		}

#region DestroyParticle
		private static delegate*<long, Bool8, void> _DestroyParticle = &___DestroyParticle;
		private static delegate* unmanaged[Cdecl]<long, Bool8, void> __DestroyParticle;
		private static void ___DestroyParticle(long particle, Bool8 destroyImmediately)
		{
			__DestroyParticle(particle, destroyImmediately);
		}
#endregion DestroyParticle
		/// <summary>
		/// Destroy active particle instance
		/// </summary>
		/// <param name="particle">particle</param>
		/// <param name="destroyImmediately">destroyImmediately</param>
		internal static void DestroyParticle(long particle, Bool8 destroyImmediately)
		{
			_DestroyParticle(particle, destroyImmediately);
		}

	}

#pragma warning restore CS0649
}
