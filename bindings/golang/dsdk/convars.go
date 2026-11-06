package dsdk

/*
#include "convars.h"
#cgo noescape FindConVar
#cgo noescape CreateConVar
#cgo noescape GetConVarInt
#cgo noescape GetConVarFloat
#cgo noescape GetConVarString
#cgo noescape GetConVarBool
#cgo noescape SetConVarInt
#cgo noescape SetConVarFloat
#cgo noescape SetConVarString
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

// Generated from dsdk (group: convars)

var _FindConVar = func(name string) uint64 {
	var __retVal uint64
	__name := plugify.ConstructString(name)
	plugify.Block {
		Try: func() {
			__retVal = uint64(C.FindConVar((*C.String)(unsafe.Pointer(&__name))))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__name)
		},
	}.Do()
	return __retVal
}

// FindConVar 
//  @brief Find ConVar by name
//
func FindConVar(name string) uint64 {
	return _FindConVar(name)
}

var _CreateConVar = func(name string, defaultValue string, description string, flags uint64) uint64 {
	var __retVal uint64
	__name := plugify.ConstructString(name)
	__defaultValue := plugify.ConstructString(defaultValue)
	__description := plugify.ConstructString(description)
	__flags := C.uint64_t(flags)
	plugify.Block {
		Try: func() {
			__retVal = uint64(C.CreateConVar((*C.String)(unsafe.Pointer(&__name)), (*C.String)(unsafe.Pointer(&__defaultValue)), (*C.String)(unsafe.Pointer(&__description)), __flags))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__name)
			plugify.DestroyString(&__defaultValue)
			plugify.DestroyString(&__description)
		},
	}.Do()
	return __retVal
}

// CreateConVar 
//  @brief Create custom ConVar
//
func CreateConVar(name string, defaultValue string, description string, flags uint64) uint64 {
	return _CreateConVar(name, defaultValue, description, flags)
}

var _GetConVarInt = func(handle uint64) int32 {
	var __retVal int32
	__handle := C.uint64_t(handle)
	__retVal = int32(C.GetConVarInt(__handle))
	return __retVal
}

// GetConVarInt 
//  @brief Get ConVar integer value
//
func GetConVarInt(handle uint64) int32 {
	return _GetConVarInt(handle)
}

var _GetConVarFloat = func(handle uint64) float32 {
	var __retVal float32
	__handle := C.uint64_t(handle)
	__retVal = float32(C.GetConVarFloat(__handle))
	return __retVal
}

// GetConVarFloat 
//  @brief Get ConVar float value
//
func GetConVarFloat(handle uint64) float32 {
	return _GetConVarFloat(handle)
}

var _GetConVarString = func(handle uint64) string {
	var __retVal string
	var __retVal_native plugify.PlgString
	__handle := C.uint64_t(handle)
	plugify.Block {
		Try: func() {
			__native := C.GetConVarString(__handle)
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

// GetConVarString 
//  @brief Get ConVar string value
//
func GetConVarString(handle uint64) string {
	return _GetConVarString(handle)
}

var _GetConVarBool = func(handle uint64) bool {
	var __retVal bool
	__handle := C.uint64_t(handle)
	__retVal = bool(C.GetConVarBool(__handle))
	return __retVal
}

// GetConVarBool 
//  @brief Get ConVar bool value
//
func GetConVarBool(handle uint64) bool {
	return _GetConVarBool(handle)
}

var _SetConVarInt = func(handle uint64, value int32) {
	__handle := C.uint64_t(handle)
	__value := C.int32_t(value)
	C.SetConVarInt(__handle, __value)
}

// SetConVarInt 
//  @brief Set ConVar int value
//
func SetConVarInt(handle uint64, value int32) {
	_SetConVarInt(handle, value)
}

var _SetConVarFloat = func(handle uint64, value float32) {
	__handle := C.uint64_t(handle)
	__value := C.float(value)
	C.SetConVarFloat(__handle, __value)
}

// SetConVarFloat 
//  @brief Set ConVar float value
//
func SetConVarFloat(handle uint64, value float32) {
	_SetConVarFloat(handle, value)
}

var _SetConVarString = func(handle uint64, value string) bool {
	var __retVal bool
	__handle := C.uint64_t(handle)
	__value := plugify.ConstructString(value)
	plugify.Block {
		Try: func() {
			__retVal = bool(C.SetConVarString(__handle, (*C.String)(unsafe.Pointer(&__value))))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__value)
		},
	}.Do()
	return __retVal
}

// SetConVarString 
//  @brief Set ConVar string value
//
func SetConVarString(handle uint64, value string) bool {
	return _SetConVarString(handle, value)
}

