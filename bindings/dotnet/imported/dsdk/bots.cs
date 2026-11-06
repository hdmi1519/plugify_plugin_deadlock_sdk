using System;
using System.Numerics;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using Plugify;

// Generated from dsdk.pplugin (group: bots)

namespace dsdk {
#pragma warning disable CS0649

	internal static unsafe partial class dsdk {

#region BotCreate
		private static delegate*<string, int, float, float, float, Bool8, long> _BotCreate = &___BotCreate;
		private static delegate* unmanaged[Cdecl]<String192*, int, float, float, float, Bool8, long> __BotCreate;
		private static long ___BotCreate(string heroName, int team, float posX, float posY, float posZ, Bool8 assignLane)
		{
			long __retVal;
			var __heroName = NativeMethods.ConstructString(heroName);
			try {
				__retVal = __BotCreate(&__heroName, team, posX, posY, posZ, assignLane);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__heroName);
			}
			return __retVal;
		}
#endregion BotCreate
		/// <summary>
		/// Spawn a bot hero into the match
		/// </summary>
		/// <param name="heroName">heroName</param>
		/// <param name="team">team</param>
		/// <param name="posX">posX</param>
		/// <param name="posY">posY</param>
		/// <param name="posZ">posZ</param>
		/// <param name="assignLane">assignLane</param>
		internal static long BotCreate(string heroName, int team, float posX, float posY, float posZ, Bool8 assignLane)
		{
			return _BotCreate(heroName, team, posX, posY, posZ, assignLane);
		}

#region BotGetBrain
		private static delegate*<long, long> _BotGetBrain = &___BotGetBrain;
		private static delegate* unmanaged[Cdecl]<long, long> __BotGetBrain;
		private static long ___BotGetBrain(long pawn)
		{
			long __retVal = __BotGetBrain(pawn);
			return __retVal;
		}
#endregion BotGetBrain
		/// <summary>
		/// Get brain entity pointer for player bot pawn
		/// </summary>
		/// <param name="pawn">pawn</param>
		internal static long BotGetBrain(long pawn)
		{
			return _BotGetBrain(pawn);
		}

#region BotGetPawn
		private static delegate*<long, long> _BotGetPawn = &___BotGetPawn;
		private static delegate* unmanaged[Cdecl]<long, long> __BotGetPawn;
		private static long ___BotGetPawn(long brain)
		{
			long __retVal = __BotGetPawn(brain);
			return __retVal;
		}
#endregion BotGetPawn
		/// <summary>
		/// Get pawn entity controlled by bot brain
		/// </summary>
		/// <param name="brain">brain</param>
		internal static long BotGetPawn(long brain)
		{
			return _BotGetPawn(brain);
		}

#region BotSetLane
		private static delegate*<long, int, Bool8> _BotSetLane = &___BotSetLane;
		private static delegate* unmanaged[Cdecl]<long, int, Bool8> __BotSetLane;
		private static Bool8 ___BotSetLane(long pawn, int lane)
		{
			Bool8 __retVal = __BotSetLane(pawn, lane);
			return __retVal;
		}
#endregion BotSetLane
		/// <summary>
		/// Assign lane index to bot
		/// </summary>
		/// <param name="pawn">pawn</param>
		/// <param name="lane">lane</param>
		internal static Bool8 BotSetLane(long pawn, int lane)
		{
			return _BotSetLane(pawn, lane);
		}

#region BotGetLane
		private static delegate*<long, int> _BotGetLane = &___BotGetLane;
		private static delegate* unmanaged[Cdecl]<long, int> __BotGetLane;
		private static int ___BotGetLane(long pawn)
		{
			int __retVal = __BotGetLane(pawn);
			return __retVal;
		}
#endregion BotGetLane
		/// <summary>
		/// Get assigned lane index of bot
		/// </summary>
		/// <param name="pawn">pawn</param>
		internal static int BotGetLane(long pawn)
		{
			return _BotGetLane(pawn);
		}

	}

#pragma warning restore CS0649
}
