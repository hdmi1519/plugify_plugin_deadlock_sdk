package dsdk

/*
#include "bots.h"
#cgo noescape BotCreate
#cgo noescape BotGetBrain
#cgo noescape BotGetPawn
#cgo noescape BotSetLane
#cgo noescape BotGetLane
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

// Generated from dsdk (group: bots)

var _BotCreate = func(heroName string, team int32, posX float32, posY float32, posZ float32, assignLane bool) int64 {
	var __retVal int64
	__heroName := plugify.ConstructString(heroName)
	__team := C.int32_t(team)
	__posX := C.float(posX)
	__posY := C.float(posY)
	__posZ := C.float(posZ)
	__assignLane := C.bool(assignLane)
	plugify.Block {
		Try: func() {
			__retVal = int64(C.BotCreate((*C.String)(unsafe.Pointer(&__heroName)), __team, __posX, __posY, __posZ, __assignLane))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__heroName)
		},
	}.Do()
	return __retVal
}

// BotCreate 
//  @brief Spawn a bot hero into the match
//
func BotCreate(heroName string, team int32, posX float32, posY float32, posZ float32, assignLane bool) int64 {
	return _BotCreate(heroName, team, posX, posY, posZ, assignLane)
}

var _BotGetBrain = func(pawn int64) int64 {
	var __retVal int64
	__pawn := C.int64_t(pawn)
	__retVal = int64(C.BotGetBrain(__pawn))
	return __retVal
}

// BotGetBrain 
//  @brief Get brain entity pointer for player bot pawn
//
func BotGetBrain(pawn int64) int64 {
	return _BotGetBrain(pawn)
}

var _BotGetPawn = func(brain int64) int64 {
	var __retVal int64
	__brain := C.int64_t(brain)
	__retVal = int64(C.BotGetPawn(__brain))
	return __retVal
}

// BotGetPawn 
//  @brief Get pawn entity controlled by bot brain
//
func BotGetPawn(brain int64) int64 {
	return _BotGetPawn(brain)
}

var _BotSetLane = func(pawn int64, lane int32) bool {
	var __retVal bool
	__pawn := C.int64_t(pawn)
	__lane := C.int32_t(lane)
	__retVal = bool(C.BotSetLane(__pawn, __lane))
	return __retVal
}

// BotSetLane 
//  @brief Assign lane index to bot
//
func BotSetLane(pawn int64, lane int32) bool {
	return _BotSetLane(pawn, lane)
}

var _BotGetLane = func(pawn int64) int32 {
	var __retVal int32
	__pawn := C.int64_t(pawn)
	__retVal = int32(C.BotGetLane(__pawn))
	return __retVal
}

// BotGetLane 
//  @brief Get assigned lane index of bot
//
func BotGetLane(pawn int64) int32 {
	return _BotGetLane(pawn)
}

