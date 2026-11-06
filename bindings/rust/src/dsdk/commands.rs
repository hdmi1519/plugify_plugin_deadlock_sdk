// Generated from dsdk.pplugin (group: commands)

#[allow(unused_imports)]
use std::sync::RwLock;
#[allow(unused_imports)]
use super::enums::*;
#[allow(unused_imports)]
use super::aliases::*;
#[allow(unused_imports)]
use super::delegates::*;
#[allow(unused_imports)]
use plugify::{scope, Str, Arr, Var, Vec2, Vec3, Vec4, Mat4x4};

/// Register a server-console-only command
///
/// # Arguments
/// * `name` - (string)
/// * `description` - (string)
/// * `flags` - (int64)
/// * `callback` - (function)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn AddServerCommand(name: &Str, description: &Str, flags: i64, callback: CommandCallback) -> bool {
    unsafe { __dsdk_AddServerCommand.expect("AddServerCommand function was not found")(name, description, flags, callback) }
}
pub type _AddServerCommand = unsafe extern "C" fn(&Str, &Str, i64, CommandCallback) -> bool;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_AddServerCommand: Option<_AddServerCommand> = None;

/// Register a client-console-only command
///
/// # Arguments
/// * `name` - (string)
/// * `description` - (string)
/// * `flags` - (int64)
/// * `callback` - (function)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn AddClientCommand(name: &Str, description: &Str, flags: i64, callback: CommandCallback) -> bool {
    unsafe { __dsdk_AddClientCommand.expect("AddClientCommand function was not found")(name, description, flags, callback) }
}
pub type _AddClientCommand = unsafe extern "C" fn(&Str, &Str, i64, CommandCallback) -> bool;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_AddClientCommand: Option<_AddClientCommand> = None;

/// Register a client-chat-only command
///
/// # Arguments
/// * `name` - (string)
/// * `description` - (string)
/// * `flags` - (int64)
/// * `callback` - (function)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn AddChatCommand(name: &Str, description: &Str, flags: i64, callback: CommandCallback) -> bool {
    unsafe { __dsdk_AddChatCommand.expect("AddChatCommand function was not found")(name, description, flags, callback) }
}
pub type _AddChatCommand = unsafe extern "C" fn(&Str, &Str, i64, CommandCallback) -> bool;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_AddChatCommand: Option<_AddChatCommand> = None;

/// Register a server/chat console command
///
/// # Arguments
/// * `name` - (string)
/// * `description` - (string)
/// * `flags` - (int64)
/// * `callback` - (function)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn AddConsoleCommand(name: &Str, description: &Str, flags: i64, callback: CommandCallback) -> bool {
    unsafe { __dsdk_AddConsoleCommand.expect("AddConsoleCommand function was not found")(name, description, flags, callback) }
}
pub type _AddConsoleCommand = unsafe extern "C" fn(&Str, &Str, i64, CommandCallback) -> bool;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_AddConsoleCommand: Option<_AddConsoleCommand> = None;

/// Unregister a console command
///
/// # Arguments
/// * `name` - (string)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn RemoveCommand(name: &Str) -> bool {
    unsafe { __dsdk_RemoveCommand.expect("RemoveCommand function was not found")(name) }
}
pub type _RemoveCommand = unsafe extern "C" fn(&Str) -> bool;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_RemoveCommand: Option<_RemoveCommand> = None;

/// Execute a command on the server console
///
/// # Arguments
/// * `command` - (string)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn ServerCommand(command: &Str) {
    unsafe { __dsdk_ServerCommand.expect("ServerCommand function was not found")(command) }
}
pub type _ServerCommand = unsafe extern "C" fn(&Str);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_ServerCommand: Option<_ServerCommand> = None;

/// Execute a command on behalf of a player
///
/// # Arguments
/// * `playerSlot` - (int32)
/// * `command` - (string)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn ExecuteCommandAsPlayer(playerSlot: i32, command: &Str) -> bool {
    unsafe { __dsdk_ExecuteCommandAsPlayer.expect("ExecuteCommandAsPlayer function was not found")(playerSlot, command) }
}
pub type _ExecuteCommandAsPlayer = unsafe extern "C" fn(i32, &Str) -> bool;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_ExecuteCommandAsPlayer: Option<_ExecuteCommandAsPlayer> = None;

/// Execute command on client
///
/// # Arguments
/// * `playerSlot` - (int32)
/// * `command` - (string)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn ClientCommand(playerSlot: i32, command: &Str) {
    unsafe { __dsdk_ClientCommand.expect("ClientCommand function was not found")(playerSlot, command) }
}
pub type _ClientCommand = unsafe extern "C" fn(i32, &Str);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_ClientCommand: Option<_ClientCommand> = None;

