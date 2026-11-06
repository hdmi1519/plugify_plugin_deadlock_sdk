package dsdk

/*
#include "items.h"
#cgo noescape AddItem
#cgo noescape SellItem
#cgo noescape GetItemImbueEffects
#cgo noescape CanImbueAbility
#cgo noescape ImbueAbility
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

// Generated from dsdk (group: items)

var _AddItem = func(pawn int64, itemName string, upgradeTier int32) int64 {
	var __retVal int64
	__pawn := C.int64_t(pawn)
	__itemName := plugify.ConstructString(itemName)
	__upgradeTier := C.int32_t(upgradeTier)
	plugify.Block {
		Try: func() {
			__retVal = int64(C.AddItem(__pawn, (*C.String)(unsafe.Pointer(&__itemName)), __upgradeTier))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__itemName)
		},
	}.Do()
	return __retVal
}

// AddItem 
//  @brief Add an item to player pawn
//
func AddItem(pawn int64, itemName string, upgradeTier int32) int64 {
	return _AddItem(pawn, itemName, upgradeTier)
}

var _SellItem = func(pawn int64, itemName string, fullRefund bool, forceSellPrice bool) bool {
	var __retVal bool
	__pawn := C.int64_t(pawn)
	__itemName := plugify.ConstructString(itemName)
	__fullRefund := C.bool(fullRefund)
	__forceSellPrice := C.bool(forceSellPrice)
	plugify.Block {
		Try: func() {
			__retVal = bool(C.SellItem(__pawn, (*C.String)(unsafe.Pointer(&__itemName)), __fullRefund, __forceSellPrice))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__itemName)
		},
	}.Do()
	return __retVal
}

// SellItem 
//  @brief Sell an item from pawn
//
func SellItem(pawn int64, itemName string, fullRefund bool, forceSellPrice bool) bool {
	return _SellItem(pawn, itemName, fullRefund, forceSellPrice)
}

var _GetItemImbueEffects = func(itemName string) int32 {
	var __retVal int32
	__itemName := plugify.ConstructString(itemName)
	plugify.Block {
		Try: func() {
			__retVal = int32(C.GetItemImbueEffects((*C.String)(unsafe.Pointer(&__itemName))))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__itemName)
		},
	}.Do()
	return __retVal
}

// GetItemImbueEffects 
//  @brief Get item imbue effect flags
//
func GetItemImbueEffects(itemName string) int32 {
	return _GetItemImbueEffects(itemName)
}

var _CanImbueAbility = func(targetAbility int64, itemName string) bool {
	var __retVal bool
	__targetAbility := C.int64_t(targetAbility)
	__itemName := plugify.ConstructString(itemName)
	plugify.Block {
		Try: func() {
			__retVal = bool(C.CanImbueAbility(__targetAbility, (*C.String)(unsafe.Pointer(&__itemName))))
		},
		Finally: func() {
			// Perform cleanup.
			plugify.DestroyString(&__itemName)
		},
	}.Do()
	return __retVal
}

// CanImbueAbility 
//  @brief Check if ability can receive imbue
//
func CanImbueAbility(targetAbility int64, itemName string) bool {
	return _CanImbueAbility(targetAbility, itemName)
}

var _ImbueAbility = func(item int64, targetAbility int64) bool {
	var __retVal bool
	__item := C.int64_t(item)
	__targetAbility := C.int64_t(targetAbility)
	__retVal = bool(C.ImbueAbility(__item, __targetAbility))
	return __retVal
}

// ImbueAbility 
//  @brief Imbue item onto target ability
//
func ImbueAbility(item int64, targetAbility int64) bool {
	return _ImbueAbility(item, targetAbility)
}

