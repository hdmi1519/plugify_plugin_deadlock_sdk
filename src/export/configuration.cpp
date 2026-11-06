#include "pch.hpp"
#include "core/settings.hpp"

extern "C" {

PLUGIN_API plg::string GetConfigString(const plg::string &key, const plg::string &defaultValue) {
    auto val = dsdk::Settings::Get().GetString(key.c_str(), defaultValue.c_str());
    return plg::string(val.c_str());
}

PLUGIN_API int32_t GetConfigInt(const plg::string &key, int32_t defaultValue) {
    return dsdk::Settings::Get().GetInt(key.c_str(), defaultValue);
}

PLUGIN_API bool GetConfigBool(const plg::string &key, bool defaultValue) {
    return dsdk::Settings::Get().GetBool(key.c_str(), defaultValue);
}

PLUGIN_API float GetConfigFloat(const plg::string &key, float defaultValue) {
    return dsdk::Settings::Get().GetFloat(key.c_str(), defaultValue);
}

}
