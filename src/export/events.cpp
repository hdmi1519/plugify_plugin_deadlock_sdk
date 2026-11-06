#include "pch.hpp"
#include "core/globals.hpp"
#include "core/memory/data_loader.hpp"
#include "core/logger.hpp"
#include "core/listeners/listeners.hpp"
#include <igameevents.h>
#include <tier1/keyvalues3.h>

static IGameEventManager2 *GetGameEventManager() {
    static IGameEventManager2 *s_pMgr = nullptr;
    if (!s_pMgr) {
        auto opt = dsdk::MemoryDataLoader::Get().GetOffset("g_GameEventManager");
        if (opt.has_value()) {
            auto xref = *opt;
            auto disp = *reinterpret_cast<int32_t *>(xref + 9);
            s_pMgr = *reinterpret_cast<IGameEventManager2 **>(xref + 13 + disp);
        }
    }
    return s_pMgr;
}

extern "C" {

class CDeadlockEventListener : public IGameEventListener2 {
public:
    ~CDeadlockEventListener() override {}
    void FireGameEvent(IGameEvent *event) override {
        if (!event) return;
        const char *name = event->GetName();
        if (!name) return;
        dsdk::g_GameEventListeners.Dispatch(plg::string(name), reinterpret_cast<int64_t>(event));
    }
};
static CDeadlockEventListener s_EventListener;

PLUGIN_API void OnGameEvent_Register(dsdk::GameEventCallback callback) {
    dsdk::g_GameEventListeners.Register(callback);
}

PLUGIN_API void OnGameEvent_Unregister(dsdk::GameEventCallback callback) {
    dsdk::g_GameEventListeners.Unregister(callback);
}

PLUGIN_API void RegisterGameEvent(const plg::string &name) {
    auto *mgr = GetGameEventManager();
    if (!mgr || name.empty()) return;
    mgr->AddListener(&s_EventListener, name.c_str(), true);
    dsdk::Logger::Debug("RegisterGameEvent: added listener for '{}'", name.c_str());
}

PLUGIN_API int64_t CreateGameEvent(const plg::string &name, bool force) {
    auto *mgr = GetGameEventManager();
    if (!mgr || name.empty()) return 0;
    return reinterpret_cast<int64_t>(mgr->CreateEvent(name.c_str(), force));
}

PLUGIN_API bool FireGameEvent(int64_t event, bool dontBroadcast) {
    auto *mgr = GetGameEventManager();
    if (!mgr || !event) return false;
    return mgr->FireEvent(reinterpret_cast<IGameEvent *>(event), dontBroadcast);
}

PLUGIN_API void FreeGameEvent(int64_t event) {
    auto *mgr = GetGameEventManager();
    if (!mgr || !event) return;
    mgr->FreeEvent(reinterpret_cast<IGameEvent *>(event));
}

PLUGIN_API bool GameEventGetBool(int64_t event, const plg::string &key, bool def) {
    if (!event || key.empty()) return def;
    auto keySymbol = GameEventKeySymbol_t::Make(key.c_str());
    return reinterpret_cast<IGameEvent *>(event)->GetBool(keySymbol, def);
}

PLUGIN_API int32_t GameEventGetInt(int64_t event, const plg::string &key, int32_t def) {
    if (!event || key.empty()) return def;
    auto keySymbol = GameEventKeySymbol_t::Make(key.c_str());
    return reinterpret_cast<IGameEvent *>(event)->GetInt(keySymbol, def);
}

PLUGIN_API float GameEventGetFloat(int64_t event, const plg::string &key, float def) {
    if (!event || key.empty()) return def;
    auto keySymbol = GameEventKeySymbol_t::Make(key.c_str());
    return reinterpret_cast<IGameEvent *>(event)->GetFloat(keySymbol, def);
}

PLUGIN_API plg::string GameEventGetString(int64_t event, const plg::string &key, const plg::string &def) {
    if (!event || key.empty()) return def;
    auto keySymbol = GameEventKeySymbol_t::Make(key.c_str());
    const char *val = reinterpret_cast<IGameEvent *>(event)->GetString(keySymbol, def.c_str());
    return val ? plg::string(val) : def;
}

PLUGIN_API uint64_t GameEventGetUint64(int64_t event, const plg::string &key, uint64_t def) {
    if (!event || key.empty()) return def;
    auto keySymbol = GameEventKeySymbol_t::Make(key.c_str());
    return reinterpret_cast<IGameEvent *>(event)->GetUint64(keySymbol, def);
}

PLUGIN_API void GameEventSetBool(int64_t event, const plg::string &key, bool val) {
    if (!event || key.empty()) return;
    auto keySymbol = GameEventKeySymbol_t::Make(key.c_str());
    reinterpret_cast<IGameEvent *>(event)->SetBool(keySymbol, val);
}

PLUGIN_API void GameEventSetInt(int64_t event, const plg::string &key, int32_t val) {
    if (!event || key.empty()) return;
    auto keySymbol = GameEventKeySymbol_t::Make(key.c_str());
    reinterpret_cast<IGameEvent *>(event)->SetInt(keySymbol, val);
}

PLUGIN_API void GameEventSetFloat(int64_t event, const plg::string &key, float val) {
    if (!event || key.empty()) return;
    auto keySymbol = GameEventKeySymbol_t::Make(key.c_str());
    reinterpret_cast<IGameEvent *>(event)->SetFloat(keySymbol, val);
}

PLUGIN_API void GameEventSetString(int64_t event, const plg::string &key, const plg::string &val) {
    if (!event || key.empty()) return;
    auto keySymbol = GameEventKeySymbol_t::Make(key.c_str());
    reinterpret_cast<IGameEvent *>(event)->SetString(keySymbol, val.c_str());
}

PLUGIN_API int32_t GameEventGetPlayerSlot(int64_t event, const plg::string &key) {
    if (!event || key.empty()) return -1;
    auto keySymbol = GameEventKeySymbol_t::Make(key.c_str());
    return reinterpret_cast<IGameEvent *>(event)->GetPlayerSlot(keySymbol).Get();
}

PLUGIN_API int64_t GameEventGetPlayerPawn(int64_t event, const plg::string &key) {
    if (!event || key.empty()) return 0;
    auto keySymbol = GameEventKeySymbol_t::Make(key.c_str());
    return reinterpret_cast<int64_t>(reinterpret_cast<IGameEvent *>(event)->GetPlayerPawn(keySymbol));
}

PLUGIN_API int64_t GameEventGetPlayerController(int64_t event, const plg::string &key) {
    if (!event || key.empty()) return 0;
    auto keySymbol = GameEventKeySymbol_t::Make(key.c_str());
    return reinterpret_cast<int64_t>(reinterpret_cast<IGameEvent *>(event)->GetPlayerController(keySymbol));
}

}
