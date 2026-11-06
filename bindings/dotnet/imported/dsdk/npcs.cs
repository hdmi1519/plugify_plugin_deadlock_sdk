using System;
using System.Numerics;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using Plugify;

// Generated from dsdk.pplugin (group: npcs)

namespace dsdk {
#pragma warning disable CS0649

	internal static unsafe partial class dsdk {

#region NpcMoveTo
		private static delegate*<long, float, float, float, Bool8, float, void> _NpcMoveTo = &___NpcMoveTo;
		private static delegate* unmanaged[Cdecl]<long, float, float, float, Bool8, float, void> __NpcMoveTo;
		private static void ___NpcMoveTo(long npc, float x, float y, float z, Bool8 run, float tolerance)
		{
			__NpcMoveTo(npc, x, y, z, run, tolerance);
		}
#endregion NpcMoveTo
		/// <summary>
		/// Direct AI NPC to move to goal location
		/// </summary>
		/// <param name="npc">npc</param>
		/// <param name="x">x</param>
		/// <param name="y">y</param>
		/// <param name="z">z</param>
		/// <param name="run">run</param>
		/// <param name="tolerance">tolerance</param>
		internal static void NpcMoveTo(long npc, float x, float y, float z, Bool8 run, float tolerance)
		{
			_NpcMoveTo(npc, x, y, z, run, tolerance);
		}

#region NpcStopMoving
		private static delegate*<long, Bool8, void> _NpcStopMoving = &___NpcStopMoving;
		private static delegate* unmanaged[Cdecl]<long, Bool8, void> __NpcStopMoving;
		private static void ___NpcStopMoving(long npc, Bool8 instant)
		{
			__NpcStopMoving(npc, instant);
		}
#endregion NpcStopMoving
		/// <summary>
		/// Stop movement of AI NPC
		/// </summary>
		/// <param name="npc">npc</param>
		/// <param name="instant">instant</param>
		internal static void NpcStopMoving(long npc, Bool8 instant)
		{
			_NpcStopMoving(npc, instant);
		}

#region NpcSetEnemy
		private static delegate*<long, long, void> _NpcSetEnemy = &___NpcSetEnemy;
		private static delegate* unmanaged[Cdecl]<long, long, void> __NpcSetEnemy;
		private static void ___NpcSetEnemy(long npc, long enemy)
		{
			__NpcSetEnemy(npc, enemy);
		}
#endregion NpcSetEnemy
		/// <summary>
		/// Set target enemy entity of AI NPC
		/// </summary>
		/// <param name="npc">npc</param>
		/// <param name="enemy">enemy</param>
		internal static void NpcSetEnemy(long npc, long enemy)
		{
			_NpcSetEnemy(npc, enemy);
		}

#region NpcSetState
		private static delegate*<long, int, void> _NpcSetState = &___NpcSetState;
		private static delegate* unmanaged[Cdecl]<long, int, void> __NpcSetState;
		private static void ___NpcSetState(long npc, int state)
		{
			__NpcSetState(npc, state);
		}
#endregion NpcSetState
		/// <summary>
		/// Set NPC AI state
		/// </summary>
		/// <param name="npc">npc</param>
		/// <param name="state">state</param>
		internal static void NpcSetState(long npc, int state)
		{
			_NpcSetState(npc, state);
		}

#region NpcCreateTrooper
		private static delegate*<float, float, float, float, float, float, int, int, int, Bool8, long> _NpcCreateTrooper = &___NpcCreateTrooper;
		private static delegate* unmanaged[Cdecl]<float, float, float, float, float, float, int, int, int, Bool8, long> __NpcCreateTrooper;
		private static long ___NpcCreateTrooper(float posX, float posY, float posZ, float pitch, float yaw, float roll, int team, int type, int variant, Bool8 snapToGround)
		{
			long __retVal = __NpcCreateTrooper(posX, posY, posZ, pitch, yaw, roll, team, type, variant, snapToGround);
			return __retVal;
		}
#endregion NpcCreateTrooper
		/// <summary>
		/// Spawn lane or neutral trooper NPC
		/// </summary>
		/// <param name="posX">posX</param>
		/// <param name="posY">posY</param>
		/// <param name="posZ">posZ</param>
		/// <param name="pitch">pitch</param>
		/// <param name="yaw">yaw</param>
		/// <param name="roll">roll</param>
		/// <param name="team">team</param>
		/// <param name="type">type</param>
		/// <param name="variant">variant</param>
		/// <param name="snapToGround">snapToGround</param>
		internal static long NpcCreateTrooper(float posX, float posY, float posZ, float pitch, float yaw, float roll, int team, int type, int variant, Bool8 snapToGround)
		{
			return _NpcCreateTrooper(posX, posY, posZ, pitch, yaw, roll, team, type, variant, snapToGround);
		}

	}

#pragma warning restore CS0649
}
