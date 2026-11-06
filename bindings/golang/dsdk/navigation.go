package dsdk

/*
#include "navigation.h"
#cgo noescape NavGetNearestPoint
#cgo noescape NavGetGroundHeight
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

// Generated from dsdk (group: navigation)

var _NavGetNearestPoint = func(x float32, y float32, z float32, maxDistance float32, hull int32) bool {
	var __retVal bool
	__x := C.float(x)
	__y := C.float(y)
	__z := C.float(z)
	__maxDistance := C.float(maxDistance)
	__hull := C.int32_t(hull)
	__retVal = bool(C.NavGetNearestPoint(__x, __y, __z, __maxDistance, __hull))
	return __retVal
}

// NavGetNearestPoint 
//  @brief Find nearest point on navmesh
//
func NavGetNearestPoint(x float32, y float32, z float32, maxDistance float32, hull int32) bool {
	return _NavGetNearestPoint(x, y, z, maxDistance, hull)
}

var _NavGetGroundHeight = func(x float32, y float32, z float32, maxDistance float32, hull int32) float32 {
	var __retVal float32
	__x := C.float(x)
	__y := C.float(y)
	__z := C.float(z)
	__maxDistance := C.float(maxDistance)
	__hull := C.int32_t(hull)
	__retVal = float32(C.NavGetGroundHeight(__x, __y, __z, __maxDistance, __hull))
	return __retVal
}

// NavGetGroundHeight 
//  @brief Get ground elevation from navmesh
//
func NavGetGroundHeight(x float32, y float32, z float32, maxDistance float32, hull int32) float32 {
	return _NavGetGroundHeight(x, y, z, maxDistance, hull)
}

