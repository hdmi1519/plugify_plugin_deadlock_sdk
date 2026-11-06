#include "pch.hpp"
#include "core/memory/data_loader.hpp"
#include "core/memory/virtual.hpp"
#include "core/globals.hpp"
#include "core/logger.hpp"
#include "core/sdk/Core.hpp"
#include "core/sdk/CCitadelPlayerController.hpp"
#include "core/sdk/CCitadelPlayerPawn.hpp"
#include <eiface.h>
#include <inetchannelinfo.h>

extern "C" {

PLUGIN_API int64_t GetPlayerController(int32_t playerSlot) {
    auto *inst = GameEntitySystem()->GetEntityInstance(CEntityIndex(playerSlot + 1));
    return reinterpret_cast<int64_t>(inst);
}

PLUGIN_API int64_t GetPlayerPawn(int32_t playerSlot) {
    auto *inst = GameEntitySystem()->GetEntityInstance(CEntityIndex(playerSlot + 1));
    if (!inst) return 0;
    auto *controller = static_cast<CCitadelPlayerController *>(inst);
    auto *pawn = controller->GetHeroPawn();
    return reinterpret_cast<int64_t>(pawn);
}

PLUGIN_API int32_t GetPlayerSlot(int64_t controller) {
    if (!controller) return -1;
    auto *ent = reinterpret_cast<CBaseEntity *>(controller);
    return ent->GetEntityIndex().Get() - 1;
}

PLUGIN_API plg::string GetPlayerName(int32_t playerSlot) {
    if (dsdk::g_pEngineServer) {
        const char *name = dsdk::g_pEngineServer->GetClientConVarValue(CPlayerSlot(playerSlot), "name");
        if (name && *name) return plg::string(name);
    }
    return plg::string("Player");
}

PLUGIN_API uint64_t GetSteamID(int32_t playerSlot) {
    auto *inst = GameEntitySystem()->GetEntityInstance(CEntityIndex(playerSlot + 1));
    if (!inst) return 0;
    auto *controller = static_cast<CBasePlayerController *>(inst);
    return controller->m_steamID.Get();
}

PLUGIN_API bool IsClientAuthenticated(int32_t playerSlot) {
    return GetSteamID(playerSlot) != 0;
}

PLUGIN_API bool IsClientConnected(int32_t playerSlot) {
    auto *inst = GameEntitySystem()->GetEntityInstance(CEntityIndex(playerSlot + 1));
    if (!inst) return false;
    auto *controller = static_cast<CBasePlayerController *>(inst);
    return controller->m_iConnected.Get() > 0;
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
    if (dsdk::g_pEngineServer) {
        dsdk::g_pEngineServer->DisconnectClient(CPlayerSlot(playerSlot), static_cast<ENetworkDisconnectionReason>(reason));
    }
}

PLUGIN_API void KickClient(int32_t playerSlot, const plg::string &reason, int32_t code) {
    if (dsdk::g_pEngineServer) {
        dsdk::g_pEngineServer->KickClient(CPlayerSlot(playerSlot), reason.c_str(), static_cast<ENetworkDisconnectionReason>(code));
    }
}

PLUGIN_API void ChangeTeam(int64_t controller, int32_t teamNum, bool keepHero) {
    if (!controller) return;
    auto changeTeamOpt = dsdk::MemoryDataLoader::Get().GetVirtual("CBaseEntity::ChangeTeam");
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
    if (dsdk::g_pEngineServer) {
        auto *info = dsdk::g_pEngineServer->GetPlayerNetInfo(CPlayerSlot(playerSlot));
        if (info) {
            return static_cast<int32_t>(info->GetAvgLatency() * 1000.0f);
        }
    }
    return 0;
}

}
