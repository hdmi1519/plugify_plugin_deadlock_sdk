package dsdk

/*
#include "heroes.h"
#cgo noescape SelectHero
#cgo noescape ResetHero
#cgo noescape PrecacheHero
#cgo noescape ForceRespawn
#cgo noescape GetHeroData
#cgo noescape GetHeroName
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

// Generated from dsdk (group: heroes)

var _SelectHero = func(controller int64, heroName string) {
	__controller := C.int64_t(controller)
	__heroName := plugify.ConstructString(heroName)
	plugify.Block {
		Try: func() {
			C.SelectHero(__controller, (*C.String)(unsafe.Pointer(&__heroName)))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__heroName)
		},
	}.Do()
}

// SelectHero 
//  @brief Select a hero for controller
//
func SelectHero(controller int64, heroName string) {
	_SelectHero(controller, heroName)
}

var _ResetHero = func(pawn int64, reset bool) {
	__pawn := C.int64_t(pawn)
	__reset := C.bool(reset)
	C.ResetHero(__pawn, __reset)
}

// ResetHero 
//  @brief Reset hero state on pawn
//
func ResetHero(pawn int64, reset bool) {
	_ResetHero(pawn, reset)
}

var _PrecacheHero = func(heroName string) {
	__heroName := plugify.ConstructString(heroName)
	plugify.Block {
		Try: func() {
			C.PrecacheHero((*C.String)(unsafe.Pointer(&__heroName)))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__heroName)
		},
	}.Do()
}

// PrecacheHero 
//  @brief Precache hero assets
//
func PrecacheHero(heroName string) {
	_PrecacheHero(heroName)
}

var _ForceRespawn = func(pawn int64, releaseButtons bool) {
	__pawn := C.int64_t(pawn)
	__releaseButtons := C.bool(releaseButtons)
	C.ForceRespawn(__pawn, __releaseButtons)
}

// ForceRespawn 
//  @brief Force immediate hero pawn respawn
//
func ForceRespawn(pawn int64, releaseButtons bool) {
	_ForceRespawn(pawn, releaseButtons)
}

var _GetHeroData = func(heroName string) int64 {
	var __retVal int64
	__heroName := plugify.ConstructString(heroName)
	plugify.Block {
		Try: func() {
			__retVal = int64(C.GetHeroData((*C.String)(unsafe.Pointer(&__heroName))))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__heroName)
		},
	}.Do()
	return __retVal
}

// GetHeroData 
//  @brief Lookup hero definition pointer
//
func GetHeroData(heroName string) int64 {
	return _GetHeroData(heroName)
}

var _GetHeroName = func(pawn int64) string {
	var __retVal string
	var __retVal_native plugify.PlgString
	__pawn := C.int64_t(pawn)
	plugify.Block {
		Try: func() {
			__native := C.GetHeroName(__pawn)
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

// GetHeroName 
//  @brief Get name of hero for pawn
//
func GetHeroName(pawn int64) string {
	return _GetHeroName(pawn)
}

