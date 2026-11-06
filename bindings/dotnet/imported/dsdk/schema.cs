using System;
using System.Numerics;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using Plugify;

// Generated from dsdk.pplugin (group: schema)

namespace dsdk {
#pragma warning disable CS0649

	internal static unsafe partial class dsdk {

#region GetSchemaFieldOffset
		private static delegate*<string, string, int> _GetSchemaFieldOffset = &___GetSchemaFieldOffset;
		private static delegate* unmanaged[Cdecl]<String192*, String192*, int> __GetSchemaFieldOffset;
		private static int ___GetSchemaFieldOffset(string className, string fieldName)
		{
			int __retVal;
			var __className = NativeMethods.ConstructString(className);
			var __fieldName = NativeMethods.ConstructString(fieldName);
			try {
				__retVal = __GetSchemaFieldOffset(&__className, &__fieldName);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__className);
				NativeMethods.DestroyString(&__fieldName);
			}
			return __retVal;
		}
#endregion GetSchemaFieldOffset
		/// <summary>
		/// Get byte offset of class field in schema
		/// </summary>
		/// <param name="className">className</param>
		/// <param name="fieldName">fieldName</param>
		internal static int GetSchemaFieldOffset(string className, string fieldName)
		{
			return _GetSchemaFieldOffset(className, fieldName);
		}

#region NotifyStateChanged
		private static delegate*<long, int, short, int, void> _NotifyStateChanged = &___NotifyStateChanged;
		private static delegate* unmanaged[Cdecl]<long, int, short, int, void> __NotifyStateChanged;
		private static void ___NotifyStateChanged(long entity, int fieldOffset, short chainOffset, int networkStateChangedOffset)
		{
			__NotifyStateChanged(entity, fieldOffset, chainOffset, networkStateChangedOffset);
		}
#endregion NotifyStateChanged
		/// <summary>
		/// Notify network system of field modification
		/// </summary>
		/// <param name="entity">entity</param>
		/// <param name="fieldOffset">fieldOffset</param>
		/// <param name="chainOffset">chainOffset</param>
		/// <param name="networkStateChangedOffset">networkStateChangedOffset</param>
		internal static void NotifyStateChanged(long entity, int fieldOffset, short chainOffset, int networkStateChangedOffset)
		{
			_NotifyStateChanged(entity, fieldOffset, chainOffset, networkStateChangedOffset);
		}

#region SetSchemaString
		private static delegate*<long, string, string, string, void> _SetSchemaString = &___SetSchemaString;
		private static delegate* unmanaged[Cdecl]<long, String192*, String192*, String192*, void> __SetSchemaString;
		private static void ___SetSchemaString(long entity, string className, string fieldName, string value)
		{
			var __className = NativeMethods.ConstructString(className);
			var __fieldName = NativeMethods.ConstructString(fieldName);
			var __value = NativeMethods.ConstructString(value);
			try {
				__SetSchemaString(entity, &__className, &__fieldName, &__value);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__className);
				NativeMethods.DestroyString(&__fieldName);
				NativeMethods.DestroyString(&__value);
			}
		}
#endregion SetSchemaString
		/// <summary>
		/// Set string field in schema structure
		/// </summary>
		/// <param name="entity">entity</param>
		/// <param name="className">className</param>
		/// <param name="fieldName">fieldName</param>
		/// <param name="value">value</param>
		internal static void SetSchemaString(long entity, string className, string fieldName, string value)
		{
			_SetSchemaString(entity, className, fieldName, value);
		}

#region GetSchemaClassSize
		private static delegate*<string, int> _GetSchemaClassSize = &___GetSchemaClassSize;
		private static delegate* unmanaged[Cdecl]<String192*, int> __GetSchemaClassSize;
		private static int ___GetSchemaClassSize(string className)
		{
			int __retVal;
			var __className = NativeMethods.ConstructString(className);
			try {
				__retVal = __GetSchemaClassSize(&__className);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__className);
			}
			return __retVal;
		}
#endregion GetSchemaClassSize
		/// <summary>
		/// Get sizeof schema class
		/// </summary>
		/// <param name="className">className</param>
		internal static int GetSchemaClassSize(string className)
		{
			return _GetSchemaClassSize(className);
		}

	}

#pragma warning restore CS0649
}
