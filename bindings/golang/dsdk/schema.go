package dsdk

/*
#include "schema.h"
#cgo noescape GetSchemaFieldOffset
#cgo noescape NotifyStateChanged
#cgo noescape SetSchemaString
#cgo noescape GetSchemaClassSize
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

// Generated from dsdk (group: schema)

var _GetSchemaFieldOffset = func(className string, fieldName string) int32 {
	var __retVal int32
	__className := plugify.ConstructString(className)
	__fieldName := plugify.ConstructString(fieldName)
	plugify.Block {
		Try: func() {
			__retVal = int32(C.GetSchemaFieldOffset((*C.String)(unsafe.Pointer(&__className)), (*C.String)(unsafe.Pointer(&__fieldName))))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__className)
			plugify.DestroyString(&__fieldName)
		},
	}.Do()
	return __retVal
}

// GetSchemaFieldOffset 
//  @brief Get byte offset of class field in schema
//
func GetSchemaFieldOffset(className string, fieldName string) int32 {
	return _GetSchemaFieldOffset(className, fieldName)
}

var _NotifyStateChanged = func(entity int64, fieldOffset int32, chainOffset int16, networkStateChangedOffset int32) {
	__entity := C.int64_t(entity)
	__fieldOffset := C.int32_t(fieldOffset)
	__chainOffset := C.int16_t(chainOffset)
	__networkStateChangedOffset := C.int32_t(networkStateChangedOffset)
	C.NotifyStateChanged(__entity, __fieldOffset, __chainOffset, __networkStateChangedOffset)
}

// NotifyStateChanged 
//  @brief Notify network system of field modification
//
func NotifyStateChanged(entity int64, fieldOffset int32, chainOffset int16, networkStateChangedOffset int32) {
	_NotifyStateChanged(entity, fieldOffset, chainOffset, networkStateChangedOffset)
}

var _SetSchemaString = func(entity int64, className string, fieldName string, value string) {
	__entity := C.int64_t(entity)
	__className := plugify.ConstructString(className)
	__fieldName := plugify.ConstructString(fieldName)
	__value := plugify.ConstructString(value)
	plugify.Block {
		Try: func() {
			C.SetSchemaString(__entity, (*C.String)(unsafe.Pointer(&__className)), (*C.String)(unsafe.Pointer(&__fieldName)), (*C.String)(unsafe.Pointer(&__value)))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__className)
			plugify.DestroyString(&__fieldName)
			plugify.DestroyString(&__value)
		},
	}.Do()
}

// SetSchemaString 
//  @brief Set string field in schema structure
//
func SetSchemaString(entity int64, className string, fieldName string, value string) {
	_SetSchemaString(entity, className, fieldName, value)
}

var _GetSchemaClassSize = func(className string) int32 {
	var __retVal int32
	__className := plugify.ConstructString(className)
	plugify.Block {
		Try: func() {
			__retVal = int32(C.GetSchemaClassSize((*C.String)(unsafe.Pointer(&__className))))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__className)
		},
	}.Do()
	return __retVal
}

// GetSchemaClassSize 
//  @brief Get sizeof schema class
//
func GetSchemaClassSize(className string) int32 {
	return _GetSchemaClassSize(className)
}

