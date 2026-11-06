using System;
using System.Numerics;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using Plugify;

// Generated from dsdk.pplugin (group: server)

namespace dsdk {
#pragma warning disable CS0649

	internal static unsafe partial class dsdk {

#region GetMapName
		private static delegate*<string> _GetMapName = &___GetMapName;
		private static delegate* unmanaged[Cdecl]<String192> __GetMapName;
		private static string ___GetMapName()
		{
			string __retVal;
			String192 __retVal_native;
			try {
				__retVal_native = __GetMapName();
				// Unmarshal - Convert native data to managed data.
				__retVal = NativeMethods.GetStringData(&__retVal_native);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__retVal_native);
			}
			return __retVal;
		}
#endregion GetMapName
		/// <summary>
		/// Get currently loaded map name
		/// </summary>
		internal static string GetMapName()
		{
			return _GetMapName();
		}

#region IsMapValid
		private static delegate*<string, Bool8> _IsMapValid = &___IsMapValid;
		private static delegate* unmanaged[Cdecl]<String192*, Bool8> __IsMapValid;
		private static Bool8 ___IsMapValid(string map)
		{
			Bool8 __retVal;
			var __map = NativeMethods.ConstructString(map);
			try {
				__retVal = __IsMapValid(&__map);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__map);
			}
			return __retVal;
		}
#endregion IsMapValid
		/// <summary>
		/// Check if map exists and can be loaded
		/// </summary>
		/// <param name="map">map</param>
		internal static Bool8 IsMapValid(string map)
		{
			return _IsMapValid(map);
		}

#region SetServerKeyValue
		private static delegate*<string, string, Bool8> _SetServerKeyValue = &___SetServerKeyValue;
		private static delegate* unmanaged[Cdecl]<String192*, String192*, Bool8> __SetServerKeyValue;
		private static Bool8 ___SetServerKeyValue(string key, string value)
		{
			Bool8 __retVal;
			var __key = NativeMethods.ConstructString(key);
			var __value = NativeMethods.ConstructString(value);
			try {
				__retVal = __SetServerKeyValue(&__key, &__value);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__key);
				NativeMethods.DestroyString(&__value);
			}
			return __retVal;
		}
#endregion SetServerKeyValue
		/// <summary>
		/// Set Steam A2S rule key-value
		/// </summary>
		/// <param name="key">key</param>
		/// <param name="value">value</param>
		internal static Bool8 SetServerKeyValue(string key, string value)
		{
			return _SetServerKeyValue(key, value);
		}

#region ClearServerKeyValues
		private static delegate*<Bool8> _ClearServerKeyValues = &___ClearServerKeyValues;
		private static delegate* unmanaged[Cdecl]<Bool8> __ClearServerKeyValues;
		private static Bool8 ___ClearServerKeyValues()
		{
			Bool8 __retVal = __ClearServerKeyValues();
			return __retVal;
		}
#endregion ClearServerKeyValues
		/// <summary>
		/// Clear Steam A2S rules
		/// </summary>
		internal static Bool8 ClearServerKeyValues()
		{
			return _ClearServerKeyValues();
		}

#region SetServerAddons
		private static delegate*<string, void> _SetServerAddons = &___SetServerAddons;
		private static delegate* unmanaged[Cdecl]<String192*, void> __SetServerAddons;
		private static void ___SetServerAddons(string addons)
		{
			var __addons = NativeMethods.ConstructString(addons);
			try {
				__SetServerAddons(&__addons);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__addons);
			}
		}
#endregion SetServerAddons
		/// <summary>
		/// Set active server workshop addons
		/// </summary>
		/// <param name="addons">addons</param>
		internal static void SetServerAddons(string addons)
		{
			_SetServerAddons(addons);
		}

#region AddFileSystemSearchPath
		private static delegate*<string, string, int, Bool8> _AddFileSystemSearchPath = &___AddFileSystemSearchPath;
		private static delegate* unmanaged[Cdecl]<String192*, String192*, int, Bool8> __AddFileSystemSearchPath;
		private static Bool8 ___AddFileSystemSearchPath(string path, string pathId, int addType)
		{
			Bool8 __retVal;
			var __path = NativeMethods.ConstructString(path);
			var __pathId = NativeMethods.ConstructString(pathId);
			try {
				__retVal = __AddFileSystemSearchPath(&__path, &__pathId, addType);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__path);
				NativeMethods.DestroyString(&__pathId);
			}
			return __retVal;
		}
#endregion AddFileSystemSearchPath
		/// <summary>
		/// Add file search path
		/// </summary>
		/// <param name="path">path</param>
		/// <param name="pathId">pathId</param>
		/// <param name="addType">addType</param>
		internal static Bool8 AddFileSystemSearchPath(string path, string pathId, int addType)
		{
			return _AddFileSystemSearchPath(path, pathId, addType);
		}

#region HasCommandLineParm
		private static delegate*<string, Bool8> _HasCommandLineParm = &___HasCommandLineParm;
		private static delegate* unmanaged[Cdecl]<String192*, Bool8> __HasCommandLineParm;
		private static Bool8 ___HasCommandLineParm(string parm)
		{
			Bool8 __retVal;
			var __parm = NativeMethods.ConstructString(parm);
			try {
				__retVal = __HasCommandLineParm(&__parm);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__parm);
			}
			return __retVal;
		}
#endregion HasCommandLineParm
		/// <summary>
		/// Check if command line argument exists
		/// </summary>
		/// <param name="parm">parm</param>
		internal static Bool8 HasCommandLineParm(string parm)
		{
			return _HasCommandLineParm(parm);
		}

#region SetConnectRejectReason
		private static delegate*<string, void> _SetConnectRejectReason = &___SetConnectRejectReason;
		private static delegate* unmanaged[Cdecl]<String192*, void> __SetConnectRejectReason;
		private static void ___SetConnectRejectReason(string reason)
		{
			var __reason = NativeMethods.ConstructString(reason);
			try {
				__SetConnectRejectReason(&__reason);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__reason);
			}
		}
#endregion SetConnectRejectReason
		/// <summary>
		/// Set reject reason for connection rejection
		/// </summary>
		/// <param name="reason">reason</param>
		internal static void SetConnectRejectReason(string reason)
		{
			_SetConnectRejectReason(reason);
		}

#region GetGlobalVars
		private static delegate*<long> _GetGlobalVars = &___GetGlobalVars;
		private static delegate* unmanaged[Cdecl]<long> __GetGlobalVars;
		private static long ___GetGlobalVars()
		{
			long __retVal = __GetGlobalVars();
			return __retVal;
		}
#endregion GetGlobalVars
		/// <summary>
		/// Get CGlobalVars pointer
		/// </summary>
		internal static long GetGlobalVars()
		{
			return _GetGlobalVars();
		}

#region GetGameTime
		private static delegate*<float> _GetGameTime = &___GetGameTime;
		private static delegate* unmanaged[Cdecl]<float> __GetGameTime;
		private static float ___GetGameTime()
		{
			float __retVal = __GetGameTime();
			return __retVal;
		}
#endregion GetGameTime
		/// <summary>
		/// Get current engine game time in seconds
		/// </summary>
		internal static float GetGameTime()
		{
			return _GetGameTime();
		}

#region GetGameTickCount
		private static delegate*<int> _GetGameTickCount = &___GetGameTickCount;
		private static delegate* unmanaged[Cdecl]<int> __GetGameTickCount;
		private static int ___GetGameTickCount()
		{
			int __retVal = __GetGameTickCount();
			return __retVal;
		}
#endregion GetGameTickCount
		/// <summary>
		/// Get current engine tick count
		/// </summary>
		internal static int GetGameTickCount()
		{
			return _GetGameTickCount();
		}

	}

#pragma warning restore CS0649
}
