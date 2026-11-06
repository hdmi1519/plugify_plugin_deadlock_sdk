using System;
using System.Numerics;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using Plugify;

// Generated from dsdk.pplugin (group: worldtext)

namespace dsdk {
#pragma warning disable CS0649

	internal static unsafe partial class dsdk {

#region CreateWorldText
		private static delegate*<string, float, float, float, float, byte, byte, byte, byte, long> _CreateWorldText = &___CreateWorldText;
		private static delegate* unmanaged[Cdecl]<String192*, float, float, float, float, byte, byte, byte, byte, long> __CreateWorldText;
		private static long ___CreateWorldText(string message, float x, float y, float z, float fontSize, byte r, byte g, byte b, byte a)
		{
			long __retVal;
			var __message = NativeMethods.ConstructString(message);
			try {
				__retVal = __CreateWorldText(&__message, x, y, z, fontSize, r, g, b, a);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__message);
			}
			return __retVal;
		}
#endregion CreateWorldText
		/// <summary>
		/// Create 3D point_worldtext entity in the world
		/// </summary>
		/// <param name="message">message</param>
		/// <param name="x">x</param>
		/// <param name="y">y</param>
		/// <param name="z">z</param>
		/// <param name="fontSize">fontSize</param>
		/// <param name="r">r</param>
		/// <param name="g">g</param>
		/// <param name="b">b</param>
		/// <param name="a">a</param>
		internal static long CreateWorldText(string message, float x, float y, float z, float fontSize, byte r, byte g, byte b, byte a)
		{
			return _CreateWorldText(message, x, y, z, fontSize, r, g, b, a);
		}

#region SetWorldTextMessage
		private static delegate*<long, string, void> _SetWorldTextMessage = &___SetWorldTextMessage;
		private static delegate* unmanaged[Cdecl]<long, String192*, void> __SetWorldTextMessage;
		private static void ___SetWorldTextMessage(long worldText, string text)
		{
			var __text = NativeMethods.ConstructString(text);
			try {
				__SetWorldTextMessage(worldText, &__text);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__text);
			}
		}
#endregion SetWorldTextMessage
		/// <summary>
		/// Update message text of CPointWorldText
		/// </summary>
		/// <param name="worldText">worldText</param>
		/// <param name="text">text</param>
		internal static void SetWorldTextMessage(long worldText, string text)
		{
			_SetWorldTextMessage(worldText, text);
		}

	}

#pragma warning restore CS0649
}
