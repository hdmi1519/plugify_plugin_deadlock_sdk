#include "pch.hpp"
#include "core/globals.hpp"
#include <icvar.h>
#include <tier1/convar.h>
#include <tier0/bufferstring.h>

extern "C" {

PLUGIN_API uint64_t FindConVar(const plg::string &name) {
    if (!dsdk::g_pCVar || name.empty()) return 0;
    ConVarRef ref = dsdk::g_pCVar->FindConVar(name.c_str());
    return ref.IsValidRef() ? static_cast<uint64_t>(ref) : 0;
}

PLUGIN_API uint64_t CreateConVar(const plg::string &name, const plg::string &defaultValue, const plg::string &description, uint64_t flags) {
    if (!dsdk::g_pCVar || name.empty()) return 0;
    ConVarRef ref = dsdk::g_pCVar->FindConVar(name.c_str());
    if (ref.IsValidRef()) return static_cast<uint64_t>(ref);
    return 0;
}

PLUGIN_API int32_t GetConVarInt(uint64_t handle) {
    if (!handle || !dsdk::g_pCVar) return 0;
    ConVarRef ref(handle);
    ConVarData *data = dsdk::g_pCVar->GetConVarData(ref);
    if (!data) return 0;
    ConVarRefAbstract cvarAbs(ref, data);
    return cvarAbs.GetAs<int>();
}

PLUGIN_API float GetConVarFloat(uint64_t handle) {
    if (!handle || !dsdk::g_pCVar) return 0.0f;
    ConVarRef ref(handle);
    ConVarData *data = dsdk::g_pCVar->GetConVarData(ref);
    if (!data) return 0.0f;
    ConVarRefAbstract cvarAbs(ref, data);
    return cvarAbs.GetAs<float>();
}

PLUGIN_API plg::string GetConVarString(uint64_t handle) {
    if (!handle || !dsdk::g_pCVar) return plg::string("");
    ConVarRef ref(handle);
    ConVarRefAbstract cvarAbs(ref);
    if (!cvarAbs.IsValidRef() || !cvarAbs.IsConVarDataValid()) return plg::string("");
    CBufferStringGrowable<256> buf;
    cvarAbs.GetValueAsString(buf);
    return plg::string(buf.Get() ? buf.Get() : "");
}

PLUGIN_API bool GetConVarBool(uint64_t handle) {
    if (!handle || !dsdk::g_pCVar) return false;
    ConVarRef ref(handle);
    ConVarData *data = dsdk::g_pCVar->GetConVarData(ref);
    if (!data) return false;
    ConVarRefAbstract cvarAbs(ref, data);
    return cvarAbs.GetAs<bool>();
}

PLUGIN_API void SetConVarInt(uint64_t handle, int32_t value) {
    if (!handle || !dsdk::g_pCVar) return;
    ConVarRef ref(handle);
    ConVarData *data = dsdk::g_pCVar->GetConVarData(ref);
    if (!data) return;
    ConVarRefAbstract cvarAbs(ref, data);
    cvarAbs.RemoveFlags(FCVAR_CHEAT | FCVAR_PROTECTED);
    cvarAbs.SetAs<int>(value);
}

PLUGIN_API void SetConVarFloat(uint64_t handle, float value) {
    if (!handle || !dsdk::g_pCVar) return;
    ConVarRef ref(handle);
    ConVarData *data = dsdk::g_pCVar->GetConVarData(ref);
    if (!data) return;
    ConVarRefAbstract cvarAbs(ref, data);
    cvarAbs.RemoveFlags(FCVAR_CHEAT | FCVAR_PROTECTED);
    cvarAbs.SetAs<float>(value);
}

PLUGIN_API bool SetConVarString(uint64_t handle, const plg::string &value) {
    if (!handle || !dsdk::g_pCVar) return false;
    ConVarRef ref(handle);
    ConVarData *data = dsdk::g_pCVar->GetConVarData(ref);
    if (!data) return false;
    ConVarRefAbstract cvarAbs(ref, data);
    cvarAbs.RemoveFlags(FCVAR_CHEAT | FCVAR_PROTECTED);
    return cvarAbs.SetString(CUtlString(value.c_str()));
}

}
