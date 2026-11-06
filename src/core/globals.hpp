#pragma once

#include <filesystem>
#include <cstdint>

class ISource2Server;
class ISource2GameClients;
class ISource2GameEntities;
class INetworkServerService;
class IVEngineServer2;
class IGameEventSystem;
class ISchemaSystem;
class CEntitySystem;
class CGlobalVars;
class ICvar;
class IFileSystem;
class INetworkMessages;
class IGameResourceService;

namespace dsdk {

extern ISource2Server *g_pSource2Server;
extern ISource2GameClients *g_pSource2GameClients;
extern ISource2GameEntities *g_pSource2GameEntities;
extern INetworkServerService *g_pNetworkServerService;
extern IVEngineServer2 *g_pEngineServer;
extern IGameEventSystem *g_pGameEventSystem;
extern ISchemaSystem *g_pSchemaSystem;
extern CEntitySystem *g_pEntitySystem;
extern CGlobalVars *g_pGlobalVars;
extern ICvar *g_pCVar;
extern IFileSystem *g_pFullFileSystem;
extern INetworkMessages *g_pNetworkMessages;
extern IGameResourceService *g_pGameResourceServiceServer;
extern void *g_pGameRules;
extern void *g_pPhysicsQuery;
extern void *g_pCurrentManifest;
extern std::string g_CurrentMapName;

extern std::filesystem::path g_PluginPath;
extern std::filesystem::path g_SignaturesPath;
extern std::filesystem::path g_SettingsPath;

void InitializeGlobals();

} // namespace dsdk
