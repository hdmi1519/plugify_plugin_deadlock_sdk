package dsdk

/*
#include "sound.h"
#cgo noescape EmitSound
#cgo noescape TakeSoundEventGuid
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

// Generated from dsdk (group: sound)

var _EmitSound = func(entity int64, soundName string, pitch int32, volume float32, delay float32) {
	__entity := C.int64_t(entity)
	__soundName := plugify.ConstructString(soundName)
	__pitch := C.int32_t(pitch)
	__volume := C.float(volume)
	__delay := C.float(delay)
	plugify.Block {
		Try: func() {
			C.EmitSound(__entity, (*C.String)(unsafe.Pointer(&__soundName)), __pitch, __volume, __delay)
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__soundName)
		},
	}.Do()
}

// EmitSound 
//  @brief Emit sound event from entity
//
func EmitSound(entity int64, soundName string, pitch int32, volume float32, delay float32) {
	_EmitSound(entity, soundName, pitch, volume, delay)
}

var _TakeSoundEventGuid = func() uint32 {
	__retVal := uint32(C.TakeSoundEventGuid())
	return __retVal
}

// TakeSoundEventGuid 
//  @brief Generate unique sound event GUID
//
func TakeSoundEventGuid() uint32 {
	return _TakeSoundEventGuid()
}

