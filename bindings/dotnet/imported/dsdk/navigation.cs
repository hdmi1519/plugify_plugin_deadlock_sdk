using System;
using System.Numerics;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using Plugify;

// Generated from dsdk.pplugin (group: navigation)

namespace dsdk {
#pragma warning disable CS0649

	internal static unsafe partial class dsdk {

#region NavGetNearestPoint
		private static delegate*<float, float, float, float, int, Bool8> _NavGetNearestPoint = &___NavGetNearestPoint;
		private static delegate* unmanaged[Cdecl]<float, float, float, float, int, Bool8> __NavGetNearestPoint;
		private static Bool8 ___NavGetNearestPoint(float x, float y, float z, float maxDistance, int hull)
		{
			Bool8 __retVal = __NavGetNearestPoint(x, y, z, maxDistance, hull);
			return __retVal;
		}
#endregion NavGetNearestPoint
		/// <summary>
		/// Find nearest point on navmesh
		/// </summary>
		/// <param name="x">x</param>
		/// <param name="y">y</param>
		/// <param name="z">z</param>
		/// <param name="maxDistance">maxDistance</param>
		/// <param name="hull">hull</param>
		internal static Bool8 NavGetNearestPoint(float x, float y, float z, float maxDistance, int hull)
		{
			return _NavGetNearestPoint(x, y, z, maxDistance, hull);
		}

#region NavGetGroundHeight
		private static delegate*<float, float, float, float, int, float> _NavGetGroundHeight = &___NavGetGroundHeight;
		private static delegate* unmanaged[Cdecl]<float, float, float, float, int, float> __NavGetGroundHeight;
		private static float ___NavGetGroundHeight(float x, float y, float z, float maxDistance, int hull)
		{
			float __retVal = __NavGetGroundHeight(x, y, z, maxDistance, hull);
			return __retVal;
		}
#endregion NavGetGroundHeight
		/// <summary>
		/// Get ground elevation from navmesh
		/// </summary>
		/// <param name="x">x</param>
		/// <param name="y">y</param>
		/// <param name="z">z</param>
		/// <param name="maxDistance">maxDistance</param>
		/// <param name="hull">hull</param>
		internal static float NavGetGroundHeight(float x, float y, float z, float maxDistance, int hull)
		{
			return _NavGetGroundHeight(x, y, z, maxDistance, hull);
		}

	}

#pragma warning restore CS0649
}
