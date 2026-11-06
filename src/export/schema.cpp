#include "pch.hpp"
#include "core/sdk/schema/Schema.hpp"
#include "core/sdk/Core.hpp"
#include "core/globals.hpp"
#include <schemasystem/schemasystem.h>
#include <tier0/utlstring.h>
#include <tier1/utlsymbollarge.h>

extern "C" {

PLUGIN_API int32_t GetSchemaFieldOffset(const plg::string &className, const plg::string &fieldName) {
    auto classKey = hash_32_fnv1a_const(className.c_str());
    auto memberKey = hash_32_fnv1a_const(fieldName.c_str());
    auto key = schema::GetOffset(className.c_str(), classKey, fieldName.c_str(), memberKey);
    return key.Offset;
}

PLUGIN_API void NotifyStateChanged(int64_t entity, int32_t fieldOffset, int16_t chainOffset, int32_t networkStateChangedOffset) {
    if (!entity) return;
    if (chainOffset > 0) {
        ChainNetworkStateChanged(static_cast<uintptr_t>(entity + chainOffset), static_cast<uint32_t>(fieldOffset));
    } else if (networkStateChangedOffset != 0) {
        NetworkVarStateChanged(static_cast<uintptr_t>(entity), static_cast<uint32_t>(fieldOffset), static_cast<uint32_t>(networkStateChangedOffset));
    } else {
        EntityNetworkStateChanged(static_cast<uintptr_t>(entity), static_cast<uint32_t>(fieldOffset));
    }
}

PLUGIN_API void SetSchemaString(int64_t entity, const plg::string &className, const plg::string &fieldName, const plg::string &value) {
    if (!entity) return;
    auto classKey = hash_32_fnv1a_const(className.c_str());
    auto memberKey = hash_32_fnv1a_const(fieldName.c_str());
    auto key = schema::GetOffset(className.c_str(), classKey, fieldName.c_str(), memberKey);
    if (key.Offset <= 0) return;

    auto *pType = ::g_pSchemaSystem ? ::g_pSchemaSystem->FindTypeScopeForModule("server.dll") : nullptr;
    if (pType) {
        auto *pClassInfo = pType->FindDeclaredClass(className.c_str()).Get();
        if (pClassInfo) {
            for (int i = 0; i < pClassInfo->m_nFieldCount; ++i) {
                auto &f = pClassInfo->m_pFields[i];
                if (fieldName == f.m_pszName && f.m_pType) {
                    CBufferString typeStr;
                    f.m_pType->ToString(typeStr, false);
                    if (strstr(typeStr.Get(), "CUtlSymbolLarge")) {
                        auto *pEntitySystem = GameEntitySystem();
                        if (pEntitySystem) {
                            *reinterpret_cast<CUtlSymbolLarge*>(entity + f.m_nSingleInheritanceOffset) = pEntitySystem->AllocPooledString(value.c_str());
                        }
                    } else {
                        reinterpret_cast<CUtlString*>(entity + f.m_nSingleInheritanceOffset)->Set(value.c_str());
                    }
                    NotifyStateChanged(entity, f.m_nSingleInheritanceOffset, 0, 0);
                    return;
                }
            }
        }
    }

    reinterpret_cast<CUtlString*>(entity + key.Offset)->Set(value.c_str());
    NotifyStateChanged(entity, key.Offset, 0, 0);
}

PLUGIN_API int32_t GetSchemaClassSize(const plg::string &className) {
    return schema::GetClassSize(className.c_str());
}

}
