# Plugify Deadlock SDK (dsdk)

<p align="center">
  <a href="README.md">English</a> | <b>Русский</b>
</p>

<p align="center">
  <b>Высокопроизводительный нативный C++ Deadlock SDK плагин для экосистемы <a href="https://github.com/untrustedmodders/plugify">Plugify</a>.</b>
</p>

---

## 📖 Обзор проекта

**Plugify Deadlock SDK (`dsdk`)** — это нативное C++ расширение, предоставляющее глубокую интеграцию с выделенным сервером игры **Deadlock** от Valve. Проект служит производительным мостом между движком Source 2 и плагинами Plugify, написанными на **Golang, C++, C#, Python, Rust, Lua, JavaScript (V8) и D**.

`dsdk` представляет собой нативную C++ реализацию и архитектурный порт реверс-инжиниринговых API, сигнатур памяти, хуков и схем сущностей, заложенных проектом **[Deadworks](https://github.com/Deadworks-net/deadworks)** и интерактивной базой данных **[Deadworks Modding Database](https://deadworks.net/db)**. В то время как Deadworks спроектирован как монолитный C#-фреймворк, `dsdk` ориентирован на модульную экосистему Plugify, позволяя разработчикам серверов писать плагины для Deadlock на удобном языке с практически нулевыми накладными расходами.

---

## 🌟 Ключевая архитектура и возможности

### 1. Динамическое разрешение смещений схем (Schema Resolution)
В отличие от плагинов с захардкоженными оффсетами, `dsdk` запрашивает смещения полей сущностей динамически при старте сервера через `g_pSchemaSystem` (`server.dll`).
- **Устойчивость к патчам:** Мелкие обновления игры, сдвигающие поля в структурах, не ломают плагин и не требуют перекомпиляции.
- Автоматическое кэширование с 32-битным FNV-1a хешированием обеспечивает доступ к полям за наносекунды.

### 2. Универсальный динамический диспетчер игровых эвентов
- **Никакого хардкода эвентов:** Подписка на **любой** игровой эвент Source 2 в рантайме с помощью `RegisterGameEvent(name)`.
- Поддержка `player_death`, `player_respawned`, `entity_killed`, `hideout_lobby_changed` или любых кастомных эвентов на лету.
- Встроенные хелперы для мгновенного получения слота игрока, контроллера и пешки из параметров эвента.

### 3. Внутриигровой интерфейс и коммуникации
- **HUD Оповещения:** Отображение анимированных баннеров-анонсов на экранах игроков (`SetHUDAnnouncement`, `SetHUDAnnouncementForPlayer`).
- **Чат и Консоль:** Широковещательные сообщения в чат, вывод в консоль разработчика и выполнение клиентских команд от имени игрока (`DispatchCommandAsPlayer`).

### 4. Хуки движка (SafetyHook)
Низкоуровневые inline-хуки на базе библиотеки [SafetyHook](https://github.com/cursey/safetyhook):
- `CCitadelPlayerPawn::ModifyCurrency` — Отслеживание, изменение или блокировка получения/траты душ и золота.
- `CBaseEntity::TakeDamageOld` — Перехват и модификация входящего урона и параметров удара.
- `ProcessUsercmds` — Чтение и модификация команд ввода игрока.
- `ClientConnect` / `ClientDisconnect` — Отслеживание жизненного цикла сессий игроков.

### 5. Геймплей и управление сущностями
- **ConVars:** Чтение и запись строковых, дробных, целочисленных и логических кваров (с корректной поддержкой смещения типов `int8`/`uint8` из билда Deadlock 6860+).
- **Способности и Модификаторы:** Прокачка способностей, включение/выключение, добавление/трата зарядов, наложение и снятие модификаторов по имени VData.
- **Герои и Пешки:** Возрождение, выбор героя, проверка команды и состояния пешек.
- **NPC и Крипы:** Спавн крипов на линии и нейтралов (`Trooper_SpawnAt`), управление передвижением (`ForceNpcGo`, `StopMoving`).
- **Навигация и Трассировка:** Запросы к навмешу (`CNavMesh::GetNearestNav`, `CNavPath::ComputePathPosToPos`) и геометрические лучи (`TraceShape`).

---

## 🔗 Связанные проекты и благодарности

SDK опирается на наработки сообществ разработки под Source 2 и Deadlock:

- **[Deadworks](https://github.com/Deadworks-net/deadworks)** — C# фреймворк для моддинга Deadlock, послуживший основой для сигнатур памяти и логики движка.
- **[Deadworks Modding Database](https://deadworks.net/db)** — Интерактивная база данных схем, сущностей, конваров и эвентов Deadlock.
- **[Plugify](https://github.com/untrustedmodders/plugify)** — Мультиязычный высокопроизводительный фреймворк для плагинов.
- **[Untrusted Modders](https://github.com/untrustedmodders)** — Организация-создатель Plugify и языковых модулей.
- **[plugify-plugin-s2sdk](https://github.com/untrustedmodders/plugify-plugin-s2sdk)** — Референсный плагин Source 2 SDK под Counter-Strike 2.
- **[plugify-source2-launcher](https://github.com/untrustedmodders/plugify-source2-launcher)** — Лаунчер выделенного сервера Source 2 с интеграцией Plugify.
- **[Wend4r/sourcesdk](https://github.com/Wend4r/sourcesdk)** — Заголовочные файлы и определения движка Source 2 C++.
- **[SafetyHook](https://github.com/cursey/safetyhook)** — Быстрая библиотека для inline-перехвата функций x86/x64.

---

## 📦 Установка и развертывание

1. Скачайте свежую сборку со страницы **[Releases](https://github.com/untrustedmodders/plugify-plugin-deadlock-sdk/releases)** (`plugify-plugin-deadlock-sdk-build-win-vX.X.X.zip`).
2. Распакуйте файлы в каталог плагинов вашего выделенного сервера:
   ```text
   deadlock_server/game/citadel/addons/plugify/envs/plugins/
   ├── bin/
   │   └── plugify-plugin-deadlock-sdk.dll
   ├── plugify-plugin-deadlock-sdk.pplugin
   ├── signatures.jsonc
   └── settings.jsonc
   ```
3. Чтобы видеть полные отладочные сообщения (поиск сигнатур, хуки), добавьте аргумент `--verbosity=debug` в команду запуска сервера:
   ```bat
   .\s2launcher.exe --verbosity=debug -dedicated -dev -console -insecure ...
   ```

---

## 💻 Пример плагина на Go

Использование автоматически сгенерированных биндингов из `bindings/golang`:

```go
package main

import (
    "fmt"
    "github.com/untrustedmodders/go-plugify"
    "dev_utils/dsdk"
)

type MyPlugin struct{}

func (p *MyPlugin) OnPluginStart() {
    // Динамически подписываемся на события смерти и возрождения
    dsdk.RegisterGameEvent("player_death")
    dsdk.RegisterGameEvent("player_respawned")

    // Обрабатываем игровые события
    dsdk.OnGameEvent_Register(func(eventName string, eventHandle int64) {
        slot := dsdk.GameEventGetPlayerSlot(eventHandle, "userid")
        if slot >= 0 {
            name := dsdk.GetPlayerName(int32(slot))
            if eventName == "player_death" {
                dsdk.BroadcastChatMessage(fmt.Sprintf("[DEATH] Игрок %s погиб!", name))
            } else if eventName == "player_respawned" {
                dsdk.SetHUDAnnouncement(fmt.Sprintf("%s возродился на поле боя!", name), 4.0)
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

## 🛠 Автоматизация GitHub Actions

В репозитории настроены два автоматических воркфлоу:

1. **[generate_bindings.yml](.github/workflows/generate_bindings.yml)**:
   Срабатывает при push при изменении шаблона манифеста или версий. Собирает чистый инструмент `plugify-gen` и автоматически генерирует биндинги для всех языков (`cpp`, `cxx`, `dlang`, `dotnet`, `golang`, `lua`, `python`, `rust`, `v8`) в папку `bindings/`.
2. **[build.yml](.github/workflows/build.yml)**:
   Собирает Windows Release библиотеку с помощью MSVC, упаковывает `.dll`, готовый `.pplugin`, `signatures.jsonc` и `settings.jsonc` в архив `plugify-plugin-deadlock-sdk-build-win-v<версия>.zip` и публикует релизные артефакты.

---

## 📄 Лицензия

Проект распространяется под лицензией **GPLv3**. Подробности в файле `LICENSE`.
