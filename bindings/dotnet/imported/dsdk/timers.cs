using System;
using System.Numerics;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using Plugify;

// Generated from dsdk.pplugin (group: timers)

namespace dsdk {
#pragma warning disable CS0649

	internal static unsafe partial class dsdk {

#region CreateTimer
		private static delegate*<float, TimerCallback, Bool8, long> _CreateTimer = &___CreateTimer;
		private static delegate* unmanaged[Cdecl]<float, nint, Bool8, long> __CreateTimer;
		private static long ___CreateTimer(float interval, TimerCallback callback, Bool8 repeating)
		{
			long __retVal = __CreateTimer(interval, Marshalling.GetFunctionPointerForDelegate(callback), repeating);
			return __retVal;
		}
#endregion CreateTimer
		/// <summary>
		/// Create a one-shot or repeating timer
		/// </summary>
		/// <param name="interval">interval</param>
		/// <param name="callback">callback</param>
		/// <param name="repeating">repeating</param>
		internal static long CreateTimer(float interval, TimerCallback callback, Bool8 repeating)
		{
			return _CreateTimer(interval, callback, repeating);
		}

#region KillTimer
		private static delegate*<long, Bool8> _KillTimer = &___KillTimer;
		private static delegate* unmanaged[Cdecl]<long, Bool8> __KillTimer;
		private static Bool8 ___KillTimer(long timerId)
		{
			Bool8 __retVal = __KillTimer(timerId);
			return __retVal;
		}
#endregion KillTimer
		/// <summary>
		/// Stop and delete an active timer
		/// </summary>
		/// <param name="timerId">timerId</param>
		internal static Bool8 KillTimer(long timerId)
		{
			return _KillTimer(timerId);
		}

	}

#pragma warning restore CS0649
}
