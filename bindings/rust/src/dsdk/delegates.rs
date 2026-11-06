// Generated from dsdk.pplugin

#[allow(unused_imports)]
use super::enums::*;
#[allow(unused_imports)]
use super::aliases::*;
#[allow(unused_imports)]
use plugify::{Str, Arr, Var, Vec2, Vec3, Vec4, Mat4x4};

#[allow(unused)]
pub type CommandCallback = unsafe extern "C" fn(i32, &Arr<Str>);


#[allow(unused)]
pub type TimerCallback = unsafe extern "C" fn();


#[allow(unused)]
pub type ModifyCurrencyCallback = unsafe extern "C" fn(i64, ECurrencyType, i32, ECurrencySource, bool, bool, bool, i64, i64) -> HookResult;


#[allow(unused)]
pub type TakeDamageCallback = unsafe extern "C" fn(i64, i64) -> HookResult;


#[allow(unused)]
pub type ClientConnectCallback = unsafe extern "C" fn(i32, &Str, u64) -> bool;


#[allow(unused)]
pub type ClientPutInServerCallback = unsafe extern "C" fn(i32);


#[allow(unused)]
pub type ClientDisconnectCallback = unsafe extern "C" fn(i32, i32);


#[allow(unused)]
pub type GameFrameCallback = unsafe extern "C" fn(bool, bool, bool);


#[allow(unused)]
pub type EntityCallback = unsafe extern "C" fn(i64);


#[allow(unused)]
pub type GameStateChangedCallback = unsafe extern "C" fn(EGameState);


#[allow(unused)]
pub type EntityIOCallback = unsafe extern "C" fn(&Str, &Str, i64, i64, i64, &Str) -> HookResult;


#[allow(unused)]
pub type NpcSelectScheduleCallback = unsafe extern "C" fn(i64, &Str) -> Str;


#[allow(unused)]
pub type EntityOutputCallback = unsafe extern "C" fn(&Str, &Str, i64, i64, f32) -> HookResult;


#[allow(unused)]
pub type ProcessUsercmdsCallback = unsafe extern "C" fn(i32, i32, bool);


#[allow(unused)]
pub type AbilityThinkCallback = unsafe extern "C" fn(i32, i64);


#[allow(unused)]
pub type AddModifierCallback = unsafe extern "C" fn(i64, i64, u32, i32) -> HookResult;


#[allow(unused)]
pub type HeroInitializedCallback = unsafe extern "C" fn(i64);


#[allow(unused)]
pub type GameEventCallback = unsafe extern "C" fn(&Str, i64);


