using System;
using System.Numerics;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using Plugify;

// Generated from dsdk.pplugin (group: convars)

namespace dsdk {
#pragma warning disable CS0649

	internal static unsafe partial class dsdk {

#region FindConVar
		private static delegate*<string, ulong> _FindConVar = &___FindConVar;
		private static delegate* unmanaged[Cdecl]<String192*, ulong> __FindConVar;
		private static ulong ___FindConVar(string name)
		{
			ulong __retVal;
			var __name = NativeMethods.ConstructString(name);
			try {
				__retVal = __FindConVar(&__name);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__name);
			}
			return __retVal;
		}
#endregion FindConVar
		/// <summary>
		/// Find ConVar by name
		/// </summary>
		/// <param name="name">name</param>
		internal static ulong FindConVar(string name)
		{
			return _FindConVar(name);
		}

#region CreateConVar
		private static delegate*<string, string, string, ulong, ulong> _CreateConVar = &___CreateConVar;
		private static delegate* unmanaged[Cdecl]<String192*, String192*, String192*, ulong, ulong> __CreateConVar;
		private static ulong ___CreateConVar(string name, string defaultValue, string description, ulong flags)
		{
			ulong __retVal;
			var __name = NativeMethods.ConstructString(name);
			var __defaultValue = NativeMethods.ConstructString(defaultValue);
			var __description = NativeMethods.ConstructString(description);
			try {
				__retVal = __CreateConVar(&__name, &__defaultValue, &__description, flags);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__name);
				NativeMethods.DestroyString(&__defaultValue);
				NativeMethods.DestroyString(&__description);
			}
			return __retVal;
		}
#endregion CreateConVar
		/// <summary>
		/// Create custom ConVar
		/// </summary>
		/// <param name="name">name</param>
		/// <param name="defaultValue">defaultValue</param>
		/// <param name="description">description</param>
		/// <param name="flags">flags</param>
		internal static ulong CreateConVar(string name, string defaultValue, string description, ulong flags)
		{
			return _CreateConVar(name, defaultValue, description, flags);
		}

#region GetConVarInt
		private static delegate*<ulong, int> _GetConVarInt = &___GetConVarInt;
		private static delegate* unmanaged[Cdecl]<ulong, int> __GetConVarInt;
		private static int ___GetConVarInt(ulong handle)
		{
			int __retVal = __GetConVarInt(handle);
			return __retVal;
		}
#endregion GetConVarInt
		/// <summary>
		/// Get ConVar integer value
		/// </summary>
		/// <param name="handle">handle</param>
		internal static int GetConVarInt(ulong handle)
		{
			return _GetConVarInt(handle);
		}

#region GetConVarFloat
		private static delegate*<ulong, float> _GetConVarFloat = &___GetConVarFloat;
		private static delegate* unmanaged[Cdecl]<ulong, float> __GetConVarFloat;
		private static float ___GetConVarFloat(ulong handle)
		{
			float __retVal = __GetConVarFloat(handle);
			return __retVal;
		}
#endregion GetConVarFloat
		/// <summary>
		/// Get ConVar float value
		/// </summary>
		/// <param name="handle">handle</param>
		internal static float GetConVarFloat(ulong handle)
		{
			return _GetConVarFloat(handle);
		}

#region GetConVarString
		private static delegate*<ulong, string> _GetConVarString = &___GetConVarString;
		private static delegate* unmanaged[Cdecl]<ulong, String192> __GetConVarString;
		private static string ___GetConVarString(ulong handle)
		{
			string __retVal;
			String192 __retVal_native;
			try {
				__retVal_native = __GetConVarString(handle);
				// Unmarshal - Convert native data to managed data.
				__retVal = NativeMethods.GetStringData(&__retVal_native);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__retVal_native);
			}
			return __retVal;
		}
#endregion GetConVarString
		/// <summary>
		/// Get ConVar string value
		/// </summary>
		/// <param name="handle">handle</param>
		internal static string GetConVarString(ulong handle)
		{
			return _GetConVarString(handle);
		}

#region GetConVarBool
		private static delegate*<ulong, Bool8> _GetConVarBool = &___GetConVarBool;
		private static delegate* unmanaged[Cdecl]<ulong, Bool8> __GetConVarBool;
		private static Bool8 ___GetConVarBool(ulong handle)
		{
			Bool8 __retVal = __GetConVarBool(handle);
			return __retVal;
		}
#endregion GetConVarBool
		/// <summary>
		/// Get ConVar bool value
		/// </summary>
		/// <param name="handle">handle</param>
		internal static Bool8 GetConVarBool(ulong handle)
		{
			return _GetConVarBool(handle);
		}

#region SetConVarInt
		private static delegate*<ulong, int, void> _SetConVarInt = &___SetConVarInt;
		private static delegate* unmanaged[Cdecl]<ulong, int, void> __SetConVarInt;
		private static void ___SetConVarInt(ulong handle, int value)
		{
			__SetConVarInt(handle, value);
		}
#endregion SetConVarInt
		/// <summary>
		/// Set ConVar int value
		/// </summary>
		/// <param name="handle">handle</param>
		/// <param name="value">value</param>
		internal static void SetConVarInt(ulong handle, int value)
		{
			_SetConVarInt(handle, value);
		}

#region SetConVarFloat
		private static delegate*<ulong, float, void> _SetConVarFloat = &___SetConVarFloat;
		private static delegate* unmanaged[Cdecl]<ulong, float, void> __SetConVarFloat;
		private static void ___SetConVarFloat(ulong handle, float value)
		{
			__SetConVarFloat(handle, value);
		}
#endregion SetConVarFloat
		/// <summary>
		/// Set ConVar float value
		/// </summary>
		/// <param name="handle">handle</param>
		/// <param name="value">value</param>
		internal static void SetConVarFloat(ulong handle, float value)
		{
			_SetConVarFloat(handle, value);
		}

#region SetConVarString
		private static delegate*<ulong, string, Bool8> _SetConVarString = &___SetConVarString;
		private static delegate* unmanaged[Cdecl]<ulong, String192*, Bool8> __SetConVarString;
		private static Bool8 ___SetConVarString(ulong handle, string value)
		{
			Bool8 __retVal;
			var __value = NativeMethods.ConstructString(value);
			try {
				__retVal = __SetConVarString(handle, &__value);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__value);
			}
			return __retVal;
		}
#endregion SetConVarString
		/// <summary>
		/// Set ConVar string value
		/// </summary>
		/// <param name="handle">handle</param>
		/// <param name="value">value</param>
		internal static Bool8 SetConVarString(ulong handle, string value)
		{
			return _SetConVarString(handle, value);
		}

	}

#pragma warning restore CS0649
}
