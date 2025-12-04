// https://dodona.be/en/courses/5451/series/63968/activities/89088944
#include <stdlib.h>
#include "encoder.h"

#define StackSize 500
extern IntType *fp;
extern IntType *sp;
extern IntType baseStack[StackSize];
extern unsigned char * ip;

void executeReturnTop(unsigned char numArgs) {
  #if DEBUG
    printf("\033[0;31m***\033[0m executeReturnTop(%d)\n", numArgs);
    printStack();
  #endif
  IntType retValue = *sp;
  ip = *((unsigned char **)(fp - 1));
  sp = fp - 2 - numArgs; // before ip
  fp = *((IntType **)fp);
  *(++sp) = retValue;
}

void executePushArg(signed char argIndex) {
  ++sp;
  *sp = *(fp - 1 + argIndex);
}
