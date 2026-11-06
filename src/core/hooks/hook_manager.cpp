#include "pch.hpp"
#include "core/hooks/hook_manager.hpp"
#include <google/protobuf/message_lite.h>
#include "core/memory/data_loader.hpp"
#include "core/listeners/listeners.hpp"
#include "core/timers/timer_system.hpp"
#include "core/settings.hpp"
#include "core/logger.hpp"
#include "core/globals.hpp"
#include "core/sdk/Core.hpp"
#include "core/sdk/schema/Schema.hpp"
#include "export/commands.hpp"
#include <eiface.h>
#include <playerslot.h>
#include <tier0/bufferstring.h>
#include <tier1/convar.h>
#include <tier1/bitbuf.h>
#include <entityhandle.h>
#include <entityinstance.h>
#include <iserver.h>
#include <serversideclient.h>
#include <entity2/entitysystem.h>
#include <networksystem/inetworkmessages.h>
#include <networksystem/inetworkserializer.h>
#include <networksystem/netmessage.h>

namespace dsdk {

// VMT hooks
static safetyhook::VmtHook g_VmtGameClients;
static safetyhook::VmHook g_ClientConnectHook;
static safetyhook::VmHook g_ClientPutInServerHook;
static safetyhook::VmHook g_ClientDisconnectHook;

static safetyhook::VmtHook g_VmtSource2Server;
static safetyhook::VmHook g_GameFrameHook;
static safetyhook::VmHook g_ApplyGameSettingsHook;

static safetyhook::VmtHook g_VmtNetworkServerService;
static safetyhook::VmHook g_StartupServerHook;

// Inline hooks
static safetyhook::InlineHook g_FilterMessageHook;
static safetyhook::InlineHook g_ModifyCurrencyHook;
static safetyhook::InlineHook g_TakeDamageHook;
static safetyhook::InlineHook g_ChangeGameStateHook;
static safetyhook::InlineHook g_GetNewScheduleHook;
static safetyhook::InlineHook g_ClientConCommandHook;
static safetyhook::InlineHook g_SetPawnHook;
static safetyhook::InlineHook g_ProcessUsercmdsHook;
static safetyhook::InlineHook g_AbilityThinkHook;
static safetyhook::InlineHook g_AddModifierHook;
static safetyhook::InlineHook g_AcceptInputHook;
static safetyhook::InlineHook g_FireOutputInternalHook;
static safetyhook::InlineHook g_InitializeHeroOnPawnHook;
static safetyhook::InlineHook g_SelectHeroInternalHook;
static safetyhook::InlineHook g_ServerGCSystemInitHook;
static safetyhook::InlineHook g_ServerVersionCheckHook;
static safetyhook::InlineHook g_TraceShapeHook;

class CEntityListener : public IEntityListener {
public:
    void OnEntityCreated(CEntityInstance *pEntity) override {
        if (!pEntity) return;
        g_EntityCreatedListeners.Dispatch(reinterpret_cast<int64_t>(pEntity));
    }
    void OnEntitySpawned(CEntityInstance *pEntity) override {
        if (!pEntity) return;
        g_EntitySpawnedListeners.Dispatch(reinterpret_cast<int64_t>(pEntity));
    }
    void OnEntityDeleted(CEntityInstance *pEntity) override {
        if (!pEntity) return;
        g_EntityDeletedListeners.Dispatch(reinterpret_cast<int64_t>(pEntity));
    }
};

static CEntityListener g_EntityListener;

// ----------------------------------------------------------------------------
// Safety Helper: Validate Pawn Controller
// ----------------------------------------------------------------------------

static bool PawnHasLiveController(void *pPawn) {
    if (!pPawn) return false;
    static const int kPawn_hController = schema::GetOffset(
        "CBasePlayerPawn", hash_32_fnv1a_const("CBasePlayerPawn"),
        "m_hController", hash_32_fnv1a_const("m_hController")).Offset;
    if (kPawn_hController <= 0)
        return true;

    auto *system = GameEntitySystem();
    if (!system)
        return true;

    uint32_t handleVal = *reinterpret_cast<const uint32_t *>(
        reinterpret_cast<uintptr_t>(pPawn) + kPawn_hController);
    CEntityHandle handle(handleVal);
    if (!handle.IsValid())
        return false;

    return system->GetEntityInstance(handle) != nullptr;
}

// ----------------------------------------------------------------------------
// VMT Detours: ISource2GameClients
// ----------------------------------------------------------------------------

static thread_local bool s_bInClientConnect = false;
static bool __fastcall Detour_ClientConnect(void *thisptr, CPlayerSlot slot, const char *pszName, uint64_t xuid,
                                            const char *pszNetworkID, bool unk1, CBufferString *pRejectReason) {
    if (s_bInClientConnect) {
        return g_ClientConnectHook.call<bool>(thisptr, slot, pszName, xuid, pszNetworkID, unk1, pRejectReason);
    }

    s_bInClientConnect = true;
    bool bAllow = g_ClientConnectListeners.DispatchWithResult<bool>(
        true,
        slot.Get(),
        plg::string(pszName ? pszName : ""),
        xuid
    );
    s_bInClientConnect = false;

    if (!bAllow) {
        if (pRejectReason) {
            pRejectReason->Set("Connection rejected by Deadlock SDK plugin.");
        }
        return false;
    }

    return g_ClientConnectHook.call<bool>(thisptr, slot, pszName, xuid, pszNetworkID, unk1, pRejectReason);
}

static void __fastcall Detour_ClientPutInServer(void *thisptr, CPlayerSlot slot, char const *pszName, int type, uint64_t xuid) {
    g_ClientPutInServerHook.call<void>(thisptr, slot, pszName, type, xuid);
    g_ClientPutInServerListeners.Dispatch(slot.Get());
}

static void __fastcall Detour_ClientDisconnect(void *thisptr, CPlayerSlot slot, int32_t reason, const char *pszName, uint64_t xuid, const char *pszNetworkID) {
    g_ClientDisconnectListeners.Dispatch(slot.Get(), reason);
    g_ClientDisconnectHook.call<void>(thisptr, slot, reason, pszName, xuid, pszNetworkID);
}

// ----------------------------------------------------------------------------
// VMT Detours: ISource2Server
// ----------------------------------------------------------------------------

static void __fastcall Detour_ApplyGameSettings(void *thisptr, void *pKV) {
    g_ApplyGameSettingsHook.call<void>(thisptr, pKV);
}

static void __fastcall Detour_GameFrame(void *thisptr, bool simulating, bool bFirstTick, bool bLastTick) {
    g_GameFrameListeners.Dispatch(simulating, bFirstTick, bLastTick);
    g_GameFrameHook.call<void>(thisptr, simulating, bFirstTick, bLastTick);
}

// ----------------------------------------------------------------------------
// VMT Detours: INetworkServerService
// ----------------------------------------------------------------------------

static void __fastcall Detour_StartupServer(void *thisptr, const void *config, void *pWorldSession, const char *pszMap) {
    if (pszMap && *pszMap) {
        dsdk::g_CurrentMapName = pszMap;
    }
    g_StartupServerHook.call<void>(thisptr, config, pWorldSession, pszMap);
    Logger::Debug("Server startup detected on map: {}", pszMap ? pszMap : "<unknown>");
}

// ----------------------------------------------------------------------------
// Inline Detours
// ----------------------------------------------------------------------------

static bool ReadVarint(const uint8_t *&at, const uint8_t *end, uint64_t &value) {
    value = 0;
    for (int shift = 0; at < end && shift < 64; shift += 7) {
        const uint8_t byte = *at++;
        value |= static_cast<uint64_t>(byte & 0x7F) << shift;
        if (!(byte & 0x80)) return true;
    }
    return false;
}

static bool ExtractChatText(const uint8_t *data, size_t length, std::string &outText) {
    const uint8_t *at = data;
    const uint8_t *end = data + length;
    while (at < end) {
        uint64_t key = 0;
        if (!ReadVarint(at, end, key)) return false;
        uint32_t field = static_cast<uint32_t>(key >> 3);
        uint32_t wire = static_cast<uint32_t>(key & 7);
        switch (wire) {
        case 0: { // varint
            uint64_t dummy = 0;
            if (!ReadVarint(at, end, dummy)) return false;
            break;
        }
        case 1: { // 64-bit
            if (at + 8 > end) return false;
            at += 8;
            break;
        }
        case 2: { // length-delimited
            uint64_t len = 0;
            if (!ReadVarint(at, end, len) || at + len > end) return false;
            if (field == 1) { // CCitadelClientMsg_ChatMsg::chat_text = 1
                outText.assign(reinterpret_cast<const char *>(at), static_cast<size_t>(len));
                return true;
            }
            at += len;
            break;
        }
        case 5: { // 32-bit
            if (at + 4 > end) return false;
            at += 4;
            break;
        }
        default:
            return false;
        }
    }
    return false;
}

// Detour: CServerSideClientBase::FilterMessage (Incoming Network Message Interceptor)
static thread_local bool s_bInFilterMessage = false;
static bool __fastcall Detour_FilterMessage(INetworkMessageProcessingPreFilter *thisptr, const CNetMessage *pData, INetChannel *pChannel) {
    if (s_bInFilterMessage) {
        return g_FilterMessageHook.thiscall<bool>(thisptr, pData, pChannel);
    }

    if (thisptr && pData && g_pNetworkMessages) {
        auto *serializer = pData->GetSerializerPB();
        if (serializer) {
            auto *info = serializer->GetNetMessageInfo();
            const char *msgName = serializer->GetUnscopedName();
            if (info && (info->m_MessageId == 1005 || (msgName && strstr(msgName, "ChatMsg")))) {
                int playerSlot = -1;

                // 1. Accurate slot resolution by comparing filter pointer on connected clients
                if (g_pNetworkServerService && g_pNetworkServerService->IsServerRunning()) {
                    auto *pNetServer = g_pNetworkServerService->GetNetworkServer();
                    if (pNetServer) {
                        for (int i = 0; i < ABSOLUTE_PLAYER_LIMIT; ++i) {
                            auto *c = pNetServer->GetClientBySlot(i);
                            if (c) {
                                if (static_cast<INetworkMessageProcessingPreFilter *>(c) == thisptr ||
                                    (pChannel && c->GetNetChannel() == pChannel)) {
                                    playerSlot = i;
                                    break;
                                }
                            }
                        }
                    }
                }

                // 2. Fallback to direct static_cast
                if (playerSlot < 0 || playerSlot >= ABSOLUTE_PLAYER_LIMIT) {
                    auto *client = static_cast<CServerSideClientBase *>(thisptr);
                    if (client) {
                        playerSlot = client->GetPlayerSlot().Get();
                    }
                }

                auto *pb = pData->AsMessageLite();
                if (pb) {
                    int size = static_cast<int>(pb->ByteSizeLong());
                    if (size > 0 && size < 65536) {
                        std::vector<uint8_t> buf(size);
                        if (pb->SerializeToArray(buf.data(), size)) {
                            std::string chatText;
                            if (ExtractChatText(buf.data(), size, chatText)) {
                                Logger::Debug("Detour_FilterMessage: Captured ChatMsg from slot {}: '{}'", playerSlot, chatText);
                                if (DispatchChatCommand(playerSlot, chatText)) {
                                    // Handled as a command callback! Suppress from public chat
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    s_bInFilterMessage = true;
    bool ret = g_FilterMessageHook.thiscall<bool>(thisptr, pData, pChannel);
    s_bInFilterMessage = false;
    return ret;
}

// Detour: CCitadelPlayerController::ClientConCommand (Universal Command Dispatcher)
static thread_local bool s_bInClientConCommand = false;
static bool __fastcall Detour_ClientConCommand(void *controller, const CCommand &args) {
    if (s_bInClientConCommand) {
        return g_ClientConCommandHook.thiscall<bool>(controller, args);
    }

    if (controller && args.ArgC() > 0) {
        auto *entity = reinterpret_cast<CEntityInstance *>(controller);
        int playerSlot = entity->GetRefEHandle().GetEntryIndex() - 1;

        std::string firstArg = args.Arg(0);
        // Intercept player chat commands (e.g. say "!command" or say_team "/command")
        if ((firstArg == "say" || firstArg == "say_team") && args.ArgC() >= 2) {
            std::string chatText = args.Arg(1);
            if (DispatchChatCommand(playerSlot, chatText)) {
                return true;
            }
        } else {
            // Direct client console command (e.g. typed in '~' developer console)
            if (DispatchCommand(playerSlot, args)) {
                return true;
            }
        }
    }

    s_bInClientConCommand = true;
    bool ret = g_ClientConCommandHook.thiscall<bool>(controller, args);
    s_bInClientConCommand = false;
    return ret;
}

// Detour: CBasePlayerController::SetPawn
static void __fastcall Detour_SetPawn(void *controller, void *pawn, bool bRetainOldPawnTeam, bool bCopyMovementState, bool bAllowTeamMismatch, bool bPreserveMovementState) {
    auto *pController = reinterpret_cast<CEntityInstance *>(controller);
    int oldPawn = 0;
    static const int kCtrl_hPawn = schema::GetOffset(
        "CBasePlayerController", hash_32_fnv1a_const("CBasePlayerController"),
        "m_hPawn", hash_32_fnv1a_const("m_hPawn")).Offset;
    if (kCtrl_hPawn > 0 && controller) {
        oldPawn = *reinterpret_cast<int *>(reinterpret_cast<uintptr_t>(controller) + kCtrl_hPawn);
    }

    g_SetPawnHook.call<void>(controller, pawn, bRetainOldPawnTeam, bCopyMovementState, bAllowTeamMismatch, bPreserveMovementState);

    if (kCtrl_hPawn > 0 && controller && g_pNetworkServerService) {
        int newPawn = *reinterpret_cast<int *>(reinterpret_cast<uintptr_t>(controller) + kCtrl_hPawn);
        if (newPawn != 0 && newPawn != -1 && newPawn != oldPawn) {
            auto *server = g_pNetworkServerService->GetIGameServer();
            if (server && pController) {
                int slot = pController->GetEntityIndex().Get() - 1;
                auto *client = server->GetClientBySlot(CPlayerSlot(slot));
                if (client && !client->IsFakeClient() && !client->IsHLTV() && client->IsInGame()) {
                    client->m_nDeltaTick = -1;
                    client->m_nHltvReplayDeltaTick = -1;
                    client->m_nForceWaitForTick = -1;
                }
            }
        }
    }
}

// Detour: CCitadelPlayerPawn::ModifyCurrency
static thread_local bool s_bInModifyCurrency = false;
static void __fastcall Detour_ModifyCurrency(void *thisptr, uint32_t currencyType, int32_t amount,
                                             uint32_t source, int32_t bSilent, int32_t bForceGain, int32_t bSpendOnly,
                                             void *pSourceAbility, void *pSourceEntity) {
    if (s_bInModifyCurrency) {
        g_ModifyCurrencyHook.thiscall<void>(thisptr, currencyType, amount, source, bSilent, bForceGain, bSpendOnly, pSourceAbility, pSourceEntity);
        return;
    }

    s_bInModifyCurrency = true;
    int32_t result = g_ModifyCurrencyListeners.DispatchWithResult<int32_t>(
        0,
        reinterpret_cast<int64_t>(thisptr),
        currencyType,
        amount,
        source,
        bSilent != 0,
        bForceGain != 0,
        bSpendOnly != 0,
        reinterpret_cast<int64_t>(pSourceAbility),
        reinterpret_cast<int64_t>(pSourceEntity)
    );
    s_bInModifyCurrency = false;

    // If Handled (2) or Stop (3), block the original function call
    if (result >= static_cast<int32_t>(HookResult::Handled)) {
        return;
    }

    g_ModifyCurrencyHook.thiscall<void>(thisptr, currencyType, amount, source, bSilent, bForceGain, bSpendOnly, pSourceAbility, pSourceEntity);
}

// Detour: CBaseEntity::TakeDamageOld
static thread_local bool s_bInTakeDamage = false;
static void __fastcall Detour_TakeDamageOld(void *entity, void *info, void *result) {
    if (s_bInTakeDamage) {
        g_TakeDamageHook.thiscall<void>(entity, info, result);
        return;
    }

    s_bInTakeDamage = true;
    int32_t hookRes = g_TakeDamageListeners.DispatchWithResult<int32_t>(
        0,
        reinterpret_cast<int64_t>(entity),
        reinterpret_cast<int64_t>(info)
    );
    s_bInTakeDamage = false;

    if (hookRes >= static_cast<int32_t>(HookResult::Handled)) {
        return;
    }

    g_TakeDamageHook.thiscall<void>(entity, info, result);
}

// Detour: CCitadelGameRules::ChangeGameState
static void __fastcall Detour_ChangeGameState(void *gameRules, int32_t newState) {
    g_pGameRules = gameRules;
    g_GameStateChangedListeners.Dispatch(newState);
    g_ChangeGameStateHook.call<void>(gameRules, newState);
}

// Detour: TraceShape
static void __fastcall Detour_TraceShape(void *pPhysQuery, void *ray, void *start, void *end, void *filter, void *traceOutput) {
    if (!g_pPhysicsQuery && pPhysQuery) {
        g_pPhysicsQuery = pPhysQuery;
    }
    g_TraceShapeHook.call<void>(pPhysQuery, ray, start, end, filter, traceOutput);
}

// Detour: CAI_BaseNPC::GetNewSchedule
static void *__fastcall Detour_GetNewSchedule(void *npc, void **outSchedule, const char **outName, const char **outId) {
    void *schedule = g_GetNewScheduleHook.call<void *>(npc, outSchedule, outName, outId);

    if (!g_NpcSelectScheduleListeners.Empty() && outId && *outId) {
        plg::string chosen(*outId);
        auto newSched = g_NpcSelectScheduleListeners.DispatchWithResult<plg::string>(
            chosen,
            reinterpret_cast<int64_t>(npc),
            chosen
        );
    }

    return schedule;
}

// Detour: CBasePlayerController::ProcessUsercmds
static void *__fastcall Detour_ProcessUsercmds(void *pController, void *cmds, int numcmds, unsigned char paused, float margin) {
    if (pController && numcmds > 0) {
        auto *entity = reinterpret_cast<CEntityInstance *>(pController);
        int slot = entity->GetRefEHandle().GetEntryIndex() - 1;
        if (slot >= 0 && slot < 64) {
            g_ProcessUsercmdsListeners.Dispatch(slot, numcmds, paused != 0);
        }
    }
    return g_ProcessUsercmdsHook.thiscall<void *>(pController, cmds, numcmds, paused, margin);
}

// Detour: CCitadelPlayerPawn::AbilityThink
static void __fastcall Detour_AbilityThink(void *pPawn) {
    if (pPawn) {
        g_AbilityThinkListeners.Dispatch(-1, reinterpret_cast<int64_t>(pPawn));
    }
    g_AbilityThinkHook.call<void>(pPawn);
}

// Detour: CModifierProperty::AddModifier
static void *__fastcall Detour_AddModifier(void *thisptr, void *pCaster, uint32_t hAbility, int iTeam, void *vdata, void *pParams, void *pKV) {
    int32_t res = g_AddModifierListeners.DispatchWithResult<int32_t>(
        0,
        reinterpret_cast<int64_t>(thisptr),
        reinterpret_cast<int64_t>(pCaster),
        hAbility,
        iTeam
    );
    if (res >= static_cast<int32_t>(HookResult::Handled)) {
        return nullptr;
    }
    return g_AddModifierHook.thiscall<void *>(thisptr, pCaster, hAbility, iTeam, vdata, pParams, pKV);
}

// Detour: CEntityInstance::AcceptInput
static bool __fastcall Detour_AcceptInput(CEntityInstance *thisptr, const char *inputName, CEntityInstance *activator, CEntityInstance *caller, void *variantValue) {
    const char *className = thisptr ? thisptr->GetClassname() : "";
    int32_t res = g_EntityAcceptInputListeners.DispatchWithResult<int32_t>(
        0,
        plg::string(className ? className : ""),
        plg::string(inputName ? inputName : ""),
        reinterpret_cast<int64_t>(thisptr),
        reinterpret_cast<int64_t>(activator),
        reinterpret_cast<int64_t>(caller),
        plg::string("")
    );
    if (res >= static_cast<int32_t>(HookResult::Handled)) {
        return true;
    }
    return g_AcceptInputHook.call<bool>(thisptr, inputName, activator, caller, variantValue);
}

// Detour: CEntityIOOutput::FireOutputInternal
static void __fastcall Detour_FireOutputInternal(void *pThis, CEntityInstance *pActivator, CEntityInstance *pCaller, const void *pParams, float delay, void *unk, const void *pValue) {
    const char *callerClass = pCaller ? pCaller->GetClassname() : "";
    int32_t res = g_EntityOutputListeners.DispatchWithResult<int32_t>(
        0,
        plg::string(callerClass ? callerClass : ""),
        plg::string(""),
        reinterpret_cast<int64_t>(pActivator),
        reinterpret_cast<int64_t>(pCaller),
        delay
    );
    if (res >= static_cast<int32_t>(HookResult::Handled)) {
        return;
    }
    g_FireOutputInternalHook.call<void>(pThis, pActivator, pCaller, pParams, delay, unk, pValue);
}

// Detour: CCitadelPlayerPawn::InitializeHeroOnPawn
static __int64 __fastcall Detour_InitializeHeroOnPawn(void *pPawn, char bWipeItems) {
    if (pPawn && !PawnHasLiveController(pPawn)) {
        Logger::Warning("InitializeHeroOnPawn skipped: pawn {:p} has no live controller (m_hController is stale)", pPawn);
        return 0;
    }

    auto result = g_InitializeHeroOnPawnHook.thiscall<__int64>(pPawn, bWipeItems);
    if (pPawn) {
        g_HeroInitializedListeners.Dispatch(reinterpret_cast<int64_t>(pPawn));
    }
    return result;
}

// Detour: CCitadelPlayerPawn::SelectHeroInternal
static void __fastcall Detour_SelectHeroInternal(void *pPawn, void *pHeroDef) {
    if (pPawn && !PawnHasLiveController(pPawn)) {
        Logger::Warning("SelectHeroInternal skipped: pawn {:p} has no live controller (m_hController is stale)", pPawn);
        return;
    }

    g_SelectHeroInternalHook.thiscall<void>(pPawn, pHeroDef);
}

// Detour: CCitadelServerGCSystem::Init
static bool __fastcall Detour_ServerGCSystemInit(void *gcSystem) {
    const bool result = g_ServerGCSystemInitHook.call<bool>(gcSystem);
    // Unix time of the maximum-uptime shutdown; 0 means none. Prevents server auto-shutdown!
    constexpr uintptr_t kServerGCSystem_MaxUptimeShutdownTime = 0x430;
    if (gcSystem) {
        *reinterpret_cast<uint32_t *>(reinterpret_cast<uintptr_t>(gcSystem) + kServerGCSystem_MaxUptimeShutdownTime) = 0;
    }
    return result;
}

// Detour: CGCClientSystem::OnServerVersionCheck
static bool __fastcall Detour_ServerVersionCheck(void *a1, int a2) {
    return true;
}

// ----------------------------------------------------------------------------
// Helper Hook Registrations
// ----------------------------------------------------------------------------

bool HookManager::HookSignature(safetyhook::InlineHook &hook, const std::string &sigName, void *detour) {
    auto offset = MemoryDataLoader::Get().GetOffset(sigName);
    if (!offset.has_value()) {
        Logger::Warning("Hook skipped: signature '{}' not resolved", sigName);
        return false;
    }

    auto target = reinterpret_cast<void *>(*offset);
    hook = safetyhook::create_inline(target, detour);
    if (!hook) {
        Logger::Error("Failed to hook '{}'", sigName);
        return false;
    }

    Logger::Debug("Installed inline hook for '{}'", sigName);
    return true;
}

static bool HookVmtMethod(safetyhook::VmtHook &vmt, safetyhook::VmHook &hook, const std::string &virtualName, int defaultIndex, void *detour) {
    int index = defaultIndex;
    auto optIdx = MemoryDataLoader::Get().GetVirtual(virtualName);
    if (optIdx.has_value()) {
        index = *optIdx;
    }

    auto res = vmt.hook_method(index, detour);
    if (!res) {
        Logger::Error("Failed to hook VMT method '{}' (index {})", virtualName, index);
        return false;
    }

    hook = std::move(*res);
    Logger::Debug("Installed VMT hook for '{}' (index {})", virtualName, index);
    return true;
}

bool HookManager::InstallHooks() {
    Logger::Debug("Installing Deadlock SDK engine hooks...");

    // 1. ISource2GameClients hooks
    if (g_pSource2GameClients && Settings::Get().GetBool("features.enable_client_hooks", true)) {
        auto vmtRes = safetyhook::VmtHook::create(g_pSource2GameClients);
        if (vmtRes) {
            g_VmtGameClients = std::move(*vmtRes);
            HookVmtMethod(g_VmtGameClients, g_ClientConnectHook, "ISource2GameClients::ClientConnect", 12, reinterpret_cast<void *>(&Detour_ClientConnect));
            HookVmtMethod(g_VmtGameClients, g_ClientPutInServerHook, "ISource2GameClients::ClientPutInServer", 13, reinterpret_cast<void *>(&Detour_ClientPutInServer));
            HookVmtMethod(g_VmtGameClients, g_ClientDisconnectHook, "ISource2GameClients::ClientDisconnect", 16, reinterpret_cast<void *>(&Detour_ClientDisconnect));
        } else {
            Logger::Error("Failed to create VMT hook for ISource2GameClients");
        }
    }

    // 2. ISource2Server hooks
    if (g_pSource2Server && Settings::Get().GetBool("features.enable_server_hooks", true)) {
        auto vmtRes = safetyhook::VmtHook::create(g_pSource2Server);
        if (vmtRes) {
            g_VmtSource2Server = std::move(*vmtRes);
            HookVmtMethod(g_VmtSource2Server, g_ApplyGameSettingsHook, "ISource2Server::ApplyGameSettings", 18, reinterpret_cast<void *>(&Detour_ApplyGameSettings));
            HookVmtMethod(g_VmtSource2Server, g_GameFrameHook, "ISource2Server::GameFrame", 19, reinterpret_cast<void *>(&Detour_GameFrame));
        } else {
            Logger::Error("Failed to create VMT hook for ISource2Server");
        }
    }

    // 3. INetworkServerService hooks
    if (g_pNetworkServerService && Settings::Get().GetBool("features.enable_server_hooks", true)) {
        auto vmtRes = safetyhook::VmtHook::create(g_pNetworkServerService);
        if (vmtRes) {
            g_VmtNetworkServerService = std::move(*vmtRes);
            HookVmtMethod(g_VmtNetworkServerService, g_StartupServerHook, "INetworkServerService::StartupServer", 26, reinterpret_cast<void *>(&Detour_StartupServer));
        } else {
            Logger::Error("Failed to create VMT hook for INetworkServerService");
        }
    }

    // 4. Inline Detour hooks
    HookSignature(g_FilterMessageHook, "CServerSideClientBase::FilterMessage", reinterpret_cast<void *>(&Detour_FilterMessage));
    if (Settings::Get().GetBool("features.enable_currency_hooks", true)) {
        HookSignature(g_ModifyCurrencyHook, "CCitadelPlayerPawn::ModifyCurrency", reinterpret_cast<void *>(&Detour_ModifyCurrency));
    }
    if (Settings::Get().GetBool("features.enable_damage_hooks", true)) {
        HookSignature(g_TakeDamageHook, "CBaseEntity::TakeDamageOld", reinterpret_cast<void *>(&Detour_TakeDamageOld));
    }
    if (Settings::Get().GetBool("features.enable_game_state_hooks", true)) {
        HookSignature(g_ChangeGameStateHook, "CCitadelGameRules::ChangeGameState", reinterpret_cast<void *>(&Detour_ChangeGameState));
    }
    if (Settings::Get().GetBool("features.enable_npc_schedule_hooks", true)) {
        HookSignature(g_GetNewScheduleHook, "CAI_BaseNPC::GetNewSchedule", reinterpret_cast<void *>(&Detour_GetNewSchedule));
    }
    HookSignature(g_ClientConCommandHook, "CCitadelPlayerController::ClientConCommand", reinterpret_cast<void *>(&Detour_ClientConCommand));
    HookSignature(g_SetPawnHook, "CBasePlayerController::SetPawn", reinterpret_cast<void *>(&Detour_SetPawn));

    if (Settings::Get().GetBool("features.enable_usercmd_hooks", true)) {
        HookSignature(g_ProcessUsercmdsHook, "CBasePlayerController::ProcessUsercmds", reinterpret_cast<void *>(&Detour_ProcessUsercmds));
    }
    if (Settings::Get().GetBool("features.enable_ability_think_hooks", true)) {
        HookSignature(g_AbilityThinkHook, "CCitadelPlayerPawn::AbilityThink", reinterpret_cast<void *>(&Detour_AbilityThink));
    }
    if (Settings::Get().GetBool("features.enable_modifier_hooks", true)) {
        HookSignature(g_AddModifierHook, "CModifierProperty::AddModifier", reinterpret_cast<void *>(&Detour_AddModifier));
    }
    if (Settings::Get().GetBool("features.enable_entity_io_hooks", true)) {
        HookSignature(g_AcceptInputHook, "CEntityInstance::AcceptInput", reinterpret_cast<void *>(&Detour_AcceptInput));
        HookSignature(g_FireOutputInternalHook, "CEntityIOOutput::FireOutputInternal", reinterpret_cast<void *>(&Detour_FireOutputInternal));
    }

    // Hero lifecycle & safety guards
    HookSignature(g_InitializeHeroOnPawnHook, "CCitadelPlayerPawn::InitializeHeroOnPawn", reinterpret_cast<void *>(&Detour_InitializeHeroOnPawn));
    HookSignature(g_SelectHeroInternalHook, "CCitadelPlayerPawn::SelectHeroInternal", reinterpret_cast<void *>(&Detour_SelectHeroInternal));

    // Server stability & GC hooks
    HookSignature(g_ServerGCSystemInitHook, "CCitadelServerGCSystem::Init", reinterpret_cast<void *>(&Detour_ServerGCSystemInit));
    HookSignature(g_ServerVersionCheckHook, "CGCClientSystem::OnServerVersionCheck", reinterpret_cast<void *>(&Detour_ServerVersionCheck));
    HookSignature(g_TraceShapeHook, "TraceShape", reinterpret_cast<void *>(&Detour_TraceShape));

    auto *pEntitySys = GameEntitySystem();
    if (pEntitySys) {
        pEntitySys->AddListenerEntity(&g_EntityListener);
        Logger::Debug("Registered CEntityListener with GameEntitySystem");
    }

    return true;
}

void HookManager::UninstallHooks() {
    Logger::Debug("Uninstalling Deadlock SDK engine hooks...");
    g_ClientConnectHook.reset();
    g_ClientPutInServerHook.reset();
    g_ClientDisconnectHook.reset();
    g_VmtGameClients.reset();

    g_GameFrameHook.reset();
    g_ApplyGameSettingsHook.reset();
    g_VmtSource2Server.reset();

    g_StartupServerHook.reset();
    g_VmtNetworkServerService.reset();

    g_FilterMessageHook.reset();
    g_ModifyCurrencyHook.reset();
    g_TakeDamageHook.reset();
    g_ChangeGameStateHook.reset();
    g_GetNewScheduleHook.reset();
    g_SetPawnHook.reset();
    g_ProcessUsercmdsHook.reset();
    g_AbilityThinkHook.reset();
    g_AddModifierHook.reset();
    g_AcceptInputHook.reset();
    g_FireOutputInternalHook.reset();
    g_InitializeHeroOnPawnHook.reset();
    g_SelectHeroInternalHook.reset();
    g_ServerGCSystemInitHook.reset();
    g_ServerVersionCheckHook.reset();
    g_TraceShapeHook.reset();

    auto *pEntitySys = GameEntitySystem();
    if (pEntitySys) {
        pEntitySys->RemoveListenerEntity(&g_EntityListener);
    }
}

} // namespace dsdk
