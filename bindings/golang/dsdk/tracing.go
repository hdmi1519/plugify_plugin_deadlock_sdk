package dsdk

/*
#include "tracing.h"
#cgo noescape LineTrace
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

// Generated from dsdk (group: tracing)

var _LineTrace = func(startX float32, startY float32, startZ float32, endX float32, endY float32, endZ float32, mask uint32, ignoreEntity int64) bool {
	var __retVal bool
	__startX := C.float(startX)
	__startY := C.float(startY)
	__startZ := C.float(startZ)
	__endX := C.float(endX)
	__endY := C.float(endY)
	__endZ := C.float(endZ)
	__mask := C.uint32_t(mask)
	__ignoreEntity := C.int64_t(ignoreEntity)
	__retVal = bool(C.LineTrace(__startX, __startY, __startZ, __endX, __endY, __endZ, __mask, __ignoreEntity))
	return __retVal
}

// LineTrace 
//  @brief Perform physics raycast trace between start and end vectors
//
func LineTrace(startX float32, startY float32, startZ float32, endX float32, endY float32, endZ float32, mask uint32, ignoreEntity int64) bool {
	return _LineTrace(startX, startY, startZ, endX, endY, endZ, mask, ignoreEntity)
}

