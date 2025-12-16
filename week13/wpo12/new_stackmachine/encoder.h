#ifndef ENCODER_H
#define ENCODER_H

/************************
* Instruction Encoding
************************/

/*
> Single byte
Pop: 			00: Pop top of stack.
Primitive +: 	01: Pop the top two values on the stack, add them, and pushes the result.
Primitive -: 	02: Pop the top two values on the stack, substract them, and pushes the result.
 
// Start BufferOverflowExtension
PrintBar:		03: Prints "Bar" to stdoutput.
PrintFoo:		04: Prints "Foo" to stdoutput.
// End BufferOverflowExtension

> Double byte
PushArg: 	10 xx: Push the value of arg xx on the stack. xx is backward (0 is last argument)
PushTemp: 	11 xx: Push the value of temp xx on the stack.
StoreTemp: 	12 xx: Store the value on top of the stack into temp xx.
DefineTemp: 13 xx: Define the number of temps (xx) used in the method.
ReturnTop: 	14 xx: Return to caller's frame and pushes current top of stack to caller's stack, active function has xx args
 
// Start BufferOverflowExtension
PushArrayRef:	15 xx: Pop the top value on the stack, use that as the index in the array whose location is encoded as xx, dereference the array element and push it to the top of the stack
StoreArrayRef:	22 xx: Store the value at the top of the stack in the array whose location is encoded as xx, with index [top of the stack minus 1].
// End BufferOverflowExtension

> Many bytes
PushInt: 	20 xx xx xx xx (xx xx xx xx): Push the IntType constant encoded in the next 4/8 bytes on the stack.
Call: 		21 xx xx xx xx (xx xx xx xx): Call the function which pointer is encoded in the next 4/8 bytes
// Start BufferOverflowExtension
ReadInput: 	22 xx yy: Read input fromt stdinput until NUL-character (character with ascii value 0) is read. Input is stored in the array starting at xx and whose length is yy.
// End BufferOverflowExtension
*/

// Single byte
#define Pop (unsigned char) 0
#define Plus (unsigned char) 1
#define Sub (unsigned char) 2

// Start BufferOverflowExtension
#define PrintBar ((unsigned char) 3)
#define PrintFoo ((unsigned char) 4)
// End BufferOverflowExtension

// Double byte
#define PushArg (unsigned char) 10
#define PushTemp (unsigned char) 11
#define StoreTemp (unsigned char) 12
#define DefineTemps (unsigned char) 13
#define ReturnTop (unsigned char) 14
// Start BufferOverflowExtension
#define PushArrayRef ((unsigned char) 15)
#define StoreArrayRef ((unsigned char) 16)
#define PushAddress ((unsigned char) 17)
// End BufferOverflowExtension

// Many bytes
#define PushInt (unsigned char) 20
#define Call (unsigned char) 21
// Start BufferOverflowExtension
#define ReadInput ((unsigned char) 22)
// End BufferOverflowExtension

/*********************
* Type definition
*********************/

// These macros define the IntType for 16-, 32- and 64-bit operating systems (OS).
// Checking which OS is being used is compiler-dependent.

// Windows...
#if _WIN32 || _WIN64
   #if _WIN64
     #define IntType long long
  #else
    #define IntType int
  #endif
#endif
// GCC/LLVM...
#if __GNUC__
  #if __x86_64__ || __ppc64__ || __aarch64__
    #define IntType long long
  #else
    #define IntType int
  #endif
#endif
// Rest of the world...
#ifndef IntType
	#error "Must define IntType, unsupported compiler non sense. Set IntType to long long or int depending on word size (64 -> long long, 32 & 16 -> int)"
#endif

// A function is a list of bytecode instructions.
typedef unsigned char * Function;

// FunctionBuffer is used to create a function.
#define FunctionBufferSize 200
typedef struct {
	int pos;
	unsigned char *buffer;
} FunctionBuffer;

/*********************
 * Function assembling
 *********************/

FunctionBuffer * createFunctionBuffer();
Function * assemble(FunctionBuffer *fbuffer);
void pop(FunctionBuffer *fbuffer);
void plus(FunctionBuffer *fbuffer);
void sub(FunctionBuffer *fbuffer);
void pushArg(FunctionBuffer *fbuffer, unsigned char argIndex);
void pushTemp(FunctionBuffer *fbuffer, unsigned char tempIndex);
void storeTemp(FunctionBuffer *fbuffer, unsigned char tempIndex);
void defineTemps(FunctionBuffer *fbuffer, unsigned char numTemps);
void returnTop(FunctionBuffer *fbuffer, unsigned char numArgs);
void returnTop0(FunctionBuffer *fbuffer);
void pushInt(FunctionBuffer *fbuffer, IntType theConstant);
void call(FunctionBuffer *fbuffer, Function * function);
void sourcePointer(FunctionBuffer *fbuffer, char * sourcePointer);
void printFunction(Function *function);


// Start BufferOverflowExtension
void printBar(FunctionBuffer *fbuffer);
void printFoo(FunctionBuffer *fbuffer);
void pushAddress(FunctionBuffer *fbuffer, unsigned char location);
void arrayRef(FunctionBuffer *fbuffer);
void arrayStore(FunctionBuffer *fnuffer);
void readInput(FunctionBuffer *fnuffer);
// End BufferOverflowExtension

#endif
