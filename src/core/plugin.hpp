#pragma once

#include <plg/plugin.hpp>

namespace dsdk {

class DeadlockSDKPlugin final : public plg::Plugin {
public:
    DeadlockSDKPlugin() = default;
    ~DeadlockSDKPlugin() = default;

    plg::PluginResult OnPluginStart() override;
    plg::PluginResult OnPluginEnd() override;
    void OnPluginUpdate(float dt);
};

extern DeadlockSDKPlugin g_Plugin;

} // namespace dsdk
