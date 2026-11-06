#pragma once

#if defined(_WIN32)
    #define PLUGIN_API __declspec(dllexport)
#else
    #define PLUGIN_API __attribute__((visibility("default")))
#endif

#include <plg/bitmask.hpp>
#include <plg/enum.hpp>
#include <plg/path.hpp>
#include <plg/plugin.hpp>

#define UNUSED(x) [[maybe_unused]] auto _ = x

#define NONCOPYABLE(x) \
    x(const x&) = delete; \
    x(x&&) = delete; \
    x& operator=(const x&) = delete; \
    x& operator=(x&&) = delete;

template<typename T>
using Result = std::expected<T, std::string>;

template <typename First>
constexpr auto MakeError(First&& error) {
    return std::unexpected(std::forward<First>(error));
}
