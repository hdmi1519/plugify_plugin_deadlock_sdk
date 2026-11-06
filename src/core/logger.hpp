#pragma once

#include <string_view>
#include <format>
#include <plg/plugin.hpp>

namespace dsdk {

class Logger {
public:
    template<typename... Args>
    static void Trace(std::string_view fmt, Args&&... args) {
        Log(plg::Severity::Trace, std::vformat(fmt, std::make_format_args(args...)));
    }

    template<typename... Args>
    static void Debug(std::string_view fmt, Args&&... args) {
        Log(plg::Severity::Debug, std::vformat(fmt, std::make_format_args(args...)));
    }

    template<typename... Args>
    static void Info(std::string_view fmt, Args&&... args) {
        Log(plg::Severity::Info, std::vformat(fmt, std::make_format_args(args...)));
    }

    template<typename... Args>
    static void Warning(std::string_view fmt, Args&&... args) {
        Log(plg::Severity::Warning, std::vformat(fmt, std::make_format_args(args...)));
    }

    template<typename... Args>
    static void Error(std::string_view fmt, Args&&... args) {
        Log(plg::Severity::Error, std::vformat(fmt, std::make_format_args(args...)));
    }

private:
    static void Log(plg::Severity severity, std::string_view msg);
};

} // namespace dsdk
