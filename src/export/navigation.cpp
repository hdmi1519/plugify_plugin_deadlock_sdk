#include "pch.hpp"
#include "core/memory/data_loader.hpp"
#include <mathlib/vector.h>

struct NavNearestParams {
    uint64_t unk0 = 0;
    float unk8 = -1.0f;
    uint32_t unk12 = 0;
    float heightLimitA = 80.0f;
    float heightLimitB = 18.0f;
    float radiusLimit = 16.0f;
    uint32_t unk28 = 0;
    int64_t unk32 = -1;
    uint64_t areaAttributes = 0x20000;
    void *acceptFilter = nullptr;
    void *unk56 = nullptr;
    uint8_t unk64 = 1;
    uint8_t pad[15] = {};
};

using GetNearestNavFn = void *(__fastcall *)(void *navMesh, const Vector *pos, const int32_t *hull, uint32_t flags,
                                             Vector *outPos, float maxDistance, const NavNearestParams *params);
using AreaGetZFn = float(__fastcall *)(void *area, float x, float y);

static void **g_ppNavMesh = nullptr;
static GetNearestNavFn g_pGetNearestNav = nullptr;
static AreaGetZFn g_pAreaGetZ = nullptr;

static void EnsureNavMeshResolved() {
    if (g_ppNavMesh) return;
    auto globalRefOpt = dsdk::MemoryDataLoader::Get().GetOffset("CNavMesh::GlobalRef");
    if (globalRefOpt.has_value()) {
        auto globalRef = *globalRefOpt;
        auto disp = *reinterpret_cast<int32_t *>(globalRef + 3);
        g_ppNavMesh = reinterpret_cast<void **>(globalRef + 7 + disp);
    }
    auto getNearestOpt = dsdk::MemoryDataLoader::Get().GetOffset("CNavMesh::GetNearestNav");
    if (getNearestOpt.has_value()) {
        g_pGetNearestNav = reinterpret_cast<GetNearestNavFn>(*getNearestOpt);
    }
    auto areaGetZOpt = dsdk::MemoryDataLoader::Get().GetOffset("CNavArea::GetZ");
    if (areaGetZOpt.has_value()) {
        g_pAreaGetZ = reinterpret_cast<AreaGetZFn>(*areaGetZOpt);
    }
}

static void *GetNavMesh() {
    EnsureNavMeshResolved();
    return g_ppNavMesh ? *g_ppNavMesh : nullptr;
}

extern "C" {

PLUGIN_API bool NavGetNearestPoint(float x, float y, float z, float maxDistance, int32_t hull) {
    void *navMesh = GetNavMesh();
    if (!navMesh || !g_pGetNearestNav) return true;

    Vector pos(x, y, z);
    Vector outPos(x, y, z);
    NavNearestParams params;
    uint32_t flags = 0x20;
    void *area = g_pGetNearestNav(navMesh, &pos, &hull, flags, &outPos, maxDistance, &params);
    return area != nullptr;
}

PLUGIN_API float NavGetGroundHeight(float x, float y, float z, float maxDistance, int32_t hull) {
    void *navMesh = GetNavMesh();
    if (!navMesh || !g_pGetNearestNav || !g_pAreaGetZ) return z;

    Vector pos(x, y, z);
    Vector outPos(x, y, z);
    NavNearestParams params;
    uint32_t flags = 0x20;
    void *area = g_pGetNearestNav(navMesh, &pos, &hull, flags, &outPos, maxDistance, &params);
    if (!area) return z;

    return g_pAreaGetZ(area, x, y);
}

}
