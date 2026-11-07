#include "pch.hpp"
#include "core/memory/data_loader.hpp"
#include "core/logger.hpp"
#include "core/sdk/CCitadelPlayerController.hpp"
#include "core/sdk/schema/Schema.hpp"

inline uintptr_t ResolveE8Call(uintptr_t callAddr) {
    int32_t rel = *reinterpret_cast<const int32_t *>(callAddr + 1);
    return callAddr + 5 + rel;
}

using GetHeroDataManagerFn = void *(*)();
using HeroNameToIdFn = int *(*)(void *manager, int *outId, const char *heroName);
using GetHeroByIdFn = void *(*)(void *manager, unsigned int heroId);
using CreateHeroPawnFn = void *(*)(void *controller, int teamNum);
using SelectHeroInternalFn = void (*)(void *pawn, void *heroDef);
using ResetHeroFn = void(__fastcall *)(void *pawn, bool reset);
using ForceRespawnFn = void(__fastcall *)(void *pawn, uint8_t releaseButtons);
using PrecacheHeroFn = void(__fastcall *)(void *globalSet, const char *heroName, void *resourceCtx);

static void *GetHeroDataManager() {
    auto anchor = dsdk::MemoryDataLoader::Get().GetOffset("CHeroDefinitionManager::GetManagerAnchor");
    if (!anchor.has_value()) return nullptr;
    auto fn = reinterpret_cast<GetHeroDataManagerFn>(ResolveE8Call(*anchor + 0xE));
    return fn ? fn() : nullptr;
}

static void *GetHeroDataPtr(const char *heroName) {
    if (!heroName) return nullptr;
    void *manager = GetHeroDataManager();
    if (!manager) return nullptr;

    auto nameToIdAddr = dsdk::MemoryDataLoader::Get().GetOffset("CHeroDefinitionManager::HeroNameToId");
    auto getByIdAddr = dsdk::MemoryDataLoader::Get().GetOffset("CHeroDefinitionManager::GetHeroById");
    if (!nameToIdAddr.has_value() || !getByIdAddr.has_value()) return nullptr;

    auto heroNameToId = reinterpret_cast<HeroNameToIdFn>(*nameToIdAddr);
    auto getHeroById = reinterpret_cast<GetHeroByIdFn>(*getByIdAddr);

    int heroId = 0;
    heroNameToId(manager, &heroId, heroName);
    if (heroId <= 0) return nullptr;

    return getHeroById(manager, static_cast<unsigned int>(heroId));
}

extern "C" {

PLUGIN_API void SelectHero(int64_t controller, const plg::string &heroName) {
    if (!controller) return;
    void *heroDef = GetHeroDataPtr(heroName.c_str());
    if (!heroDef) {
        dsdk::Logger::Warning("SelectHero: definition not found for '{}'", heroName.c_str());
        return;
    }

    auto *pCtrl = reinterpret_cast<CCitadelPlayerController *>(controller);
    void *pawn = pCtrl ? pCtrl->GetHeroPawn() : nullptr;
    if (!pawn) {
        auto createPawnAddr = dsdk::MemoryDataLoader::Get().GetOffset("CCitadelPlayerController::CreateHeroPawn");
        if (createPawnAddr.has_value()) {
            auto createPawn = reinterpret_cast<CreateHeroPawnFn>(*createPawnAddr);
            int teamNum = pCtrl ? pCtrl->m_iTeamNum.Get() : 2;
            pawn = createPawn(reinterpret_cast<void *>(controller), teamNum);
        }
    }
    if (!pawn) {
        dsdk::Logger::Warning("SelectHero: could not obtain pawn for controller {:p}", reinterpret_cast<void *>(controller));
        return;
    }

    auto selectInternalAddr = dsdk::MemoryDataLoader::Get().GetOffset("CCitadelPlayerPawn::SelectHeroInternal");
    if (selectInternalAddr.has_value()) {
        auto selectHeroInternal = reinterpret_cast<SelectHeroInternalFn>(*selectInternalAddr);
        selectHeroInternal(pawn, heroDef);
        dsdk::Logger::Debug("SelectHero: successfully switched to '{}'", heroName.c_str());
    }
}

PLUGIN_API void ResetHero(int64_t pawn, bool reset) {
    if (!pawn) return;
    auto offset = dsdk::MemoryDataLoader::Get().GetOffset("CCitadelPlayerPawn::ResetHero");
    if (offset.has_value()) {
        auto fn = reinterpret_cast<ResetHeroFn>(*offset);
        fn(reinterpret_cast<void *>(pawn), reset);
    }
}

PLUGIN_API void PrecacheHero(const plg::string &heroName) {
    dsdk::Logger::Debug("PrecacheHero called for hero: {}", heroName.c_str());
}

PLUGIN_API void ForceRespawn(int64_t pawn, bool releaseButtons) {
    if (!pawn) return;
    auto offset = dsdk::MemoryDataLoader::Get().GetOffset("CBasePlayerPawn::ForceRespawn");
    if (!offset.has_value()) {
        offset = dsdk::MemoryDataLoader::Get().GetOffset("CCitadelPlayerPawn::ForceRespawn");
    }
    if (offset.has_value()) {
        auto fn = reinterpret_cast<ForceRespawnFn>(*offset);
        fn(reinterpret_cast<void *>(pawn), releaseButtons ? 1 : 0);
    }
}

PLUGIN_API int64_t GetHeroData(const plg::string &heroName) {
    return reinterpret_cast<int64_t>(GetHeroDataPtr(heroName.c_str()));
}

static plg::string ResolveHeroNameById(uint32_t heroId) {
    if (heroId == 0) return plg::string("");
    void *manager = GetHeroDataManager();
    auto getByIdAddr = dsdk::MemoryDataLoader::Get().GetOffset("CHeroDefinitionManager::GetHeroById");
    if (manager && getByIdAddr.has_value()) {
        auto getHeroById = reinterpret_cast<GetHeroByIdFn>(*getByIdAddr);
        void *heroData = getHeroById(manager, heroId);
        if (heroData) {
            static int s_searchNameOffset = -1;
            if (s_searchNameOffset == -1) {
                s_searchNameOffset = schema::GetOffset("CitadelHeroData_t", hash_32_fnv1a_const("CitadelHeroData_t"),
                                                       "m_strHeroSearchName", hash_32_fnv1a_const("m_strHeroSearchName")).Offset;
            }
            if (s_searchNameOffset > 0) {
                const char *pStr = *reinterpret_cast<const char **>(reinterpret_cast<uintptr_t>(heroData) + s_searchNameOffset);
                if (pStr && *pStr) return plg::string(pStr);
            }
        }
    }
    return plg::string("");
}

PLUGIN_API plg::string GetHeroName(int64_t pawn) {
    if (!pawn) return plg::string("");

    uint32_t heroId = 0;

    // 1. Try reading from CCitadelPlayerPawn::m_CCitadelHeroComponent (embedded struct, NOT a pointer!)
    static int s_heroCompOffset = -1;
    if (s_heroCompOffset == -1) {
        s_heroCompOffset = schema::GetOffset("CCitadelPlayerPawn", hash_32_fnv1a_const("CCitadelPlayerPawn"),
                                             "m_CCitadelHeroComponent", hash_32_fnv1a_const("m_CCitadelHeroComponent")).Offset;
    }
    static int s_spawnedHeroOffset = -1;
    if (s_spawnedHeroOffset == -1) {
        s_spawnedHeroOffset = schema::GetOffset("CCitadelHeroComponent", hash_32_fnv1a_const("CCitadelHeroComponent"),
                                               "m_spawnedHero", hash_32_fnv1a_const("m_spawnedHero")).Offset;
    }
    static int s_heroIdOffset = -1;
    if (s_heroIdOffset == -1) {
        s_heroIdOffset = schema::GetOffset("CitadelHeroSpawnData_t", hash_32_fnv1a_const("CitadelHeroSpawnData_t"),
                                           "m_nHeroID", hash_32_fnv1a_const("m_nHeroID")).Offset;
    }

    if (s_heroCompOffset > 0 && s_spawnedHeroOffset >= 0 && s_heroIdOffset >= 0) {
        uintptr_t heroCompAddr = static_cast<uintptr_t>(pawn) + s_heroCompOffset;
        heroId = *reinterpret_cast<uint32_t *>(heroCompAddr + s_spawnedHeroOffset + s_heroIdOffset);
    }

    static int s_playerDataGlobalOffset = -1;
    if (s_playerDataGlobalOffset == -1) {
        s_playerDataGlobalOffset = schema::GetOffset("CCitadelPlayerController", hash_32_fnv1a_const("CCitadelPlayerController"),
                                                     "m_PlayerDataGlobal", hash_32_fnv1a_const("m_PlayerDataGlobal")).Offset;
    }
    static int s_ctrlHeroIdOffset = -1;
    if (s_ctrlHeroIdOffset == -1) {
        s_ctrlHeroIdOffset = schema::GetOffset("PlayerDataGlobal_t", hash_32_fnv1a_const("PlayerDataGlobal_t"),
                                               "m_nHeroID", hash_32_fnv1a_const("m_nHeroID")).Offset;
    }

    // 2. If heroId is 0, maybe pawn's controller has it in m_PlayerDataGlobal.m_nHeroID
    if (heroId == 0) {
        static int s_hControllerOffset = -1;
        if (s_hControllerOffset == -1) {
            s_hControllerOffset = schema::GetOffset("CBasePlayerPawn", hash_32_fnv1a_const("CBasePlayerPawn"),
                                                    "m_hController", hash_32_fnv1a_const("m_hController")).Offset;
        }
        if (s_hControllerOffset > 0) {
            auto *hCtrl = reinterpret_cast<CHandle<CBaseEntity> *>(static_cast<uintptr_t>(pawn) + s_hControllerOffset);
            auto *ctrl = hCtrl ? hCtrl->Get() : nullptr;
            if (ctrl && s_playerDataGlobalOffset > 0 && s_ctrlHeroIdOffset >= 0) {
                heroId = *reinterpret_cast<uint32_t *>(reinterpret_cast<uintptr_t>(ctrl) + s_playerDataGlobalOffset + s_ctrlHeroIdOffset);
            }
        }
    }

    // 3. What if the caller passed the controller directly as the argument?
    if (heroId == 0 && s_playerDataGlobalOffset > 0 && s_ctrlHeroIdOffset >= 0) {
        heroId = *reinterpret_cast<uint32_t *>(static_cast<uintptr_t>(pawn) + s_playerDataGlobalOffset + s_ctrlHeroIdOffset);
    }

    return ResolveHeroNameById(heroId);
}

}
