#include "pch.hpp"
#include "core/memory/data_loader.hpp"
#include "core/logger.hpp"
#include "core/globals.hpp"
#include "core/sdk/Core.hpp"
#include "core/sdk/schema/Schema.hpp"
#include "core/sdk/CCitadelPlayerPawn.hpp"
#include <entityinstance.h>
#include <entity2/entitysystem.h>
#include <mathlib/vector.h>

using CreateBotByHeroNameFn = void *(__fastcall *)(void *gameRules, const char *heroName, int32_t team, const Vector *position);
using AssignBotLaneFn = void(__fastcall *)(void *gameRules, int32_t team, void *pawn);
using BotSetLaneFn = void(__fastcall *)(void *bot, int32_t lane);

static void *GetCitadelGameRules() {
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

PLUGIN_API int64_t BotCreate(const plg::string &heroName, int32_t team,
                             float posX, float posY, float posZ, bool assignLane) {
    void *gameRules = GetCitadelGameRules();
    if (!gameRules || heroName.empty()) return 0;

    auto createOpt = dsdk::MemoryDataLoader::Get().GetOffset("CCitadelGameRules::CreateBotByHeroName");
    if (!createOpt.has_value()) return 0;
    auto createFn = reinterpret_cast<CreateBotByHeroNameFn>(*createOpt);

    Vector pos(posX, posY, posZ);
    void *pawn = createFn(gameRules, heroName.c_str(), team, &pos);
    if (pawn && assignLane) {
        auto assignOpt = dsdk::MemoryDataLoader::Get().GetOffset("CCitadelGameRules::AssignBotLane");
        if (assignOpt.has_value()) {
            auto assignFn = reinterpret_cast<AssignBotLaneFn>(*assignOpt);
            assignFn(gameRules, team, pawn);
        }
    }
    return reinterpret_cast<int64_t>(pawn);
}

PLUGIN_API int64_t BotGetBrain(int64_t pawn) {
    if (!pawn) return 0;
    auto *pPawn = reinterpret_cast<CCitadelPlayerPawn *>(pawn);
    auto *bot = static_cast<uint8_t *>(pPawn->m_pBot.Get());
    if (!bot) return 0;
    return reinterpret_cast<int64_t>(*reinterpret_cast<void **>(bot + 0x4B90));
}

PLUGIN_API int64_t BotGetPawn(int64_t brain) {
    if (!brain) return 0;
    return reinterpret_cast<int64_t>(*reinterpret_cast<void **>(reinterpret_cast<uint8_t *>(brain) + 0x1868));
}

PLUGIN_API bool BotSetLane(int64_t pawn, int32_t lane) {
    if (!pawn) return false;
    auto *pPawn = reinterpret_cast<CCitadelPlayerPawn *>(pawn);
    auto *bot = static_cast<uint8_t *>(pPawn->m_pBot.Get());
    if (!bot) return false;
    auto setLaneOpt = dsdk::MemoryDataLoader::Get().GetOffset("CCitadelPlayerBot::SetLane");
    if (!setLaneOpt.has_value()) return false;
    auto fn = reinterpret_cast<BotSetLaneFn>(*setLaneOpt);
    fn(bot, lane);
    return true;
}

PLUGIN_API int32_t BotGetLane(int64_t pawn) {
    if (!pawn) return 0;
    auto *pPawn = reinterpret_cast<CCitadelPlayerPawn *>(pawn);
    auto *bot = static_cast<uint8_t *>(pPawn->m_pBot.Get());
    return bot ? *reinterpret_cast<int32_t *>(bot + 0x4994) : 0;
}

}
