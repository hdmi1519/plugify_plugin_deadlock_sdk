package dsdk

/*
#include "entities.h"
#cgo noescape CreateEntityByName
#cgo noescape QueueSpawnEntity
#cgo noescape ExecuteQueuedCreation
#cgo noescape RemoveEntity
#cgo noescape GetEntityByIndex
#cgo noescape GetEntityFromHandle
#cgo noescape GetEntityHandle
#cgo noescape FindEntityByName
#cgo noescape GetEntityDesignerName
#cgo noescape GetEntityClassname
#cgo noescape Teleport
#cgo noescape SetModel
#cgo noescape GetModelName
#cgo noescape SetScale
#cgo noescape SetMoveType
#cgo noescape SetGravityScale
#cgo noescape EntityDerivesFrom
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

// Generated from dsdk (group: entities)

var _CreateEntityByName = func(className string) int64 {
	var __retVal int64
	__className := plugify.ConstructString(className)
	plugify.Block {
		Try: func() {
			__retVal = int64(C.CreateEntityByName((*C.String)(unsafe.Pointer(&__className))))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__className)
		},
	}.Do()
	return __retVal
}

// CreateEntityByName 
//  @brief Create entity instance by class name
//
func CreateEntityByName(className string) int64 {
	return _CreateEntityByName(className)
}

var _QueueSpawnEntity = func(entity int64, ekv int64) {
	__entity := C.int64_t(entity)
	__ekv := C.int64_t(ekv)
	C.QueueSpawnEntity(__entity, __ekv)
}

// QueueSpawnEntity 
//  @brief Queue entity spawn with optional entity keyvalues
//
func QueueSpawnEntity(entity int64, ekv int64) {
	_QueueSpawnEntity(entity, ekv)
}

var _ExecuteQueuedCreation = func() {
	C.ExecuteQueuedCreation()
}

// ExecuteQueuedCreation 
//  @brief Execute queued entity creation
//
func ExecuteQueuedCreation() {
	_ExecuteQueuedCreation()
}

var _RemoveEntity = func(entity int64) {
	__entity := C.int64_t(entity)
	C.RemoveEntity(__entity)
}

// RemoveEntity 
//  @brief Remove/destroy entity
//
func RemoveEntity(entity int64) {
	_RemoveEntity(entity)
}

var _GetEntityByIndex = func(index int32) int64 {
	var __retVal int64
	__index := C.int32_t(index)
	__retVal = int64(C.GetEntityByIndex(__index))
	return __retVal
}

// GetEntityByIndex 
//  @brief Get entity pointer by index
//
func GetEntityByIndex(index int32) int64 {
	return _GetEntityByIndex(index)
}

var _GetEntityFromHandle = func(handle uint32) int64 {
	var __retVal int64
	__handle := C.uint32_t(handle)
	__retVal = int64(C.GetEntityFromHandle(__handle))
	return __retVal
}

// GetEntityFromHandle 
//  @brief Resolve entity pointer from uint32 handle
//
func GetEntityFromHandle(handle uint32) int64 {
	return _GetEntityFromHandle(handle)
}

var _GetEntityHandle = func(entity int64) uint32 {
	var __retVal uint32
	__entity := C.int64_t(entity)
	__retVal = uint32(C.GetEntityHandle(__entity))
	return __retVal
}

// GetEntityHandle 
//  @brief Get handle of entity
//
func GetEntityHandle(entity int64) uint32 {
	return _GetEntityHandle(entity)
}

var _FindEntityByName = func(startEntity int64, name string) int64 {
	var __retVal int64
	__startEntity := C.int64_t(startEntity)
	__name := plugify.ConstructString(name)
	plugify.Block {
		Try: func() {
			__retVal = int64(C.FindEntityByName(__startEntity, (*C.String)(unsafe.Pointer(&__name))))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__name)
		},
	}.Do()
	return __retVal
}

// FindEntityByName 
//  @brief Find entity by name
//
func FindEntityByName(startEntity int64, name string) int64 {
	return _FindEntityByName(startEntity, name)
}

var _GetEntityDesignerName = func(entity int64) string {
	var __retVal string
	var __retVal_native plugify.PlgString
	__entity := C.int64_t(entity)
	plugify.Block {
		Try: func() {
			__native := C.GetEntityDesignerName(__entity)
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

// GetEntityDesignerName 
//  @brief Get designer name of entity
//
func GetEntityDesignerName(entity int64) string {
	return _GetEntityDesignerName(entity)
}

var _GetEntityClassname = func(entity int64) string {
	var __retVal string
	var __retVal_native plugify.PlgString
	__entity := C.int64_t(entity)
	plugify.Block {
		Try: func() {
			__native := C.GetEntityClassname(__entity)
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

// GetEntityClassname 
//  @brief Get class name of entity
//
func GetEntityClassname(entity int64) string {
	return _GetEntityClassname(entity)
}

var _Teleport = func(entity int64, posX float32, posY float32, posZ float32, angPitch float32, angYaw float32, angRoll float32, velX float32, velY float32, velZ float32) {
	__entity := C.int64_t(entity)
	__posX := C.float(posX)
	__posY := C.float(posY)
	__posZ := C.float(posZ)
	__angPitch := C.float(angPitch)
	__angYaw := C.float(angYaw)
	__angRoll := C.float(angRoll)
	__velX := C.float(velX)
	__velY := C.float(velY)
	__velZ := C.float(velZ)
	C.Teleport(__entity, __posX, __posY, __posZ, __angPitch, __angYaw, __angRoll, __velX, __velY, __velZ)
}

// Teleport 
//  @brief Teleport entity with position, angles and velocity
//
func Teleport(entity int64, posX float32, posY float32, posZ float32, angPitch float32, angYaw float32, angRoll float32, velX float32, velY float32, velZ float32) {
	_Teleport(entity, posX, posY, posZ, angPitch, angYaw, angRoll, velX, velY, velZ)
}

var _SetModel = func(entity int64, modelName string) {
	__entity := C.int64_t(entity)
	__modelName := plugify.ConstructString(modelName)
	plugify.Block {
		Try: func() {
			C.SetModel(__entity, (*C.String)(unsafe.Pointer(&__modelName)))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__modelName)
		},
	}.Do()
}

// SetModel 
//  @brief Set visual model of entity
//
func SetModel(entity int64, modelName string) {
	_SetModel(entity, modelName)
}

var _GetModelName = func(entity int64) string {
	var __retVal string
	var __retVal_native plugify.PlgString
	__entity := C.int64_t(entity)
	plugify.Block {
		Try: func() {
			__native := C.GetModelName(__entity)
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

// GetModelName 
//  @brief Get model name of entity
//
func GetModelName(entity int64) string {
	return _GetModelName(entity)
}

var _SetScale = func(entity int64, scale float32) {
	__entity := C.int64_t(entity)
	__scale := C.float(scale)
	C.SetScale(__entity, __scale)
}

// SetScale 
//  @brief Set visual scale of entity
//
func SetScale(entity int64, scale float32) {
	_SetScale(entity, scale)
}

var _SetMoveType = func(entity int64, moveType uint8) {
	__entity := C.int64_t(entity)
	__moveType := C.uint8_t(moveType)
	C.SetMoveType(__entity, __moveType)
}

// SetMoveType 
//  @brief Set entity move type
//
func SetMoveType(entity int64, moveType uint8) {
	_SetMoveType(entity, moveType)
}

var _SetGravityScale = func(entity int64, scale float32) {
	__entity := C.int64_t(entity)
	__scale := C.float(scale)
	C.SetGravityScale(__entity, __scale)
}

// SetGravityScale 
//  @brief Set entity gravity multiplier
//
func SetGravityScale(entity int64, scale float32) {
	_SetGravityScale(entity, scale)
}

var _EntityDerivesFrom = func(entity int64, baseClassName string) bool {
	var __retVal bool
	__entity := C.int64_t(entity)
	__baseClassName := plugify.ConstructString(baseClassName)
	plugify.Block {
		Try: func() {
			__retVal = bool(C.EntityDerivesFrom(__entity, (*C.String)(unsafe.Pointer(&__baseClassName))))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__baseClassName)
		},
	}.Do()
	return __retVal
}

// EntityDerivesFrom 
//  @brief Check if entity class derives from base class name
//
func EntityDerivesFrom(entity int64, baseClassName string) bool {
	return _EntityDerivesFrom(entity, baseClassName)
}

