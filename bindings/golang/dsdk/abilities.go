package dsdk

/*
#include "abilities.h"
#cgo noescape AddAbility
#cgo noescape RemoveAbility
#cgo noescape RemoveAbilityByEntity
#cgo noescape FindAbilityByName
#cgo noescape GetAbilityBySlot
#cgo noescape ExecuteAbility
#cgo noescape ToggleActivate
#cgo noescape ResetAbilityCooldown
#cgo noescape GetAbilityMaxCharges
#cgo noescape SetUpgradeBits
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

// Generated from dsdk (group: abilities)

var _AddAbility = func(pawn int64, abilityName string, slot uint16) int64 {
	var __retVal int64
	__pawn := C.int64_t(pawn)
	__abilityName := plugify.ConstructString(abilityName)
	__slot := C.uint16_t(slot)
	plugify.Block {
		Try: func() {
			__retVal = int64(C.AddAbility(__pawn, (*C.String)(unsafe.Pointer(&__abilityName)), __slot))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__abilityName)
		},
	}.Do()
	return __retVal
}

// AddAbility 
//  @brief Add an ability to player pawn
//
func AddAbility(pawn int64, abilityName string, slot uint16) int64 {
	return _AddAbility(pawn, abilityName, slot)
}

var _RemoveAbility = func(pawn int64, abilityName string) bool {
	var __retVal bool
	__pawn := C.int64_t(pawn)
	__abilityName := plugify.ConstructString(abilityName)
	plugify.Block {
		Try: func() {
			__retVal = bool(C.RemoveAbility(__pawn, (*C.String)(unsafe.Pointer(&__abilityName))))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__abilityName)
		},
	}.Do()
	return __retVal
}

// RemoveAbility 
//  @brief Remove ability by name from pawn
//
func RemoveAbility(pawn int64, abilityName string) bool {
	return _RemoveAbility(pawn, abilityName)
}

var _RemoveAbilityByEntity = func(pawn int64, ability int64) bool {
	var __retVal bool
	__pawn := C.int64_t(pawn)
	__ability := C.int64_t(ability)
	__retVal = bool(C.RemoveAbilityByEntity(__pawn, __ability))
	return __retVal
}

// RemoveAbilityByEntity 
//  @brief Remove ability by entity pointer
//
func RemoveAbilityByEntity(pawn int64, ability int64) bool {
	return _RemoveAbilityByEntity(pawn, ability)
}

var _FindAbilityByName = func(abilityComponent int64, abilityName string) int64 {
	var __retVal int64
	__abilityComponent := C.int64_t(abilityComponent)
	__abilityName := plugify.ConstructString(abilityName)
	plugify.Block {
		Try: func() {
			__retVal = int64(C.FindAbilityByName(__abilityComponent, (*C.String)(unsafe.Pointer(&__abilityName))))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__abilityName)
		},
	}.Do()
	return __retVal
}

// FindAbilityByName 
//  @brief Find ability in ability component
//
func FindAbilityByName(abilityComponent int64, abilityName string) int64 {
	return _FindAbilityByName(abilityComponent, abilityName)
}

var _GetAbilityBySlot = func(abilityComponent int64, slot int16) int64 {
	var __retVal int64
	__abilityComponent := C.int64_t(abilityComponent)
	__slot := C.int16_t(slot)
	__retVal = int64(C.GetAbilityBySlot(__abilityComponent, __slot))
	return __retVal
}

// GetAbilityBySlot 
//  @brief Get ability at slot index
//
func GetAbilityBySlot(abilityComponent int64, slot int16) int64 {
	return _GetAbilityBySlot(abilityComponent, slot)
}

var _ExecuteAbility = func(abilityComponent int64, ability int64, altCast bool, flags uint8) int32 {
	var __retVal int32
	__abilityComponent := C.int64_t(abilityComponent)
	__ability := C.int64_t(ability)
	__altCast := C.bool(altCast)
	__flags := C.uint8_t(flags)
	__retVal = int32(C.ExecuteAbility(__abilityComponent, __ability, __altCast, __flags))
	return __retVal
}

// ExecuteAbility 
//  @brief Cast/execute an ability
//
func ExecuteAbility(abilityComponent int64, ability int64, altCast bool, flags uint8) int32 {
	return _ExecuteAbility(abilityComponent, ability, altCast, flags)
}

var _ToggleActivate = func(ability int64, activate bool) {
	__ability := C.int64_t(ability)
	__activate := C.bool(activate)
	C.ToggleActivate(__ability, __activate)
}

// ToggleActivate 
//  @brief Toggle ability active status
//
func ToggleActivate(ability int64, activate bool) {
	_ToggleActivate(ability, activate)
}

var _ResetAbilityCooldown = func(ability int64) {
	__ability := C.int64_t(ability)
	C.ResetAbilityCooldown(__ability)
}

// ResetAbilityCooldown 
//  @brief Reset ability cooldown and refill charges
//
func ResetAbilityCooldown(ability int64) {
	_ResetAbilityCooldown(ability)
}

var _GetAbilityMaxCharges = func(ability int64) int32 {
	var __retVal int32
	__ability := C.int64_t(ability)
	__retVal = int32(C.GetAbilityMaxCharges(__ability))
	return __retVal
}

// GetAbilityMaxCharges 
//  @brief Get maximum charges of an ability
//
func GetAbilityMaxCharges(ability int64) int32 {
	return _GetAbilityMaxCharges(ability)
}

var _SetUpgradeBits = func(ability int64, newBits int32) {
	__ability := C.int64_t(ability)
	__newBits := C.int32_t(newBits)
	C.SetUpgradeBits(__ability, __newBits)
}

// SetUpgradeBits 
//  @brief Set upgrade bits on ability
//
func SetUpgradeBits(ability int64, newBits int32) {
	_SetUpgradeBits(ability, newBits)
}

