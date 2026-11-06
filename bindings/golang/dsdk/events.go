package dsdk

/*
#include "events.h"
#cgo noescape RegisterGameEvent
#cgo noescape CreateGameEvent
#cgo noescape FireGameEvent
#cgo noescape FreeGameEvent
#cgo noescape GameEventGetBool
#cgo noescape GameEventGetInt
#cgo noescape GameEventGetFloat
#cgo noescape GameEventGetString
#cgo noescape GameEventGetUint64
#cgo noescape GameEventSetBool
#cgo noescape GameEventSetInt
#cgo noescape GameEventSetFloat
#cgo noescape GameEventSetString
#cgo noescape GameEventGetPlayerSlot
#cgo noescape GameEventGetPlayerPawn
#cgo noescape GameEventGetPlayerController
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

// Generated from dsdk (group: events)

var _RegisterGameEvent = func(name string) {
	__name := plugify.ConstructString(name)
	plugify.Block {
		Try: func() {
			C.RegisterGameEvent((*C.String)(unsafe.Pointer(&__name)))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__name)
		},
	}.Do()
}

// RegisterGameEvent 
//  @brief Register game event listener for engine event
//
func RegisterGameEvent(name string) {
	_RegisterGameEvent(name)
}

var _CreateGameEvent = func(name string, force bool) int64 {
	var __retVal int64
	__name := plugify.ConstructString(name)
	__force := C.bool(force)
	plugify.Block {
		Try: func() {
			__retVal = int64(C.CreateGameEvent((*C.String)(unsafe.Pointer(&__name)), __force))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__name)
		},
	}.Do()
	return __retVal
}

// CreateGameEvent 
//  @brief Create a new game event
//
func CreateGameEvent(name string, force bool) int64 {
	return _CreateGameEvent(name, force)
}

var _FireGameEvent = func(event int64, dontBroadcast bool) bool {
	var __retVal bool
	__event := C.int64_t(event)
	__dontBroadcast := C.bool(dontBroadcast)
	__retVal = bool(C.FireGameEvent(__event, __dontBroadcast))
	return __retVal
}

// FireGameEvent 
//  @brief Fire game event
//
func FireGameEvent(event int64, dontBroadcast bool) bool {
	return _FireGameEvent(event, dontBroadcast)
}

var _FreeGameEvent = func(event int64) {
	__event := C.int64_t(event)
	C.FreeGameEvent(__event)
}

// FreeGameEvent 
//  @brief Free game event object
//
func FreeGameEvent(event int64) {
	_FreeGameEvent(event)
}

var _GameEventGetBool = func(event int64, key string, def bool) bool {
	var __retVal bool
	__event := C.int64_t(event)
	__key := plugify.ConstructString(key)
	__def := C.bool(def)
	plugify.Block {
		Try: func() {
			__retVal = bool(C.GameEventGetBool(__event, (*C.String)(unsafe.Pointer(&__key)), __def))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__key)
		},
	}.Do()
	return __retVal
}

// GameEventGetBool 
//  @brief Get boolean key from game event
//
func GameEventGetBool(event int64, key string, def bool) bool {
	return _GameEventGetBool(event, key, def)
}

var _GameEventGetInt = func(event int64, key string, def int32) int32 {
	var __retVal int32
	__event := C.int64_t(event)
	__key := plugify.ConstructString(key)
	__def := C.int32_t(def)
	plugify.Block {
		Try: func() {
			__retVal = int32(C.GameEventGetInt(__event, (*C.String)(unsafe.Pointer(&__key)), __def))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__key)
		},
	}.Do()
	return __retVal
}

// GameEventGetInt 
//  @brief Get int32 key from game event
//
func GameEventGetInt(event int64, key string, def int32) int32 {
	return _GameEventGetInt(event, key, def)
}

var _GameEventGetFloat = func(event int64, key string, def float32) float32 {
	var __retVal float32
	__event := C.int64_t(event)
	__key := plugify.ConstructString(key)
	__def := C.float(def)
	plugify.Block {
		Try: func() {
			__retVal = float32(C.GameEventGetFloat(__event, (*C.String)(unsafe.Pointer(&__key)), __def))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__key)
		},
	}.Do()
	return __retVal
}

// GameEventGetFloat 
//  @brief Get float key from game event
//
func GameEventGetFloat(event int64, key string, def float32) float32 {
	return _GameEventGetFloat(event, key, def)
}

var _GameEventGetString = func(event int64, key string, def string) string {
	var __retVal string
	var __retVal_native plugify.PlgString
	__event := C.int64_t(event)
	__key := plugify.ConstructString(key)
	__def := plugify.ConstructString(def)
	plugify.Block {
		Try: func() {
			__native := C.GameEventGetString(__event, (*C.String)(unsafe.Pointer(&__key)), (*C.String)(unsafe.Pointer(&__def)))
			__retVal_native = *(*plugify.PlgString)(unsafe.Pointer(&__native))
			// Unmarshal - Convert native data to managed data.
			__retVal = plugify.GetStringData[string](&__retVal_native)
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__retVal_native)
			plugify.DestroyString(&__key)
			plugify.DestroyString(&__def)
		},
	}.Do()
	return __retVal
}

// GameEventGetString 
//  @brief Get string key from game event
//
func GameEventGetString(event int64, key string, def string) string {
	return _GameEventGetString(event, key, def)
}

var _GameEventGetUint64 = func(event int64, key string, def uint64) uint64 {
	var __retVal uint64
	__event := C.int64_t(event)
	__key := plugify.ConstructString(key)
	__def := C.uint64_t(def)
	plugify.Block {
		Try: func() {
			__retVal = uint64(C.GameEventGetUint64(__event, (*C.String)(unsafe.Pointer(&__key)), __def))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__key)
		},
	}.Do()
	return __retVal
}

// GameEventGetUint64 
//  @brief Get uint64 key from game event
//
func GameEventGetUint64(event int64, key string, def uint64) uint64 {
	return _GameEventGetUint64(event, key, def)
}

var _GameEventSetBool = func(event int64, key string, val bool) {
	__event := C.int64_t(event)
	__key := plugify.ConstructString(key)
	__val := C.bool(val)
	plugify.Block {
		Try: func() {
			C.GameEventSetBool(__event, (*C.String)(unsafe.Pointer(&__key)), __val)
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__key)
		},
	}.Do()
}

// GameEventSetBool 
//  @brief Set boolean key in game event
//
func GameEventSetBool(event int64, key string, val bool) {
	_GameEventSetBool(event, key, val)
}

var _GameEventSetInt = func(event int64, key string, val int32) {
	__event := C.int64_t(event)
	__key := plugify.ConstructString(key)
	__val := C.int32_t(val)
	plugify.Block {
		Try: func() {
			C.GameEventSetInt(__event, (*C.String)(unsafe.Pointer(&__key)), __val)
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__key)
		},
	}.Do()
}

// GameEventSetInt 
//  @brief Set int32 key in game event
//
func GameEventSetInt(event int64, key string, val int32) {
	_GameEventSetInt(event, key, val)
}

var _GameEventSetFloat = func(event int64, key string, val float32) {
	__event := C.int64_t(event)
	__key := plugify.ConstructString(key)
	__val := C.float(val)
	plugify.Block {
		Try: func() {
			C.GameEventSetFloat(__event, (*C.String)(unsafe.Pointer(&__key)), __val)
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__key)
		},
	}.Do()
}

// GameEventSetFloat 
//  @brief Set float key in game event
//
func GameEventSetFloat(event int64, key string, val float32) {
	_GameEventSetFloat(event, key, val)
}

var _GameEventSetString = func(event int64, key string, val string) {
	__event := C.int64_t(event)
	__key := plugify.ConstructString(key)
	__val := plugify.ConstructString(val)
	plugify.Block {
		Try: func() {
			C.GameEventSetString(__event, (*C.String)(unsafe.Pointer(&__key)), (*C.String)(unsafe.Pointer(&__val)))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__key)
			plugify.DestroyString(&__val)
		},
	}.Do()
}

// GameEventSetString 
//  @brief Set string key in game event
//
func GameEventSetString(event int64, key string, val string) {
	_GameEventSetString(event, key, val)
}

var _GameEventGetPlayerSlot = func(event int64, key string) int32 {
	var __retVal int32
	__event := C.int64_t(event)
	__key := plugify.ConstructString(key)
	plugify.Block {
		Try: func() {
			__retVal = int32(C.GameEventGetPlayerSlot(__event, (*C.String)(unsafe.Pointer(&__key))))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__key)
		},
	}.Do()
	return __retVal
}

// GameEventGetPlayerSlot 
//  @brief Gets player slot from an event key (e.g. userid)
//
func GameEventGetPlayerSlot(event int64, key string) int32 {
	return _GameEventGetPlayerSlot(event, key)
}

var _GameEventGetPlayerPawn = func(event int64, key string) int64 {
	var __retVal int64
	__event := C.int64_t(event)
	__key := plugify.ConstructString(key)
	plugify.Block {
		Try: func() {
			__retVal = int64(C.GameEventGetPlayerPawn(__event, (*C.String)(unsafe.Pointer(&__key))))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__key)
		},
	}.Do()
	return __retVal
}

// GameEventGetPlayerPawn 
//  @brief Gets player pawn pointer from an event key (e.g. userid)
//
func GameEventGetPlayerPawn(event int64, key string) int64 {
	return _GameEventGetPlayerPawn(event, key)
}

var _GameEventGetPlayerController = func(event int64, key string) int64 {
	var __retVal int64
	__event := C.int64_t(event)
	__key := plugify.ConstructString(key)
	plugify.Block {
		Try: func() {
			__retVal = int64(C.GameEventGetPlayerController(__event, (*C.String)(unsafe.Pointer(&__key))))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__key)
		},
	}.Do()
	return __retVal
}

// GameEventGetPlayerController 
//  @brief Gets player controller pointer from an event key (e.g. userid)
//
func GameEventGetPlayerController(event int64, key string) int64 {
	return _GameEventGetPlayerController(event, key)
}

