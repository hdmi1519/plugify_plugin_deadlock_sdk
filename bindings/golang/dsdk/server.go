package dsdk

/*
#include "server.h"
#cgo noescape GetMapName
#cgo noescape IsMapValid
#cgo noescape SetServerKeyValue
#cgo noescape ClearServerKeyValues
#cgo noescape SetServerAddons
#cgo noescape AddFileSystemSearchPath
#cgo noescape HasCommandLineParm
#cgo noescape SetConnectRejectReason
#cgo noescape GetGlobalVars
#cgo noescape GetGameTime
#cgo noescape GetGameTickCount
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

// Generated from dsdk (group: server)

var _GetMapName = func() string {
	var __retVal string
	var __retVal_native plugify.PlgString
	plugify.Block {
		Try: func() {
			__native := C.GetMapName()
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

// GetMapName 
//  @brief Get currently loaded map name
//
func GetMapName() string {
	return _GetMapName()
}

var _IsMapValid = func(map_ string) bool {
	var __retVal bool
	__map_ := plugify.ConstructString(map_)
	plugify.Block {
		Try: func() {
			__retVal = bool(C.IsMapValid((*C.String)(unsafe.Pointer(&__map_))))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__map_)
		},
	}.Do()
	return __retVal
}

// IsMapValid 
//  @brief Check if map exists and can be loaded
//
func IsMapValid(map_ string) bool {
	return _IsMapValid(map_)
}

var _SetServerKeyValue = func(key string, value string) bool {
	var __retVal bool
	__key := plugify.ConstructString(key)
	__value := plugify.ConstructString(value)
	plugify.Block {
		Try: func() {
			__retVal = bool(C.SetServerKeyValue((*C.String)(unsafe.Pointer(&__key)), (*C.String)(unsafe.Pointer(&__value))))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__key)
			plugify.DestroyString(&__value)
		},
	}.Do()
	return __retVal
}

// SetServerKeyValue 
//  @brief Set Steam A2S rule key-value
//
func SetServerKeyValue(key string, value string) bool {
	return _SetServerKeyValue(key, value)
}

var _ClearServerKeyValues = func() bool {
	__retVal := bool(C.ClearServerKeyValues())
	return __retVal
}

// ClearServerKeyValues 
//  @brief Clear Steam A2S rules
//
func ClearServerKeyValues() bool {
	return _ClearServerKeyValues()
}

var _SetServerAddons = func(addons string) {
	__addons := plugify.ConstructString(addons)
	plugify.Block {
		Try: func() {
			C.SetServerAddons((*C.String)(unsafe.Pointer(&__addons)))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__addons)
		},
	}.Do()
}

// SetServerAddons 
//  @brief Set active server workshop addons
//
func SetServerAddons(addons string) {
	_SetServerAddons(addons)
}

var _AddFileSystemSearchPath = func(path string, pathId string, addType int32) bool {
	var __retVal bool
	__path := plugify.ConstructString(path)
	__pathId := plugify.ConstructString(pathId)
	__addType := C.int32_t(addType)
	plugify.Block {
		Try: func() {
			__retVal = bool(C.AddFileSystemSearchPath((*C.String)(unsafe.Pointer(&__path)), (*C.String)(unsafe.Pointer(&__pathId)), __addType))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__path)
			plugify.DestroyString(&__pathId)
		},
	}.Do()
	return __retVal
}

// AddFileSystemSearchPath 
//  @brief Add file search path
//
func AddFileSystemSearchPath(path string, pathId string, addType int32) bool {
	return _AddFileSystemSearchPath(path, pathId, addType)
}

var _HasCommandLineParm = func(parm string) bool {
	var __retVal bool
	__parm := plugify.ConstructString(parm)
	plugify.Block {
		Try: func() {
			__retVal = bool(C.HasCommandLineParm((*C.String)(unsafe.Pointer(&__parm))))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__parm)
		},
	}.Do()
	return __retVal
}

// HasCommandLineParm 
//  @brief Check if command line argument exists
//
func HasCommandLineParm(parm string) bool {
	return _HasCommandLineParm(parm)
}

var _SetConnectRejectReason = func(reason string) {
	__reason := plugify.ConstructString(reason)
	plugify.Block {
		Try: func() {
			C.SetConnectRejectReason((*C.String)(unsafe.Pointer(&__reason)))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__reason)
		},
	}.Do()
}

// SetConnectRejectReason 
//  @brief Set reject reason for connection rejection
//
func SetConnectRejectReason(reason string) {
	_SetConnectRejectReason(reason)
}

var _GetGlobalVars = func() int64 {
	__retVal := int64(C.GetGlobalVars())
	return __retVal
}

// GetGlobalVars 
//  @brief Get CGlobalVars pointer
//
func GetGlobalVars() int64 {
	return _GetGlobalVars()
}

var _GetGameTime = func() float32 {
	__retVal := float32(C.GetGameTime())
	return __retVal
}

// GetGameTime 
//  @brief Get current engine game time in seconds
//
func GetGameTime() float32 {
	return _GetGameTime()
}

var _GetGameTickCount = func() int32 {
	__retVal := int32(C.GetGameTickCount())
	return __retVal
}

// GetGameTickCount 
//  @brief Get current engine tick count
//
func GetGameTickCount() int32 {
	return _GetGameTickCount()
}

