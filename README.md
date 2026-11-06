# Plugify Deadlock SDK (dsdk)

<p align="center">
  <b>English</b> | <a href="README_ru.md">Русский</a>
</p>

<p align="center">
  <img src="https://raw.githubusercontent.com/untrustedmodders/plugify/refs/heads/main/assets/plugify-logo.png" alt="Plugify Logo" width="128"/>
</p>

<p align="center">
  <b>A high-performance C++ Deadlock SDK plugin for the <a href="https://github.com/untrustedmodders/plugify">Plugify</a> modding ecosystem.</b>
</p>

---

## 📖 Overview

**Plugify Deadlock SDK (`dsdk`)** is a native C++ extension that provides deep integration with Valve's **Deadlock** dedicated server. It acts as a comprehensive bridge between the Source 2 engine and Plugify plugins written in **Golang, C++, C#, Python, Rust, Lua, JavaScript (V8), and D**.

`dsdk` is a native C++ implementation and architectural port of the reverse-engineered APIs, memory signatures, engine hooks, and entity systems pioneered by the **[Deadworks](https://github.com/Deadworks-net/deadworks)** project and the **[Deadworks Modding Database](https://deadworks.net/db)**. While Deadworks is engineered as a standalone C# framework, `dsdk` is purpose-built for the modular Plugify ecosystem, allowing server modders to write Deadlock plugins in their language of choice with near-zero runtime overhead.

---

## 🌟 Key Architecture & Features

### 1. Dynamic Runtime Schema Resolution
Unlike traditional plugins that hardcode memory offsets at compile time, `dsdk` queries field offsets dynamically at server startup via Source 2's `g_pSchemaSystem` (`server.dll`).
- **Update Immunity:** Minor game patches that displace structure fields do not break the plugin or require recompilation.
- Automatic caching using 32-bit FNV-1a hashing guarantees nanosecond-level field lookups.

### 2. Generic Dynamic Game Event Dispatcher
- **Zero Hardcoded Events:** Subscribe to **any** Source 2 game event dynamically at runtime using `RegisterGameEvent(name)`.
- Listen to `player_death`, `player_respawned`, `entity_killed`, `hideout_lobby_changed`, or custom game events on the fly.
- Helper functions to easily extract player slots, controllers, and pawns from event parameters.

### 3. In-Game HUD & Communications
- **HUD Announcements:** Display high-priority, animated announcement banners across client screens (`SetHUDAnnouncement`, `SetHUDAnnouncementForPlayer`).
- **Chat & Console:** Broadcast in-game chat messages, print to developer consoles, and execute client-side console commands (`DispatchCommandAsPlayer`).

### 4. Engine Detours & Hooks (SafetyHook)
Low-overhead inline function hooking powered by [SafetyHook](https://github.com/cursey/safetyhook):
- `CCitadelPlayerPawn::ModifyCurrency` — Inspect, alter, or block souls/gold gains and expenditures.
- `CBaseEntity::TakeDamageOld` — Intercept and modify incoming damage info and calculations.
- `ProcessUsercmds` — Access and alter player input commands.
- `ClientConnect` / `ClientDisconnect` — Full lifecycle tracking across map changes.

### 5. Gameplay & Entity Management
- **ConVars:** Read and write integer, float, string, and boolean console variables (with built-in support for Deadlock build 6860+ `int8`/`uint8` type offsets).
- **Abilities & Modifiers:** Upgrade ability bits, toggle activation, grant/consume charges, and apply/remove modifiers by VData name.
- **Heroes & Pawns:** Respawn heroes, select hero pawns, query player teams, and inspect player pawn states.
- **NPCs & Troopers:** Spawn lane minions and neutral creeps (`Trooper_SpawnAt`), issue movement and state orders (`ForceNpcGo`, `StopMoving`).
- **Navigation & Tracing:** Query navmesh points (`CNavMesh::GetNearestNav`, `CNavPath::ComputePathPosToPos`) and perform geometric raycasts (`TraceShape`).

---

## 🔗 Related Projects & Credits

This SDK builds upon foundational work from across the Source 2 and Deadlock modding communities:

- **[Deadworks](https://github.com/Deadworks-net/deadworks)** — The pioneering Source 2 C# modding framework for Deadlock, from which memory signatures, offsets, and game systems were referenced.
- **[Deadworks Modding Database](https://deadworks.net/db)** — Interactive reference for Deadlock schemas, entities, convars, and game events.
- **[Plugify](https://github.com/untrustedmodders/plugify)** — Next-generation, high-performance multi-language plugin framework.
- **[Untrusted Modders](https://github.com/untrustedmodders)** — Organization maintaining Plugify core and language modules.
- **[plugify-plugin-s2sdk](https://github.com/untrustedmodders/plugify-plugin-s2sdk)** — Reference Source 2 SDK plugin for Counter-Strike 2.
- **[plugify-source2-launcher](https://github.com/untrustedmodders/plugify-source2-launcher)** — Dedicated server launcher for Source 2 games.
- **[Wend4r/sourcesdk](https://github.com/Wend4r/sourcesdk)** — Modern Source 2 C++ engine headers and definitions.
- **[SafetyHook](https://github.com/cursey/safetyhook)** — Fast, lightweight x86/x64 inline hooking library.

---

## 📦 Installation & Deployment

1. Download the latest build from the **[Releases](https://github.com/untrustedmodders/plugify-plugin-deadlock-sdk/releases)** page (`plugify-plugin-deadlock-sdk-build-win-vX.X.X.zip`).
2. Extract the files into your dedicated server's plugin directory:
   ```text
   deadlock_server/game/citadel/addons/plugify/envs/plugins/
   ├── bin/
   │   └── plugify-plugin-deadlock-sdk.dll
   ├── plugify-plugin-deadlock-sdk.pplugin
   ├── signatures.jsonc
   └── settings.jsonc
   ```
3. To view full debug messages (signature scans, hook initializations), add `--verbosity=debug` to your server startup command:
   ```bat
   .\s2launcher.exe --verbosity=debug -dedicated -dev -console -insecure ...
   ```

---

## 💻 Example: Writing a Plugin in Go

Using the auto-generated Go bindings from `bindings/golang`:

```go
package main

import (
    "fmt"
    "github.com/untrustedmodders/go-plugify"
    "dev_utils/dsdk"
)

type MyPlugin struct{}

func (p *MyPlugin) OnPluginStart() {
    // Dynamically register for player death and respawn events
    dsdk.RegisterGameEvent("player_death")
    dsdk.RegisterGameEvent("player_respawned")

    // Listen to generic game events
    dsdk.OnGameEvent_Register(func(eventName string, eventHandle int64) {
        slot := dsdk.GameEventGetPlayerSlot(eventHandle, "userid")
        if slot >= 0 {
            name := dsdk.GetPlayerName(int32(slot))
            if eventName == "player_death" {
                dsdk.BroadcastChatMessage(fmt.Sprintf("[DEATH] Player %s was eliminated!", name))
            } else if eventName == "player_respawned" {
                dsdk.SetHUDAnnouncement(fmt.Sprintf("%s has returned to the fight!", name), 4.0)
            }
        }
    })
}

func (p *MyPlugin) OnPluginEnd() {}

func main() {
    plugify.RegisterPlugin(&MyPlugin{})
}
```

---

## 🛠 CI/CD Workflows

This repository uses automated GitHub Actions workflows:

1. **[generate_bindings.yml](.github/workflows/generate_bindings.yml)**:
   Triggered on push whenever the manifest template or versions change. It compiles the clean `plugify-gen` tool and auto-generates bindings for all languages (`cpp`, `cxx`, `dlang`, `dotnet`, `golang`, `lua`, `python`, `rust`, `v8`) into `bindings/`.
2. **[build.yml](.github/workflows/build.yml)**:
   Builds the Windows Release binary using MSVC, packages the `.dll`, configured `.pplugin`, `signatures.jsonc`, and `settings.jsonc` into a zip archive named `plugify-plugin-deadlock-sdk-build-win-v<version>.zip`, and publishes release artifacts.

---

## 📄 License

This project is licensed under the **GPLv3 License**. See the `LICENSE` file for details.
