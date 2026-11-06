package dsdk

/*
#include "configuration.h"
#cgo noescape GetConfigString
#cgo noescape GetConfigInt
#cgo noescape GetConfigBool
#cgo noescape GetConfigFloat
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

// Generated from dsdk (group: configuration)

var _GetConfigString = func(key string, defaultValue string) string {
	var __retVal string
	var __retVal_native plugify.PlgString
	__key := plugify.ConstructString(key)
	__defaultValue := plugify.ConstructString(defaultValue)
	plugify.Block {
		Try: func() {
			__native := C.GetConfigString((*C.String)(unsafe.Pointer(&__key)), (*C.String)(unsafe.Pointer(&__defaultValue)))
			__retVal_native = *(*plugify.PlgString)(unsafe.Pointer(&__native))
			// Unmarshal - Convert native data to managed data.
			__retVal = plugify.GetStringData[string](&__retVal_native)
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__retVal_native)
			plugify.DestroyString(&__key)
			plugify.DestroyString(&__defaultValue)
		},
	}.Do()
	return __retVal
}

// GetConfigString 
//  @brief Read string from settings.jsonc
//
func GetConfigString(key string, defaultValue string) string {
	return _GetConfigString(key, defaultValue)
}

var _GetConfigInt = func(key string, defaultValue int32) int32 {
	var __retVal int32
	__key := plugify.ConstructString(key)
	__defaultValue := C.int32_t(defaultValue)
	plugify.Block {
		Try: func() {
			__retVal = int32(C.GetConfigInt((*C.String)(unsafe.Pointer(&__key)), __defaultValue))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__key)
		},
	}.Do()
	return __retVal
}

// GetConfigInt 
//  @brief Read int from settings.jsonc
//
func GetConfigInt(key string, defaultValue int32) int32 {
	return _GetConfigInt(key, defaultValue)
}

var _GetConfigBool = func(key string, defaultValue bool) bool {
	var __retVal bool
	__key := plugify.ConstructString(key)
	__defaultValue := C.bool(defaultValue)
	plugify.Block {
		Try: func() {
			__retVal = bool(C.GetConfigBool((*C.String)(unsafe.Pointer(&__key)), __defaultValue))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__key)
		},
	}.Do()
	return __retVal
}

// GetConfigBool 
//  @brief Read bool from settings.jsonc
//
func GetConfigBool(key string, defaultValue bool) bool {
	return _GetConfigBool(key, defaultValue)
}

var _GetConfigFloat = func(key string, defaultValue float32) float32 {
	var __retVal float32
	__key := plugify.ConstructString(key)
	__defaultValue := C.float(defaultValue)
	plugify.Block {
		Try: func() {
			__retVal = float32(C.GetConfigFloat((*C.String)(unsafe.Pointer(&__key)), __defaultValue))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__key)
		},
	}.Do()
	return __retVal
}

// GetConfigFloat 
//  @brief Read float from settings.jsonc
//
func GetConfigFloat(key string, defaultValue float32) float32 {
	return _GetConfigFloat(key, defaultValue)
}

