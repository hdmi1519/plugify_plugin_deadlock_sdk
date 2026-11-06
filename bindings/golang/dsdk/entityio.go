package dsdk

/*
#include "entityio.h"
#cgo noescape AcceptInput
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

// Generated from dsdk (group: entityio)

var _AcceptInput = func(entity int64, inputName string, activator int64, caller int64, value string) {
	__entity := C.int64_t(entity)
	__inputName := plugify.ConstructString(inputName)
	__activator := C.int64_t(activator)
	__caller := C.int64_t(caller)
	__value := plugify.ConstructString(value)
	plugify.Block {
		Try: func() {
			C.AcceptInput(__entity, (*C.String)(unsafe.Pointer(&__inputName)), __activator, __caller, (*C.String)(unsafe.Pointer(&__value)))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__inputName)
			plugify.DestroyString(&__value)
		},
	}.Do()
}

// AcceptInput 
//  @brief Fire input on target entity
//
func AcceptInput(entity int64, inputName string, activator int64, caller int64, value string) {
	_AcceptInput(entity, inputName, activator, caller, value)
}

