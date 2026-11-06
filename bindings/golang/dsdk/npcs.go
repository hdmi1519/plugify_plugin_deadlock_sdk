package dsdk

/*
#include "npcs.h"
#cgo noescape NpcMoveTo
#cgo noescape NpcStopMoving
#cgo noescape NpcSetEnemy
#cgo noescape NpcSetState
#cgo noescape NpcCreateTrooper
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

// Generated from dsdk (group: npcs)

var _NpcMoveTo = func(npc int64, x float32, y float32, z float32, run bool, tolerance float32) {
	__npc := C.int64_t(npc)
	__x := C.float(x)
	__y := C.float(y)
	__z := C.float(z)
	__run := C.bool(run)
	__tolerance := C.float(tolerance)
	C.NpcMoveTo(__npc, __x, __y, __z, __run, __tolerance)
}

// NpcMoveTo 
//  @brief Direct AI NPC to move to goal location
//
func NpcMoveTo(npc int64, x float32, y float32, z float32, run bool, tolerance float32) {
	_NpcMoveTo(npc, x, y, z, run, tolerance)
}

var _NpcStopMoving = func(npc int64, instant bool) {
	__npc := C.int64_t(npc)
	__instant := C.bool(instant)
	C.NpcStopMoving(__npc, __instant)
}

// NpcStopMoving 
//  @brief Stop movement of AI NPC
//
func NpcStopMoving(npc int64, instant bool) {
	_NpcStopMoving(npc, instant)
}

var _NpcSetEnemy = func(npc int64, enemy int64) {
	__npc := C.int64_t(npc)
	__enemy := C.int64_t(enemy)
	C.NpcSetEnemy(__npc, __enemy)
}

// NpcSetEnemy 
//  @brief Set target enemy entity of AI NPC
//
func NpcSetEnemy(npc int64, enemy int64) {
	_NpcSetEnemy(npc, enemy)
}

var _NpcSetState = func(npc int64, state int32) {
	__npc := C.int64_t(npc)
	__state := C.int32_t(state)
	C.NpcSetState(__npc, __state)
}

// NpcSetState 
//  @brief Set NPC AI state
//
func NpcSetState(npc int64, state int32) {
	_NpcSetState(npc, state)
}

var _NpcCreateTrooper = func(posX float32, posY float32, posZ float32, pitch float32, yaw float32, roll float32, team int32, type_ int32, variant int32, snapToGround bool) int64 {
	var __retVal int64
	__posX := C.float(posX)
	__posY := C.float(posY)
	__posZ := C.float(posZ)
	__pitch := C.float(pitch)
	__yaw := C.float(yaw)
	__roll := C.float(roll)
	__team := C.int32_t(team)
	__type_ := C.int32_t(type_)
	__variant := C.int32_t(variant)
	__snapToGround := C.bool(snapToGround)
	__retVal = int64(C.NpcCreateTrooper(__posX, __posY, __posZ, __pitch, __yaw, __roll, __team, __type_, __variant, __snapToGround))
	return __retVal
}

// NpcCreateTrooper 
//  @brief Spawn lane or neutral trooper NPC
//
func NpcCreateTrooper(posX float32, posY float32, posZ float32, pitch float32, yaw float32, roll float32, team int32, type_ int32, variant int32, snapToGround bool) int64 {
	return _NpcCreateTrooper(posX, posY, posZ, pitch, yaw, roll, team, type_, variant, snapToGround)
}

