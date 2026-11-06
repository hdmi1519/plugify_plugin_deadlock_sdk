package dsdk

/*
#include "players.h"
#cgo noescape GetPlayerController
#cgo noescape GetPlayerPawn
#cgo noescape GetPlayerSlot
#cgo noescape GetPlayerName
#cgo noescape GetSteamID
#cgo noescape IsClientAuthenticated
#cgo noescape IsClientConnected
#cgo noescape IsFakeClient
#cgo noescape CreateFakeClient
#cgo noescape DisconnectClient
#cgo noescape KickClient
#cgo noescape ChangeTeam
#cgo noescape GetPlayerPing
*/
import "C"
import (
	"errors"
	"reflect"
	"runtime"
	"unsafe"
	"github.com/untrustedmodders/go-plugify"
)

var _ = errors.New("")
var _ = reflect.TypeOf(0)
var _ = runtime.GOOS
var _ = unsafe.Sizeof(0)
var _ = plugify.ApiVersion

// Generated from dsdk (group: players)

var _GetPlayerController = func(playerSlot int32) int64 {
	var __retVal int64
	__playerSlot := C.int32_t(playerSlot)
	__retVal = int64(C.GetPlayerController(__playerSlot))
	return __retVal
}

// GetPlayerController 
//  @brief Get CBasePlayerController address for player slot
//
func GetPlayerController(playerSlot int32) int64 {
	return _GetPlayerController(playerSlot)
}

var _GetPlayerPawn = func(playerSlot int32) int64 {
	var __retVal int64
	__playerSlot := C.int32_t(playerSlot)
	__retVal = int64(C.GetPlayerPawn(__playerSlot))
	return __retVal
}

// GetPlayerPawn 
//  @brief Get CCitadelPlayerPawn address for player slot
//
func GetPlayerPawn(playerSlot int32) int64 {
	return _GetPlayerPawn(playerSlot)
}

var _GetPlayerSlot = func(controller int64) int32 {
	var __retVal int32
	__controller := C.int64_t(controller)
	__retVal = int32(C.GetPlayerSlot(__controller))
	return __retVal
}

// GetPlayerSlot 
//  @brief Get player slot from controller address
//
func GetPlayerSlot(controller int64) int32 {
	return _GetPlayerSlot(controller)
}

var _GetPlayerName = func(playerSlot int32) string {
	var __retVal string
	var __retVal_native plugify.PlgString
	__playerSlot := C.int32_t(playerSlot)
	plugify.Block {
		Try: func() {
			__native := C.GetPlayerName(__playerSlot)
			__retVal_native = *(*plugify.PlgString)(unsafe.Pointer(&__native))
			// Unmarshal - Convert native data to managed data.
			__retVal = plugify.GetStringData[string](&__retVal_native)
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__retVal_native)
		},
	}.Do()
	return __retVal
}

// GetPlayerName 
//  @brief Get player display name
//
func GetPlayerName(playerSlot int32) string {
	return _GetPlayerName(playerSlot)
}

var _GetSteamID = func(playerSlot int32) uint64 {
	var __retVal uint64
	__playerSlot := C.int32_t(playerSlot)
	__retVal = uint64(C.GetSteamID(__playerSlot))
	return __retVal
}

// GetSteamID 
//  @brief Get player 64-bit SteamID
//
func GetSteamID(playerSlot int32) uint64 {
	return _GetSteamID(playerSlot)
}

var _IsClientAuthenticated = func(playerSlot int32) bool {
	var __retVal bool
	__playerSlot := C.int32_t(playerSlot)
	__retVal = bool(C.IsClientAuthenticated(__playerSlot))
	return __retVal
}

// IsClientAuthenticated 
//  @brief Check if player Steam ticket is validated
//
func IsClientAuthenticated(playerSlot int32) bool {
	return _IsClientAuthenticated(playerSlot)
}

var _IsClientConnected = func(playerSlot int32) bool {
	var __retVal bool
	__playerSlot := C.int32_t(playerSlot)
	__retVal = bool(C.IsClientConnected(__playerSlot))
	return __retVal
}

// IsClientConnected 
//  @brief Check if client is connected
//
func IsClientConnected(playerSlot int32) bool {
	return _IsClientConnected(playerSlot)
}

var _IsFakeClient = func(playerSlot int32) bool {
	var __retVal bool
	__playerSlot := C.int32_t(playerSlot)
	__retVal = bool(C.IsFakeClient(__playerSlot))
	return __retVal
}

// IsFakeClient 
//  @brief Check if player is a bot/fake client
//
func IsFakeClient(playerSlot int32) bool {
	return _IsFakeClient(playerSlot)
}

var _CreateFakeClient = func(name string) int32 {
	var __retVal int32
	__name := plugify.ConstructString(name)
	plugify.Block {
		Try: func() {
			__retVal = int32(C.CreateFakeClient((*C.String)(unsafe.Pointer(&__name))))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__name)
		},
	}.Do()
	return __retVal
}

// CreateFakeClient 
//  @brief Create a fake client in the match
//
func CreateFakeClient(name string) int32 {
	return _CreateFakeClient(name)
}

var _DisconnectClient = func(playerSlot int32, reason int32) {
	__playerSlot := C.int32_t(playerSlot)
	__reason := C.int32_t(reason)
	C.DisconnectClient(__playerSlot, __reason)
}

// DisconnectClient 
//  @brief Disconnect a client with disconnection reason code
//
func DisconnectClient(playerSlot int32, reason int32) {
	_DisconnectClient(playerSlot, reason)
}

var _KickClient = func(playerSlot int32, reason string, code int32) {
	__playerSlot := C.int32_t(playerSlot)
	__reason := plugify.ConstructString(reason)
	__code := C.int32_t(code)
	plugify.Block {
		Try: func() {
			C.KickClient(__playerSlot, (*C.String)(unsafe.Pointer(&__reason)), __code)
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__reason)
		},
	}.Do()
}

// KickClient 
//  @brief Kick client with message and code
//
func KickClient(playerSlot int32, reason string, code int32) {
	_KickClient(playerSlot, reason, code)
}

var _ChangeTeam = func(controller int64, teamNum int32, keepHero bool) {
	__controller := C.int64_t(controller)
	__teamNum := C.int32_t(teamNum)
	__keepHero := C.bool(keepHero)
	C.ChangeTeam(__controller, __teamNum, __keepHero)
}

// ChangeTeam 
//  @brief Change team of player controller
//
func ChangeTeam(controller int64, teamNum int32, keepHero bool) {
	_ChangeTeam(controller, teamNum, keepHero)
}

var _GetPlayerPing = func(playerSlot int32) int32 {
	var __retVal int32
	__playerSlot := C.int32_t(playerSlot)
	__retVal = int32(C.GetPlayerPing(__playerSlot))
	return __retVal
}

// GetPlayerPing 
//  @brief Get ping of player in milliseconds
//
func GetPlayerPing(playerSlot int32) int32 {
	return _GetPlayerPing(playerSlot)
}

