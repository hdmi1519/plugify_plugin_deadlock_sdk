#pragma once

#include <ehandle.h>

#include "Schema/Schema.hpp"
#include "CBaseEntity.hpp"
#include "CBasePlayerPawn.hpp"

#include "core/memory/data_loader.hpp"

enum class PlayerConnectedState : int32_t {
    PlayerNeverConnected = -1,
    PlayerConnected = 0,
    PlayerConnecting = 1,
    PlayerReconnecting = 2,
    PlayerDisconnecting = 3,
    PlayerDisconnected = 4,
    PlayerReserved = 5,
};

class CBasePlayerController : public CBaseEntity {
public:
    DECLARE_SCHEMA_CLASS(CBasePlayerController);
    SCHEMA_FIELD(CHandle<CBasePlayerPawn>, m_hPawn);
    SCHEMA_FIELD(uint64_t, m_steamID);
    SCHEMA_FIELD(PlayerConnectedState, m_iConnected);

    bool IsConnected() {
        return m_iConnected.Get() == PlayerConnectedState::PlayerConnected;
    }

    void SetPawn(CBasePlayerPawn *pPawn, bool bRetainOldPawnTeam, bool bCopyMovementState, bool bAllowTeamMismatch, bool bPreserveMovementState) {
        static const auto offset = dsdk::MemoryDataLoader::Get().GetOffset("CBasePlayerController::SetPawn").value();
        using SetPawnFn = void(__thiscall *)(CBasePlayerController *, CBasePlayerPawn *, bool, bool, bool, bool);
        return reinterpret_cast<SetPawnFn>(offset)(this, pPawn, bRetainOldPawnTeam, bCopyMovementState, bAllowTeamMismatch, bPreserveMovementState);
    }
};
