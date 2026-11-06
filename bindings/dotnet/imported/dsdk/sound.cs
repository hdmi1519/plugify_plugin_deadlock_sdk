using System;
using System.Numerics;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using Plugify;

// Generated from dsdk.pplugin (group: sound)

namespace dsdk {
#pragma warning disable CS0649

	internal static unsafe partial class dsdk {

#region EmitSound
		private static delegate*<long, string, int, float, float, void> _EmitSound = &___EmitSound;
		private static delegate* unmanaged[Cdecl]<long, String192*, int, float, float, void> __EmitSound;
		private static void ___EmitSound(long entity, string soundName, int pitch, float volume, float delay)
		{
			var __soundName = NativeMethods.ConstructString(soundName);
			try {
				__EmitSound(entity, &__soundName, pitch, volume, delay);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__soundName);
			}
		}
#endregion EmitSound
		/// <summary>
		/// Emit sound event from entity
		/// </summary>
		/// <param name="entity">entity</param>
		/// <param name="soundName">soundName</param>
		/// <param name="pitch">pitch</param>
		/// <param name="volume">volume</param>
		/// <param name="delay">delay</param>
		internal static void EmitSound(long entity, string soundName, int pitch, float volume, float delay)
		{
			_EmitSound(entity, soundName, pitch, volume, delay);
		}

#region TakeSoundEventGuid
		private static delegate*<uint> _TakeSoundEventGuid = &___TakeSoundEventGuid;
		private static delegate* unmanaged[Cdecl]<uint> __TakeSoundEventGuid;
		private static uint ___TakeSoundEventGuid()
		{
			uint __retVal = __TakeSoundEventGuid();
			return __retVal;
		}
#endregion TakeSoundEventGuid
		/// <summary>
		/// Generate unique sound event GUID
		/// </summary>
		internal static uint TakeSoundEventGuid()
		{
			return _TakeSoundEventGuid();
		}

	}

#pragma warning restore CS0649
}
