using System;
using System.Numerics;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using Plugify;

// Generated from dsdk.pplugin (group: zones)

namespace dsdk {
#pragma warning disable CS0649

	internal static unsafe partial class dsdk {

#region CreateBeam
		private static delegate*<float, float, float, float, float, float, float, byte, byte, byte, byte, long> _CreateBeam = &___CreateBeam;
		private static delegate* unmanaged[Cdecl]<float, float, float, float, float, float, float, byte, byte, byte, byte, long> __CreateBeam;
		private static long ___CreateBeam(float startX, float startY, float startZ, float endX, float endY, float endZ, float width, byte r, byte g, byte b, byte a)
		{
			long __retVal = __CreateBeam(startX, startY, startZ, endX, endY, endZ, width, r, g, b, a);
			return __retVal;
		}
#endregion CreateBeam
		/// <summary>
		/// Spawn a glowing laser beam entity between two world points
		/// </summary>
		/// <param name="startX">startX</param>
		/// <param name="startY">startY</param>
		/// <param name="startZ">startZ</param>
		/// <param name="endX">endX</param>
		/// <param name="endY">endY</param>
		/// <param name="endZ">endZ</param>
		/// <param name="width">width</param>
		/// <param name="r">r</param>
		/// <param name="g">g</param>
		/// <param name="b">b</param>
		/// <param name="a">a</param>
		internal static long CreateBeam(float startX, float startY, float startZ, float endX, float endY, float endZ, float width, byte r, byte g, byte b, byte a)
		{
			return _CreateBeam(startX, startY, startZ, endX, endY, endZ, width, r, g, b, a);
		}

#region CreateZone
		private static delegate*<string, float, float, float, float, float, float, long> _CreateZone = &___CreateZone;
		private static delegate* unmanaged[Cdecl]<String192*, float, float, float, float, float, float, long> __CreateZone;
		private static long ___CreateZone(string name, float minX, float minY, float minZ, float maxX, float maxY, float maxZ)
		{
			long __retVal;
			var __name = NativeMethods.ConstructString(name);
			try {
				__retVal = __CreateZone(&__name, minX, minY, minZ, maxX, maxY, maxZ);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__name);
			}
			return __retVal;
		}
#endregion CreateZone
		/// <summary>
		/// Create a spatial trigger volume box
		/// </summary>
		/// <param name="name">name</param>
		/// <param name="minX">minX</param>
		/// <param name="minY">minY</param>
		/// <param name="minZ">minZ</param>
		/// <param name="maxX">maxX</param>
		/// <param name="maxY">maxY</param>
		/// <param name="maxZ">maxZ</param>
		internal static long CreateZone(string name, float minX, float minY, float minZ, float maxX, float maxY, float maxZ)
		{
			return _CreateZone(name, minX, minY, minZ, maxX, maxY, maxZ);
		}

#region DestroyZone
		private static delegate*<long, void> _DestroyZone = &___DestroyZone;
		private static delegate* unmanaged[Cdecl]<long, void> __DestroyZone;
		private static void ___DestroyZone(long zoneId)
		{
			__DestroyZone(zoneId);
		}
#endregion DestroyZone
		/// <summary>
		/// Destroy a spatial zone trigger
		/// </summary>
		/// <param name="zoneId">zoneId</param>
		internal static void DestroyZone(long zoneId)
		{
			_DestroyZone(zoneId);
		}

	}

#pragma warning restore CS0649
}
