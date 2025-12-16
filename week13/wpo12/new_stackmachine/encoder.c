#include <stdio.h>
#include <stdlib.h>
#include "encoder.h"



/********************************************************************
 * THIS CODE IS USED FOR THE INTERNAL WORKING OF THE STACK MACHINE
 ********************************************************************/

/***********************
 * Function assembling
 ***********************/

FunctionBuffer * createFunctionBuffer(){
	FunctionBuffer * fbuffer = (FunctionBuffer *) malloc(sizeof(FunctionBuffer));
	fbuffer->pos = 0;
	fbuffer->buffer = (unsigned char *) malloc(FunctionBufferSize);
	return fbuffer;
}

Function * assemble(FunctionBuffer *fbuffer){
	Function * func = (Function *) realloc(fbuffer->buffer, fbuffer->pos);
	free(fbuffer);
	return func;
}

// Single byte
void add1ByteInstr(FunctionBuffer *fbuffer, unsigned char byte){
	fbuffer->buffer[fbuffer->pos++] = byte;
}

void pop(FunctionBuffer *fbuffer){
	add1ByteInstr(fbuffer,Pop);
}

void plus(FunctionBuffer *fbuffer){
	add1ByteInstr(fbuffer,Plus);
}

void sub(FunctionBuffer *fbuffer){
	add1ByteInstr(fbuffer,Sub);
}

// Double byte
void add2ByteInstr(FunctionBuffer *fbuffer, unsigned char byte, unsigned char extraByte){
	fbuffer->buffer[fbuffer->pos++] = byte;
	fbuffer->buffer[fbuffer->pos++] = extraByte;
}

void pushArg(FunctionBuffer *fbuffer, unsigned char argIndex){
	add2ByteInstr(fbuffer,PushArg,(unsigned char) argIndex);
}

void pushTemp(FunctionBuffer *fbuffer, unsigned char tempIndex){
	add2ByteInstr(fbuffer,PushTemp,tempIndex);
}

void storeTemp(FunctionBuffer *fbuffer, unsigned char tempIndex){
	add2ByteInstr(fbuffer,StoreTemp,tempIndex);
}

void defineTemps(FunctionBuffer *fbuffer, unsigned char numTemps){
	add2ByteInstr(fbuffer,DefineTemps,numTemps);
}

void returnTop(FunctionBuffer *fbuffer, unsigned char numArgs){
	add2ByteInstr(fbuffer,ReturnTop, numArgs);
}

void returnTop0(FunctionBuffer *fbuffer){
	returnTop(fbuffer,0);
}

// Many bytes
void pushInt(FunctionBuffer *fbuffer, IntType theConstant){
	fbuffer->buffer[fbuffer->pos++] = PushInt;
	IntType * intLocation = (IntType *)(&(fbuffer->buffer[fbuffer->pos]));
	*intLocation = theConstant;
	fbuffer->pos += sizeof(IntType);
}

void call(FunctionBuffer *fbuffer, Function * function){
	fbuffer->buffer[fbuffer->pos++] = Call;
	Function ** funcLocation = (Function **)(&(fbuffer->buffer[fbuffer->pos]));
	*funcLocation = function;
	fbuffer->pos += sizeof(void *);
}

// Debugging support
void sourcePointer(FunctionBuffer *fbuffer, char * sourcePointer){
	char ** stringLocation = (char **)(&(fbuffer->buffer[fbuffer->pos]));
	*stringLocation = sourcePointer;
	fbuffer->pos += sizeof(void *);
}

// Start BufferOverflowExtension

void printBar(FunctionBuffer *fbuffer){
	add1ByteInstr(fbuffer, PrintBar);
}

void printFoo(FunctionBuffer *fbuffer){
	add1ByteInstr(fbuffer, PrintFoo);
}

void pushAddress(FunctionBuffer *fbuffer, unsigned char location) {
	add2ByteInstr(fbuffer, PushAddress, location);
}

void arrayRef(FunctionBuffer *fbuffer){
	add1ByteInstr(fbuffer, PushArrayRef);
}

void arrayStore(FunctionBuffer *fbuffer){
	add1ByteInstr(fbuffer, StoreArrayRef);
}

void readInput(FunctionBuffer *fbuffer){
	add1ByteInstr(fbuffer, ReadInput);
}

// End BufferOverflowExtension

/******************************************
 * Function disassembling (debugging only)
 ******************************************/

void printFunction(Function *function){
	unsigned char *ip = (unsigned char *) function;
	int keepGoing = 1;
	// disassemble and print instructions.
	printf("\033[0;31m>\033[0m Instructions:\n");
	while(keepGoing){
		printf("%p\t",ip);
		switch (*ip++) {
				// 1 byte
			case Pop:
				printf("\tPop\n");
				break;
			case Plus:
				printf("\tPlus\n");
				break;
			case Sub:
				printf("\tSub\n");
				break;
				
				// 2 bytes
			case PushArg:
				printf("\tPushArg %i\n", *((signed char *) ip++));
				break;
			case PushTemp:
				printf("\tPushTemp %i\n", *ip++);
				break;
			case StoreTemp:
				printf("\tStoreTemp %i\n", *ip++);
				break;
			case DefineTemps:
				printf("\tDefineTemps %i\n", *ip++);
				break;
			case ReturnTop:
				printf("\tReturnTop %i\n", *ip++);
				keepGoing = 0;
				break;
				
				// Many bytes
			case PushInt:
				printf("\tPushInt %i\n", (int) *((IntType *) ip));
				ip += (sizeof(IntType));
				break;
			case Call:
				printf("\tCall %p\n", *((Function *)ip));
				ip += sizeof(void *);
				break;
					
			// Start BufferOverflowExtension
			case PrintBar:
				printf("\tPrintBar\n");
				break;
			case PrintFoo:
				printf("\tPrintFoo\n");
				break;
			case PushAddress:
				printf("\tPushAddress %i\n", *ip++);
				break;
			case PushArrayRef:
				printf("\tPushArrayRef\n");
				break;
			case StoreArrayRef:
				printf("\tStoreArrayRef\n");
				break;
			case ReadInput:
				printf("\tReadInput\n");
				break;
			// End BufferOverflowExtension
		}
	}
	//print source
	printf("\033[0;31m>\033[0m Source:\n");
	printf("%s\n",*((char **)ip));
}
