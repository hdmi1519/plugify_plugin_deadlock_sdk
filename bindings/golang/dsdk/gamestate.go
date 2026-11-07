package dsdk

/*
#include "gamestate.h"
#cgo noescape GetGameState
#cgo noescape GetMatchTime
#cgo noescape ChangeGameState
#cgo noescape SetWaitingForPlayersRoster
#cgo noescape SetMatchStartOnAnyMap
#cgo noescape GetMatchStartOnAnyMap
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

// Generated from dsdk (group: gamestate)

var _GetGameState = func() EGameState {
	__retVal := EGameState(C.GetGameState())
	return __retVal
}

// GetGameState 
//  @brief Get current game state enum
//
func GetGameState() EGameState {
	return _GetGameState()
}

var _GetMatchTime = func() float32 {
	__retVal := float32(C.GetMatchTime())
	return __retVal
}

// GetMatchTime 
//  @brief Get current match clock in seconds
//
func GetMatchTime() float32 {
	return _GetMatchTime()
}

var _ChangeGameState = func(newState EGameState) {
	__newState := C.int32_t(newState)
	C.ChangeGameState(__newState)
}

// ChangeGameState 
//  @brief Force Deadlock game state change
//
func ChangeGameState(newState EGameState) {
	_ChangeGameState(newState)
}

var _SetWaitingForPlayersRoster = func(readyCount uint32, totalCount uint32) {
	__readyCount := C.uint32_t(readyCount)
	__totalCount := C.uint32_t(totalCount)
	C.SetWaitingForPlayersRoster(__readyCount, __totalCount)
}

// SetWaitingForPlayersRoster 
//  @brief Set waiting for players roster counts
//
func SetWaitingForPlayersRoster(readyCount uint32, totalCount uint32) {
	_SetWaitingForPlayersRoster(readyCount, totalCount)
}

var _SetMatchStartOnAnyMap = func(enabled bool) {
	__enabled := C.bool(enabled)
	C.SetMatchStartOnAnyMap(__enabled)
}

// SetMatchStartOnAnyMap 
//  @brief Enable/disable match start sequence on custom maps
//
func SetMatchStartOnAnyMap(enabled bool) {
	_SetMatchStartOnAnyMap(enabled)
}

var _GetMatchStartOnAnyMap = func() bool {
	__retVal := bool(C.GetMatchStartOnAnyMap())
	return __retVal
}

// GetMatchStartOnAnyMap 
//  @brief Check if match start on custom maps is enabled
//
func GetMatchStartOnAnyMap() bool {
	return _GetMatchStartOnAnyMap()
}

