#pragma once

#include <optional>
#include <vector>
#include <expected>
#include <string>
#include <span>
#include <cstdint>

namespace dsdk {

using SignatureByte = std::optional<std::byte>;
using Signature = std::vector<SignatureByte>;

class Scanner {
public:
    static std::expected<Signature, std::string> ParseSignature(std::string_view sig);
    static std::optional<uintptr_t> FindFirst(std::span<std::byte> memory, const Signature &pattern);
};

} // namespace dsdk
