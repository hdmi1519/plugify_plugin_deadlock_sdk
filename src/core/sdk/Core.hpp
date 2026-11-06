#pragma once

#include <igameresourceservice.h>

extern IGameResourceService *g_pGameResourceServiceServer;

class CGameEntitySystem;
// must be defined in global scope
inline CGameEntitySystem *GameEntitySystem() {
    if (!g_pGameResourceServiceServer) return nullptr;
    return reinterpret_cast<CGameResourceService *>(g_pGameResourceServiceServer)->m_pEntitySystem;
}
