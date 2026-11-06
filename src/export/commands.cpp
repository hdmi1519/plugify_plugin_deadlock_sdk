#include "pch.hpp"
#include "export/commands.hpp"
#include "core/memory/data_loader.hpp"
#include "core/globals.hpp"
#include "core/settings.hpp"
#include "core/logger.hpp"
#include <eiface.h>
#include <tier1/convar.h>
#include <sstream>

using CommandCallback = void (*)(int32_t playerSlot, const plg::vector<plg::string> &args);
using ExecCommandAsPlayerFn = uint8_t(__fastcall *)(int32_t slot, const char *cmd);

static std::unordered_map<std::string, CommandCallback> g_ServerCommandCallbacks;
static std::unordered_map<std::string, CommandCallback> g_ClientCommandCallbacks;
static std::unordered_map<std::string, CommandCallback> g_ChatCommandCallbacks;
static std::unordered_map<std::string, CommandCallback> g_UniversalCommandCallbacks;
static std::unordered_map<std::string, ConCommand *> g_EngineConCommands;

static std::string GetServerPrefix() {
    std::string prefix = dsdk::Settings::Get().GetString("commands.server_prefix", "plg");
    if (!prefix.empty() && !prefix.ends_with('_')) {
        prefix += "_";
    }
    return prefix;
}

static std::vector<std::string> GetChatPrefixes() {
    std::vector<std::string> prefixes;
    try {
        const auto &json = dsdk::Settings::Get().GetJson();
        if (json.contains("commands") && json["commands"].contains("chat_prefixes") && json["commands"]["chat_prefixes"].is_array()) {
            for (const auto &item : json["commands"]["chat_prefixes"]) {
                if (item.is_string()) {
                    prefixes.push_back(item.get<std::string>());
                }
            }
        }
    } catch (...) {}
    if (prefixes.empty()) {
        prefixes = { "!", "/" };
    }
    return prefixes;
}

namespace dsdk {

bool DispatchCommand(int playerSlot, const CCommand &args) {
    if (args.ArgC() <= 0) return false;
    std::string cmdName = args.Arg(0);

    // If typed with prefix ('!' or '/') in client console or server terminal
    if (!cmdName.empty() && (cmdName[0] == '!' || cmdName[0] == '/')) {
        cmdName = cmdName.substr(1);
    }

    std::string srvPrefix = GetServerPrefix();
    if (!srvPrefix.empty()) {
        if (!cmdName.starts_with(srvPrefix)) {
            return false;
        }
    }

    plg::vector<plg::string> vecArgs;
    vecArgs.emplace_back(cmdName);
    for (int i = 1; i < args.ArgC(); ++i) {
        vecArgs.emplace_back(args.Arg(i));
    }

    if (playerSlot == -1) {
        // Server console: check server-specific commands first
        auto it = g_ServerCommandCallbacks.find(cmdName);
        if (it != g_ServerCommandCallbacks.end() && it->second) {
            it->second(playerSlot, vecArgs);
            return true;
        }
    } else {
        // Client console (slot >= 0): check client-specific commands first
        auto it = g_ClientCommandCallbacks.find(cmdName);
        if (it != g_ClientCommandCallbacks.end() && it->second) {
            it->second(playerSlot, vecArgs);
            return true;
        }
    }

    // Fall back to universal commands
    auto itUniv = g_UniversalCommandCallbacks.find(cmdName);
    if (itUniv != g_UniversalCommandCallbacks.end() && itUniv->second) {
        itUniv->second(playerSlot, vecArgs);
        return true;
    }

    return false;
}

bool DispatchChatCommand(int playerSlot, const std::string &chatText) {
    if (chatText.empty()) return false;

    // Trim leading whitespace
    std::string text = chatText;
    while (!text.empty() && (text.front() == ' ' || text.front() == '\t' || text.front() == '\r' || text.front() == '\n')) {
        text.erase(text.begin());
    }
    if (text.empty()) return false;

    // MUST start with a configured chat prefix (default '!' or '/')
    auto prefixes = GetChatPrefixes();
    std::string matchedPrefix;
    for (const auto &pfx : prefixes) {
        if (!pfx.empty() && text.starts_with(pfx)) {
            matchedPrefix = pfx;
            break;
        }
    }
    if (matchedPrefix.empty()) {
        // Plain text without ! or / is normal chat, NEVER execute as command
        return false;
    }

    std::string line = text.substr(matchedPrefix.length());
    while (!line.empty() && (line.front() == ' ' || line.front() == '\t')) {
        line.erase(line.begin());
    }
    if (line.empty()) return true; // Suppress lone '!' or '/'

    // Tokenize arguments (whitespace delimited, preserves tokens)
    std::stringstream ss(line);
    std::string token;
    plg::vector<plg::string> vecArgs;
    while (ss >> token) {
        vecArgs.push_back(token);
    }
    if (vecArgs.empty()) return true;

    std::string cmdName = vecArgs[0].c_str();

    // 1. Check chat-specific command callbacks first
    auto itChat = g_ChatCommandCallbacks.find(cmdName);
    if (itChat != g_ChatCommandCallbacks.end() && itChat->second) {
        dsdk::Logger::Debug("[ChatCommand] Dispatched chat command '{}' from slot {}", cmdName, playerSlot);
        itChat->second(playerSlot, vecArgs);
        return true;
    }

    // 2. Check universal callbacks (with and without prefix)
    auto itUniv = g_UniversalCommandCallbacks.find(cmdName);
    if (itUniv == g_UniversalCommandCallbacks.end()) {
        std::string srvPrefix = GetServerPrefix();
        if (!srvPrefix.empty()) {
            if (cmdName.starts_with(srvPrefix)) {
                itUniv = g_UniversalCommandCallbacks.find(cmdName.substr(srvPrefix.length()));
            } else {
                itUniv = g_UniversalCommandCallbacks.find(srvPrefix + cmdName);
            }
        }
    }
    if (itUniv != g_UniversalCommandCallbacks.end() && itUniv->second) {
        dsdk::Logger::Debug("[ChatCommand] Dispatched universal command '{}' via chat from slot {}", cmdName, playerSlot);
        itUniv->second(playerSlot, vecArgs);
        return true;
    }

    // Suppress unrecognized prefixed commands so typos like !help don't spam public chat
    return true;
}

} // namespace dsdk

static void ConCommandDispatchCallback(const CCommandContext &context, const CCommand &args) {
    int playerSlot = context.GetPlayerSlot().Get();
    dsdk::DispatchCommand(playerSlot, args);
}

extern "C" {

PLUGIN_API bool AddServerCommand(const plg::string &name, const plg::string &description, int64_t flags, CommandCallback callback) {
    std::string strName(name.c_str());
    if (strName.empty() || !callback) return false;

    while (!strName.empty() && (strName.front() == '!' || strName.front() == '/')) {
        strName.erase(strName.begin());
    }

    std::string srvPrefix = GetServerPrefix();
    std::string engineCmdName;
    if (!srvPrefix.empty()) {
        if (!strName.starts_with(srvPrefix)) {
            engineCmdName = srvPrefix + strName;
        } else {
            engineCmdName = strName;
            strName = engineCmdName.substr(srvPrefix.length());
        }
    } else {
        engineCmdName = strName;
    }

    uint64_t nFlags = static_cast<uint64_t>(flags);
    if (nFlags == 0) {
        nFlags = FCVAR_LINKED_CONCOMMAND;
    }

    g_ServerCommandCallbacks[engineCmdName] = callback;
    g_ServerCommandCallbacks[strName] = callback;

    if (g_EngineConCommands.find(engineCmdName) == g_EngineConCommands.end()) {
        char *pName = _strdup(engineCmdName.c_str());
        char *pHelp = _strdup(description.c_str());
        auto *cmd = new ConCommand(pName, ConCommandDispatchCallback, pHelp, nFlags);
        g_EngineConCommands[engineCmdName] = cmd;
    }

    dsdk::Logger::Debug("Registered server-only console command: '{}' (engine: '{}')", strName, engineCmdName);
    return true;
}

PLUGIN_API bool AddClientCommand(const plg::string &name, const plg::string &description, int64_t flags, CommandCallback callback) {
    std::string strName(name.c_str());
    if (strName.empty() || !callback) return false;

    while (!strName.empty() && (strName.front() == '!' || strName.front() == '/')) {
        strName.erase(strName.begin());
    }

    std::string srvPrefix = GetServerPrefix();
    std::string engineCmdName;
    if (!srvPrefix.empty()) {
        if (!strName.starts_with(srvPrefix)) {
            engineCmdName = srvPrefix + strName;
        } else {
            engineCmdName = strName;
            strName = engineCmdName.substr(srvPrefix.length());
        }
    } else {
        engineCmdName = strName;
    }

    uint64_t nFlags = static_cast<uint64_t>(flags) | FCVAR_CLIENT_CAN_EXECUTE | FCVAR_LINKED_CONCOMMAND;

    g_ClientCommandCallbacks[engineCmdName] = callback;
    g_ClientCommandCallbacks[strName] = callback;

    if (g_EngineConCommands.find(engineCmdName) == g_EngineConCommands.end()) {
        char *pName = _strdup(engineCmdName.c_str());
        char *pHelp = _strdup(description.c_str());
        auto *cmd = new ConCommand(pName, ConCommandDispatchCallback, pHelp, nFlags);
        g_EngineConCommands[engineCmdName] = cmd;
    }

    dsdk::Logger::Debug("Registered client console command: '{}' (engine: '{}')", strName, engineCmdName);
    return true;
}

PLUGIN_API bool AddChatCommand(const plg::string &name, const plg::string &description, int64_t flags, CommandCallback callback) {
    std::string strName(name.c_str());
    if (strName.empty() || !callback) return false;

    while (!strName.empty() && (strName.front() == '!' || strName.front() == '/')) {
        strName.erase(strName.begin());
    }

    g_ChatCommandCallbacks[strName] = callback;
    dsdk::Logger::Debug("Registered client chat command: '{}'", strName);
    return true;
}

PLUGIN_API bool AddConsoleCommand(const plg::string &name, const plg::string &description, int64_t flags, CommandCallback callback) {
    std::string strName(name.c_str());
    if (strName.empty() || !callback) return false;

    while (!strName.empty() && (strName.front() == '!' || strName.front() == '/')) {
        strName.erase(strName.begin());
    }

    std::string srvPrefix = GetServerPrefix();
    std::string engineCmdName;
    if (!srvPrefix.empty()) {
        if (!strName.starts_with(srvPrefix)) {
            engineCmdName = srvPrefix + strName;
        } else {
            engineCmdName = strName;
            strName = engineCmdName.substr(srvPrefix.length());
        }
    } else {
        engineCmdName = strName;
    }

    uint64_t nFlags = static_cast<uint64_t>(flags);
    if (nFlags == 0) {
        nFlags = FCVAR_CLIENT_CAN_EXECUTE | FCVAR_LINKED_CONCOMMAND;
    }

    g_UniversalCommandCallbacks[engineCmdName] = callback;
    g_UniversalCommandCallbacks[strName] = callback;

    if (g_EngineConCommands.find(engineCmdName) == g_EngineConCommands.end()) {
        char *pName = _strdup(engineCmdName.c_str());
        char *pHelp = _strdup(description.c_str());
        auto *cmd = new ConCommand(pName, ConCommandDispatchCallback, pHelp, nFlags);
        g_EngineConCommands[engineCmdName] = cmd;
    }

    dsdk::Logger::Debug("Registered universal console command: '{}' (engine: '{}')", strName, engineCmdName);
    return true;
}

PLUGIN_API bool RemoveCommand(const plg::string &name) {
    std::string strName(name.c_str());
    g_ServerCommandCallbacks.erase(strName);
    g_ClientCommandCallbacks.erase(strName);
    g_ChatCommandCallbacks.erase(strName);
    g_UniversalCommandCallbacks.erase(strName);

    std::string srvPrefix = GetServerPrefix();
    if (!srvPrefix.empty()) {
        g_ServerCommandCallbacks.erase(srvPrefix + strName);
        g_ClientCommandCallbacks.erase(srvPrefix + strName);
        g_UniversalCommandCallbacks.erase(srvPrefix + strName);
    }

    auto it = g_EngineConCommands.find(strName);
    if (it != g_EngineConCommands.end()) {
        delete it->second;
        g_EngineConCommands.erase(it);
        return true;
    }
    if (!srvPrefix.empty()) {
        it = g_EngineConCommands.find(srvPrefix + strName);
        if (it != g_EngineConCommands.end()) {
            delete it->second;
            g_EngineConCommands.erase(it);
            return true;
        }
    }
    return false;
}

PLUGIN_API void ServerCommand(const plg::string &command) {
    if (dsdk::g_pEngineServer) {
        std::string cmd = std::string(command.c_str()) + "\n";
        dsdk::g_pEngineServer->ServerCommand(cmd.c_str());
    }
}

PLUGIN_API bool ExecuteCommandAsPlayer(int32_t playerSlot, const plg::string &command) {
    auto offset = dsdk::MemoryDataLoader::Get().GetOffset("ExecuteCommandAsPlayer");
    if (!offset.has_value()) {
        if (dsdk::g_pEngineServer) {
            std::string cmd = std::string(command.c_str()) + "\n";
            dsdk::g_pEngineServer->ServerCommand(cmd.c_str());
            return true;
        }
        return false;
    }
    auto fn = reinterpret_cast<ExecCommandAsPlayerFn>(*offset);
    return fn(playerSlot, command.c_str()) != 0;
}

PLUGIN_API void ClientCommand(int32_t playerSlot, const plg::string &command) {
    if (dsdk::g_pEngineServer) {
        dsdk::g_pEngineServer->ClientCommand(CPlayerSlot(playerSlot), command.c_str());
    }
}

}
