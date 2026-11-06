#include "pch.hpp"
#include "core/settings.hpp"
#include "core/logger.hpp"
#include <fstream>

namespace dsdk {

static const nlohmann::json *FindNode(const nlohmann::json &root, std::string_view key) {
    if (root.is_null()) return nullptr;
    if (root.contains(key)) return &root[std::string(key)];

    const nlohmann::json *cur = &root;
    size_t start = 0;
    while (start < key.size()) {
        size_t dot = key.find('.', start);
        std::string part(key.substr(start, dot == std::string_view::npos ? std::string_view::npos : dot - start));
        if (!cur->is_object() || !cur->contains(part)) {
            return nullptr;
        }
        cur = &(*cur)[part];
        if (dot == std::string_view::npos) break;
        start = dot + 1;
    }
    return cur;
}

bool Settings::Load(std::string_view path) {
    std::ifstream file(path.data());
    if (!file.is_open()) {
        Logger::Warning("Could not open settings file: {}", path);
        return false;
    }

    try {
        m_data = nlohmann::json::parse(file, nullptr, false, true);
        Logger::Debug("Loaded settings from {}", path);
        return true;
    } catch (const std::exception &e) {
        Logger::Error("Failed to parse settings JSON: {}", e.what());
        return false;
    }
}

std::string Settings::GetString(std::string_view key, std::string_view defaultValue) const {
    const auto *node = FindNode(m_data, key);
    if (node && node->is_string()) {
        return node->get<std::string>();
    }
    return std::string(defaultValue);
}

int32_t Settings::GetInt(std::string_view key, int32_t defaultValue) const {
    const auto *node = FindNode(m_data, key);
    if (node && node->is_number_integer()) {
        return node->get<int32_t>();
    }
    return defaultValue;
}

bool Settings::GetBool(std::string_view key, bool defaultValue) const {
    const auto *node = FindNode(m_data, key);
    if (node && node->is_boolean()) {
        return node->get<bool>();
    }
    return defaultValue;
}

float Settings::GetFloat(std::string_view key, float defaultValue) const {
    const auto *node = FindNode(m_data, key);
    if (node && node->is_number()) {
        return node->get<float>();
    }
    return defaultValue;
}

} // namespace dsdk
