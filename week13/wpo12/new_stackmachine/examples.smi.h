#ifndef examples_smi_h
#define examples_smi_h

#include "encoder.h"

Function * createFunctionExample01Return();
Function * createFunctionExample02Add();
Function * createFunctionExample03MinusAdd();
Function * createFunctionExample04Temp();
Function * createFunctionExample05StoreTemp();
Function * createFunctionExample06Call();
Function * createFunctionExample07CallArgs();
Function * createFunctionExample08TempAndCallAndCallArgs();
Function * createFunctionExample09NestedCall();
Function * createFunctionExample10StoreForValue();
Function * createFunctionExample11MultiTempArgs();

// Start BufferOverflowExtension
Function * createFunctionExample12ReadInput();
// End BufferOverflowExtension

#endif /* examples_smi_h */
