#include "pch.hpp"
#include "core/memory/data_loader.hpp"
#include "core/memory/virtual.hpp"
#include "core/sdk/CAI_BaseNPC.hpp"
#include <mathlib/vector.h>

struct SourceLocation {
    const char *file;
    int line;
    const char *function;
};

using ForceNpcGoFn = void(__fastcall *)(void *npc, const Vector *goal, bool run, float tolerance,
                                        const Vector *teleportFirst, bool log);
using SetEnemyFn = void(__fastcall *)(void *npc, void *enemy);
using SetStateFn = void(__fastcall *)(void *npc, int32_t state);
using StopMovingFn = void(__fastcall *)(void *moveInterface, int32_t mode, int32_t facing, const SourceLocation *caller);
using TrooperSpawnAtFn = void *(__fastcall *)(const Vector *origin, const QAngle *angles, int32_t team, int32_t variant, int32_t type);
using SnapToNavGroundFn = bool(__fastcall *)(void *trooper);

extern "C" {

PLUGIN_API void NpcMoveTo(int64_t npc, float x, float y, float z, bool run, float tolerance) {
    if (!npc) return;
    auto opt = dsdk::MemoryDataLoader::Get().GetOffset("CAI_BaseNPC::ForceNpcGo");
    if (!opt.has_value()) return;
    auto fn = reinterpret_cast<ForceNpcGoFn>(*opt);
    Vector goal(x, y, z);
    fn(reinterpret_cast<void *>(npc), &goal, run, tolerance, nullptr, false);
}

PLUGIN_API void NpcStopMoving(int64_t npc, bool instant) {
    if (!npc) return;
    auto *aiNpc = reinterpret_cast<CAI_BaseNPC *>(npc);
    void *navigator = aiNpc->m_pNavigator.Get();
    if (!navigator) return;

    auto optIdx = dsdk::MemoryDataLoader::Get().GetVirtual("CAI_Navigator::StopMoving");
    if (!optIdx.has_value()) return;

    static const SourceLocation caller{__FILE__, __LINE__, "NpcStopMoving"};
    void *moveInterface = reinterpret_cast<uint8_t *>(navigator) + 0x48;
    auto stopFn = dsdk::GetVirtual<StopMovingFn>(moveInterface, *optIdx);
    stopFn(moveInterface, instant ? 0 : 2, 0, &caller);
}

PLUGIN_API void NpcSetEnemy(int64_t npc, int64_t enemy) {
    if (!npc) return;
    auto opt = dsdk::MemoryDataLoader::Get().GetOffset("CAI_BaseNPC::SetEnemy");
    if (!opt.has_value()) return;
    auto fn = reinterpret_cast<SetEnemyFn>(*opt);
    fn(reinterpret_cast<void *>(npc), reinterpret_cast<void *>(enemy));
}

PLUGIN_API void NpcSetState(int64_t npc, int32_t state) {
    if (!npc) return;
    auto opt = dsdk::MemoryDataLoader::Get().GetOffset("CAI_BaseNPC::SetState");
    if (!opt.has_value()) return;
    auto fn = reinterpret_cast<SetStateFn>(*opt);
    fn(reinterpret_cast<void *>(npc), state);
}

PLUGIN_API int64_t NpcCreateTrooper(float posX, float posY, float posZ,
                                    float pitch, float yaw, float roll,
                                    int32_t team, int32_t type, int32_t variant, bool snapToGround) {
    auto opt = dsdk::MemoryDataLoader::Get().GetOffset("Trooper_SpawnAt");
    if (!opt.has_value()) return 0;
    auto fn = reinterpret_cast<TrooperSpawnAtFn>(*opt);
    Vector origin(posX, posY, posZ);
    QAngle angles(pitch, yaw, roll);
    void *trooper = fn(&origin, &angles, team, variant, type);
    if (trooper && snapToGround) {
        auto snapOpt = dsdk::MemoryDataLoader::Get().GetOffset("CNPC_Trooper::SnapToNavGround");
        if (snapOpt.has_value()) {
            auto snapFn = reinterpret_cast<SnapToNavGroundFn>(*snapOpt);
            snapFn(trooper);
        }
    }
    return reinterpret_cast<int64_t>(trooper);
}

}
