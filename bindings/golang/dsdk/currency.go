package dsdk

/*
#include "currency.h"
#cgo noescape ModifyCurrency
#cgo noescape GetCurrency
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

// Generated from dsdk (group: currency)

var _ModifyCurrency = func(pawn int64, currencyType ECurrencyType, amount int32, source ECurrencySource, silent bool, forceGain bool, spendOnly bool, sourceAbility int64, sourceEntity int64) {
	__pawn := C.int64_t(pawn)
	__currencyType := C.uint32_t(currencyType)
	__amount := C.int32_t(amount)
	__source := C.uint32_t(source)
	__silent := C.bool(silent)
	__forceGain := C.bool(forceGain)
	__spendOnly := C.bool(spendOnly)
	__sourceAbility := C.int64_t(sourceAbility)
	__sourceEntity := C.int64_t(sourceEntity)
	C.ModifyCurrency(__pawn, __currencyType, __amount, __source, __silent, __forceGain, __spendOnly, __sourceAbility, __sourceEntity)
}

// ModifyCurrency 
//  @brief Modify currency (souls/gold) for player pawn
//
func ModifyCurrency(pawn int64, currencyType ECurrencyType, amount int32, source ECurrencySource, silent bool, forceGain bool, spendOnly bool, sourceAbility int64, sourceEntity int64) {
	_ModifyCurrency(pawn, currencyType, amount, source, silent, forceGain, spendOnly, sourceAbility, sourceEntity)
}

var _GetCurrency = func(pawn int64, currencyType ECurrencyType) int32 {
	var __retVal int32
	__pawn := C.int64_t(pawn)
	__currencyType := C.uint32_t(currencyType)
	__retVal = int32(C.GetCurrency(__pawn, __currencyType))
	return __retVal
}

// GetCurrency 
//  @brief Get current currency value of pawn
//
func GetCurrency(pawn int64, currencyType ECurrencyType) int32 {
	return _GetCurrency(pawn, currencyType)
}

