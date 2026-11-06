#include "pch.hpp"
#include "core/globals.hpp"
#include "core/memory/data_loader.hpp"
#include <mathlib/vector.h>
#include <entityinstance.h>
#include <entityhandle.h>

enum class RayType_t : uint8_t {
    LINE = 0,
    SPHERE,
    HULL,
    CAPSULE,
    MESH,
};

#pragma pack(push, 1)
struct Ray_t {
    union {
        struct { Vector startOffset; float radius; } line;
        struct { Vector center; float radius; } sphere;
        struct { Vector mins; Vector maxs; } hull;
        struct { Vector center0; Vector center1; float radius; } capsule;
        uint8_t _data[40];
    };
    RayType_t type;
    uint8_t _pad[7];

    void InitLine(const Vector &offset = Vector(0, 0, 0)) {
        memset(this, 0, sizeof(*this));
        line.startOffset = offset;
        line.radius = 0.0f;
        type = RayType_t::LINE;
    }
};
static_assert(sizeof(Ray_t) == 48);
#pragma pack(pop)

enum class CollisionGroup_t : uint8_t {
    ALWAYS = 0,
};

enum class RnQueryObjectSet : uint8_t {
    STATIC = 0x01,
    KEYFRAMED = 0x02,
    DYNAMIC = 0x04,
    LOCATABLE = 0x08,
    ALL = 0x0F,
};

#pragma pack(push, 8)
struct RnQueryShapeAttr_t {
    uint64_t interactsWith;
    uint64_t interactsExclude;
    uint64_t interactsAs;
    uint32_t entityIdsToIgnore[2];
    uint32_t ownerIdsToIgnore[2];
    uint16_t hierarchyIds[2];
    uint16_t includedDetailLayers;
    uint8_t targetDetailLayer;
    RnQueryObjectSet objectSetMask;
    CollisionGroup_t collisionGroup;
    uint8_t data;

    RnQueryShapeAttr_t() {
        memset(this, 0, sizeof(*this));
        entityIdsToIgnore[0] = 0xFFFFFFFF;
        entityIdsToIgnore[1] = 0xFFFFFFFF;
        ownerIdsToIgnore[0] = 0xFFFFFFFF;
        ownerIdsToIgnore[1] = 0xFFFFFFFF;
        objectSetMask = RnQueryObjectSet::ALL;
        collisionGroup = CollisionGroup_t::ALWAYS;
        data = 0x49;
    }
};
#pragma pack(pop)

struct alignas(8) CTraceFilter {
    void *vtable;
    RnQueryShapeAttr_t queryShapeAttributes;
    uint8_t iterateEntities;

    CTraceFilter() {
        memset(this, 0, sizeof(*this));
        new (&queryShapeAttributes) RnQueryShapeAttr_t();
    }
};
static_assert(sizeof(CTraceFilter) == 72);

struct alignas(16) CGameTrace {
    void *surfaceProperties;
    void *pEntity;
    void *hitBox;
    void *body;
    void *shape;
    uint64_t contents;
    uint8_t bodyTransform[32];
    uint8_t shapeAttributes[40];
    Vector startPos;
    Vector endPos;
    Vector hitNormal;
    Vector hitPoint;
    float hitOffset;
    float fraction;
    int32_t triangle;
    int32_t unk_B4;
    int16_t hitboxBoneIndex;
    RayType_t rayType;
    bool startInSolid;
    bool exactHitPoint;
    uint8_t _pad[3];

    CGameTrace() {
        memset(this, 0, sizeof(*this));
        *reinterpret_cast<float *>(bodyTransform + 0x0C) = 1.0f;
        fraction = 1.0f;
        triangle = -1;
        unk_B4 = -1;
        hitboxBoneIndex = -1;
    }

    bool DidHit() const { return fraction < 1.0f || startInSolid; }
};
static_assert(sizeof(CGameTrace) == 0xC0);

using TraceShapeFn = void(__fastcall *)(void *pPhysQuery, Ray_t *ray, Vector *start, Vector *end, CTraceFilter *filter, CGameTrace *traceOutput);

extern "C" {

PLUGIN_API bool LineTrace(float startX, float startY, float startZ,
                          float endX, float endY, float endZ,
                          uint32_t mask, int64_t ignoreEntity) {
    if (!dsdk::g_pPhysicsQuery) {
        return false;
    }
    auto offset = dsdk::MemoryDataLoader::Get().GetOffset("TraceShape");
    if (!offset.has_value()) {
        return false;
    }
    auto traceFn = reinterpret_cast<TraceShapeFn>(*offset);

    Ray_t ray;
    ray.InitLine();
    Vector start(startX, startY, startZ);
    Vector end(endX, endY, endZ);
    CTraceFilter filter;
    if (mask != 0) {
        filter.queryShapeAttributes.interactsWith = mask;
    }
    if (ignoreEntity != 0) {
        auto *inst = reinterpret_cast<CEntityInstance *>(ignoreEntity);
        if (inst && inst->m_pEntity) {
            filter.queryShapeAttributes.entityIdsToIgnore[0] = inst->GetRefEHandle().GetEntryIndex();
        }
    }
    CGameTrace traceOutput;
    traceFn(dsdk::g_pPhysicsQuery, &ray, &start, &end, &filter, &traceOutput);
    return traceOutput.DidHit();
}

}
