package dsdk

/*
#include "timers.h"
#cgo noescape CreateTimer
#cgo noescape KillTimer
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

// Generated from dsdk (group: timers)

var _CreateTimer = func(interval float32, callback TimerCallback, repeating bool) int64 {
	var __retVal int64
	__interval := C.float(interval)
	__callback := plugify.GetFunctionPointerForDelegate(callback)
	__repeating := C.bool(repeating)
	__retVal = int64(C.CreateTimer(__interval, __callback, __repeating))
	return __retVal
}

// CreateTimer 
//  @brief Create a one-shot or repeating timer
//
func CreateTimer(interval float32, callback TimerCallback, repeating bool) int64 {
	return _CreateTimer(interval, callback, repeating)
}

var _KillTimer = func(timerId int64) bool {
	var __retVal bool
	__timerId := C.int64_t(timerId)
	__retVal = bool(C.KillTimer(__timerId))
	return __retVal
}

// KillTimer 
//  @brief Stop and delete an active timer
//
func KillTimer(timerId int64) bool {
	return _KillTimer(timerId)
}

