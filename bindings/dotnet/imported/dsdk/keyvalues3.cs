using System;
using System.Numerics;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using Plugify;

// Generated from dsdk.pplugin (group: keyvalues3)

namespace dsdk {
#pragma warning disable CS0649

	internal static unsafe partial class dsdk {

#region KV3Create
		private static delegate*<long> _KV3Create = &___KV3Create;
		private static delegate* unmanaged[Cdecl]<long> __KV3Create;
		private static long ___KV3Create()
		{
			long __retVal = __KV3Create();
			return __retVal;
		}
#endregion KV3Create
		/// <summary>
		/// Allocate new KeyValues3 document
		/// </summary>
		internal static long KV3Create()
		{
			return _KV3Create();
		}

#region KV3Destroy
		private static delegate*<long, void> _KV3Destroy = &___KV3Destroy;
		private static delegate* unmanaged[Cdecl]<long, void> __KV3Destroy;
		private static void ___KV3Destroy(long kv3)
		{
			__KV3Destroy(kv3);
		}
#endregion KV3Destroy
		/// <summary>
		/// Free KeyValues3 document
		/// </summary>
		/// <param name="kv3">kv3</param>
		internal static void KV3Destroy(long kv3)
		{
			_KV3Destroy(kv3);
		}

#region KV3SetString
		private static delegate*<long, string, string, void> _KV3SetString = &___KV3SetString;
		private static delegate* unmanaged[Cdecl]<long, String192*, String192*, void> __KV3SetString;
		private static void ___KV3SetString(long kv3, string key, string value)
		{
			var __key = NativeMethods.ConstructString(key);
			var __value = NativeMethods.ConstructString(value);
			try {
				__KV3SetString(kv3, &__key, &__value);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__key);
				NativeMethods.DestroyString(&__value);
			}
		}
#endregion KV3SetString
		/// <summary>
		/// Set string value in KeyValues3 document
		/// </summary>
		/// <param name="kv3">kv3</param>
		/// <param name="key">key</param>
		/// <param name="value">value</param>
		internal static void KV3SetString(long kv3, string key, string value)
		{
			_KV3SetString(kv3, key, value);
		}

#region KV3SetBool
		private static delegate*<long, string, Bool8, void> _KV3SetBool = &___KV3SetBool;
		private static delegate* unmanaged[Cdecl]<long, String192*, Bool8, void> __KV3SetBool;
		private static void ___KV3SetBool(long kv3, string key, Bool8 value)
		{
			var __key = NativeMethods.ConstructString(key);
			try {
				__KV3SetBool(kv3, &__key, value);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__key);
			}
		}
#endregion KV3SetBool
		/// <summary>
		/// Set bool value in KeyValues3 document
		/// </summary>
		/// <param name="kv3">kv3</param>
		/// <param name="key">key</param>
		/// <param name="value">value</param>
		internal static void KV3SetBool(long kv3, string key, Bool8 value)
		{
			_KV3SetBool(kv3, key, value);
		}

#region KV3SetInt
		private static delegate*<long, string, int, void> _KV3SetInt = &___KV3SetInt;
		private static delegate* unmanaged[Cdecl]<long, String192*, int, void> __KV3SetInt;
		private static void ___KV3SetInt(long kv3, string key, int value)
		{
			var __key = NativeMethods.ConstructString(key);
			try {
				__KV3SetInt(kv3, &__key, value);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__key);
			}
		}
#endregion KV3SetInt
		/// <summary>
		/// Set int32 value in KeyValues3 document
		/// </summary>
		/// <param name="kv3">kv3</param>
		/// <param name="key">key</param>
		/// <param name="value">value</param>
		internal static void KV3SetInt(long kv3, string key, int value)
		{
			_KV3SetInt(kv3, key, value);
		}

#region KV3SetFloat
		private static delegate*<long, string, float, void> _KV3SetFloat = &___KV3SetFloat;
		private static delegate* unmanaged[Cdecl]<long, String192*, float, void> __KV3SetFloat;
		private static void ___KV3SetFloat(long kv3, string key, float value)
		{
			var __key = NativeMethods.ConstructString(key);
			try {
				__KV3SetFloat(kv3, &__key, value);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__key);
			}
		}
#endregion KV3SetFloat
		/// <summary>
		/// Set float value in KeyValues3 document
		/// </summary>
		/// <param name="kv3">kv3</param>
		/// <param name="key">key</param>
		/// <param name="value">value</param>
		internal static void KV3SetFloat(long kv3, string key, float value)
		{
			_KV3SetFloat(kv3, key, value);
		}

	}

#pragma warning restore CS0649
}
