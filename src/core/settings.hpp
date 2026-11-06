#pragma once

#include <string>
#include <string_view>
#include <nlohmann/json.hpp>

namespace dsdk {

class Settings {
public:
    static Settings &Get() {
        static Settings instance;
        return instance;
    }

    bool Load(std::string_view path);

    std::string GetString(std::string_view key, std::string_view defaultValue = "") const;
    int32_t GetInt(std::string_view key, int32_t defaultValue = 0) const;
    bool GetBool(std::string_view key, bool defaultValue = false) const;
    float GetFloat(std::string_view key, float defaultValue = 0.0f) const;

    const nlohmann::json &GetJson() const { return m_data; }

private:
    nlohmann::json m_data;
};

} // namespace dsdk
