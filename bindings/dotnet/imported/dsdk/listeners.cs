using System;
using System.Numerics;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using Plugify;

// Generated from dsdk.pplugin (group: listeners)

namespace dsdk {
#pragma warning disable CS0649

	internal static unsafe partial class dsdk {

#region OnModifyCurrency_Register
		private static delegate*<ModifyCurrencyCallback, void> _OnModifyCurrency_Register = &___OnModifyCurrency_Register;
		private static delegate* unmanaged[Cdecl]<nint, void> __OnModifyCurrency_Register;
		private static void ___OnModifyCurrency_Register(ModifyCurrencyCallback callback)
		{
			__OnModifyCurrency_Register(Marshalling.GetFunctionPointerForDelegate(callback));
		}
#endregion OnModifyCurrency_Register
		/// <summary>
		/// Register Currency modification listener hook
		/// </summary>
		/// <param name="callback">callback</param>
		internal static void OnModifyCurrency_Register(ModifyCurrencyCallback callback)
		{
			_OnModifyCurrency_Register(callback);
		}

#region OnModifyCurrency_Unregister
		private static delegate*<ModifyCurrencyCallback, void> _OnModifyCurrency_Unregister = &___OnModifyCurrency_Unregister;
		private static delegate* unmanaged[Cdecl]<nint, void> __OnModifyCurrency_Unregister;
		private static void ___OnModifyCurrency_Unregister(ModifyCurrencyCallback callback)
		{
			__OnModifyCurrency_Unregister(Marshalling.GetFunctionPointerForDelegate(callback));
		}
#endregion OnModifyCurrency_Unregister
		/// <summary>
		/// Unregister Currency modification listener hook
		/// </summary>
		/// <param name="callback">callback</param>
		internal static void OnModifyCurrency_Unregister(ModifyCurrencyCallback callback)
		{
			_OnModifyCurrency_Unregister(callback);
		}

#region OnTakeDamage_Register
		private static delegate*<TakeDamageCallback, void> _OnTakeDamage_Register = &___OnTakeDamage_Register;
		private static delegate* unmanaged[Cdecl]<nint, void> __OnTakeDamage_Register;
		private static void ___OnTakeDamage_Register(TakeDamageCallback callback)
		{
			__OnTakeDamage_Register(Marshalling.GetFunctionPointerForDelegate(callback));
		}
#endregion OnTakeDamage_Register
		/// <summary>
		/// Register Entity take damage listener hook
		/// </summary>
		/// <param name="callback">callback</param>
		internal static void OnTakeDamage_Register(TakeDamageCallback callback)
		{
			_OnTakeDamage_Register(callback);
		}

#region OnTakeDamage_Unregister
		private static delegate*<TakeDamageCallback, void> _OnTakeDamage_Unregister = &___OnTakeDamage_Unregister;
		private static delegate* unmanaged[Cdecl]<nint, void> __OnTakeDamage_Unregister;
		private static void ___OnTakeDamage_Unregister(TakeDamageCallback callback)
		{
			__OnTakeDamage_Unregister(Marshalling.GetFunctionPointerForDelegate(callback));
		}
#endregion OnTakeDamage_Unregister
		/// <summary>
		/// Unregister Entity take damage listener hook
		/// </summary>
		/// <param name="callback">callback</param>
		internal static void OnTakeDamage_Unregister(TakeDamageCallback callback)
		{
			_OnTakeDamage_Unregister(callback);
		}

#region OnClientConnect_Register
		private static delegate*<ClientConnectCallback, void> _OnClientConnect_Register = &___OnClientConnect_Register;
		private static delegate* unmanaged[Cdecl]<nint, void> __OnClientConnect_Register;
		private static void ___OnClientConnect_Register(ClientConnectCallback callback)
		{
			__OnClientConnect_Register(Marshalling.GetFunctionPointerForDelegate(callback));
		}
#endregion OnClientConnect_Register
		/// <summary>
		/// Register Client connection listener hook
		/// </summary>
		/// <param name="callback">callback</param>
		internal static void OnClientConnect_Register(ClientConnectCallback callback)
		{
			_OnClientConnect_Register(callback);
		}

#region OnClientConnect_Unregister
		private static delegate*<ClientConnectCallback, void> _OnClientConnect_Unregister = &___OnClientConnect_Unregister;
		private static delegate* unmanaged[Cdecl]<nint, void> __OnClientConnect_Unregister;
		private static void ___OnClientConnect_Unregister(ClientConnectCallback callback)
		{
			__OnClientConnect_Unregister(Marshalling.GetFunctionPointerForDelegate(callback));
		}
#endregion OnClientConnect_Unregister
		/// <summary>
		/// Unregister Client connection listener hook
		/// </summary>
		/// <param name="callback">callback</param>
		internal static void OnClientConnect_Unregister(ClientConnectCallback callback)
		{
			_OnClientConnect_Unregister(callback);
		}

#region OnClientPutInServer_Register
		private static delegate*<ClientPutInServerCallback, void> _OnClientPutInServer_Register = &___OnClientPutInServer_Register;
		private static delegate* unmanaged[Cdecl]<nint, void> __OnClientPutInServer_Register;
		private static void ___OnClientPutInServer_Register(ClientPutInServerCallback callback)
		{
			__OnClientPutInServer_Register(Marshalling.GetFunctionPointerForDelegate(callback));
		}
#endregion OnClientPutInServer_Register
		/// <summary>
		/// Register Client put in server listener hook
		/// </summary>
		/// <param name="callback">callback</param>
		internal static void OnClientPutInServer_Register(ClientPutInServerCallback callback)
		{
			_OnClientPutInServer_Register(callback);
		}

#region OnClientPutInServer_Unregister
		private static delegate*<ClientPutInServerCallback, void> _OnClientPutInServer_Unregister = &___OnClientPutInServer_Unregister;
		private static delegate* unmanaged[Cdecl]<nint, void> __OnClientPutInServer_Unregister;
		private static void ___OnClientPutInServer_Unregister(ClientPutInServerCallback callback)
		{
			__OnClientPutInServer_Unregister(Marshalling.GetFunctionPointerForDelegate(callback));
		}
#endregion OnClientPutInServer_Unregister
		/// <summary>
		/// Unregister Client put in server listener hook
		/// </summary>
		/// <param name="callback">callback</param>
		internal static void OnClientPutInServer_Unregister(ClientPutInServerCallback callback)
		{
			_OnClientPutInServer_Unregister(callback);
		}

#region OnClientDisconnect_Register
		private static delegate*<ClientDisconnectCallback, void> _OnClientDisconnect_Register = &___OnClientDisconnect_Register;
		private static delegate* unmanaged[Cdecl]<nint, void> __OnClientDisconnect_Register;
		private static void ___OnClientDisconnect_Register(ClientDisconnectCallback callback)
		{
			__OnClientDisconnect_Register(Marshalling.GetFunctionPointerForDelegate(callback));
		}
#endregion OnClientDisconnect_Register
		/// <summary>
		/// Register Client disconnect listener hook
		/// </summary>
		/// <param name="callback">callback</param>
		internal static void OnClientDisconnect_Register(ClientDisconnectCallback callback)
		{
			_OnClientDisconnect_Register(callback);
		}

#region OnClientDisconnect_Unregister
		private static delegate*<ClientDisconnectCallback, void> _OnClientDisconnect_Unregister = &___OnClientDisconnect_Unregister;
		private static delegate* unmanaged[Cdecl]<nint, void> __OnClientDisconnect_Unregister;
		private static void ___OnClientDisconnect_Unregister(ClientDisconnectCallback callback)
		{
			__OnClientDisconnect_Unregister(Marshalling.GetFunctionPointerForDelegate(callback));
		}
#endregion OnClientDisconnect_Unregister
		/// <summary>
		/// Unregister Client disconnect listener hook
		/// </summary>
		/// <param name="callback">callback</param>
		internal static void OnClientDisconnect_Unregister(ClientDisconnectCallback callback)
		{
			_OnClientDisconnect_Unregister(callback);
		}

#region OnGameFrame_Register
		private static delegate*<GameFrameCallback, void> _OnGameFrame_Register = &___OnGameFrame_Register;
		private static delegate* unmanaged[Cdecl]<nint, void> __OnGameFrame_Register;
		private static void ___OnGameFrame_Register(GameFrameCallback callback)
		{
			__OnGameFrame_Register(Marshalling.GetFunctionPointerForDelegate(callback));
		}
#endregion OnGameFrame_Register
		/// <summary>
		/// Register Server game tick frame listener hook
		/// </summary>
		/// <param name="callback">callback</param>
		internal static void OnGameFrame_Register(GameFrameCallback callback)
		{
			_OnGameFrame_Register(callback);
		}

#region OnGameFrame_Unregister
		private static delegate*<GameFrameCallback, void> _OnGameFrame_Unregister = &___OnGameFrame_Unregister;
		private static delegate* unmanaged[Cdecl]<nint, void> __OnGameFrame_Unregister;
		private static void ___OnGameFrame_Unregister(GameFrameCallback callback)
		{
			__OnGameFrame_Unregister(Marshalling.GetFunctionPointerForDelegate(callback));
		}
#endregion OnGameFrame_Unregister
		/// <summary>
		/// Unregister Server game tick frame listener hook
		/// </summary>
		/// <param name="callback">callback</param>
		internal static void OnGameFrame_Unregister(GameFrameCallback callback)
		{
			_OnGameFrame_Unregister(callback);
		}

#region OnEntityCreated_Register
		private static delegate*<EntityCallback, void> _OnEntityCreated_Register = &___OnEntityCreated_Register;
		private static delegate* unmanaged[Cdecl]<nint, void> __OnEntityCreated_Register;
		private static void ___OnEntityCreated_Register(EntityCallback callback)
		{
			__OnEntityCreated_Register(Marshalling.GetFunctionPointerForDelegate(callback));
		}
#endregion OnEntityCreated_Register
		/// <summary>
		/// Register Entity created listener hook
		/// </summary>
		/// <param name="callback">callback</param>
		internal static void OnEntityCreated_Register(EntityCallback callback)
		{
			_OnEntityCreated_Register(callback);
		}

#region OnEntityCreated_Unregister
		private static delegate*<EntityCallback, void> _OnEntityCreated_Unregister = &___OnEntityCreated_Unregister;
		private static delegate* unmanaged[Cdecl]<nint, void> __OnEntityCreated_Unregister;
		private static void ___OnEntityCreated_Unregister(EntityCallback callback)
		{
			__OnEntityCreated_Unregister(Marshalling.GetFunctionPointerForDelegate(callback));
		}
#endregion OnEntityCreated_Unregister
		/// <summary>
		/// Unregister Entity created listener hook
		/// </summary>
		/// <param name="callback">callback</param>
		internal static void OnEntityCreated_Unregister(EntityCallback callback)
		{
			_OnEntityCreated_Unregister(callback);
		}

#region OnEntitySpawned_Register
		private static delegate*<EntityCallback, void> _OnEntitySpawned_Register = &___OnEntitySpawned_Register;
		private static delegate* unmanaged[Cdecl]<nint, void> __OnEntitySpawned_Register;
		private static void ___OnEntitySpawned_Register(EntityCallback callback)
		{
			__OnEntitySpawned_Register(Marshalling.GetFunctionPointerForDelegate(callback));
		}
#endregion OnEntitySpawned_Register
		/// <summary>
		/// Register Entity spawned listener hook
		/// </summary>
		/// <param name="callback">callback</param>
		internal static void OnEntitySpawned_Register(EntityCallback callback)
		{
			_OnEntitySpawned_Register(callback);
		}

#region OnEntitySpawned_Unregister
		private static delegate*<EntityCallback, void> _OnEntitySpawned_Unregister = &___OnEntitySpawned_Unregister;
		private static delegate* unmanaged[Cdecl]<nint, void> __OnEntitySpawned_Unregister;
		private static void ___OnEntitySpawned_Unregister(EntityCallback callback)
		{
			__OnEntitySpawned_Unregister(Marshalling.GetFunctionPointerForDelegate(callback));
		}
#endregion OnEntitySpawned_Unregister
		/// <summary>
		/// Unregister Entity spawned listener hook
		/// </summary>
		/// <param name="callback">callback</param>
		internal static void OnEntitySpawned_Unregister(EntityCallback callback)
		{
			_OnEntitySpawned_Unregister(callback);
		}

#region OnEntityDeleted_Register
		private static delegate*<EntityCallback, void> _OnEntityDeleted_Register = &___OnEntityDeleted_Register;
		private static delegate* unmanaged[Cdecl]<nint, void> __OnEntityDeleted_Register;
		private static void ___OnEntityDeleted_Register(EntityCallback callback)
		{
			__OnEntityDeleted_Register(Marshalling.GetFunctionPointerForDelegate(callback));
		}
#endregion OnEntityDeleted_Register
		/// <summary>
		/// Register Entity deleted listener hook
		/// </summary>
		/// <param name="callback">callback</param>
		internal static void OnEntityDeleted_Register(EntityCallback callback)
		{
			_OnEntityDeleted_Register(callback);
		}

#region OnEntityDeleted_Unregister
		private static delegate*<EntityCallback, void> _OnEntityDeleted_Unregister = &___OnEntityDeleted_Unregister;
		private static delegate* unmanaged[Cdecl]<nint, void> __OnEntityDeleted_Unregister;
		private static void ___OnEntityDeleted_Unregister(EntityCallback callback)
		{
			__OnEntityDeleted_Unregister(Marshalling.GetFunctionPointerForDelegate(callback));
		}
#endregion OnEntityDeleted_Unregister
		/// <summary>
		/// Unregister Entity deleted listener hook
		/// </summary>
		/// <param name="callback">callback</param>
		internal static void OnEntityDeleted_Unregister(EntityCallback callback)
		{
			_OnEntityDeleted_Unregister(callback);
		}

#region OnGameStateChanged_Register
		private static delegate*<GameStateChangedCallback, void> _OnGameStateChanged_Register = &___OnGameStateChanged_Register;
		private static delegate* unmanaged[Cdecl]<nint, void> __OnGameStateChanged_Register;
		private static void ___OnGameStateChanged_Register(GameStateChangedCallback callback)
		{
			__OnGameStateChanged_Register(Marshalling.GetFunctionPointerForDelegate(callback));
		}
#endregion OnGameStateChanged_Register
		/// <summary>
		/// Register Game state change listener hook
		/// </summary>
		/// <param name="callback">callback</param>
		internal static void OnGameStateChanged_Register(GameStateChangedCallback callback)
		{
			_OnGameStateChanged_Register(callback);
		}

#region OnGameStateChanged_Unregister
		private static delegate*<GameStateChangedCallback, void> _OnGameStateChanged_Unregister = &___OnGameStateChanged_Unregister;
		private static delegate* unmanaged[Cdecl]<nint, void> __OnGameStateChanged_Unregister;
		private static void ___OnGameStateChanged_Unregister(GameStateChangedCallback callback)
		{
			__OnGameStateChanged_Unregister(Marshalling.GetFunctionPointerForDelegate(callback));
		}
#endregion OnGameStateChanged_Unregister
		/// <summary>
		/// Unregister Game state change listener hook
		/// </summary>
		/// <param name="callback">callback</param>
		internal static void OnGameStateChanged_Unregister(GameStateChangedCallback callback)
		{
			_OnGameStateChanged_Unregister(callback);
		}

#region OnEntityAcceptInput_Register
		private static delegate*<EntityIOCallback, void> _OnEntityAcceptInput_Register = &___OnEntityAcceptInput_Register;
		private static delegate* unmanaged[Cdecl]<nint, void> __OnEntityAcceptInput_Register;
		private static void ___OnEntityAcceptInput_Register(EntityIOCallback callback)
		{
			__OnEntityAcceptInput_Register(Marshalling.GetFunctionPointerForDelegate(callback));
		}
#endregion OnEntityAcceptInput_Register
		/// <summary>
		/// Register Entity AcceptInput listener hook
		/// </summary>
		/// <param name="callback">callback</param>
		internal static void OnEntityAcceptInput_Register(EntityIOCallback callback)
		{
			_OnEntityAcceptInput_Register(callback);
		}

#region OnEntityAcceptInput_Unregister
		private static delegate*<EntityIOCallback, void> _OnEntityAcceptInput_Unregister = &___OnEntityAcceptInput_Unregister;
		private static delegate* unmanaged[Cdecl]<nint, void> __OnEntityAcceptInput_Unregister;
		private static void ___OnEntityAcceptInput_Unregister(EntityIOCallback callback)
		{
			__OnEntityAcceptInput_Unregister(Marshalling.GetFunctionPointerForDelegate(callback));
		}
#endregion OnEntityAcceptInput_Unregister
		/// <summary>
		/// Unregister Entity AcceptInput listener hook
		/// </summary>
		/// <param name="callback">callback</param>
		internal static void OnEntityAcceptInput_Unregister(EntityIOCallback callback)
		{
			_OnEntityAcceptInput_Unregister(callback);
		}

#region OnNpcSelectSchedule_Register
		private static delegate*<NpcSelectScheduleCallback, void> _OnNpcSelectSchedule_Register = &___OnNpcSelectSchedule_Register;
		private static delegate* unmanaged[Cdecl]<nint, void> __OnNpcSelectSchedule_Register;
		private static void ___OnNpcSelectSchedule_Register(NpcSelectScheduleCallback callback)
		{
			__OnNpcSelectSchedule_Register(Marshalling.GetFunctionPointerForDelegate(callback));
		}
#endregion OnNpcSelectSchedule_Register
		/// <summary>
		/// Register NPC schedule selection listener hook
		/// </summary>
		/// <param name="callback">callback</param>
		internal static void OnNpcSelectSchedule_Register(NpcSelectScheduleCallback callback)
		{
			_OnNpcSelectSchedule_Register(callback);
		}

#region OnNpcSelectSchedule_Unregister
		private static delegate*<NpcSelectScheduleCallback, void> _OnNpcSelectSchedule_Unregister = &___OnNpcSelectSchedule_Unregister;
		private static delegate* unmanaged[Cdecl]<nint, void> __OnNpcSelectSchedule_Unregister;
		private static void ___OnNpcSelectSchedule_Unregister(NpcSelectScheduleCallback callback)
		{
			__OnNpcSelectSchedule_Unregister(Marshalling.GetFunctionPointerForDelegate(callback));
		}
#endregion OnNpcSelectSchedule_Unregister
		/// <summary>
		/// Unregister NPC schedule selection listener hook
		/// </summary>
		/// <param name="callback">callback</param>
		internal static void OnNpcSelectSchedule_Unregister(NpcSelectScheduleCallback callback)
		{
			_OnNpcSelectSchedule_Unregister(callback);
		}

#region OnEntityFireOutput_Register
		private static delegate*<EntityOutputCallback, void> _OnEntityFireOutput_Register = &___OnEntityFireOutput_Register;
		private static delegate* unmanaged[Cdecl]<nint, void> __OnEntityFireOutput_Register;
		private static void ___OnEntityFireOutput_Register(EntityOutputCallback callback)
		{
			__OnEntityFireOutput_Register(Marshalling.GetFunctionPointerForDelegate(callback));
		}
#endregion OnEntityFireOutput_Register
		/// <summary>
		/// Register Entity FireOutput listener hook
		/// </summary>
		/// <param name="callback">callback</param>
		internal static void OnEntityFireOutput_Register(EntityOutputCallback callback)
		{
			_OnEntityFireOutput_Register(callback);
		}

#region OnEntityFireOutput_Unregister
		private static delegate*<EntityOutputCallback, void> _OnEntityFireOutput_Unregister = &___OnEntityFireOutput_Unregister;
		private static delegate* unmanaged[Cdecl]<nint, void> __OnEntityFireOutput_Unregister;
		private static void ___OnEntityFireOutput_Unregister(EntityOutputCallback callback)
		{
			__OnEntityFireOutput_Unregister(Marshalling.GetFunctionPointerForDelegate(callback));
		}
#endregion OnEntityFireOutput_Unregister
		/// <summary>
		/// Unregister Entity FireOutput listener hook
		/// </summary>
		/// <param name="callback">callback</param>
		internal static void OnEntityFireOutput_Unregister(EntityOutputCallback callback)
		{
			_OnEntityFireOutput_Unregister(callback);
		}

#region OnProcessUsercmds_Register
		private static delegate*<ProcessUsercmdsCallback, void> _OnProcessUsercmds_Register = &___OnProcessUsercmds_Register;
		private static delegate* unmanaged[Cdecl]<nint, void> __OnProcessUsercmds_Register;
		private static void ___OnProcessUsercmds_Register(ProcessUsercmdsCallback callback)
		{
			__OnProcessUsercmds_Register(Marshalling.GetFunctionPointerForDelegate(callback));
		}
#endregion OnProcessUsercmds_Register
		/// <summary>
		/// Register CBasePlayerController::ProcessUsercmds listener hook
		/// </summary>
		/// <param name="callback">callback</param>
		internal static void OnProcessUsercmds_Register(ProcessUsercmdsCallback callback)
		{
			_OnProcessUsercmds_Register(callback);
		}

#region OnProcessUsercmds_Unregister
		private static delegate*<ProcessUsercmdsCallback, void> _OnProcessUsercmds_Unregister = &___OnProcessUsercmds_Unregister;
		private static delegate* unmanaged[Cdecl]<nint, void> __OnProcessUsercmds_Unregister;
		private static void ___OnProcessUsercmds_Unregister(ProcessUsercmdsCallback callback)
		{
			__OnProcessUsercmds_Unregister(Marshalling.GetFunctionPointerForDelegate(callback));
		}
#endregion OnProcessUsercmds_Unregister
		/// <summary>
		/// Unregister CBasePlayerController::ProcessUsercmds listener hook
		/// </summary>
		/// <param name="callback">callback</param>
		internal static void OnProcessUsercmds_Unregister(ProcessUsercmdsCallback callback)
		{
			_OnProcessUsercmds_Unregister(callback);
		}

#region OnAbilityThink_Register
		private static delegate*<AbilityThinkCallback, void> _OnAbilityThink_Register = &___OnAbilityThink_Register;
		private static delegate* unmanaged[Cdecl]<nint, void> __OnAbilityThink_Register;
		private static void ___OnAbilityThink_Register(AbilityThinkCallback callback)
		{
			__OnAbilityThink_Register(Marshalling.GetFunctionPointerForDelegate(callback));
		}
#endregion OnAbilityThink_Register
		/// <summary>
		/// Register CCitadelPlayerPawn::AbilityThink listener hook
		/// </summary>
		/// <param name="callback">callback</param>
		internal static void OnAbilityThink_Register(AbilityThinkCallback callback)
		{
			_OnAbilityThink_Register(callback);
		}

#region OnAbilityThink_Unregister
		private static delegate*<AbilityThinkCallback, void> _OnAbilityThink_Unregister = &___OnAbilityThink_Unregister;
		private static delegate* unmanaged[Cdecl]<nint, void> __OnAbilityThink_Unregister;
		private static void ___OnAbilityThink_Unregister(AbilityThinkCallback callback)
		{
			__OnAbilityThink_Unregister(Marshalling.GetFunctionPointerForDelegate(callback));
		}
#endregion OnAbilityThink_Unregister
		/// <summary>
		/// Unregister CCitadelPlayerPawn::AbilityThink listener hook
		/// </summary>
		/// <param name="callback">callback</param>
		internal static void OnAbilityThink_Unregister(AbilityThinkCallback callback)
		{
			_OnAbilityThink_Unregister(callback);
		}

#region OnAddModifier_Register
		private static delegate*<AddModifierCallback, void> _OnAddModifier_Register = &___OnAddModifier_Register;
		private static delegate* unmanaged[Cdecl]<nint, void> __OnAddModifier_Register;
		private static void ___OnAddModifier_Register(AddModifierCallback callback)
		{
			__OnAddModifier_Register(Marshalling.GetFunctionPointerForDelegate(callback));
		}
#endregion OnAddModifier_Register
		/// <summary>
		/// Register CModifierProperty::AddModifier listener hook
		/// </summary>
		/// <param name="callback">callback</param>
		internal static void OnAddModifier_Register(AddModifierCallback callback)
		{
			_OnAddModifier_Register(callback);
		}

#region OnAddModifier_Unregister
		private static delegate*<AddModifierCallback, void> _OnAddModifier_Unregister = &___OnAddModifier_Unregister;
		private static delegate* unmanaged[Cdecl]<nint, void> __OnAddModifier_Unregister;
		private static void ___OnAddModifier_Unregister(AddModifierCallback callback)
		{
			__OnAddModifier_Unregister(Marshalling.GetFunctionPointerForDelegate(callback));
		}
#endregion OnAddModifier_Unregister
		/// <summary>
		/// Unregister CModifierProperty::AddModifier listener hook
		/// </summary>
		/// <param name="callback">callback</param>
		internal static void OnAddModifier_Unregister(AddModifierCallback callback)
		{
			_OnAddModifier_Unregister(callback);
		}

#region OnHeroInitialized_Register
		private static delegate*<HeroInitializedCallback, void> _OnHeroInitialized_Register = &___OnHeroInitialized_Register;
		private static delegate* unmanaged[Cdecl]<nint, void> __OnHeroInitialized_Register;
		private static void ___OnHeroInitialized_Register(HeroInitializedCallback callback)
		{
			__OnHeroInitialized_Register(Marshalling.GetFunctionPointerForDelegate(callback));
		}
#endregion OnHeroInitialized_Register
		/// <summary>
		/// Register CCitadelPlayerPawn::InitializeHeroOnPawn listener hook
		/// </summary>
		/// <param name="callback">callback</param>
		internal static void OnHeroInitialized_Register(HeroInitializedCallback callback)
		{
			_OnHeroInitialized_Register(callback);
		}

#region OnHeroInitialized_Unregister
		private static delegate*<HeroInitializedCallback, void> _OnHeroInitialized_Unregister = &___OnHeroInitialized_Unregister;
		private static delegate* unmanaged[Cdecl]<nint, void> __OnHeroInitialized_Unregister;
		private static void ___OnHeroInitialized_Unregister(HeroInitializedCallback callback)
		{
			__OnHeroInitialized_Unregister(Marshalling.GetFunctionPointerForDelegate(callback));
		}
#endregion OnHeroInitialized_Unregister
		/// <summary>
		/// Unregister CCitadelPlayerPawn::InitializeHeroOnPawn listener hook
		/// </summary>
		/// <param name="callback">callback</param>
		internal static void OnHeroInitialized_Unregister(HeroInitializedCallback callback)
		{
			_OnHeroInitialized_Unregister(callback);
		}

#region OnGameEvent_Register
		private static delegate*<GameEventCallback, void> _OnGameEvent_Register = &___OnGameEvent_Register;
		private static delegate* unmanaged[Cdecl]<nint, void> __OnGameEvent_Register;
		private static void ___OnGameEvent_Register(GameEventCallback callback)
		{
			__OnGameEvent_Register(Marshalling.GetFunctionPointerForDelegate(callback));
		}
#endregion OnGameEvent_Register
		/// <summary>
		/// Register game event listener hook (e.g. player_death, player_respawned)
		/// </summary>
		/// <param name="callback">callback</param>
		internal static void OnGameEvent_Register(GameEventCallback callback)
		{
			_OnGameEvent_Register(callback);
		}

#region OnGameEvent_Unregister
		private static delegate*<GameEventCallback, void> _OnGameEvent_Unregister = &___OnGameEvent_Unregister;
		private static delegate* unmanaged[Cdecl]<nint, void> __OnGameEvent_Unregister;
		private static void ___OnGameEvent_Unregister(GameEventCallback callback)
		{
			__OnGameEvent_Unregister(Marshalling.GetFunctionPointerForDelegate(callback));
		}
#endregion OnGameEvent_Unregister
		/// <summary>
		/// Unregister game event listener hook
		/// </summary>
		/// <param name="callback">callback</param>
		internal static void OnGameEvent_Unregister(GameEventCallback callback)
		{
			_OnGameEvent_Unregister(callback);
		}

	}

#pragma warning restore CS0649
}
