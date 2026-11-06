#include "pch.hpp"
#include "core/logger.hpp"
#include <iostream>

namespace dsdk {

void Logger::Log(plg::Severity severity, std::string_view msg) {
    if (plg::Log) {
        plg::Log(msg, severity, plg::source_location::current());
    } else {
        std::println(stderr, "[dsdk] {}", msg);
    }
}

} // namespace dsdk
