#include "pch.hpp"
#include "core/memory/data_loader.hpp"
#include "core/logger.hpp"
#include "core/globals.hpp"
#include "core/sdk/Core.hpp"
#include "core/sdk/schema/Schema.hpp"
#include <entityinstance.h>
#include <entity2/entitysystem.h>

using ChangeGameStateFn = void(__fastcall *)(void *rules, int32_t state);

static bool g_MatchStartOnAnyMap = false;

static void *GetGameRulesInstance() {
    if (dsdk::g_pGameRules) return dsdk::g_pGameRules;
    auto *sys = GameEntitySystem();
    if (!sys) return nullptr;
    static int s_offset = -1;
    if (s_offset == -1) {
        s_offset = schema::GetOffset("CCitadelGameRulesProxy", hash_32_fnv1a_const("CCitadelGameRulesProxy"),
                                     "m_pGameRules", hash_32_fnv1a_const("m_pGameRules")).Offset;
    }
    for (int i = 1; i <= 2048; ++i) {
        auto *inst = sys->GetEntityInstance(CEntityIndex(i));
        if (!inst || !inst->m_pEntity) continue;
        const char *name = inst->m_pEntity->GetClassname();
        if (name && strcmp(name, "citadel_gamerules") == 0) {
            if (s_offset > 0) {
                return *reinterpret_cast<void **>(reinterpret_cast<uintptr_t>(inst) + s_offset);
            }
            return inst;
        }
    }
    return nullptr;
}

extern "C" {

PLUGIN_API int32_t GetGameState() {
    void *rules = GetGameRulesInstance();
    if (rules) {
        static int s_stateOffset = -1;
        if (s_stateOffset == -1) {
            s_stateOffset = schema::GetOffset("CCitadelGameRules", hash_32_fnv1a_const("CCitadelGameRules"),
                                              "m_eGameState", hash_32_fnv1a_const("m_eGameState")).Offset;
        }
        if (s_stateOffset > 0) {
            return *reinterpret_cast<int32_t *>(reinterpret_cast<uintptr_t>(rules) + s_stateOffset);
        }
    }
    return 7; // GameInProgress fallback
}

PLUGIN_API void ChangeGameState(int32_t newState) {
    void *rules = GetGameRulesInstance();
    if (!rules) return;
    auto offset = dsdk::MemoryDataLoader::Get().GetOffset("CCitadelGameRules::ChangeGameState");
    if (offset.has_value()) {
        auto fn = reinterpret_cast<ChangeGameStateFn>(*offset);
        fn(rules, newState);
    }
}

PLUGIN_API void SetWaitingForPlayersRoster(uint32_t readyCount, uint32_t totalCount) {
    dsdk::Logger::Debug("SetWaitingForPlayersRoster: {}/{}", readyCount, totalCount);
}

PLUGIN_API void SetMatchStartOnAnyMap(bool enabled) {
    g_MatchStartOnAnyMap = enabled;
}

PLUGIN_API bool GetMatchStartOnAnyMap() {
    return g_MatchStartOnAnyMap;
}

}
