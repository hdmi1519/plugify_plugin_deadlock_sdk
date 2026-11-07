using System;
using System.Numerics;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using Plugify;

// Generated from dsdk.pplugin (group: gamestate)

namespace dsdk {
#pragma warning disable CS0649

	internal static unsafe partial class dsdk {

#region GetGameState
		private static delegate*<EGameState> _GetGameState = &___GetGameState;
		private static delegate* unmanaged[Cdecl]<EGameState> __GetGameState;
		private static EGameState ___GetGameState()
		{
			EGameState __retVal = __GetGameState();
			return __retVal;
		}
#endregion GetGameState
		/// <summary>
		/// Get current game state enum
		/// </summary>
		internal static EGameState GetGameState()
		{
			return _GetGameState();
		}

#region GetMatchTime
		private static delegate*<float> _GetMatchTime = &___GetMatchTime;
		private static delegate* unmanaged[Cdecl]<float> __GetMatchTime;
		private static float ___GetMatchTime()
		{
			float __retVal = __GetMatchTime();
			return __retVal;
		}
#endregion GetMatchTime
		/// <summary>
		/// Get current match clock in seconds
		/// </summary>
		internal static float GetMatchTime()
		{
			return _GetMatchTime();
		}

#region ChangeGameState
		private static delegate*<EGameState, void> _ChangeGameState = &___ChangeGameState;
		private static delegate* unmanaged[Cdecl]<EGameState, void> __ChangeGameState;
		private static void ___ChangeGameState(EGameState newState)
		{
			__ChangeGameState(newState);
		}
#endregion ChangeGameState
		/// <summary>
		/// Force Deadlock game state change
		/// </summary>
		/// <param name="newState">newState</param>
		internal static void ChangeGameState(EGameState newState)
		{
			_ChangeGameState(newState);
		}

#region SetWaitingForPlayersRoster
		private static delegate*<uint, uint, void> _SetWaitingForPlayersRoster = &___SetWaitingForPlayersRoster;
		private static delegate* unmanaged[Cdecl]<uint, uint, void> __SetWaitingForPlayersRoster;
		private static void ___SetWaitingForPlayersRoster(uint readyCount, uint totalCount)
		{
			__SetWaitingForPlayersRoster(readyCount, totalCount);
		}
#endregion SetWaitingForPlayersRoster
		/// <summary>
		/// Set waiting for players roster counts
		/// </summary>
		/// <param name="readyCount">readyCount</param>
		/// <param name="totalCount">totalCount</param>
		internal static void SetWaitingForPlayersRoster(uint readyCount, uint totalCount)
		{
			_SetWaitingForPlayersRoster(readyCount, totalCount);
		}

#region SetMatchStartOnAnyMap
		private static delegate*<Bool8, void> _SetMatchStartOnAnyMap = &___SetMatchStartOnAnyMap;
		private static delegate* unmanaged[Cdecl]<Bool8, void> __SetMatchStartOnAnyMap;
		private static void ___SetMatchStartOnAnyMap(Bool8 enabled)
		{
			__SetMatchStartOnAnyMap(enabled);
		}
#endregion SetMatchStartOnAnyMap
		/// <summary>
		/// Enable/disable match start sequence on custom maps
		/// </summary>
		/// <param name="enabled">enabled</param>
		internal static void SetMatchStartOnAnyMap(Bool8 enabled)
		{
			_SetMatchStartOnAnyMap(enabled);
		}

#region GetMatchStartOnAnyMap
		private static delegate*<Bool8> _GetMatchStartOnAnyMap = &___GetMatchStartOnAnyMap;
		private static delegate* unmanaged[Cdecl]<Bool8> __GetMatchStartOnAnyMap;
		private static Bool8 ___GetMatchStartOnAnyMap()
		{
			Bool8 __retVal = __GetMatchStartOnAnyMap();
			return __retVal;
		}
#endregion GetMatchStartOnAnyMap
		/// <summary>
		/// Check if match start on custom maps is enabled
		/// </summary>
		internal static Bool8 GetMatchStartOnAnyMap()
		{
			return _GetMatchStartOnAnyMap();
		}

	}

#pragma warning restore CS0649
}
