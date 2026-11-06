using System;
using System.Numerics;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using Plugify;

// Generated from dsdk.pplugin (group: configuration)

namespace dsdk {
#pragma warning disable CS0649

	internal static unsafe partial class dsdk {

#region GetConfigString
		private static delegate*<string, string, string> _GetConfigString = &___GetConfigString;
		private static delegate* unmanaged[Cdecl]<String192*, String192*, String192> __GetConfigString;
		private static string ___GetConfigString(string key, string defaultValue)
		{
			string __retVal;
			String192 __retVal_native;
			var __key = NativeMethods.ConstructString(key);
			var __defaultValue = NativeMethods.ConstructString(defaultValue);
			try {
				__retVal_native = __GetConfigString(&__key, &__defaultValue);
				// Unmarshal - Convert native data to managed data.
				__retVal = NativeMethods.GetStringData(&__retVal_native);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__retVal_native);
				NativeMethods.DestroyString(&__key);
				NativeMethods.DestroyString(&__defaultValue);
			}
			return __retVal;
		}
#endregion GetConfigString
		/// <summary>
		/// Read string from settings.jsonc
		/// </summary>
		/// <param name="key">key</param>
		/// <param name="defaultValue">defaultValue</param>
		internal static string GetConfigString(string key, string defaultValue)
		{
			return _GetConfigString(key, defaultValue);
		}

#region GetConfigInt
		private static delegate*<string, int, int> _GetConfigInt = &___GetConfigInt;
		private static delegate* unmanaged[Cdecl]<String192*, int, int> __GetConfigInt;
		private static int ___GetConfigInt(string key, int defaultValue)
		{
			int __retVal;
			var __key = NativeMethods.ConstructString(key);
			try {
				__retVal = __GetConfigInt(&__key, defaultValue);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__key);
			}
			return __retVal;
		}
#endregion GetConfigInt
		/// <summary>
		/// Read int from settings.jsonc
		/// </summary>
		/// <param name="key">key</param>
		/// <param name="defaultValue">defaultValue</param>
		internal static int GetConfigInt(string key, int defaultValue)
		{
			return _GetConfigInt(key, defaultValue);
		}

#region GetConfigBool
		private static delegate*<string, Bool8, Bool8> _GetConfigBool = &___GetConfigBool;
		private static delegate* unmanaged[Cdecl]<String192*, Bool8, Bool8> __GetConfigBool;
		private static Bool8 ___GetConfigBool(string key, Bool8 defaultValue)
		{
			Bool8 __retVal;
			var __key = NativeMethods.ConstructString(key);
			try {
				__retVal = __GetConfigBool(&__key, defaultValue);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__key);
			}
			return __retVal;
		}
#endregion GetConfigBool
		/// <summary>
		/// Read bool from settings.jsonc
		/// </summary>
		/// <param name="key">key</param>
		/// <param name="defaultValue">defaultValue</param>
		internal static Bool8 GetConfigBool(string key, Bool8 defaultValue)
		{
			return _GetConfigBool(key, defaultValue);
		}

#region GetConfigFloat
		private static delegate*<string, float, float> _GetConfigFloat = &___GetConfigFloat;
		private static delegate* unmanaged[Cdecl]<String192*, float, float> __GetConfigFloat;
		private static float ___GetConfigFloat(string key, float defaultValue)
		{
			float __retVal;
			var __key = NativeMethods.ConstructString(key);
			try {
				__retVal = __GetConfigFloat(&__key, defaultValue);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__key);
			}
			return __retVal;
		}
#endregion GetConfigFloat
		/// <summary>
		/// Read float from settings.jsonc
		/// </summary>
		/// <param name="key">key</param>
		/// <param name="defaultValue">defaultValue</param>
		internal static float GetConfigFloat(string key, float defaultValue)
		{
			return _GetConfigFloat(key, defaultValue);
		}

	}

#pragma warning restore CS0649
}
