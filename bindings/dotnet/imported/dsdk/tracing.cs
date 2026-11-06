using System;
using System.Numerics;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using Plugify;

// Generated from dsdk.pplugin (group: tracing)

namespace dsdk {
#pragma warning disable CS0649

	internal static unsafe partial class dsdk {

#region LineTrace
		private static delegate*<float, float, float, float, float, float, uint, long, Bool8> _LineTrace = &___LineTrace;
		private static delegate* unmanaged[Cdecl]<float, float, float, float, float, float, uint, long, Bool8> __LineTrace;
		private static Bool8 ___LineTrace(float startX, float startY, float startZ, float endX, float endY, float endZ, uint mask, long ignoreEntity)
		{
			Bool8 __retVal = __LineTrace(startX, startY, startZ, endX, endY, endZ, mask, ignoreEntity);
			return __retVal;
		}
#endregion LineTrace
		/// <summary>
		/// Perform physics raycast trace between start and end vectors
		/// </summary>
		/// <param name="startX">startX</param>
		/// <param name="startY">startY</param>
		/// <param name="startZ">startZ</param>
		/// <param name="endX">endX</param>
		/// <param name="endY">endY</param>
		/// <param name="endZ">endZ</param>
		/// <param name="mask">mask</param>
		/// <param name="ignoreEntity">ignoreEntity</param>
		internal static Bool8 LineTrace(float startX, float startY, float startZ, float endX, float endY, float endZ, uint mask, long ignoreEntity)
		{
			return _LineTrace(startX, startY, startZ, endX, endY, endZ, mask, ignoreEntity);
		}

	}

#pragma warning restore CS0649
}
