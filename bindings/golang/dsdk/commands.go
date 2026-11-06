package dsdk

/*
#include "commands.h"
#cgo noescape AddServerCommand
#cgo noescape AddClientCommand
#cgo noescape AddChatCommand
#cgo noescape AddConsoleCommand
#cgo noescape RemoveCommand
#cgo noescape ServerCommand
#cgo noescape ExecuteCommandAsPlayer
#cgo noescape ClientCommand
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

// Generated from dsdk (group: commands)

var _AddServerCommand = func(name string, description string, flags int64, callback CommandCallback) bool {
	var __retVal bool
	__name := plugify.ConstructString(name)
	__description := plugify.ConstructString(description)
	__flags := C.int64_t(flags)
	__callback := plugify.GetFunctionPointerForDelegate(callback)
	plugify.Block {
		Try: func() {
			__retVal = bool(C.AddServerCommand((*C.String)(unsafe.Pointer(&__name)), (*C.String)(unsafe.Pointer(&__description)), __flags, __callback))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__name)
			plugify.DestroyString(&__description)
		},
	}.Do()
	return __retVal
}

// AddServerCommand 
//  @brief Register a server-console-only command
//
func AddServerCommand(name string, description string, flags int64, callback CommandCallback) bool {
	return _AddServerCommand(name, description, flags, callback)
}

var _AddClientCommand = func(name string, description string, flags int64, callback CommandCallback) bool {
	var __retVal bool
	__name := plugify.ConstructString(name)
	__description := plugify.ConstructString(description)
	__flags := C.int64_t(flags)
	__callback := plugify.GetFunctionPointerForDelegate(callback)
	plugify.Block {
		Try: func() {
			__retVal = bool(C.AddClientCommand((*C.String)(unsafe.Pointer(&__name)), (*C.String)(unsafe.Pointer(&__description)), __flags, __callback))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__name)
			plugify.DestroyString(&__description)
		},
	}.Do()
	return __retVal
}

// AddClientCommand 
//  @brief Register a client-console-only command
//
func AddClientCommand(name string, description string, flags int64, callback CommandCallback) bool {
	return _AddClientCommand(name, description, flags, callback)
}

var _AddChatCommand = func(name string, description string, flags int64, callback CommandCallback) bool {
	var __retVal bool
	__name := plugify.ConstructString(name)
	__description := plugify.ConstructString(description)
	__flags := C.int64_t(flags)
	__callback := plugify.GetFunctionPointerForDelegate(callback)
	plugify.Block {
		Try: func() {
			__retVal = bool(C.AddChatCommand((*C.String)(unsafe.Pointer(&__name)), (*C.String)(unsafe.Pointer(&__description)), __flags, __callback))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__name)
			plugify.DestroyString(&__description)
		},
	}.Do()
	return __retVal
}

// AddChatCommand 
//  @brief Register a client-chat-only command
//
func AddChatCommand(name string, description string, flags int64, callback CommandCallback) bool {
	return _AddChatCommand(name, description, flags, callback)
}

var _AddConsoleCommand = func(name string, description string, flags int64, callback CommandCallback) bool {
	var __retVal bool
	__name := plugify.ConstructString(name)
	__description := plugify.ConstructString(description)
	__flags := C.int64_t(flags)
	__callback := plugify.GetFunctionPointerForDelegate(callback)
	plugify.Block {
		Try: func() {
			__retVal = bool(C.AddConsoleCommand((*C.String)(unsafe.Pointer(&__name)), (*C.String)(unsafe.Pointer(&__description)), __flags, __callback))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__name)
			plugify.DestroyString(&__description)
		},
	}.Do()
	return __retVal
}

// AddConsoleCommand 
//  @brief Register a server/chat console command
//
func AddConsoleCommand(name string, description string, flags int64, callback CommandCallback) bool {
	return _AddConsoleCommand(name, description, flags, callback)
}

var _RemoveCommand = func(name string) bool {
	var __retVal bool
	__name := plugify.ConstructString(name)
	plugify.Block {
		Try: func() {
			__retVal = bool(C.RemoveCommand((*C.String)(unsafe.Pointer(&__name))))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__name)
		},
	}.Do()
	return __retVal
}

// RemoveCommand 
//  @brief Unregister a console command
//
func RemoveCommand(name string) bool {
	return _RemoveCommand(name)
}

var _ServerCommand = func(command string) {
	__command := plugify.ConstructString(command)
	plugify.Block {
		Try: func() {
			C.ServerCommand((*C.String)(unsafe.Pointer(&__command)))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__command)
		},
	}.Do()
}

// ServerCommand 
//  @brief Execute a command on the server console
//
func ServerCommand(command string) {
	_ServerCommand(command)
}

var _ExecuteCommandAsPlayer = func(playerSlot int32, command string) bool {
	var __retVal bool
	__playerSlot := C.int32_t(playerSlot)
	__command := plugify.ConstructString(command)
	plugify.Block {
		Try: func() {
			__retVal = bool(C.ExecuteCommandAsPlayer(__playerSlot, (*C.String)(unsafe.Pointer(&__command))))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__command)
		},
	}.Do()
	return __retVal
}

// ExecuteCommandAsPlayer 
//  @brief Execute a command on behalf of a player
//
func ExecuteCommandAsPlayer(playerSlot int32, command string) bool {
	return _ExecuteCommandAsPlayer(playerSlot, command)
}

var _ClientCommand = func(playerSlot int32, command string) {
	__playerSlot := C.int32_t(playerSlot)
	__command := plugify.ConstructString(command)
	plugify.Block {
		Try: func() {
			C.ClientCommand(__playerSlot, (*C.String)(unsafe.Pointer(&__command)))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__command)
		},
	}.Do()
}

// ClientCommand 
//  @brief Execute command on client
//
func ClientCommand(playerSlot int32, command string) {
	_ClientCommand(playerSlot, command)
}

