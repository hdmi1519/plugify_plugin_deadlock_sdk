using System;
using System.Numerics;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using Plugify;

// Generated from dsdk.pplugin (group: heroes)

namespace dsdk {
#pragma warning disable CS0649

	internal static unsafe partial class dsdk {

#region SelectHero
		private static delegate*<long, string, void> _SelectHero = &___SelectHero;
		private static delegate* unmanaged[Cdecl]<long, String192*, void> __SelectHero;
		private static void ___SelectHero(long controller, string heroName)
		{
			var __heroName = NativeMethods.ConstructString(heroName);
			try {
				__SelectHero(controller, &__heroName);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__heroName);
			}
		}
#endregion SelectHero
		/// <summary>
		/// Select a hero for controller
		/// </summary>
		/// <param name="controller">controller</param>
		/// <param name="heroName">heroName</param>
		internal static void SelectHero(long controller, string heroName)
		{
			_SelectHero(controller, heroName);
		}

#region ResetHero
		private static delegate*<long, Bool8, void> _ResetHero = &___ResetHero;
		private static delegate* unmanaged[Cdecl]<long, Bool8, void> __ResetHero;
		private static void ___ResetHero(long pawn, Bool8 reset)
		{
			__ResetHero(pawn, reset);
		}
#endregion ResetHero
		/// <summary>
		/// Reset hero state on pawn
		/// </summary>
		/// <param name="pawn">pawn</param>
		/// <param name="reset">reset</param>
		internal static void ResetHero(long pawn, Bool8 reset)
		{
			_ResetHero(pawn, reset);
		}

#region PrecacheHero
		private static delegate*<string, void> _PrecacheHero = &___PrecacheHero;
		private static delegate* unmanaged[Cdecl]<String192*, void> __PrecacheHero;
		private static void ___PrecacheHero(string heroName)
		{
			var __heroName = NativeMethods.ConstructString(heroName);
			try {
				__PrecacheHero(&__heroName);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__heroName);
			}
		}
#endregion PrecacheHero
		/// <summary>
		/// Precache hero assets
		/// </summary>
		/// <param name="heroName">heroName</param>
		internal static void PrecacheHero(string heroName)
		{
			_PrecacheHero(heroName);
		}

#region ForceRespawn
		private static delegate*<long, Bool8, void> _ForceRespawn = &___ForceRespawn;
		private static delegate* unmanaged[Cdecl]<long, Bool8, void> __ForceRespawn;
		private static void ___ForceRespawn(long pawn, Bool8 releaseButtons)
		{
			__ForceRespawn(pawn, releaseButtons);
		}
#endregion ForceRespawn
		/// <summary>
		/// Force immediate hero pawn respawn
		/// </summary>
		/// <param name="pawn">pawn</param>
		/// <param name="releaseButtons">releaseButtons</param>
		internal static void ForceRespawn(long pawn, Bool8 releaseButtons)
		{
			_ForceRespawn(pawn, releaseButtons);
		}

#region GetHeroData
		private static delegate*<string, long> _GetHeroData = &___GetHeroData;
		private static delegate* unmanaged[Cdecl]<String192*, long> __GetHeroData;
		private static long ___GetHeroData(string heroName)
		{
			long __retVal;
			var __heroName = NativeMethods.ConstructString(heroName);
			try {
				__retVal = __GetHeroData(&__heroName);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__heroName);
			}
			return __retVal;
		}
#endregion GetHeroData
		/// <summary>
		/// Lookup hero definition pointer
		/// </summary>
		/// <param name="heroName">heroName</param>
		internal static long GetHeroData(string heroName)
		{
			return _GetHeroData(heroName);
		}

#region GetHeroName
		private static delegate*<long, string> _GetHeroName = &___GetHeroName;
		private static delegate* unmanaged[Cdecl]<long, String192> __GetHeroName;
		private static string ___GetHeroName(long pawn)
		{
			string __retVal;
			String192 __retVal_native;
			try {
				__retVal_native = __GetHeroName(pawn);
				// Unmarshal - Convert native data to managed data.
				__retVal = NativeMethods.GetStringData(&__retVal_native);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__retVal_native);
			}
			return __retVal;
		}
#endregion GetHeroName
		/// <summary>
		/// Get name of hero for pawn
		/// </summary>
		/// <param name="pawn">pawn</param>
		internal static string GetHeroName(long pawn)
		{
			return _GetHeroName(pawn);
		}

	}

#pragma warning restore CS0649
}
