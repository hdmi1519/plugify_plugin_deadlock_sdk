#pragma once

#include <string>
#include <string_view>
#include <span>
#include <map>
#include <cstdint>
#include <cstddef>

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <Psapi.h>
#else
#include <dlfcn.h>
#endif

namespace dsdk {

class Module {
public:
    struct Section {
        std::string Name;
        uintptr_t Base = 0;
        size_t Size = 0;

        [[nodiscard]] std::span<std::byte> GetMemory() const {
            return {reinterpret_cast<std::byte *>(Base), Size};
        }
    };

    explicit Module(std::string_view moduleName)
        : m_name(moduleName) {
#ifdef _WIN32
        m_handle = GetModuleHandleA(moduleName.data());
        if (!m_handle) {
            m_handle = LoadLibraryA(moduleName.data());
        }

        if (!m_handle || m_handle == INVALID_HANDLE_VALUE)
            return;

        MODULEINFO moduleInfo{};
        GetModuleInformation(GetCurrentProcess(), m_handle, &moduleInfo, sizeof(moduleInfo));

        m_base = reinterpret_cast<uintptr_t>(moduleInfo.lpBaseOfDll);
        m_size = moduleInfo.SizeOfImage;
#else
        m_handle = dlopen(moduleName.data(), RTLD_LAZY | RTLD_NOLOAD);
        if (!m_handle) {
            m_handle = dlopen(moduleName.data(), RTLD_LAZY);
        }
#endif
        LoadSections();
    }

    [[nodiscard]] bool IsValid() const { return m_handle != nullptr; }
    [[nodiscard]] std::string_view GetName() const { return m_name; }
    [[nodiscard]] uintptr_t GetBase() const { return m_base; }
    [[nodiscard]] size_t GetSize() const { return m_size; }

#ifdef _WIN32
    template <typename T>
    [[nodiscard]] T GetSymbol(std::string_view symbolName) const {
        return reinterpret_cast<T>(GetProcAddress(m_handle, symbolName.data()));
    }
#else
    template <typename T>
    [[nodiscard]] T GetSymbol(std::string_view symbolName) const {
        return reinterpret_cast<T>(dlsym(m_handle, symbolName.data()));
    }
#endif

    [[nodiscard]] std::optional<Section> GetSection(const std::string &name) const {
        auto it = m_sections.find(name);
        if (it == m_sections.end()) return std::nullopt;
        return it->second;
    }

    [[nodiscard]] std::span<std::byte> GetSectionMemory(const std::string &name) const {
        auto sec = GetSection(name);
        if (sec.has_value()) return sec->GetMemory();
        return {reinterpret_cast<std::byte *>(m_base), m_size};
    }

private:
    void LoadSections() {
#ifdef _WIN32
        if (!m_handle) return;
        auto *dosHdr = reinterpret_cast<PIMAGE_DOS_HEADER>(m_handle);
        if (dosHdr->e_magic != IMAGE_DOS_SIGNATURE) return;

        auto *ntHeader = reinterpret_cast<PIMAGE_NT_HEADERS64>(reinterpret_cast<uintptr_t>(m_handle) + dosHdr->e_lfanew);
        if (ntHeader->Signature != IMAGE_NT_SIGNATURE) return;

        auto *sectionHeader = IMAGE_FIRST_SECTION(ntHeader);
        for (WORD i = 0; i < ntHeader->FileHeader.NumberOfSections; ++i, ++sectionHeader) {
            char secName[9] = {0};
            std::memcpy(secName, sectionHeader->Name, 8);
            std::string name(secName);
            m_sections[name] = Section{
                .Name = name,
                .Base = m_base + sectionHeader->VirtualAddress,
                .Size = sectionHeader->Misc.VirtualSize,
            };
        }
#endif
    }

    std::string m_name;
#ifdef _WIN32
    HMODULE m_handle = nullptr;
#else
    void *m_handle = nullptr;
#endif
    uintptr_t m_base = 0;
    size_t m_size = 0;
    std::map<std::string, Section> m_sections;
};

} // namespace dsdk
