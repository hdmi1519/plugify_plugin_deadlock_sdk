using System;
using System.Numerics;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using Plugify;

// Generated from dsdk.pplugin (group: chat)

namespace dsdk {
#pragma warning disable CS0649

	internal static unsafe partial class dsdk {

#region PrintToChat
		private static delegate*<int, string, void> _PrintToChat = &___PrintToChat;
		private static delegate* unmanaged[Cdecl]<int, String192*, void> __PrintToChat;
		private static void ___PrintToChat(int playerSlot, string message)
		{
			var __message = NativeMethods.ConstructString(message);
			try {
				__PrintToChat(playerSlot, &__message);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__message);
			}
		}
#endregion PrintToChat
		/// <summary>
		/// Print message to client chat
		/// </summary>
		/// <param name="playerSlot">playerSlot</param>
		/// <param name="message">message</param>
		internal static void PrintToChat(int playerSlot, string message)
		{
			_PrintToChat(playerSlot, message);
		}

#region PrintToChatAll
		private static delegate*<string, void> _PrintToChatAll = &___PrintToChatAll;
		private static delegate* unmanaged[Cdecl]<String192*, void> __PrintToChatAll;
		private static void ___PrintToChatAll(string message)
		{
			var __message = NativeMethods.ConstructString(message);
			try {
				__PrintToChatAll(&__message);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__message);
			}
		}
#endregion PrintToChatAll
		/// <summary>
		/// Broadcast message to all players
		/// </summary>
		/// <param name="message">message</param>
		internal static void PrintToChatAll(string message)
		{
			_PrintToChatAll(message);
		}

#region PrintToConsole
		private static delegate*<int, string, void> _PrintToConsole = &___PrintToConsole;
		private static delegate* unmanaged[Cdecl]<int, String192*, void> __PrintToConsole;
		private static void ___PrintToConsole(int playerSlot, string message)
		{
			var __message = NativeMethods.ConstructString(message);
			try {
				__PrintToConsole(playerSlot, &__message);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__message);
			}
		}
#endregion PrintToConsole
		/// <summary>
		/// Print message to client console
		/// </summary>
		/// <param name="playerSlot">playerSlot</param>
		/// <param name="message">message</param>
		internal static void PrintToConsole(int playerSlot, string message)
		{
			_PrintToConsole(playerSlot, message);
		}

#region PrintToConsoleAll
		private static delegate*<string, void> _PrintToConsoleAll = &___PrintToConsoleAll;
		private static delegate* unmanaged[Cdecl]<String192*, void> __PrintToConsoleAll;
		private static void ___PrintToConsoleAll(string message)
		{
			var __message = NativeMethods.ConstructString(message);
			try {
				__PrintToConsoleAll(&__message);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__message);
			}
		}
#endregion PrintToConsoleAll
		/// <summary>
		/// Print message to all player consoles
		/// </summary>
		/// <param name="message">message</param>
		internal static void PrintToConsoleAll(string message)
		{
			_PrintToConsoleAll(message);
		}

#region HudAnnounce
		private static delegate*<int, string, string, float, void> _HudAnnounce = &___HudAnnounce;
		private static delegate* unmanaged[Cdecl]<int, String192*, String192*, float, void> __HudAnnounce;
		private static void ___HudAnnounce(int playerSlot, string title, string description, float duration)
		{
			var __title = NativeMethods.ConstructString(title);
			var __description = NativeMethods.ConstructString(description);
			try {
				__HudAnnounce(playerSlot, &__title, &__description, duration);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__title);
				NativeMethods.DestroyString(&__description);
			}
		}
#endregion HudAnnounce
		/// <summary>
		/// Display a HUD game announcement banner to a player
		/// </summary>
		/// <param name="playerSlot">playerSlot</param>
		/// <param name="title">title</param>
		/// <param name="description">description</param>
		/// <param name="duration">duration</param>
		internal static void HudAnnounce(int playerSlot, string title, string description, float duration)
		{
			_HudAnnounce(playerSlot, title, description, duration);
		}

#region HudAnnounceAll
		private static delegate*<string, string, float, void> _HudAnnounceAll = &___HudAnnounceAll;
		private static delegate* unmanaged[Cdecl]<String192*, String192*, float, void> __HudAnnounceAll;
		private static void ___HudAnnounceAll(string title, string description, float duration)
		{
			var __title = NativeMethods.ConstructString(title);
			var __description = NativeMethods.ConstructString(description);
			try {
				__HudAnnounceAll(&__title, &__description, duration);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__title);
				NativeMethods.DestroyString(&__description);
			}
		}
#endregion HudAnnounceAll
		/// <summary>
		/// Display a HUD game announcement banner to all players
		/// </summary>
		/// <param name="title">title</param>
		/// <param name="description">description</param>
		/// <param name="duration">duration</param>
		internal static void HudAnnounceAll(string title, string description, float duration)
		{
			_HudAnnounceAll(title, description, duration);
		}

	}

#pragma warning restore CS0649
}
