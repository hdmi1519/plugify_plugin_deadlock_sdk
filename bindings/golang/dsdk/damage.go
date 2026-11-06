package dsdk

/*
#include "damage.h"
#cgo noescape CreateDamageInfo
#cgo noescape DestroyDamageInfo
#cgo noescape TakeDamage
#cgo noescape ApplyDamage
#cgo noescape GetMaxHealth
#cgo noescape Heal
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

// Generated from dsdk (group: damage)

var _CreateDamageInfo = func(inflictor int64, attacker int64, ability int64, damage float32, damageType int32) int64 {
	var __retVal int64
	__inflictor := C.int64_t(inflictor)
	__attacker := C.int64_t(attacker)
	__ability := C.int64_t(ability)
	__damage := C.float(damage)
	__damageType := C.int32_t(damageType)
	__retVal = int64(C.CreateDamageInfo(__inflictor, __attacker, __ability, __damage, __damageType))
	return __retVal
}

// CreateDamageInfo 
//  @brief Create CTakeDamageInfo instance
//
func CreateDamageInfo(inflictor int64, attacker int64, ability int64, damage float32, damageType int32) int64 {
	return _CreateDamageInfo(inflictor, attacker, ability, damage, damageType)
}

var _DestroyDamageInfo = func(info int64) {
	__info := C.int64_t(info)
	C.DestroyDamageInfo(__info)
}

// DestroyDamageInfo 
//  @brief Free CTakeDamageInfo instance
//
func DestroyDamageInfo(info int64) {
	_DestroyDamageInfo(info)
}

var _TakeDamage = func(victim int64, info int64) {
	__victim := C.int64_t(victim)
	__info := C.int64_t(info)
	C.TakeDamage(__victim, __info)
}

// TakeDamage 
//  @brief Inflict damage on victim entity
//
func TakeDamage(victim int64, info int64) {
	_TakeDamage(victim, info)
}

var _ApplyDamage = func(victim int64, info int64) {
	__victim := C.int64_t(victim)
	__info := C.int64_t(info)
	C.ApplyDamage(__victim, __info)
}

// ApplyDamage 
//  @brief Apply damage bypassing damage filters
//
func ApplyDamage(victim int64, info int64) {
	_ApplyDamage(victim, info)
}

var _GetMaxHealth = func(entity int64) int32 {
	var __retVal int32
	__entity := C.int64_t(entity)
	__retVal = int32(C.GetMaxHealth(__entity))
	return __retVal
}

// GetMaxHealth 
//  @brief Get maximum health of entity
//
func GetMaxHealth(entity int64) int32 {
	return _GetMaxHealth(entity)
}

var _Heal = func(entity int64, amount float32) int32 {
	var __retVal int32
	__entity := C.int64_t(entity)
	__amount := C.float(amount)
	__retVal = int32(C.Heal(__entity, __amount))
	return __retVal
}

// Heal 
//  @brief Heal entity by amount
//
func Heal(entity int64, amount float32) int32 {
	return _Heal(entity, amount)
}

