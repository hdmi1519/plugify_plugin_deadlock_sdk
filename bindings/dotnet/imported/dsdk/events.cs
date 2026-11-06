using System;
using System.Numerics;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using Plugify;

// Generated from dsdk.pplugin (group: events)

namespace dsdk {
#pragma warning disable CS0649

	internal static unsafe partial class dsdk {

#region RegisterGameEvent
		private static delegate*<string, void> _RegisterGameEvent = &___RegisterGameEvent;
		private static delegate* unmanaged[Cdecl]<String192*, void> __RegisterGameEvent;
		private static void ___RegisterGameEvent(string name)
		{
			var __name = NativeMethods.ConstructString(name);
			try {
				__RegisterGameEvent(&__name);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__name);
			}
		}
#endregion RegisterGameEvent
		/// <summary>
		/// Register game event listener for engine event
		/// </summary>
		/// <param name="name">name</param>
		internal static void RegisterGameEvent(string name)
		{
			_RegisterGameEvent(name);
		}

#region CreateGameEvent
		private static delegate*<string, Bool8, long> _CreateGameEvent = &___CreateGameEvent;
		private static delegate* unmanaged[Cdecl]<String192*, Bool8, long> __CreateGameEvent;
		private static long ___CreateGameEvent(string name, Bool8 force)
		{
			long __retVal;
			var __name = NativeMethods.ConstructString(name);
			try {
				__retVal = __CreateGameEvent(&__name, force);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__name);
			}
			return __retVal;
		}
#endregion CreateGameEvent
		/// <summary>
		/// Create a new game event
		/// </summary>
		/// <param name="name">name</param>
		/// <param name="force">force</param>
		internal static long CreateGameEvent(string name, Bool8 force)
		{
			return _CreateGameEvent(name, force);
		}

#region FireGameEvent
		private static delegate*<long, Bool8, Bool8> _FireGameEvent = &___FireGameEvent;
		private static delegate* unmanaged[Cdecl]<long, Bool8, Bool8> __FireGameEvent;
		private static Bool8 ___FireGameEvent(long event_, Bool8 dontBroadcast)
		{
			Bool8 __retVal = __FireGameEvent(event_, dontBroadcast);
			return __retVal;
		}
#endregion FireGameEvent
		/// <summary>
		/// Fire game event
		/// </summary>
		/// <param name="event_">event_</param>
		/// <param name="dontBroadcast">dontBroadcast</param>
		internal static Bool8 FireGameEvent(long event_, Bool8 dontBroadcast)
		{
			return _FireGameEvent(event_, dontBroadcast);
		}

#region FreeGameEvent
		private static delegate*<long, void> _FreeGameEvent = &___FreeGameEvent;
		private static delegate* unmanaged[Cdecl]<long, void> __FreeGameEvent;
		private static void ___FreeGameEvent(long event_)
		{
			__FreeGameEvent(event_);
		}
#endregion FreeGameEvent
		/// <summary>
		/// Free game event object
		/// </summary>
		/// <param name="event_">event_</param>
		internal static void FreeGameEvent(long event_)
		{
			_FreeGameEvent(event_);
		}

#region GameEventGetBool
		private static delegate*<long, string, Bool8, Bool8> _GameEventGetBool = &___GameEventGetBool;
		private static delegate* unmanaged[Cdecl]<long, String192*, Bool8, Bool8> __GameEventGetBool;
		private static Bool8 ___GameEventGetBool(long event_, string key, Bool8 def)
		{
			Bool8 __retVal;
			var __key = NativeMethods.ConstructString(key);
			try {
				__retVal = __GameEventGetBool(event_, &__key, def);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__key);
			}
			return __retVal;
		}
#endregion GameEventGetBool
		/// <summary>
		/// Get boolean key from game event
		/// </summary>
		/// <param name="event_">event_</param>
		/// <param name="key">key</param>
		/// <param name="def">def</param>
		internal static Bool8 GameEventGetBool(long event_, string key, Bool8 def)
		{
			return _GameEventGetBool(event_, key, def);
		}

#region GameEventGetInt
		private static delegate*<long, string, int, int> _GameEventGetInt = &___GameEventGetInt;
		private static delegate* unmanaged[Cdecl]<long, String192*, int, int> __GameEventGetInt;
		private static int ___GameEventGetInt(long event_, string key, int def)
		{
			int __retVal;
			var __key = NativeMethods.ConstructString(key);
			try {
				__retVal = __GameEventGetInt(event_, &__key, def);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__key);
			}
			return __retVal;
		}
#endregion GameEventGetInt
		/// <summary>
		/// Get int32 key from game event
		/// </summary>
		/// <param name="event_">event_</param>
		/// <param name="key">key</param>
		/// <param name="def">def</param>
		internal static int GameEventGetInt(long event_, string key, int def)
		{
			return _GameEventGetInt(event_, key, def);
		}

#region GameEventGetFloat
		private static delegate*<long, string, float, float> _GameEventGetFloat = &___GameEventGetFloat;
		private static delegate* unmanaged[Cdecl]<long, String192*, float, float> __GameEventGetFloat;
		private static float ___GameEventGetFloat(long event_, string key, float def)
		{
			float __retVal;
			var __key = NativeMethods.ConstructString(key);
			try {
				__retVal = __GameEventGetFloat(event_, &__key, def);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__key);
			}
			return __retVal;
		}
#endregion GameEventGetFloat
		/// <summary>
		/// Get float key from game event
		/// </summary>
		/// <param name="event_">event_</param>
		/// <param name="key">key</param>
		/// <param name="def">def</param>
		internal static float GameEventGetFloat(long event_, string key, float def)
		{
			return _GameEventGetFloat(event_, key, def);
		}

#region GameEventGetString
		private static delegate*<long, string, string, string> _GameEventGetString = &___GameEventGetString;
		private static delegate* unmanaged[Cdecl]<long, String192*, String192*, String192> __GameEventGetString;
		private static string ___GameEventGetString(long event_, string key, string def)
		{
			string __retVal;
			String192 __retVal_native;
			var __key = NativeMethods.ConstructString(key);
			var __def = NativeMethods.ConstructString(def);
			try {
				__retVal_native = __GameEventGetString(event_, &__key, &__def);
				// Unmarshal - Convert native data to managed data.
				__retVal = NativeMethods.GetStringData(&__retVal_native);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__retVal_native);
				NativeMethods.DestroyString(&__key);
				NativeMethods.DestroyString(&__def);
			}
			return __retVal;
		}
#endregion GameEventGetString
		/// <summary>
		/// Get string key from game event
		/// </summary>
		/// <param name="event_">event_</param>
		/// <param name="key">key</param>
		/// <param name="def">def</param>
		internal static string GameEventGetString(long event_, string key, string def)
		{
			return _GameEventGetString(event_, key, def);
		}

#region GameEventGetUint64
		private static delegate*<long, string, ulong, ulong> _GameEventGetUint64 = &___GameEventGetUint64;
		private static delegate* unmanaged[Cdecl]<long, String192*, ulong, ulong> __GameEventGetUint64;
		private static ulong ___GameEventGetUint64(long event_, string key, ulong def)
		{
			ulong __retVal;
			var __key = NativeMethods.ConstructString(key);
			try {
				__retVal = __GameEventGetUint64(event_, &__key, def);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__key);
			}
			return __retVal;
		}
#endregion GameEventGetUint64
		/// <summary>
		/// Get uint64 key from game event
		/// </summary>
		/// <param name="event_">event_</param>
		/// <param name="key">key</param>
		/// <param name="def">def</param>
		internal static ulong GameEventGetUint64(long event_, string key, ulong def)
		{
			return _GameEventGetUint64(event_, key, def);
		}

#region GameEventSetBool
		private static delegate*<long, string, Bool8, void> _GameEventSetBool = &___GameEventSetBool;
		private static delegate* unmanaged[Cdecl]<long, String192*, Bool8, void> __GameEventSetBool;
		private static void ___GameEventSetBool(long event_, string key, Bool8 val)
		{
			var __key = NativeMethods.ConstructString(key);
			try {
				__GameEventSetBool(event_, &__key, val);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__key);
			}
		}
#endregion GameEventSetBool
		/// <summary>
		/// Set boolean key in game event
		/// </summary>
		/// <param name="event_">event_</param>
		/// <param name="key">key</param>
		/// <param name="val">val</param>
		internal static void GameEventSetBool(long event_, string key, Bool8 val)
		{
			_GameEventSetBool(event_, key, val);
		}

#region GameEventSetInt
		private static delegate*<long, string, int, void> _GameEventSetInt = &___GameEventSetInt;
		private static delegate* unmanaged[Cdecl]<long, String192*, int, void> __GameEventSetInt;
		private static void ___GameEventSetInt(long event_, string key, int val)
		{
			var __key = NativeMethods.ConstructString(key);
			try {
				__GameEventSetInt(event_, &__key, val);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__key);
			}
		}
#endregion GameEventSetInt
		/// <summary>
		/// Set int32 key in game event
		/// </summary>
		/// <param name="event_">event_</param>
		/// <param name="key">key</param>
		/// <param name="val">val</param>
		internal static void GameEventSetInt(long event_, string key, int val)
		{
			_GameEventSetInt(event_, key, val);
		}

#region GameEventSetFloat
		private static delegate*<long, string, float, void> _GameEventSetFloat = &___GameEventSetFloat;
		private static delegate* unmanaged[Cdecl]<long, String192*, float, void> __GameEventSetFloat;
		private static void ___GameEventSetFloat(long event_, string key, float val)
		{
			var __key = NativeMethods.ConstructString(key);
			try {
				__GameEventSetFloat(event_, &__key, val);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__key);
			}
		}
#endregion GameEventSetFloat
		/// <summary>
		/// Set float key in game event
		/// </summary>
		/// <param name="event_">event_</param>
		/// <param name="key">key</param>
		/// <param name="val">val</param>
		internal static void GameEventSetFloat(long event_, string key, float val)
		{
			_GameEventSetFloat(event_, key, val);
		}

#region GameEventSetString
		private static delegate*<long, string, string, void> _GameEventSetString = &___GameEventSetString;
		private static delegate* unmanaged[Cdecl]<long, String192*, String192*, void> __GameEventSetString;
		private static void ___GameEventSetString(long event_, string key, string val)
		{
			var __key = NativeMethods.ConstructString(key);
			var __val = NativeMethods.ConstructString(val);
			try {
				__GameEventSetString(event_, &__key, &__val);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__key);
				NativeMethods.DestroyString(&__val);
			}
		}
#endregion GameEventSetString
		/// <summary>
		/// Set string key in game event
		/// </summary>
		/// <param name="event_">event_</param>
		/// <param name="key">key</param>
		/// <param name="val">val</param>
		internal static void GameEventSetString(long event_, string key, string val)
		{
			_GameEventSetString(event_, key, val);
		}

#region GameEventGetPlayerSlot
		private static delegate*<long, string, int> _GameEventGetPlayerSlot = &___GameEventGetPlayerSlot;
		private static delegate* unmanaged[Cdecl]<long, String192*, int> __GameEventGetPlayerSlot;
		private static int ___GameEventGetPlayerSlot(long event_, string key)
		{
			int __retVal;
			var __key = NativeMethods.ConstructString(key);
			try {
				__retVal = __GameEventGetPlayerSlot(event_, &__key);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__key);
			}
			return __retVal;
		}
#endregion GameEventGetPlayerSlot
		/// <summary>
		/// Gets player slot from an event key (e.g. userid)
		/// </summary>
		/// <param name="event_">event_</param>
		/// <param name="key">key</param>
		internal static int GameEventGetPlayerSlot(long event_, string key)
		{
			return _GameEventGetPlayerSlot(event_, key);
		}

#region GameEventGetPlayerPawn
		private static delegate*<long, string, long> _GameEventGetPlayerPawn = &___GameEventGetPlayerPawn;
		private static delegate* unmanaged[Cdecl]<long, String192*, long> __GameEventGetPlayerPawn;
		private static long ___GameEventGetPlayerPawn(long event_, string key)
		{
			long __retVal;
			var __key = NativeMethods.ConstructString(key);
			try {
				__retVal = __GameEventGetPlayerPawn(event_, &__key);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__key);
			}
			return __retVal;
		}
#endregion GameEventGetPlayerPawn
		/// <summary>
		/// Gets player pawn pointer from an event key (e.g. userid)
		/// </summary>
		/// <param name="event_">event_</param>
		/// <param name="key">key</param>
		internal static long GameEventGetPlayerPawn(long event_, string key)
		{
			return _GameEventGetPlayerPawn(event_, key);
		}

#region GameEventGetPlayerController
		private static delegate*<long, string, long> _GameEventGetPlayerController = &___GameEventGetPlayerController;
		private static delegate* unmanaged[Cdecl]<long, String192*, long> __GameEventGetPlayerController;
		private static long ___GameEventGetPlayerController(long event_, string key)
		{
			long __retVal;
			var __key = NativeMethods.ConstructString(key);
			try {
				__retVal = __GameEventGetPlayerController(event_, &__key);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__key);
			}
			return __retVal;
		}
#endregion GameEventGetPlayerController
		/// <summary>
		/// Gets player controller pointer from an event key (e.g. userid)
		/// </summary>
		/// <param name="event_">event_</param>
		/// <param name="key">key</param>
		internal static long GameEventGetPlayerController(long event_, string key)
		{
			return _GameEventGetPlayerController(event_, key);
		}

	}

#pragma warning restore CS0649
}
