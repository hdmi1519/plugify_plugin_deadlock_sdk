using System;
using System.Numerics;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using Plugify;

// Generated from dsdk.pplugin (group: networking)

namespace dsdk {
#pragma warning disable CS0649

	internal static unsafe partial class dsdk {

#region SendNetMessage
		private static delegate*<int, byte[], ulong, int, void> _SendNetMessage = &___SendNetMessage;
		private static delegate* unmanaged[Cdecl]<int, Vector192*, ulong, int, void> __SendNetMessage;
		private static void ___SendNetMessage(int msgId, byte[] protoBytes, ulong recipientMask, int bufType)
		{
			var __protoBytes = NativeMethods.ConstructVectorUInt8(protoBytes, protoBytes.Length);
			try {
				__SendNetMessage(msgId, &__protoBytes, recipientMask, bufType);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyVectorUInt8(&__protoBytes);
			}
		}
#endregion SendNetMessage
		/// <summary>
		/// Send protobuf network message to clients
		/// </summary>
		/// <param name="msgId">msgId</param>
		/// <param name="protoBytes">protoBytes</param>
		/// <param name="recipientMask">recipientMask</param>
		/// <param name="bufType">bufType</param>
		internal static void SendNetMessage(int msgId, byte[] protoBytes, ulong recipientMask, int bufType)
		{
			_SendNetMessage(msgId, protoBytes, recipientMask, bufType);
		}

#region GetNetMessageName
		private static delegate*<int, string> _GetNetMessageName = &___GetNetMessageName;
		private static delegate* unmanaged[Cdecl]<int, String192> __GetNetMessageName;
		private static string ___GetNetMessageName(int msgId)
		{
			string __retVal;
			String192 __retVal_native;
			try {
				__retVal_native = __GetNetMessageName(msgId);
				// Unmarshal - Convert native data to managed data.
				__retVal = NativeMethods.GetStringData(&__retVal_native);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__retVal_native);
			}
			return __retVal;
		}
#endregion GetNetMessageName
		/// <summary>
		/// Get registered network message name
		/// </summary>
		/// <param name="msgId">msgId</param>
		internal static string GetNetMessageName(int msgId)
		{
			return _GetNetMessageName(msgId);
		}

	}

#pragma warning restore CS0649
}
