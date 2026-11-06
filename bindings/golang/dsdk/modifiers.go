package dsdk

/*
#include "modifiers.h"
#cgo noescape AddModifier
#cgo noescape RemoveModifier
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

// Generated from dsdk (group: modifiers)

var _AddModifier = func(entity int64, modifierName string, kv3 int64, caster int64, ability int64, team int32) int64 {
	var __retVal int64
	__entity := C.int64_t(entity)
	__modifierName := plugify.ConstructString(modifierName)
	__kv3 := C.int64_t(kv3)
	__caster := C.int64_t(caster)
	__ability := C.int64_t(ability)
	__team := C.int32_t(team)
	plugify.Block {
		Try: func() {
			__retVal = int64(C.AddModifier(__entity, (*C.String)(unsafe.Pointer(&__modifierName)), __kv3, __caster, __ability, __team))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__modifierName)
		},
	}.Do()
	return __retVal
}

// AddModifier 
//  @brief Add modifier to entity
//
func AddModifier(entity int64, modifierName string, kv3 int64, caster int64, ability int64, team int32) int64 {
	return _AddModifier(entity, modifierName, kv3, caster, ability, team)
}

var _RemoveModifier = func(entity int64, modifier int64) bool {
	var __retVal bool
	__entity := C.int64_t(entity)
	__modifier := C.int64_t(modifier)
	__retVal = bool(C.RemoveModifier(__entity, __modifier))
	return __retVal
}

// RemoveModifier 
//  @brief Remove modifier instance from entity
//
func RemoveModifier(entity int64, modifier int64) bool {
	return _RemoveModifier(entity, modifier)
}

