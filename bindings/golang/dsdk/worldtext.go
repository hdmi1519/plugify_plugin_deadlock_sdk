package dsdk

/*
#include "worldtext.h"
#cgo noescape CreateWorldText
#cgo noescape SetWorldTextMessage
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

// Generated from dsdk (group: worldtext)

var _CreateWorldText = func(message string, x float32, y float32, z float32, fontSize float32, r uint8, g uint8, b uint8, a uint8) int64 {
	var __retVal int64
	__message := plugify.ConstructString(message)
	__x := C.float(x)
	__y := C.float(y)
	__z := C.float(z)
	__fontSize := C.float(fontSize)
	__r := C.uint8_t(r)
	__g := C.uint8_t(g)
	__b := C.uint8_t(b)
	__a := C.uint8_t(a)
	plugify.Block {
		Try: func() {
			__retVal = int64(C.CreateWorldText((*C.String)(unsafe.Pointer(&__message)), __x, __y, __z, __fontSize, __r, __g, __b, __a))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__message)
		},
	}.Do()
	return __retVal
}

// CreateWorldText 
//  @brief Create 3D point_worldtext entity in the world
//
func CreateWorldText(message string, x float32, y float32, z float32, fontSize float32, r uint8, g uint8, b uint8, a uint8) int64 {
	return _CreateWorldText(message, x, y, z, fontSize, r, g, b, a)
}

var _SetWorldTextMessage = func(worldText int64, text string) {
	__worldText := C.int64_t(worldText)
	__text := plugify.ConstructString(text)
	plugify.Block {
		Try: func() {
			C.SetWorldTextMessage(__worldText, (*C.String)(unsafe.Pointer(&__text)))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__text)
		},
	}.Do()
}

// SetWorldTextMessage 
//  @brief Update message text of CPointWorldText
//
func SetWorldTextMessage(worldText int64, text string) {
	_SetWorldTextMessage(worldText, text)
}

