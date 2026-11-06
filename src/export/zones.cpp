#include "pch.hpp"
#include "core/sdk/Core.hpp"
#include "core/sdk/CEntitySystem.hpp"
#include "core/sdk/CBaseEntity.hpp"
#include "core/sdk/schema/Schema.hpp"
#include "core/memory/data_loader.hpp"
#include "core/memory/virtual.hpp"
#include <unordered_map>
#include <mathlib/vector.h>

struct ZoneData {
    int64_t id;
    plg::string name;
    float min[3];
    float max[3];
};

static int64_t g_NextZoneId = 1;
static std::unordered_map<int64_t, ZoneData> g_Zones;

using TeleportFn = void(__thiscall *)(void *entity, const Vector *pos, const QAngle *ang, const Vector *vel);

extern "C" {

PLUGIN_API int64_t CreateBeam(float startX, float startY, float startZ,
                              float endX, float endY, float endZ,
                              float width, uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    auto *inst = EntitySystemHelper::CreateEntityByName("env_beam");
    if (!inst) return 0;

    EntitySystemHelper::QueueSpawnEntity(inst->m_pEntity);
    EntitySystemHelper::ExecuteQueuedCreation();

    auto teleportOpt = dsdk::MemoryDataLoader::Get().GetVirtual("CBaseEntity::Teleport");
    if (teleportOpt.has_value()) {
        auto teleportFn = dsdk::GetVirtual<TeleportFn>(inst, *teleportOpt);
        Vector pos{startX, startY, startZ};
        teleportFn(inst, &pos, nullptr, nullptr);
    }

    static int s_endPosOffset = -1;
    if (s_endPosOffset == -1) {
        s_endPosOffset = schema::GetOffset("CBeam", hash_32_fnv1a_const("CBeam"),
                                          "m_vecEndPos", hash_32_fnv1a_const("m_vecEndPos")).Offset;
    }
    if (s_endPosOffset > 0) {
        auto *endPos = reinterpret_cast<Vector *>(reinterpret_cast<uintptr_t>(inst) + s_endPosOffset);
        endPos->x = endX;
        endPos->y = endY;
        endPos->z = endZ;
    }

    static int s_widthOffset = -1;
    if (s_widthOffset == -1) {
        s_widthOffset = schema::GetOffset("CBeam", hash_32_fnv1a_const("CBeam"),
                                         "m_fWidth", hash_32_fnv1a_const("m_fWidth")).Offset;
    }
    if (s_widthOffset > 0) {
        *reinterpret_cast<float *>(reinterpret_cast<uintptr_t>(inst) + s_widthOffset) = width;
    }

    return reinterpret_cast<int64_t>(inst);
}

PLUGIN_API int64_t CreateZone(const plg::string &name,
                              float minX, float minY, float minZ,
                              float maxX, float maxY, float maxZ) {
    int64_t id = g_NextZoneId++;
    ZoneData zone;
    zone.id = id;
    zone.name = name;
    zone.min[0] = minX; zone.min[1] = minY; zone.min[2] = minZ;
    zone.max[0] = maxX; zone.max[1] = maxY; zone.max[2] = maxZ;
    g_Zones[id] = zone;
    return id;
}

PLUGIN_API void DestroyZone(int64_t zoneId) {
    g_Zones.erase(zoneId);
}

}
