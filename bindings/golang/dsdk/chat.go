package dsdk

/*
#include "chat.h"
#cgo noescape PrintToChat
#cgo noescape PrintToChatAll
#cgo noescape PrintToConsole
#cgo noescape PrintToConsoleAll
#cgo noescape HudAnnounce
#cgo noescape HudAnnounceAll
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

// Generated from dsdk (group: chat)

var _PrintToChat = func(playerSlot int32, message string) {
	__playerSlot := C.int32_t(playerSlot)
	__message := plugify.ConstructString(message)
	plugify.Block {
		Try: func() {
			C.PrintToChat(__playerSlot, (*C.String)(unsafe.Pointer(&__message)))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__message)
		},
	}.Do()
}

// PrintToChat 
//  @brief Print message to client chat
//
func PrintToChat(playerSlot int32, message string) {
	_PrintToChat(playerSlot, message)
}

var _PrintToChatAll = func(message string) {
	__message := plugify.ConstructString(message)
	plugify.Block {
		Try: func() {
			C.PrintToChatAll((*C.String)(unsafe.Pointer(&__message)))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__message)
		},
	}.Do()
}

// PrintToChatAll 
//  @brief Broadcast message to all players
//
func PrintToChatAll(message string) {
	_PrintToChatAll(message)
}

var _PrintToConsole = func(playerSlot int32, message string) {
	__playerSlot := C.int32_t(playerSlot)
	__message := plugify.ConstructString(message)
	plugify.Block {
		Try: func() {
			C.PrintToConsole(__playerSlot, (*C.String)(unsafe.Pointer(&__message)))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__message)
		},
	}.Do()
}

// PrintToConsole 
//  @brief Print message to client console
//
func PrintToConsole(playerSlot int32, message string) {
	_PrintToConsole(playerSlot, message)
}

var _PrintToConsoleAll = func(message string) {
	__message := plugify.ConstructString(message)
	plugify.Block {
		Try: func() {
			C.PrintToConsoleAll((*C.String)(unsafe.Pointer(&__message)))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__message)
		},
	}.Do()
}

// PrintToConsoleAll 
//  @brief Print message to all player consoles
//
func PrintToConsoleAll(message string) {
	_PrintToConsoleAll(message)
}

var _HudAnnounce = func(playerSlot int32, title string, description string, duration float32) {
	__playerSlot := C.int32_t(playerSlot)
	__title := plugify.ConstructString(title)
	__description := plugify.ConstructString(description)
	__duration := C.float(duration)
	plugify.Block {
		Try: func() {
			C.HudAnnounce(__playerSlot, (*C.String)(unsafe.Pointer(&__title)), (*C.String)(unsafe.Pointer(&__description)), __duration)
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__title)
			plugify.DestroyString(&__description)
		},
	}.Do()
}

// HudAnnounce 
//  @brief Display a HUD game announcement banner to a player
//
func HudAnnounce(playerSlot int32, title string, description string, duration float32) {
	_HudAnnounce(playerSlot, title, description, duration)
}

var _HudAnnounceAll = func(title string, description string, duration float32) {
	__title := plugify.ConstructString(title)
	__description := plugify.ConstructString(description)
	__duration := C.float(duration)
	plugify.Block {
		Try: func() {
			C.HudAnnounceAll((*C.String)(unsafe.Pointer(&__title)), (*C.String)(unsafe.Pointer(&__description)), __duration)
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__title)
			plugify.DestroyString(&__description)
		},
	}.Do()
}

// HudAnnounceAll 
//  @brief Display a HUD game announcement banner to all players
//
func HudAnnounceAll(title string, description string, duration float32) {
	_HudAnnounceAll(title, description, duration)
}

