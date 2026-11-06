using System;
using System.Numerics;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using Plugify;

// Generated from dsdk.pplugin (group: entities)

namespace dsdk {
#pragma warning disable CS0649

	internal static unsafe partial class dsdk {

#region CreateEntityByName
		private static delegate*<string, long> _CreateEntityByName = &___CreateEntityByName;
		private static delegate* unmanaged[Cdecl]<String192*, long> __CreateEntityByName;
		private static long ___CreateEntityByName(string className)
		{
			long __retVal;
			var __className = NativeMethods.ConstructString(className);
			try {
				__retVal = __CreateEntityByName(&__className);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__className);
			}
			return __retVal;
		}
#endregion CreateEntityByName
		/// <summary>
		/// Create entity instance by class name
		/// </summary>
		/// <param name="className">className</param>
		internal static long CreateEntityByName(string className)
		{
			return _CreateEntityByName(className);
		}

#region QueueSpawnEntity
		private static delegate*<long, long, void> _QueueSpawnEntity = &___QueueSpawnEntity;
		private static delegate* unmanaged[Cdecl]<long, long, void> __QueueSpawnEntity;
		private static void ___QueueSpawnEntity(long entity, long ekv)
		{
			__QueueSpawnEntity(entity, ekv);
		}
#endregion QueueSpawnEntity
		/// <summary>
		/// Queue entity spawn with optional entity keyvalues
		/// </summary>
		/// <param name="entity">entity</param>
		/// <param name="ekv">ekv</param>
		internal static void QueueSpawnEntity(long entity, long ekv)
		{
			_QueueSpawnEntity(entity, ekv);
		}

#region ExecuteQueuedCreation
		private static delegate*<void> _ExecuteQueuedCreation = &___ExecuteQueuedCreation;
		private static delegate* unmanaged[Cdecl]<void> __ExecuteQueuedCreation;
		private static void ___ExecuteQueuedCreation()
		{
			__ExecuteQueuedCreation();
		}
#endregion ExecuteQueuedCreation
		/// <summary>
		/// Execute queued entity creation
		/// </summary>
		internal static void ExecuteQueuedCreation()
		{
			_ExecuteQueuedCreation();
		}

#region RemoveEntity
		private static delegate*<long, void> _RemoveEntity = &___RemoveEntity;
		private static delegate* unmanaged[Cdecl]<long, void> __RemoveEntity;
		private static void ___RemoveEntity(long entity)
		{
			__RemoveEntity(entity);
		}
#endregion RemoveEntity
		/// <summary>
		/// Remove/destroy entity
		/// </summary>
		/// <param name="entity">entity</param>
		internal static void RemoveEntity(long entity)
		{
			_RemoveEntity(entity);
		}

#region GetEntityByIndex
		private static delegate*<int, long> _GetEntityByIndex = &___GetEntityByIndex;
		private static delegate* unmanaged[Cdecl]<int, long> __GetEntityByIndex;
		private static long ___GetEntityByIndex(int index)
		{
			long __retVal = __GetEntityByIndex(index);
			return __retVal;
		}
#endregion GetEntityByIndex
		/// <summary>
		/// Get entity pointer by index
		/// </summary>
		/// <param name="index">index</param>
		internal static long GetEntityByIndex(int index)
		{
			return _GetEntityByIndex(index);
		}

#region GetEntityFromHandle
		private static delegate*<uint, long> _GetEntityFromHandle = &___GetEntityFromHandle;
		private static delegate* unmanaged[Cdecl]<uint, long> __GetEntityFromHandle;
		private static long ___GetEntityFromHandle(uint handle)
		{
			long __retVal = __GetEntityFromHandle(handle);
			return __retVal;
		}
#endregion GetEntityFromHandle
		/// <summary>
		/// Resolve entity pointer from uint32 handle
		/// </summary>
		/// <param name="handle">handle</param>
		internal static long GetEntityFromHandle(uint handle)
		{
			return _GetEntityFromHandle(handle);
		}

#region GetEntityHandle
		private static delegate*<long, uint> _GetEntityHandle = &___GetEntityHandle;
		private static delegate* unmanaged[Cdecl]<long, uint> __GetEntityHandle;
		private static uint ___GetEntityHandle(long entity)
		{
			uint __retVal = __GetEntityHandle(entity);
			return __retVal;
		}
#endregion GetEntityHandle
		/// <summary>
		/// Get handle of entity
		/// </summary>
		/// <param name="entity">entity</param>
		internal static uint GetEntityHandle(long entity)
		{
			return _GetEntityHandle(entity);
		}

#region FindEntityByName
		private static delegate*<long, string, long> _FindEntityByName = &___FindEntityByName;
		private static delegate* unmanaged[Cdecl]<long, String192*, long> __FindEntityByName;
		private static long ___FindEntityByName(long startEntity, string name)
		{
			long __retVal;
			var __name = NativeMethods.ConstructString(name);
			try {
				__retVal = __FindEntityByName(startEntity, &__name);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__name);
			}
			return __retVal;
		}
#endregion FindEntityByName
		/// <summary>
		/// Find entity by name
		/// </summary>
		/// <param name="startEntity">startEntity</param>
		/// <param name="name">name</param>
		internal static long FindEntityByName(long startEntity, string name)
		{
			return _FindEntityByName(startEntity, name);
		}

#region GetEntityDesignerName
		private static delegate*<long, string> _GetEntityDesignerName = &___GetEntityDesignerName;
		private static delegate* unmanaged[Cdecl]<long, String192> __GetEntityDesignerName;
		private static string ___GetEntityDesignerName(long entity)
		{
			string __retVal;
			String192 __retVal_native;
			try {
				__retVal_native = __GetEntityDesignerName(entity);
				// Unmarshal - Convert native data to managed data.
				__retVal = NativeMethods.GetStringData(&__retVal_native);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__retVal_native);
			}
			return __retVal;
		}
#endregion GetEntityDesignerName
		/// <summary>
		/// Get designer name of entity
		/// </summary>
		/// <param name="entity">entity</param>
		internal static string GetEntityDesignerName(long entity)
		{
			return _GetEntityDesignerName(entity);
		}

#region GetEntityClassname
		private static delegate*<long, string> _GetEntityClassname = &___GetEntityClassname;
		private static delegate* unmanaged[Cdecl]<long, String192> __GetEntityClassname;
		private static string ___GetEntityClassname(long entity)
		{
			string __retVal;
			String192 __retVal_native;
			try {
				__retVal_native = __GetEntityClassname(entity);
				// Unmarshal - Convert native data to managed data.
				__retVal = NativeMethods.GetStringData(&__retVal_native);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__retVal_native);
			}
			return __retVal;
		}
#endregion GetEntityClassname
		/// <summary>
		/// Get class name of entity
		/// </summary>
		/// <param name="entity">entity</param>
		internal static string GetEntityClassname(long entity)
		{
			return _GetEntityClassname(entity);
		}

#region Teleport
		private static delegate*<long, float, float, float, float, float, float, float, float, float, void> _Teleport = &___Teleport;
		private static delegate* unmanaged[Cdecl]<long, float, float, float, float, float, float, float, float, float, void> __Teleport;
		private static void ___Teleport(long entity, float posX, float posY, float posZ, float angPitch, float angYaw, float angRoll, float velX, float velY, float velZ)
		{
			__Teleport(entity, posX, posY, posZ, angPitch, angYaw, angRoll, velX, velY, velZ);
		}
#endregion Teleport
		/// <summary>
		/// Teleport entity with position, angles and velocity
		/// </summary>
		/// <param name="entity">entity</param>
		/// <param name="posX">posX</param>
		/// <param name="posY">posY</param>
		/// <param name="posZ">posZ</param>
		/// <param name="angPitch">angPitch</param>
		/// <param name="angYaw">angYaw</param>
		/// <param name="angRoll">angRoll</param>
		/// <param name="velX">velX</param>
		/// <param name="velY">velY</param>
		/// <param name="velZ">velZ</param>
		internal static void Teleport(long entity, float posX, float posY, float posZ, float angPitch, float angYaw, float angRoll, float velX, float velY, float velZ)
		{
			_Teleport(entity, posX, posY, posZ, angPitch, angYaw, angRoll, velX, velY, velZ);
		}

#region SetModel
		private static delegate*<long, string, void> _SetModel = &___SetModel;
		private static delegate* unmanaged[Cdecl]<long, String192*, void> __SetModel;
		private static void ___SetModel(long entity, string modelName)
		{
			var __modelName = NativeMethods.ConstructString(modelName);
			try {
				__SetModel(entity, &__modelName);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__modelName);
			}
		}
#endregion SetModel
		/// <summary>
		/// Set visual model of entity
		/// </summary>
		/// <param name="entity">entity</param>
		/// <param name="modelName">modelName</param>
		internal static void SetModel(long entity, string modelName)
		{
			_SetModel(entity, modelName);
		}

#region GetModelName
		private static delegate*<long, string> _GetModelName = &___GetModelName;
		private static delegate* unmanaged[Cdecl]<long, String192> __GetModelName;
		private static string ___GetModelName(long entity)
		{
			string __retVal;
			String192 __retVal_native;
			try {
				__retVal_native = __GetModelName(entity);
				// Unmarshal - Convert native data to managed data.
				__retVal = NativeMethods.GetStringData(&__retVal_native);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__retVal_native);
			}
			return __retVal;
		}
#endregion GetModelName
		/// <summary>
		/// Get model name of entity
		/// </summary>
		/// <param name="entity">entity</param>
		internal static string GetModelName(long entity)
		{
			return _GetModelName(entity);
		}

#region SetScale
		private static delegate*<long, float, void> _SetScale = &___SetScale;
		private static delegate* unmanaged[Cdecl]<long, float, void> __SetScale;
		private static void ___SetScale(long entity, float scale)
		{
			__SetScale(entity, scale);
		}
#endregion SetScale
		/// <summary>
		/// Set visual scale of entity
		/// </summary>
		/// <param name="entity">entity</param>
		/// <param name="scale">scale</param>
		internal static void SetScale(long entity, float scale)
		{
			_SetScale(entity, scale);
		}

#region SetMoveType
		private static delegate*<long, byte, void> _SetMoveType = &___SetMoveType;
		private static delegate* unmanaged[Cdecl]<long, byte, void> __SetMoveType;
		private static void ___SetMoveType(long entity, byte moveType)
		{
			__SetMoveType(entity, moveType);
		}
#endregion SetMoveType
		/// <summary>
		/// Set entity move type
		/// </summary>
		/// <param name="entity">entity</param>
		/// <param name="moveType">moveType</param>
		internal static void SetMoveType(long entity, byte moveType)
		{
			_SetMoveType(entity, moveType);
		}

#region SetGravityScale
		private static delegate*<long, float, void> _SetGravityScale = &___SetGravityScale;
		private static delegate* unmanaged[Cdecl]<long, float, void> __SetGravityScale;
		private static void ___SetGravityScale(long entity, float scale)
		{
			__SetGravityScale(entity, scale);
		}
#endregion SetGravityScale
		/// <summary>
		/// Set entity gravity multiplier
		/// </summary>
		/// <param name="entity">entity</param>
		/// <param name="scale">scale</param>
		internal static void SetGravityScale(long entity, float scale)
		{
			_SetGravityScale(entity, scale);
		}

#region EntityDerivesFrom
		private static delegate*<long, string, Bool8> _EntityDerivesFrom = &___EntityDerivesFrom;
		private static delegate* unmanaged[Cdecl]<long, String192*, Bool8> __EntityDerivesFrom;
		private static Bool8 ___EntityDerivesFrom(long entity, string baseClassName)
		{
			Bool8 __retVal;
			var __baseClassName = NativeMethods.ConstructString(baseClassName);
			try {
				__retVal = __EntityDerivesFrom(entity, &__baseClassName);
			}
			finally {
				// Perform cleanup.
				NativeMethods.DestroyString(&__baseClassName);
			}
			return __retVal;
		}
#endregion EntityDerivesFrom
		/// <summary>
		/// Check if entity class derives from base class name
		/// </summary>
		/// <param name="entity">entity</param>
		/// <param name="baseClassName">baseClassName</param>
		internal static Bool8 EntityDerivesFrom(long entity, string baseClassName)
		{
			return _EntityDerivesFrom(entity, baseClassName);
		}

	}

#pragma warning restore CS0649
}
