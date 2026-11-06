using System;
using System.Numerics;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using Plugify;

// Generated from dsdk.pplugin (group: players)

namespace dsdk {
#pragma warning disable CS0649

	internal static unsafe partial class dsdk {

#region GetPlayerController
		private static delegate*<int, long> _GetPlayerController = &___GetPlayerController;
		private static delegate* unmanaged[Cdecl]<int, long> __GetPlayerController;
		private static long ___GetPlayerController(int playerSlot)
		{
			long __retVal = __GetPlayerController(playerSlot);
			return __retVal;
		}
#endregion GetPlayerController
		/// <summary>
		/// Get CBasePlayerController address for player slot
		/// </summary>
		/// <param name="playerSlot">playerSlot</param>
		internal static long GetPlayerController(int playerSlot)
		{
			return _GetPlayerController(playerSlot);
		}

#region GetPlayerPawn
		private static delegate*<int, long> _GetPlayerPawn = &___GetPlayerPawn;
		private static delegate* unmanaged[Cdecl]<int, long> __GetPlayerPawn;
		private static long ___GetPlayerPawn(int playerSlot)
		{
			long __retVal = __GetPlayerPawn(playerSlot);
			return __retVal;
		}
#endregion GetPlayerPawn
		/// <summary>
		/// Get CCitadelPlayerPawn address for player slot
		/// </summary>
		/// <param name="playerSlot">playerSlot</param>
		internal static long GetPlayerPawn(int playerSlot)
		{
			return _GetPlayerPawn(playerSlot);
		}

#region GetPlayerSlot
		private static delegate*<long, int> _GetPlayerSlot = &___GetPlayerSlot;
		private static delegate* unmanaged[Cdecl]<long, int> __GetPlayerSlot;
		private static int ___GetPlayerSlot(long controller)
		{
			int __retVal = __GetPlayerSlot(controller);
			return __retVal;
		}
#endregion GetPlayerSlot
		/// <summary>
		/// Get player slot from controller address
		/// </summary>
		/// <param name="controller">controller</param>
		internal static int GetPlayerSlot(long controller)
		{
			return _GetPlayerSlot(controller);
		}

#region GetPlayerName
		private static delegate*<int, string> _GetPlayerName = &___GetPlayerName;
		private static delegate* unmanaged[Cdecl]<int, String192> __GetPlayerName;
		private static string ___GetPlayerName(int playerSlot)
		{
			string __retVal;
			String192 __retVal_native;
			try {
				__retVal_native = __GetPlayerName(playerSlot);
				// Unmarshal - Convert native data to managed data.
				__retVal = NativeMethods.GetStringData(&__retVal_native);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__retVal_native);
			}
			return __retVal;
		}
#endregion GetPlayerName
		/// <summary>
		/// Get player display name
		/// </summary>
		/// <param name="playerSlot">playerSlot</param>
		internal static string GetPlayerName(int playerSlot)
		{
			return _GetPlayerName(playerSlot);
		}

#region GetSteamID
		private static delegate*<int, ulong> _GetSteamID = &___GetSteamID;
		private static delegate* unmanaged[Cdecl]<int, ulong> __GetSteamID;
		private static ulong ___GetSteamID(int playerSlot)
		{
			ulong __retVal = __GetSteamID(playerSlot);
			return __retVal;
		}
#endregion GetSteamID
		/// <summary>
		/// Get player 64-bit SteamID
		/// </summary>
		/// <param name="playerSlot">playerSlot</param>
		internal static ulong GetSteamID(int playerSlot)
		{
			return _GetSteamID(playerSlot);
		}

#region IsClientAuthenticated
		private static delegate*<int, Bool8> _IsClientAuthenticated = &___IsClientAuthenticated;
		private static delegate* unmanaged[Cdecl]<int, Bool8> __IsClientAuthenticated;
		private static Bool8 ___IsClientAuthenticated(int playerSlot)
		{
			Bool8 __retVal = __IsClientAuthenticated(playerSlot);
			return __retVal;
		}
#endregion IsClientAuthenticated
		/// <summary>
		/// Check if player Steam ticket is validated
		/// </summary>
		/// <param name="playerSlot">playerSlot</param>
		internal static Bool8 IsClientAuthenticated(int playerSlot)
		{
			return _IsClientAuthenticated(playerSlot);
		}

#region IsClientConnected
		private static delegate*<int, Bool8> _IsClientConnected = &___IsClientConnected;
		private static delegate* unmanaged[Cdecl]<int, Bool8> __IsClientConnected;
		private static Bool8 ___IsClientConnected(int playerSlot)
		{
			Bool8 __retVal = __IsClientConnected(playerSlot);
			return __retVal;
		}
#endregion IsClientConnected
		/// <summary>
		/// Check if client is connected
		/// </summary>
		/// <param name="playerSlot">playerSlot</param>
		internal static Bool8 IsClientConnected(int playerSlot)
		{
			return _IsClientConnected(playerSlot);
		}

#region IsFakeClient
		private static delegate*<int, Bool8> _IsFakeClient = &___IsFakeClient;
		private static delegate* unmanaged[Cdecl]<int, Bool8> __IsFakeClient;
		private static Bool8 ___IsFakeClient(int playerSlot)
		{
			Bool8 __retVal = __IsFakeClient(playerSlot);
			return __retVal;
		}
#endregion IsFakeClient
		/// <summary>
		/// Check if player is a bot/fake client
		/// </summary>
		/// <param name="playerSlot">playerSlot</param>
		internal static Bool8 IsFakeClient(int playerSlot)
		{
			return _IsFakeClient(playerSlot);
		}

#region CreateFakeClient
		private static delegate*<string, int> _CreateFakeClient = &___CreateFakeClient;
		private static delegate* unmanaged[Cdecl]<String192*, int> __CreateFakeClient;
		private static int ___CreateFakeClient(string name)
		{
			int __retVal;
			var __name = NativeMethods.ConstructString(name);
			try {
				__retVal = __CreateFakeClient(&__name);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__name);
			}
			return __retVal;
		}
#endregion CreateFakeClient
		/// <summary>
		/// Create a fake client in the match
		/// </summary>
		/// <param name="name">name</param>
		internal static int CreateFakeClient(string name)
		{
			return _CreateFakeClient(name);
		}

#region DisconnectClient
		private static delegate*<int, int, void> _DisconnectClient = &___DisconnectClient;
		private static delegate* unmanaged[Cdecl]<int, int, void> __DisconnectClient;
		private static void ___DisconnectClient(int playerSlot, int reason)
		{
			__DisconnectClient(playerSlot, reason);
		}
#endregion DisconnectClient
		/// <summary>
		/// Disconnect a client with disconnection reason code
		/// </summary>
		/// <param name="playerSlot">playerSlot</param>
		/// <param name="reason">reason</param>
		internal static void DisconnectClient(int playerSlot, int reason)
		{
			_DisconnectClient(playerSlot, reason);
		}

#region KickClient
		private static delegate*<int, string, int, void> _KickClient = &___KickClient;
		private static delegate* unmanaged[Cdecl]<int, String192*, int, void> __KickClient;
		private static void ___KickClient(int playerSlot, string reason, int code)
		{
			var __reason = NativeMethods.ConstructString(reason);
			try {
				__KickClient(playerSlot, &__reason, code);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__reason);
			}
		}
#endregion KickClient
		/// <summary>
		/// Kick client with message and code
		/// </summary>
		/// <param name="playerSlot">playerSlot</param>
		/// <param name="reason">reason</param>
		/// <param name="code">code</param>
		internal static void KickClient(int playerSlot, string reason, int code)
		{
			_KickClient(playerSlot, reason, code);
		}

#region ChangeTeam
		private static delegate*<long, int, Bool8, void> _ChangeTeam = &___ChangeTeam;
		private static delegate* unmanaged[Cdecl]<long, int, Bool8, void> __ChangeTeam;
		private static void ___ChangeTeam(long controller, int teamNum, Bool8 keepHero)
		{
			__ChangeTeam(controller, teamNum, keepHero);
		}
#endregion ChangeTeam
		/// <summary>
		/// Change team of player controller
		/// </summary>
		/// <param name="controller">controller</param>
		/// <param name="teamNum">teamNum</param>
		/// <param name="keepHero">keepHero</param>
		internal static void ChangeTeam(long controller, int teamNum, Bool8 keepHero)
		{
			_ChangeTeam(controller, teamNum, keepHero);
		}

#region GetPlayerPing
		private static delegate*<int, int> _GetPlayerPing = &___GetPlayerPing;
		private static delegate* unmanaged[Cdecl]<int, int> __GetPlayerPing;
		private static int ___GetPlayerPing(int playerSlot)
		{
			int __retVal = __GetPlayerPing(playerSlot);
			return __retVal;
		}
#endregion GetPlayerPing
		/// <summary>
		/// Get ping of player in milliseconds
		/// </summary>
		/// <param name="playerSlot">playerSlot</param>
		internal static int GetPlayerPing(int playerSlot)
		{
			return _GetPlayerPing(playerSlot);
		}

	}

#pragma warning restore CS0649
}
