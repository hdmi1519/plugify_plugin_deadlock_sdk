#pragma once

#include <safetyhook.hpp>
#include <string>

namespace dsdk {

class HookManager {
public:
    static HookManager &Get() {
        static HookManager instance;
        return instance;
    }

    bool InstallHooks();
    void UninstallHooks();

private:
    bool HookSignature(safetyhook::InlineHook &hook, const std::string &sigName, void *detour);
};

} // namespace dsdk
