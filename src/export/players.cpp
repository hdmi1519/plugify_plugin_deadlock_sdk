#include "pch.hpp"
#include "core/memory/data_loader.hpp"
#include "core/memory/virtual.hpp"
#include "core/globals.hpp"
#include "core/logger.hpp"
#include "core/sdk/Core.hpp"
#include "core/sdk/CCitadelPlayerController.hpp"
#include "core/sdk/CCitadelPlayerPawn.hpp"
#include "core/sdk/schema/Schema.hpp"
#include <eiface.h>
#include <inetchannelinfo.h>
#include <entity2/entityclass.h>
#include <server_class.h>

static CCitadelPlayerController *GetValidPlayerController(int32_t playerSlot) {
    if (playerSlot < 0 || playerSlot >= 64) {
        return nullptr;
    }
    auto *sys = GameEntitySystem();
    if (!sys) {
        return nullptr;
    }
    auto *inst = sys->GetEntityInstance(CEntityIndex(playerSlot + 1));
    if (!inst || !inst->m_pEntity) {
        return nullptr;
    }
    if (!inst->m_pEntity->m_pClass || !inst->m_pEntity->m_pClass->m_pServerClass) {
        return nullptr;
    }
    const char *className = inst->m_pEntity->m_pClass->m_pServerClass->m_pDLLClassName;
    if (!className || !*className) {
        return nullptr;
    }
    if (strcmp(className, "CCitadelPlayerController") != 0 &&
        !schema::IsDerivedFrom(className, "CBasePlayerController")) {
        return nullptr;
    }
    return static_cast<CCitadelPlayerController *>(inst);
}

static bool IsValidPlayerController(int64_t controller) {
    if (!controller) return false;
    auto *inst = reinterpret_cast<CEntityInstance *>(controller);
    if (!inst || !inst->m_pEntity) return false;
    if (!inst->m_pEntity->m_pClass || !inst->m_pEntity->m_pClass->m_pServerClass) return false;
    const char *className = inst->m_pEntity->m_pClass->m_pServerClass->m_pDLLClassName;
    if (!className || !*className) return false;
    return strcmp(className, "CCitadelPlayerController") == 0 ||
           schema::IsDerivedFrom(className, "CBasePlayerController");
}

extern "C" {

PLUGIN_API int64_t GetPlayerController(int32_t playerSlot) {
    auto *controller = GetValidPlayerController(playerSlot);
    return reinterpret_cast<int64_t>(controller);
}

PLUGIN_API int64_t GetPlayerPawn(int32_t playerSlot) {
    auto *controller = GetValidPlayerController(playerSlot);
    if (!controller) return 0;
    auto *pawn = controller->GetHeroPawn();
    return reinterpret_cast<int64_t>(pawn);
}

PLUGIN_API int32_t GetPlayerSlot(int64_t controller) {
    if (!IsValidPlayerController(controller)) return -1;
    auto *ent = reinterpret_cast<CBaseEntity *>(controller);
    int32_t slot = ent->GetEntityIndex().Get() - 1;
    if (slot < 0 || slot >= 64) return -1;
    return slot;
}

PLUGIN_API plg::string GetPlayerName(int32_t playerSlot) {
    auto *controller = GetValidPlayerController(playerSlot);
    if (!controller || !controller->IsConnected()) {
        return plg::string("");
    }

    static int s_nameOffset = -1;
    if (s_nameOffset == -1) {
        s_nameOffset = schema::GetOffset("CBasePlayerController", hash_32_fnv1a_const("CBasePlayerController"),
                                         "m_iszPlayerName", hash_32_fnv1a_const("m_iszPlayerName")).Offset;
    }
    if (s_nameOffset > 0) {
        const char *name = reinterpret_cast<const char *>(reinterpret_cast<uintptr_t>(controller) + s_nameOffset);
        if (name && *name) return plg::string(name);
    }

    if (dsdk::g_pEngineServer) {
        const char *name = dsdk::g_pEngineServer->GetClientConVarValue(CPlayerSlot(playerSlot), "name");
        if (name && *name) return plg::string(name);
    }

    return plg::string("Player");
}

PLUGIN_API uint64_t GetSteamID(int32_t playerSlot) {
    auto *controller = GetValidPlayerController(playerSlot);
    if (!controller || !controller->IsConnected()) return 0;
    return controller->m_steamID.Get();
}

PLUGIN_API bool IsClientAuthenticated(int32_t playerSlot) {
    return GetSteamID(playerSlot) != 0;
}

PLUGIN_API bool IsClientConnected(int32_t playerSlot) {
    auto *controller = GetValidPlayerController(playerSlot);
    if (!controller) return false;
    return controller->IsConnected();
}

PLUGIN_API bool IsFakeClient(int32_t playerSlot) {
    if (!IsClientConnected(playerSlot)) return false;
    return GetSteamID(playerSlot) == 0;
}

PLUGIN_API int32_t CreateFakeClient(const plg::string &name) {
    if (dsdk::g_pEngineServer) {
        return dsdk::g_pEngineServer->CreateFakeClient(name.c_str()).Get();
    }
    return -1;
}

PLUGIN_API void DisconnectClient(int32_t playerSlot, int32_t reason) {
    if (playerSlot < 0 || playerSlot >= 64) return;
    if (dsdk::g_pEngineServer) {
        dsdk::g_pEngineServer->DisconnectClient(CPlayerSlot(playerSlot), static_cast<ENetworkDisconnectionReason>(reason));
    }
}

PLUGIN_API void KickClient(int32_t playerSlot, const plg::string &reason, int32_t code) {
    if (playerSlot < 0 || playerSlot >= 64) return;
    if (dsdk::g_pEngineServer) {
        dsdk::g_pEngineServer->KickClient(CPlayerSlot(playerSlot), reason.c_str(), static_cast<ENetworkDisconnectionReason>(code));
    }
}

PLUGIN_API void ChangeTeam(int64_t controller, int32_t teamNum, bool keepHero) {
    if (!IsValidPlayerController(controller)) return;
    auto changeTeamOpt = dsdk::MemoryDataLoader::Get().GetOffset("CBaseEntity::ChangeTeam");
    if (!changeTeamOpt.has_value()) return;

    auto changeTeamFn = dsdk::GetVirtual<void (*)(void *, int)>(reinterpret_cast<void *>(controller), *changeTeamOpt);
    if (!keepHero) {
        changeTeamFn(reinterpret_cast<void *>(controller), teamNum);
        return;
    }

    auto anchorOpt = dsdk::MemoryDataLoader::Get().GetOffset("CCitadelPlayerController::ChangeTeamKeepHero");
    if (anchorOpt.has_value()) {
        constexpr uintptr_t kChangeTeamKeepHero_FlagDisp = 0x18;
        const int32_t disp = *reinterpret_cast<const int32_t *>(*anchorOpt + kChangeTeamKeepHero_FlagDisp);
        if (disp > 0 && disp < 0x2000) {
            auto *pFlag = reinterpret_cast<uint8_t *>(static_cast<uintptr_t>(controller) + disp);
            uint8_t prev = *pFlag;
            *pFlag = 0;
            changeTeamFn(reinterpret_cast<void *>(controller), teamNum);
            *pFlag = prev;
            return;
        }
    }

    changeTeamFn(reinterpret_cast<void *>(controller), teamNum);
}

PLUGIN_API int32_t GetPlayerPing(int32_t playerSlot) {
    if (playerSlot < 0 || playerSlot >= 64) return 0;
    if (!IsClientConnected(playerSlot)) return 0;
    if (dsdk::g_pEngineServer) {
        auto *info = dsdk::g_pEngineServer->GetPlayerNetInfo(CPlayerSlot(playerSlot));
        if (info) {
            return static_cast<int32_t>(info->GetAvgLatency() * 1000.0f);
        }
    }
    return 0;
}

PLUGIN_API float GetPlayerTimeConnected(int32_t playerSlot) {
    if (playerSlot < 0 || playerSlot >= 64) return 0.0f;
    if (!IsClientConnected(playerSlot)) return 0.0f;
    if (dsdk::g_pEngineServer) {
        auto *info = dsdk::g_pEngineServer->GetPlayerNetInfo(CPlayerSlot(playerSlot));
        if (info) {
            return info->GetTimeConnected();
        }
    }
    return 0.0f;
}

}
