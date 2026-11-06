package dsdk

/*
#include "particles.h"
#cgo noescape CreateParticle
#cgo noescape DestroyParticle
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

// Generated from dsdk (group: particles)

var _CreateParticle = func(particleName string, attachType int32, entity int64) int64 {
	var __retVal int64
	__particleName := plugify.ConstructString(particleName)
	__attachType := C.int32_t(attachType)
	__entity := C.int64_t(entity)
	plugify.Block {
		Try: func() {
			__retVal = int64(C.CreateParticle((*C.String)(unsafe.Pointer(&__particleName)), __attachType, __entity))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__particleName)
		},
	}.Do()
	return __retVal
}

// CreateParticle 
//  @brief Create and dispatch particle effect
//
func CreateParticle(particleName string, attachType int32, entity int64) int64 {
	return _CreateParticle(particleName, attachType, entity)
}

var _DestroyParticle = func(particle int64, destroyImmediately bool) {
	__particle := C.int64_t(particle)
	__destroyImmediately := C.bool(destroyImmediately)
	C.DestroyParticle(__particle, __destroyImmediately)
}

// DestroyParticle 
//  @brief Destroy active particle instance
//
func DestroyParticle(particle int64, destroyImmediately bool) {
	_DestroyParticle(particle, destroyImmediately)
}

