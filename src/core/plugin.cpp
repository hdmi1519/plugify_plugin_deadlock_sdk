#include "pch.hpp"
#include "core/plugin.hpp"
#include "core/globals.hpp"
#include "core/logger.hpp"
#include "core/settings.hpp"
#include "core/memory/data_loader.hpp"
#include "core/hooks/hook_manager.hpp"
#include "core/timers/timer_system.hpp"
#include <tier1/convar.h>

namespace dsdk {

DeadlockSDKPlugin g_Plugin;

plg::PluginResult DeadlockSDKPlugin::OnPluginStart() {
    Logger::Info("Initializing Plugify Deadlock SDK (dsdk v1.0.0)...");

    InitializeGlobals();
    ConVar_Register(0);

    auto location = plg::plugin::GetLocation(plg::plugin::handle);
    g_PluginPath = location.c_str();
    g_SignaturesPath = g_PluginPath / "signatures.jsonc";
    g_SettingsPath = g_PluginPath / "settings.jsonc";

    Logger::Debug("Plugin directory: {}", g_PluginPath.string());

    if (fs::exists(g_SettingsPath)) {
        Settings::Get().Load(g_SettingsPath.string());
    } else {
        Logger::Warning("settings.jsonc not found at {}", g_SettingsPath.string());
    }

    if (fs::exists(g_SignaturesPath)) {
        auto res = MemoryDataLoader::Get().Load(g_SignaturesPath.string());
        if (!res.has_value()) {
            Logger::Warning("Memory signatures load notice: {}", res.error());
        } else {
            Logger::Debug("Loaded memory signatures from {}", g_SignaturesPath.string());
        }
    } else {
        Logger::Warning("signatures.jsonc not found at {}", g_SignaturesPath.string());
    }

    HookManager::Get().InstallHooks();

    Logger::Info("Deadlock SDK initialized successfully.");
    return plg::PluginResult("dsdk started", plg::PluginCode::Ok);
}

plg::PluginResult DeadlockSDKPlugin::OnPluginEnd() {
    Logger::Info("Shutting down Deadlock SDK (dsdk)...");
    ConVar_Unregister();
    HookManager::Get().UninstallHooks();
    return plg::PluginResult("dsdk stopped", plg::PluginCode::Ok);
}

void DeadlockSDKPlugin::OnPluginUpdate(float dt) {
    TimerSystem::Get().Update(dt);
}

} // namespace dsdk

PLUGIFY_PLUGIN(PLUGIN_API, &dsdk::g_Plugin)
