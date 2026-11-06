#include "pch.hpp"
#include "core/globals.hpp"
#include "core/memory/module.hpp"

// Forward declare globals from Interfaces.cpp
extern ICvar *cvar;
extern ICvar *g_pCVar;
extern ISource2Server *g_pSource2Server;
extern ISource2GameClients *g_pSource2GameClients;
extern ISource2GameEntities *g_pSource2GameEntities;
extern IVEngineServer2 *g_pEngineServer;
extern INetworkServerService *g_pNetworkServerService;
extern ISchemaSystem *g_pSchemaSystem;
extern IFileSystem *g_pFullFileSystem;
extern INetworkMessages *g_pNetworkMessages;
extern IGameResourceService *g_pGameResourceServiceServer;

namespace dsdk {

ISource2Server *g_pSource2Server = nullptr;
ISource2GameClients *g_pSource2GameClients = nullptr;
ISource2GameEntities *g_pSource2GameEntities = nullptr;
INetworkServerService *g_pNetworkServerService = nullptr;
IVEngineServer2 *g_pEngineServer = nullptr;
IGameEventSystem *g_pGameEventSystem = nullptr;
ISchemaSystem *g_pSchemaSystem = nullptr;
CEntitySystem *g_pEntitySystem = nullptr;
CGlobalVars *g_pGlobalVars = nullptr;
ICvar *g_pCVar = nullptr;
IFileSystem *g_pFullFileSystem = nullptr;
INetworkMessages *g_pNetworkMessages = nullptr;
IGameResourceService *g_pGameResourceServiceServer = nullptr;
void *g_pGameRules = nullptr;
void *g_pPhysicsQuery = nullptr;
void *g_pCurrentManifest = nullptr;
std::string g_CurrentMapName;

std::filesystem::path g_PluginPath;
std::filesystem::path g_SignaturesPath;
std::filesystem::path g_SettingsPath;

using CreateInterfaceFn = void *(*)(const char *pName, int *pReturnCode);

static void *QueryInterface(const char *moduleName, const char *interfaceName) {
    Module mod(moduleName);
    if (!mod.IsValid()) return nullptr;
    auto createInterface = mod.GetSymbol<CreateInterfaceFn>("CreateInterface");
    if (!createInterface) return nullptr;
    int returnCode = 0;
    return createInterface(interfaceName, &returnCode);
}

void InitializeGlobals() {
    g_pSource2Server = reinterpret_cast<ISource2Server *>(QueryInterface("server.dll", "Source2Server001"));
    g_pSource2GameClients = reinterpret_cast<ISource2GameClients *>(QueryInterface("server.dll", "Source2GameClients001"));
    g_pSource2GameEntities = reinterpret_cast<ISource2GameEntities *>(QueryInterface("server.dll", "Source2GameEntities001"));
    g_pEngineServer = reinterpret_cast<IVEngineServer2 *>(QueryInterface("engine2.dll", "Source2EngineToServer001"));
    g_pNetworkServerService = reinterpret_cast<INetworkServerService *>(QueryInterface("engine2.dll", "NetworkServerService_001"));
    g_pGameEventSystem = reinterpret_cast<IGameEventSystem *>(QueryInterface("engine2.dll", "GameEventSystemServerV001"));
    g_pSchemaSystem = reinterpret_cast<ISchemaSystem *>(QueryInterface("schemasystem.dll", "SchemaSystem_001"));
    g_pCVar = reinterpret_cast<ICvar *>(QueryInterface("tier0.dll", "VEngineCvar007"));
    g_pFullFileSystem = reinterpret_cast<IFileSystem *>(QueryInterface("filesystem_stdio.dll", "VFileSystem017"));
    g_pNetworkMessages = reinterpret_cast<INetworkMessages *>(QueryInterface("networksystem.dll", "NetworkMessagesVersion001"));
    g_pGameResourceServiceServer = reinterpret_cast<IGameResourceService *>(QueryInterface("engine2.dll", "GameResourceServiceServerV001"));

    ::g_pSource2Server = g_pSource2Server;
    ::g_pSource2GameClients = g_pSource2GameClients;
    ::g_pSource2GameEntities = g_pSource2GameEntities;
    ::g_pEngineServer = g_pEngineServer;
    ::g_pNetworkServerService = g_pNetworkServerService;
    ::g_pSchemaSystem = g_pSchemaSystem;
    ::g_pCVar = g_pCVar;
    ::cvar = g_pCVar;
    ::g_pFullFileSystem = g_pFullFileSystem;
    ::g_pNetworkMessages = g_pNetworkMessages;
    ::g_pGameResourceServiceServer = g_pGameResourceServiceServer;
}

} // namespace dsdk
