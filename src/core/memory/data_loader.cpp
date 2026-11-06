#include "pch.hpp"
#include "core/memory/data_loader.hpp"
#include "core/memory/scanner.hpp"
#include "core/memory/module.hpp"

#include <nlohmann/json.hpp>
#include <fstream>

namespace dsdk {

std::expected<void, std::string> MemoryDataLoader::Load(std::string_view configPath) {
    std::ifstream file(configPath.data());
    if (!file.is_open()) {
        return std::unexpected("Failed to open signatures file: " + std::string(configPath));
    }

    try {
        // nlohmann::json parse with ignore_comments = true to support JSONC
        auto data = nlohmann::json::parse(file, nullptr, false, true);

        if (data.contains("signatures")) {
            for (auto &[key, value] : data["signatures"].items()) {
                auto library = value["library"].get<std::string>();
#ifdef _WIN32
                auto pattern = value["windows"].get<std::string>();
#else
                auto pattern = value["linux"].get<std::string>();
#endif
                Module module{library};
                if (!module.IsValid()) {
                    continue; // Engine module might not be loaded yet
                }

                auto sig = Scanner::ParseSignature(pattern);
                if (!sig.has_value()) {
                    m_missing.push_back(key + " (invalid pattern)");
                    continue;
                }

                const auto scanResult = Scanner::FindFirst(module.GetSectionMemory(".text"), sig.value());
                if (scanResult.has_value()) {
                    m_resolved[key] = *scanResult;
                } else {
                    m_missing.push_back(key);
                }
            }
        }

        if (data.contains("patches")) {
            for (auto &[key, value] : data["patches"].items()) {
                auto library = value["library"].get<std::string>();
#ifdef _WIN32
                auto pattern = value["windows"].get<std::string>();
#else
                auto pattern = value["linux"].get<std::string>();
#endif
                Module module{library};
                if (!module.IsValid()) continue;

                auto sig = Scanner::ParseSignature(pattern);
                if (!sig.has_value()) continue;

                const auto scanResult = Scanner::FindFirst(module.GetSectionMemory(".text"), sig.value());
                if (scanResult.has_value()) {
                    m_patches[key] = *scanResult;
                } else {
                    m_missing.push_back("patch " + key);
                }
            }
        }

        if (data.contains("virtuals")) {
            for (auto &[key, value] : data["virtuals"].items()) {
                m_virtuals[key] = value.get<int>();
            }
        }
    } catch (const std::exception &e) {
        return std::unexpected(std::string("Failed to parse signatures config: ") + e.what());
    }

    return {};
}

} // namespace dsdk
