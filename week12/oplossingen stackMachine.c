#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "examples.smi.h"

/***********************************
 * DEBUG flag
 ************************************/

#define DEBUG 1

/****************************
* Flags and buffer size
****************************/

#define StackSize 500
#define StopIP ((unsigned char *) 0xBADF00D)
#define StopFP ((IntType *) 0xDEADBEEF)

/****************************
* Stack machine functions
****************************/

void executeInstruction();
void executePop();
void executePlus();
void executeSub();
void executePushArg(signed char argIndex);
void executePushTemp(unsigned char tempIndex);
void executeStoreTemp(unsigned char tempIndex);
void executeDefineTemps(unsigned char numTemps);
void executeReturnTop(unsigned char numArgs);
void executePushInt(IntType cst);
void executeCall(unsigned char * funcFirstInstruction);
void printStack();

/*************************
* Stack machine pointers
**************************/
	
IntType *fp;
IntType *sp;
IntType baseStack[StackSize];
unsigned char * ip;

/********************************
* Stack machine helper functions
*********************************/
void ensureMachineAsExpected(){
	// Need primitive type size = pointer type size for simple stack machine implementation.
	// If there's a problem here you may need to change the definition of IntType to int in encoder.h
	assert ((sizeof(void *)) == (sizeof(IntType))); 
}

void setUpStack(){
	/* 	Initial Stack set-up:
		StopFP <- sp <- fp
		StopIP <- baseStack */
	fp = sp = baseStack + 1;
	*baseStack = (IntType) StopIP;
	*fp = (IntType) StopFP;
}

// public API: execute a given function
int executeFunction(Function * function){
	ensureMachineAsExpected();
	setUpStack();
	#if DEBUG 
		printf ("\033[0;31m***\033[0m Starting stack machine with:\n");
		printFunction(function);
	#endif
	// Set-up ip to first instruction of main function
	ip = (unsigned char *) function;
	// Main stack machine loop
	while(fp != StopFP) {executeInstruction();};
	#if DEBUG
		printf ("Execution terminated.\n");
	#endif
	// Answers result on top of stack
	return (int) *baseStack;
}

// Dispatch instructions to execute
void executeInstruction(){
	switch (*ip++) {
		//1 byte
		case Pop:
		executePop();
		break;
		case Plus:
		executePlus();
		break;
		case Sub:
		executeSub();
		break;
		
		//2 bytes
		case PushArg:
		executePushArg(*ip++);
		break;
		case PushTemp:
		executePushTemp(*ip++);
		break;
		case StoreTemp:
		executeStoreTemp(*ip++);
		break;
		case DefineTemps:
		executeDefineTemps(*ip++);
		break;
		case ReturnTop:
		executeReturnTop(*ip++);
		break;
		
		//Many bytes
		case PushInt:
		executePushInt(*((IntType *) ip));
		ip += (sizeof(IntType));
		break;
		case Call:
		ip += sizeof(Function *);
		executeCall(*((unsigned char **)(ip - sizeof(unsigned char *))));
		break;
	}
}

/***************************
* Stack machine instructions
****************************/

/**************************
* START IMPLEMENTING HERE
***************************/

void executePop() {
	sp--;
}

void executePlus(){
	IntType a = *sp;
	--sp;
	IntType b = *sp;
	*sp = a + b;
}

void executeSub(){
	IntType a = *sp;
	--sp;
	IntType b = *sp;
	*sp = b - a;
}

void executePushArg(signed char argIndex){
	++sp;
	*sp = *(fp - 1 + argIndex);
}

void executePushTemp(unsigned char tempIndex){
	++sp;
	*sp = *(fp + 1 + tempIndex);
}

void executeStoreTemp(unsigned char tempIndex){
	IntType to_store = *sp;
	*(fp + 1 + tempIndex) = to_store;
}

void executeDefineTemps(unsigned char numTemps){
	for (int i = 0; i < numTemps; i++) {
		sp++;
		*sp = 42;
	}
}

void executeReturnTop(unsigned char numArgs){
	#if DEBUG
		printf("\033[0;31m***\033[0m Stack right before return:\n");
		printStack();
	#endif
	IntType retValue = *sp;
	ip = *((unsigned char **)(fp - 1));
	sp = fp - 2 - numArgs; //before ip
	fp = *((IntType **)fp);
	*(++sp) = retValue;
}

void executePushInt(IntType cst){
	++sp;
	*sp = cst;
}

void executeCall(unsigned char *funcFirstInstruction){
#if DEBUG
	printf("\033[0;31m***\033[0m Calling function:\n");
	printFunction((Function *) funcFirstInstruction);
	printf("\033[0;31m***\033[0m Stack right before the call:\n");
	printStack();
#endif
	++sp;
	*sp = (IntType) ip;
	++sp;
	*sp = (IntType) fp;
	fp = sp;
	ip = funcFirstInstruction;
}

/***********************************
* Main: test executions of examples
************************************/

void testExample(int exampleNumber, int expected, Function * function){
	printf ("\033[0;31m*************************\033[0m\n");
	printf ("\033[0;31m*\tExample %i\t*\033[0m\n", exampleNumber);
	printf ("\033[0;31m*************************\033[0m\n");
	int res = executeFunction(function);
	if(expected == res) {
		printf("\033[0;32m OK  \033[0m\n");
	} else {
		printf("\033[0;31mKO: expected %i got %i.\033[0m\n", expected, res);
	}
	free(function);
}

int main(){
	printf("Tip: Try to toggle DEBUG at the top of this file\n");
	testExample(1,1,createFunctionExample01Return());
	testExample(2,3,createFunctionExample02Add());
	testExample(3,2,createFunctionExample03MinusAdd());
	testExample(4,42,createFunctionExample04Temp());
	testExample(5,3,createFunctionExample05StoreTemp());
	testExample(6,1,createFunctionExample06Call());
	testExample(7,1,createFunctionExample07CallArgs());
	testExample(8,-1,createFunctionExample08TempAndCallAndCallArgs());
	testExample(9,2,createFunctionExample09NestedCall());
	testExample(10,-7,createFunctionExample10StoreForValue());
	testExample(11,-4,createFunctionExample11MultiTempArgs());
	return 0;
}

/***********************************
* Debugging: print runtime stack
************************************/

void printStack(){
	if (sp < baseStack) {printf("Empty stack");return;};
	IntType * iterator = sp;
	IntType * lastIP;
	IntType * currentFP = fp;
	printf("\033[0;31m>\033[0m Stack:\n");
	while (iterator >= baseStack){
		if (iterator == currentFP){
			printf("%p\t\033[0;32mfp\t%p\033[0m",iterator,*((IntType **)iterator));
			lastIP = currentFP - 1;
			currentFP = *((IntType **) currentFP);
		} else if (iterator == lastIP) {
			printf("%p\tip\t%p",iterator,*((IntType **)iterator));
		} else {
			printf("%p\t\t%i",iterator,(int)*iterator);
		}
		if (iterator == sp) {printf("\t \033[0;35m<- sp\033[0m");};
		if (iterator == fp) {printf("\t \033[0;35m<- fp\033[0m");};
		printf("\n");
		iterator--;
	}
}
