package dsdk

/*
#include "precaching.h"
#cgo noescape PrecacheResource
#cgo noescape PrecacheModel
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

// Generated from dsdk (group: precaching)

var _PrecacheResource = func(path string) {
	__path := plugify.ConstructString(path)
	plugify.Block {
		Try: func() {
			C.PrecacheResource((*C.String)(unsafe.Pointer(&__path)))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__path)
		},
	}.Do()
}

// PrecacheResource 
//  @brief Precache resource by VPK path
//
func PrecacheResource(path string) {
	_PrecacheResource(path)
}

var _PrecacheModel = func(modelPath string) {
	__modelPath := plugify.ConstructString(modelPath)
	plugify.Block {
		Try: func() {
			C.PrecacheModel((*C.String)(unsafe.Pointer(&__modelPath)))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__modelPath)
		},
	}.Do()
}

// PrecacheModel 
//  @brief Precache model resource
//
func PrecacheModel(modelPath string) {
	_PrecacheModel(modelPath)
}

