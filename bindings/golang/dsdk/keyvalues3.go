package dsdk

/*
#include "keyvalues3.h"
#cgo noescape KV3Create
#cgo noescape KV3Destroy
#cgo noescape KV3SetString
#cgo noescape KV3SetBool
#cgo noescape KV3SetInt
#cgo noescape KV3SetFloat
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

// Generated from dsdk (group: keyvalues3)

var _KV3Create = func() int64 {
	__retVal := int64(C.KV3Create())
	return __retVal
}

// KV3Create 
//  @brief Allocate new KeyValues3 document
//
func KV3Create() int64 {
	return _KV3Create()
}

var _KV3Destroy = func(kv3 int64) {
	__kv3 := C.int64_t(kv3)
	C.KV3Destroy(__kv3)
}

// KV3Destroy 
//  @brief Free KeyValues3 document
//
func KV3Destroy(kv3 int64) {
	_KV3Destroy(kv3)
}

var _KV3SetString = func(kv3 int64, key string, value string) {
	__kv3 := C.int64_t(kv3)
	__key := plugify.ConstructString(key)
	__value := plugify.ConstructString(value)
	plugify.Block {
		Try: func() {
			C.KV3SetString(__kv3, (*C.String)(unsafe.Pointer(&__key)), (*C.String)(unsafe.Pointer(&__value)))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__key)
			plugify.DestroyString(&__value)
		},
	}.Do()
}

// KV3SetString 
//  @brief Set string value in KeyValues3 document
//
func KV3SetString(kv3 int64, key string, value string) {
	_KV3SetString(kv3, key, value)
}

var _KV3SetBool = func(kv3 int64, key string, value bool) {
	__kv3 := C.int64_t(kv3)
	__key := plugify.ConstructString(key)
	__value := C.bool(value)
	plugify.Block {
		Try: func() {
			C.KV3SetBool(__kv3, (*C.String)(unsafe.Pointer(&__key)), __value)
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__key)
		},
	}.Do()
}

// KV3SetBool 
//  @brief Set bool value in KeyValues3 document
//
func KV3SetBool(kv3 int64, key string, value bool) {
	_KV3SetBool(kv3, key, value)
}

var _KV3SetInt = func(kv3 int64, key string, value int32) {
	__kv3 := C.int64_t(kv3)
	__key := plugify.ConstructString(key)
	__value := C.int32_t(value)
	plugify.Block {
		Try: func() {
			C.KV3SetInt(__kv3, (*C.String)(unsafe.Pointer(&__key)), __value)
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__key)
		},
	}.Do()
}

// KV3SetInt 
//  @brief Set int32 value in KeyValues3 document
//
func KV3SetInt(kv3 int64, key string, value int32) {
	_KV3SetInt(kv3, key, value)
}

var _KV3SetFloat = func(kv3 int64, key string, value float32) {
	__kv3 := C.int64_t(kv3)
	__key := plugify.ConstructString(key)
	__value := C.float(value)
	plugify.Block {
		Try: func() {
			C.KV3SetFloat(__kv3, (*C.String)(unsafe.Pointer(&__key)), __value)
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__key)
		},
	}.Do()
}

// KV3SetFloat 
//  @brief Set float value in KeyValues3 document
//
func KV3SetFloat(kv3 int64, key string, value float32) {
	_KV3SetFloat(kv3, key, value)
}

