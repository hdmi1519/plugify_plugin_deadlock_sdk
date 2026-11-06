package dsdk

/*
#include "networking.h"
#cgo noescape SendNetMessage
#cgo noescape GetNetMessageName
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

// Generated from dsdk (group: networking)

var _SendNetMessage = func(msgId int32, protoBytes []uint8, recipientMask uint64, bufType int32) {
	__msgId := C.int32_t(msgId)
	__protoBytes := plugify.ConstructVectorUInt8(protoBytes)
	__recipientMask := C.uint64_t(recipientMask)
	__bufType := C.int32_t(bufType)
	plugify.Block {
		Try: func() {
			C.SendNetMessage(__msgId, (*C.Vector)(unsafe.Pointer(&__protoBytes)), __recipientMask, __bufType)
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyVectorUInt8(&__protoBytes)
		},
	}.Do()
}

// SendNetMessage 
//  @brief Send protobuf network message to clients
//
func SendNetMessage(msgId int32, protoBytes []uint8, recipientMask uint64, bufType int32) {
	_SendNetMessage(msgId, protoBytes, recipientMask, bufType)
}

var _GetNetMessageName = func(msgId int32) string {
	var __retVal string
	var __retVal_native plugify.PlgString
	__msgId := C.int32_t(msgId)
	plugify.Block {
		Try: func() {
			__native := C.GetNetMessageName(__msgId)
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

// GetNetMessageName 
//  @brief Get registered network message name
//
func GetNetMessageName(msgId int32) string {
	return _GetNetMessageName(msgId)
}

