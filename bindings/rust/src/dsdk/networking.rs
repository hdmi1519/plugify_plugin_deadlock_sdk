// Generated from dsdk.pplugin (group: networking)

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

/// Send protobuf network message to clients
///
/// # Arguments
/// * `msgId` - (int32)
/// * `protoBytes` - (uint8[])
/// * `recipientMask` - (uint64)
/// * `bufType` - (int32)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn SendNetMessage(msgId: i32, protoBytes: &Arr<u8>, recipientMask: u64, bufType: i32) {
    unsafe { __dsdk_SendNetMessage.expect("SendNetMessage function was not found")(msgId, protoBytes, recipientMask, bufType) }
}
pub type _SendNetMessage = unsafe extern "C" fn(i32, &Arr<u8>, u64, i32);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_SendNetMessage: Option<_SendNetMessage> = None;

/// Get registered network message name
///
/// # Arguments
/// * `msgId` - (int32)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GetNetMessageName(msgId: i32) -> Str {
    unsafe { __dsdk_GetNetMessageName.expect("GetNetMessageName function was not found")(msgId) }
}
pub type _GetNetMessageName = unsafe extern "C" fn(i32) -> Str;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GetNetMessageName: Option<_GetNetMessageName> = None;

