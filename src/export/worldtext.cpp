#include "pch.hpp"
#include "core/sdk/Core.hpp"
#include "core/sdk/CEntitySystem.hpp"
#include "core/sdk/CBaseEntity.hpp"
#include "core/sdk/schema/Schema.hpp"
#include "core/memory/data_loader.hpp"
#include "core/memory/virtual.hpp"
#include <mathlib/vector.h>
#include <color.h>
#include <variant.h>
#include <tier1/keyvalues3.h>

using AcceptInputFn = bool(__thiscall *)(void *thisptr, const char *pInputName, void *pActivator, void *pCaller, variant_t *pValue);
using TeleportFn = void(__thiscall *)(void *entity, const Vector *pos, const QAngle *ang, const Vector *vel);

extern "C" {

PLUGIN_API int64_t CreateWorldText(const plg::string &message, float x, float y, float z, float fontSize,
                                    uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    auto *inst = EntitySystemHelper::CreateEntityByName("point_worldtext");
    if (!inst) return 0;

    // 1. Set position and vertical orientation before spawn
    auto teleportOpt = dsdk::MemoryDataLoader::Get().GetVirtual("CBaseEntity::Teleport");
    if (teleportOpt.has_value()) {
        auto teleportFn = dsdk::GetVirtual<TeleportFn>(inst, *teleportOpt);
        Vector pos{x, y, z};
        QAngle ang{180.0f, 0.0f, 270.0f}; // Standing upright vertically
        teleportFn(inst, &pos, &ang, nullptr);
    }

    // 2. Prepare entity keyvalues with complete rendering parameters
    void *mem = MemAlloc_Alloc(sizeof(CEntityKeyValues));
    auto *ekv = new (mem) CEntityKeyValues();
    float size = fontSize > 0.0f ? fontSize : 50.0f;
    float wupp = 0.25f;

    ekv->SetString(CKV3MemberName::Make("message"), message.c_str());
    ekv->SetString(CKV3MemberName::Make("message_text"), message.c_str());
    ekv->SetString(CKV3MemberName::Make("font_name"), "Reaver");
    ekv->SetBool(CKV3MemberName::Make("enabled"), true);
    ekv->SetInt(CKV3MemberName::Make("fullbright"), 1);
    ekv->SetFloat(CKV3MemberName::Make("font_size"), size);
    ekv->SetFloat(CKV3MemberName::Make("world_units_per_pixel"), wupp);
    ekv->SetColor(CKV3MemberName::Make("color"), Color(r, g, b, a));
    ekv->SetInt(CKV3MemberName::Make("justify_horizontal"), 1); // 1 = Center
    ekv->SetInt(CKV3MemberName::Make("justify_vertical"), 1);   // 1 = Center
    ekv->SetInt(CKV3MemberName::Make("reorient_mode"), 1);      // 1 = POINT_WORLD_TEXT_REORIENT_AROUND_UP (faces camera)

    // 3. Queue spawn with keyvalues and execute
    EntitySystemHelper::QueueSpawnEntity(inst->m_pEntity, ekv);
    EntitySystemHelper::ExecuteQueuedCreation();

    // 4. Set schema fields directly and notify network state changed to replicate to all clients
    auto classKey = hash_32_fnv1a_const("CPointWorldText");
    auto msgKey = schema::GetOffset("CPointWorldText", classKey, "m_messageText", hash_32_fnv1a_const("m_messageText"));
    if (msgKey.Offset > 0) {
        char *dst = reinterpret_cast<char *>(reinterpret_cast<uintptr_t>(inst) + msgKey.Offset);
        strncpy_s(dst, 512, message.c_str(), _TRUNCATE);
        EntityNetworkStateChanged(reinterpret_cast<uintptr_t>(inst), msgKey.Offset);
    }

    auto fontKey = schema::GetOffset("CPointWorldText", classKey, "m_FontName", hash_32_fnv1a_const("m_FontName"));
    if (fontKey.Offset > 0) {
        char *dst = reinterpret_cast<char *>(reinterpret_cast<uintptr_t>(inst) + fontKey.Offset);
        strncpy_s(dst, 64, "Reaver", _TRUNCATE);
        EntityNetworkStateChanged(reinterpret_cast<uintptr_t>(inst), fontKey.Offset);
    }

    // 5. AcceptInput SetMessage and Enable
    auto acceptOpt = dsdk::MemoryDataLoader::Get().GetOffset("CEntityInstance::AcceptInput");
    if (!acceptOpt.has_value()) {
        acceptOpt = dsdk::MemoryDataLoader::Get().GetOffset("CBaseEntity::AcceptInput");
    }
    if (acceptOpt.has_value()) {
        auto acceptFn = reinterpret_cast<AcceptInputFn>(*acceptOpt);
        variant_t msgVal(message.c_str());
        acceptFn(inst, "SetMessage", nullptr, nullptr, &msgVal);
        variant_t emptyVal("");
        acceptFn(inst, "Enable", nullptr, nullptr, &emptyVal);
    }

    return reinterpret_cast<int64_t>(inst);
}

PLUGIN_API void SetWorldTextMessage(int64_t worldText, const plg::string &text) {
    if (!worldText) return;
    auto acceptOpt = dsdk::MemoryDataLoader::Get().GetOffset("CEntityInstance::AcceptInput");
    if (!acceptOpt.has_value()) {
        acceptOpt = dsdk::MemoryDataLoader::Get().GetOffset("CBaseEntity::AcceptInput");
    }
    if (acceptOpt.has_value()) {
        auto acceptFn = reinterpret_cast<AcceptInputFn>(*acceptOpt);
        variant_t val(text.c_str());
        acceptFn(reinterpret_cast<void *>(worldText), "SetMessage", nullptr, nullptr, &val);
    }

    auto classKey = hash_32_fnv1a_const("CPointWorldText");
    auto msgKey = schema::GetOffset("CPointWorldText", classKey, "m_messageText", hash_32_fnv1a_const("m_messageText"));
    if (msgKey.Offset > 0) {
        char *dst = reinterpret_cast<char *>(worldText + msgKey.Offset);
        strncpy_s(dst, 512, text.c_str(), _TRUNCATE);
        EntityNetworkStateChanged(static_cast<uintptr_t>(worldText), msgKey.Offset);
    }
}

}
