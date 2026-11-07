#include "pch.hpp"
#include "core/globals.hpp"
#include <eiface.h>
#include <filesystem.h>
#include <tier0/icommandline.h>
#include <tier0/utlstringtoken.h>
#include <string_t.h>
#include <edict.h>
#include <map>
#include <string>

static std::string g_ConnectRejectReason;
static std::string g_ServerAddons;
static std::map<std::string, std::string> g_ServerKeyValues;

static void EnsureGlobalVars() {
    if (!dsdk::g_pGlobalVars && dsdk::g_pEngineServer) {
        dsdk::g_pGlobalVars = dsdk::g_pEngineServer->GetServerGlobals();
    }
}

extern "C" {

PLUGIN_API plg::string GetMapName() {
    if (!dsdk::g_CurrentMapName.empty()) {
        return plg::string(dsdk::g_CurrentMapName);
    }
    EnsureGlobalVars();
    if (dsdk::g_pGlobalVars) {
        const char *pMap = STRING(dsdk::g_pGlobalVars->mapname);
        if (pMap && *pMap) {
            return plg::string(pMap);
        }
    }
    return plg::string("");
}

PLUGIN_API bool IsMapValid(const plg::string &map) {
    if (dsdk::g_pEngineServer) {
        return dsdk::g_pEngineServer->IsMapValid(map.c_str()) != 0;
    }
    return false;
}

PLUGIN_API bool SetServerKeyValue(const plg::string &key, const plg::string &value) {
    g_ServerKeyValues[key.c_str()] = value.c_str();
    return true;
}

PLUGIN_API bool ClearServerKeyValues() {
    g_ServerKeyValues.clear();
    return true;
}

PLUGIN_API void SetServerAddons(const plg::string &addons) {
    g_ServerAddons = addons.c_str();
}

PLUGIN_API bool AddFileSystemSearchPath(const plg::string &path, const plg::string &pathId, int32_t addType) {
    if (dsdk::g_pFullFileSystem) {
        dsdk::g_pFullFileSystem->AddSearchPath(path.c_str(), pathId.c_str(), static_cast<SearchPathAdd_t>(addType));
        return true;
    }
    return false;
}

PLUGIN_API bool HasCommandLineParm(const plg::string &parm) {
    if (CommandLine()) {
        CUtlStringToken token(parm.c_str(), static_cast<int>(parm.length()));
        return CommandLine()->HasParmUnrestricted(token);
    }
    return false;
}

PLUGIN_API void SetConnectRejectReason(const plg::string &reason) {
    g_ConnectRejectReason = reason.c_str();
}

PLUGIN_API int64_t GetGlobalVars() {
    EnsureGlobalVars();
    return reinterpret_cast<int64_t>(dsdk::g_pGlobalVars);
}

PLUGIN_API float GetGameTime() {
    EnsureGlobalVars();
    return dsdk::g_pGlobalVars ? dsdk::g_pGlobalVars->curtime : 0.0f;
}

PLUGIN_API int32_t GetGameTickCount() {
    EnsureGlobalVars();
    return dsdk::g_pGlobalVars ? dsdk::g_pGlobalVars->tickcount : 0;
}

}
