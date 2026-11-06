package dsdk

/*
#include "zones.h"
#cgo noescape CreateBeam
#cgo noescape CreateZone
#cgo noescape DestroyZone
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

// Generated from dsdk (group: zones)

var _CreateBeam = func(startX float32, startY float32, startZ float32, endX float32, endY float32, endZ float32, width float32, r uint8, g uint8, b uint8, a uint8) int64 {
	var __retVal int64
	__startX := C.float(startX)
	__startY := C.float(startY)
	__startZ := C.float(startZ)
	__endX := C.float(endX)
	__endY := C.float(endY)
	__endZ := C.float(endZ)
	__width := C.float(width)
	__r := C.uint8_t(r)
	__g := C.uint8_t(g)
	__b := C.uint8_t(b)
	__a := C.uint8_t(a)
	__retVal = int64(C.CreateBeam(__startX, __startY, __startZ, __endX, __endY, __endZ, __width, __r, __g, __b, __a))
	return __retVal
}

// CreateBeam 
//  @brief Spawn a glowing laser beam entity between two world points
//
func CreateBeam(startX float32, startY float32, startZ float32, endX float32, endY float32, endZ float32, width float32, r uint8, g uint8, b uint8, a uint8) int64 {
	return _CreateBeam(startX, startY, startZ, endX, endY, endZ, width, r, g, b, a)
}

var _CreateZone = func(name string, minX float32, minY float32, minZ float32, maxX float32, maxY float32, maxZ float32) int64 {
	var __retVal int64
	__name := plugify.ConstructString(name)
	__minX := C.float(minX)
	__minY := C.float(minY)
	__minZ := C.float(minZ)
	__maxX := C.float(maxX)
	__maxY := C.float(maxY)
	__maxZ := C.float(maxZ)
	plugify.Block {
		Try: func() {
			__retVal = int64(C.CreateZone((*C.String)(unsafe.Pointer(&__name)), __minX, __minY, __minZ, __maxX, __maxY, __maxZ))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__name)
		},
	}.Do()
	return __retVal
}

// CreateZone 
//  @brief Create a spatial trigger volume box
//
func CreateZone(name string, minX float32, minY float32, minZ float32, maxX float32, maxY float32, maxZ float32) int64 {
	return _CreateZone(name, minX, minY, minZ, maxX, maxY, maxZ)
}

var _DestroyZone = func(zoneId int64) {
	__zoneId := C.int64_t(zoneId)
	C.DestroyZone(__zoneId)
}

// DestroyZone 
//  @brief Destroy a spatial zone trigger
//
func DestroyZone(zoneId int64) {
	_DestroyZone(zoneId)
}

