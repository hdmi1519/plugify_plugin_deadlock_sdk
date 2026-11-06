using System;
using System.Numerics;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using Plugify;

// Generated from dsdk.pplugin (group: commands)

namespace dsdk {
#pragma warning disable CS0649

	internal static unsafe partial class dsdk {

#region AddServerCommand
		private static delegate*<string, string, long, CommandCallback, Bool8> _AddServerCommand = &___AddServerCommand;
		private static delegate* unmanaged[Cdecl]<String192*, String192*, long, nint, Bool8> __AddServerCommand;
		private static Bool8 ___AddServerCommand(string name, string description, long flags, CommandCallback callback)
		{
			Bool8 __retVal;
			var __name = NativeMethods.ConstructString(name);
			var __description = NativeMethods.ConstructString(description);
			try {
				__retVal = __AddServerCommand(&__name, &__description, flags, Marshalling.GetFunctionPointerForDelegate(callback));
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__name);
				NativeMethods.DestroyString(&__description);
			}
			return __retVal;
		}
#endregion AddServerCommand
		/// <summary>
		/// Register a server-console-only command
		/// </summary>
		/// <param name="name">name</param>
		/// <param name="description">description</param>
		/// <param name="flags">flags</param>
		/// <param name="callback">callback</param>
		internal static Bool8 AddServerCommand(string name, string description, long flags, CommandCallback callback)
		{
			return _AddServerCommand(name, description, flags, callback);
		}

#region AddClientCommand
		private static delegate*<string, string, long, CommandCallback, Bool8> _AddClientCommand = &___AddClientCommand;
		private static delegate* unmanaged[Cdecl]<String192*, String192*, long, nint, Bool8> __AddClientCommand;
		private static Bool8 ___AddClientCommand(string name, string description, long flags, CommandCallback callback)
		{
			Bool8 __retVal;
			var __name = NativeMethods.ConstructString(name);
			var __description = NativeMethods.ConstructString(description);
			try {
				__retVal = __AddClientCommand(&__name, &__description, flags, Marshalling.GetFunctionPointerForDelegate(callback));
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__name);
				NativeMethods.DestroyString(&__description);
			}
			return __retVal;
		}
#endregion AddClientCommand
		/// <summary>
		/// Register a client-console-only command
		/// </summary>
		/// <param name="name">name</param>
		/// <param name="description">description</param>
		/// <param name="flags">flags</param>
		/// <param name="callback">callback</param>
		internal static Bool8 AddClientCommand(string name, string description, long flags, CommandCallback callback)
		{
			return _AddClientCommand(name, description, flags, callback);
		}

#region AddChatCommand
		private static delegate*<string, string, long, CommandCallback, Bool8> _AddChatCommand = &___AddChatCommand;
		private static delegate* unmanaged[Cdecl]<String192*, String192*, long, nint, Bool8> __AddChatCommand;
		private static Bool8 ___AddChatCommand(string name, string description, long flags, CommandCallback callback)
		{
			Bool8 __retVal;
			var __name = NativeMethods.ConstructString(name);
			var __description = NativeMethods.ConstructString(description);
			try {
				__retVal = __AddChatCommand(&__name, &__description, flags, Marshalling.GetFunctionPointerForDelegate(callback));
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__name);
				NativeMethods.DestroyString(&__description);
			}
			return __retVal;
		}
#endregion AddChatCommand
		/// <summary>
		/// Register a client-chat-only command
		/// </summary>
		/// <param name="name">name</param>
		/// <param name="description">description</param>
		/// <param name="flags">flags</param>
		/// <param name="callback">callback</param>
		internal static Bool8 AddChatCommand(string name, string description, long flags, CommandCallback callback)
		{
			return _AddChatCommand(name, description, flags, callback);
		}

#region AddConsoleCommand
		private static delegate*<string, string, long, CommandCallback, Bool8> _AddConsoleCommand = &___AddConsoleCommand;
		private static delegate* unmanaged[Cdecl]<String192*, String192*, long, nint, Bool8> __AddConsoleCommand;
		private static Bool8 ___AddConsoleCommand(string name, string description, long flags, CommandCallback callback)
		{
			Bool8 __retVal;
			var __name = NativeMethods.ConstructString(name);
			var __description = NativeMethods.ConstructString(description);
			try {
				__retVal = __AddConsoleCommand(&__name, &__description, flags, Marshalling.GetFunctionPointerForDelegate(callback));
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__name);
				NativeMethods.DestroyString(&__description);
			}
			return __retVal;
		}
#endregion AddConsoleCommand
		/// <summary>
		/// Register a server/chat console command
		/// </summary>
		/// <param name="name">name</param>
		/// <param name="description">description</param>
		/// <param name="flags">flags</param>
		/// <param name="callback">callback</param>
		internal static Bool8 AddConsoleCommand(string name, string description, long flags, CommandCallback callback)
		{
			return _AddConsoleCommand(name, description, flags, callback);
		}

#region RemoveCommand
		private static delegate*<string, Bool8> _RemoveCommand = &___RemoveCommand;
		private static delegate* unmanaged[Cdecl]<String192*, Bool8> __RemoveCommand;
		private static Bool8 ___RemoveCommand(string name)
		{
			Bool8 __retVal;
			var __name = NativeMethods.ConstructString(name);
			try {
				__retVal = __RemoveCommand(&__name);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__name);
			}
			return __retVal;
		}
#endregion RemoveCommand
		/// <summary>
		/// Unregister a console command
		/// </summary>
		/// <param name="name">name</param>
		internal static Bool8 RemoveCommand(string name)
		{
			return _RemoveCommand(name);
		}

#region ServerCommand
		private static delegate*<string, void> _ServerCommand = &___ServerCommand;
		private static delegate* unmanaged[Cdecl]<String192*, void> __ServerCommand;
		private static void ___ServerCommand(string command)
		{
			var __command = NativeMethods.ConstructString(command);
			try {
				__ServerCommand(&__command);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__command);
			}
		}
#endregion ServerCommand
		/// <summary>
		/// Execute a command on the server console
		/// </summary>
		/// <param name="command">command</param>
		internal static void ServerCommand(string command)
		{
			_ServerCommand(command);
		}

#region ExecuteCommandAsPlayer
		private static delegate*<int, string, Bool8> _ExecuteCommandAsPlayer = &___ExecuteCommandAsPlayer;
		private static delegate* unmanaged[Cdecl]<int, String192*, Bool8> __ExecuteCommandAsPlayer;
		private static Bool8 ___ExecuteCommandAsPlayer(int playerSlot, string command)
		{
			Bool8 __retVal;
			var __command = NativeMethods.ConstructString(command);
			try {
				__retVal = __ExecuteCommandAsPlayer(playerSlot, &__command);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__command);
			}
			return __retVal;
		}
#endregion ExecuteCommandAsPlayer
		/// <summary>
		/// Execute a command on behalf of a player
		/// </summary>
		/// <param name="playerSlot">playerSlot</param>
		/// <param name="command">command</param>
		internal static Bool8 ExecuteCommandAsPlayer(int playerSlot, string command)
		{
			return _ExecuteCommandAsPlayer(playerSlot, command);
		}

#region ClientCommand
		private static delegate*<int, string, void> _ClientCommand = &___ClientCommand;
		private static delegate* unmanaged[Cdecl]<int, String192*, void> __ClientCommand;
		private static void ___ClientCommand(int playerSlot, string command)
		{
			var __command = NativeMethods.ConstructString(command);
			try {
				__ClientCommand(playerSlot, &__command);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__command);
			}
		}
#endregion ClientCommand
		/// <summary>
		/// Execute command on client
		/// </summary>
		/// <param name="playerSlot">playerSlot</param>
		/// <param name="command">command</param>
		internal static void ClientCommand(int playerSlot, string command)
		{
			_ClientCommand(playerSlot, command);
		}

	}

#pragma warning restore CS0649
}
