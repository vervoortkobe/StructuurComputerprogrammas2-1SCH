/* This files includes examples of SmiLang-C with an increasing difficulty to execute by the stack machine. */

#include <stdio.h>

#include "examples.smi.h"

// Example01Return

char * example01ReturnSource = "int example01Return(){return 1;}";

Function * createFunctionExample01Return(){
	FunctionBuffer *buff = createFunctionBuffer();
	pushInt(buff,1);
	returnTop0(buff);
	sourcePointer(buff,example01ReturnSource);
	return assemble(buff);
}

// Example02Add

char * example02AddSource = "int example02Add(){return 1 + 2;}";

Function * createFunctionExample02Add(){
	FunctionBuffer *buff = createFunctionBuffer();
	pushInt(buff,1);
	pushInt(buff,2);
	plus(buff);
	returnTop0(buff);
	sourcePointer(buff,example02AddSource);
	return assemble(buff);
}

// Example03MinusAdd

char * example03MinusAddSource = "int example03MinusAdd(){return 1 - 2 + 3;}";

Function * createFunctionExample03MinusAdd(){
	FunctionBuffer *buff = createFunctionBuffer();
	pushInt(buff,1);
	pushInt(buff,2);
	sub(buff);
	pushInt(buff,3);
	plus(buff);
	returnTop0(buff);
	sourcePointer(buff,example03MinusAddSource);
	return assemble(buff);
}

// Example04Temp

char * example04TempSource = "int example04Temp(){\n\tint temp;\n\treturn temp;\n}";

Function * createFunctionExample04Temp(){
	FunctionBuffer *buff = createFunctionBuffer();
	defineTemps(buff,1);
	pushTemp(buff,0);
	returnTop0(buff);
	sourcePointer(buff,example04TempSource);
	return assemble(buff);
}

// Example05StoreTemp

char * example05StoreTempSource = "int example05StoreTemp(){\n\tint temp;\n\ttemp = 1 + 2;\n\treturn temp;\n}";

Function * createFunctionExample05StoreTemp(){
	FunctionBuffer *buff = createFunctionBuffer();
	defineTemps(buff,1);
	pushInt(buff,1);
	pushInt(buff,2);
	plus(buff);
	storeTemp(buff,0);
	pop(buff);
	pushTemp(buff,0);
	returnTop0(buff);
	sourcePointer(buff,example04TempSource);
	return assemble(buff);
}

// Example06Call

char * oneSource = "int one(){return 1;}";

Function * createFunctionOne(){
	FunctionBuffer *buff = createFunctionBuffer();
	pushInt(buff,1);
	returnTop0(buff);
	sourcePointer(buff,oneSource);
	return assemble(buff);
}

char * example06CallSource = "int example06Call(){return one();}";

Function * createFunctionExample06Call(){
	FunctionBuffer *buff = createFunctionBuffer();
	call(buff,createFunctionOne());
	returnTop0(buff);
	sourcePointer(buff,example06CallSource);
	return assemble(buff);
}

// Example07CallArgs

char * minusSource = "int minus(int arg1, int arg2){return arg1 - arg2;}";

Function * createFunctionMinus(){
	FunctionBuffer *buff = createFunctionBuffer();
	pushArg(buff,-2);
	pushArg(buff,-1);
	sub(buff);
	returnTop(buff,2);
	sourcePointer(buff,minusSource);
	return assemble(buff);
}

char * example07CallArgsSource = "int example07CallArgs(){return minus(3,2);}";

Function * createFunctionExample07CallArgs(){
	FunctionBuffer *buff = createFunctionBuffer();
	pushInt(buff,3);
	pushInt(buff,2);
	call(buff,createFunctionMinus());
	returnTop0(buff);
	sourcePointer(buff,example07CallArgsSource);
	return assemble(buff);
}

// Example08TempAndCallAndCallArgs

char * example08TempAndCallAndCallArgsSource = "int example08TempAndCallAndCallArgs(){\n\tint temp;\n\ttemp = one();\n\treturn minus(temp, 2);\n}";

Function * createFunctionExample08TempAndCallAndCallArgs(){
	FunctionBuffer *buff = createFunctionBuffer();
	defineTemps(buff,1);
	call(buff,createFunctionOne());
	storeTemp(buff,0);
	pop(buff);
	pushTemp(buff,0);
	pushInt(buff,2);
	call(buff,createFunctionMinus());
	returnTop0(buff);
	sourcePointer(buff,example08TempAndCallAndCallArgsSource);
	return assemble(buff);
}

// Example09NestedCall

char * nestedCallSource = "int nestedCall(){\n\tint temp;\n\ttemp = one() + 2;\n\treturn minus(temp,one());\n}";

Function * createFunctionNestedCall(){
	FunctionBuffer *buff = createFunctionBuffer();
	defineTemps(buff,1);
	call(buff,createFunctionOne());
	pushInt(buff,2);
	plus(buff);
	storeTemp(buff,0);
	pop(buff);
	pushTemp(buff,0);
	call(buff,createFunctionOne());
	call(buff,createFunctionMinus());
	returnTop0(buff);
	sourcePointer(buff,nestedCallSource);
	return assemble(buff);
}

char * example09NestedCallSource = "int example09NestedCall(){return nestedCall();}";

Function * createFunctionExample09NestedCall(){
	FunctionBuffer *buff = createFunctionBuffer();
	call(buff,createFunctionNestedCall());
	returnTop0(buff);
	sourcePointer(buff,example09NestedCallSource);
	return assemble(buff);
}

// Example10StoreForValue

char * example10StoreForValueSource = "int example10StoreForValue(){\n\tint temp1, temp2;\n\ttemp1 = (temp2 = 1) + 7;\n\treturn temp2 - temp1;\n}";

Function * createFunctionExample10StoreForValue(){
	FunctionBuffer *buff = createFunctionBuffer();
	defineTemps(buff,2);
	pushInt(buff,1);
	storeTemp(buff,1);
	pushInt(buff,7);
	plus(buff);
	storeTemp(buff,0);
	pop(buff);
	pushTemp(buff,1);
	pushTemp(buff,0);
	sub(buff);
	returnTop0(buff);
	sourcePointer(buff,example10StoreForValueSource);
	return assemble(buff);
}

// Example11MultiTempArgs

char * multiTempArgsSource = "int multiTempArgs(int arg1, int arg2){\n\tint temp1, temp2, temp3;\n\ttemp1 = arg1 + one();\n\ttemp2 = arg2 - arg1;\n\ttemp3 = arg2 - temp1 + temp2;\n\treturn minus(temp3, arg1 + 2);\n}";

Function * createFunctionMultiTempArgs(){
	FunctionBuffer *buff = createFunctionBuffer();
	defineTemps(buff,3);
	
	pushArg(buff,-2);
	call(buff,createFunctionOne());
	plus(buff);
	storeTemp(buff,0);
	pop(buff);
	
	pushArg(buff,-1);
	pushArg(buff,-2);
	sub(buff);
	storeTemp(buff,1);
	pop(buff);
	
	pushArg(buff,-1);
	pushTemp(buff,0);
	sub(buff);
	pushTemp(buff,1);
	plus(buff);
	storeTemp(buff,2);
	pop(buff);
	
	pushTemp(buff,2);
	pushArg(buff,-2);
	pushInt(buff,2);
	plus(buff);
	call(buff,createFunctionMinus());
	returnTop(buff,2);
	sourcePointer(buff,multiTempArgsSource);
	return assemble(buff);
}

char * example11MultiTempArgsSource = "int example11MultiTempArgs(){return multiTempArgs(5,7);}";

Function * createFunctionExample11MultiTempArgs(){
	FunctionBuffer *buff = createFunctionBuffer();
	pushInt(buff,5);
	pushInt(buff,7);
	call(buff,createFunctionMultiTempArgs());
	returnTop0(buff);
	sourcePointer(buff,example11MultiTempArgsSource);
	return assemble(buff);
}


// Start BufferOverflowExtension
// example12ReadInput

char * printBarSource = "int printBar() { puts(\"Bar\"); return 1; }";

Function * createFunctionPrintBar(){
	FunctionBuffer *buff = createFunctionBuffer();
	printBar(buff);
	pushInt(buff,1);
	returnTop0(buff);
	sourcePointer(buff,printBarSource);
	Function *f = assemble(buff);
	printf("location of printBar-function = %p\n", f);
	return f;
}

char * printFooSource = "int printFoo() { puts(\"Foo\"); return 1; }";

Function * createFunctionPrintFoo(){
	FunctionBuffer *buff = createFunctionBuffer();
	printFoo(buff);
	pushInt(buff,1);
	returnTop0(buff);
	sourcePointer(buff,printFooSource);
	return assemble(buff);
}

char * fillArraySource = "int fillArray(int array[]){read_input(array); return 1;}";

Function * createFillArrayFunction(){
	FunctionBuffer *buff = createFunctionBuffer();
	pushArg(buff,-1);
	readInput(buff);
	pushInt(buff,1);
	returnTop(buff,1);
	sourcePointer(buff,fillArraySource);
	return assemble(buff);
}

char * example12ReadInputSource = "int example12ReadInput(){ int array[2]; fillArray(array); printFoo(); return 1;}";

Function * createFunctionExample12ReadInput(){
	FunctionBuffer *buff = createFunctionBuffer();
	Function *fillArrayFunction = createFillArrayFunction();
	Function *printBarFunction = createFunctionPrintBar(); // Not used directly
	Function *printFooFunction = createFunctionPrintFoo();
	defineTemps(buff,2);
	pushAddress(buff,0);
	call(buff,fillArrayFunction);
	pop(buff);
	call(buff,printFooFunction);
	pop(buff);
	pushInt(buff,1);
	returnTop0(buff);
	sourcePointer(buff,example12ReadInputSource);
	return assemble(buff);
}

// End BufferOverflowExtension
