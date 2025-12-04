// https://dodona.be/en/courses/5451/series/63968/activities/1795331817
#include <stdlib.h>
#include "encoder.h"

#define StackSize 500
extern IntType *fp;
extern IntType *sp;
extern IntType baseStack[StackSize];
extern unsigned char * ip;

void executeStoreTemp(unsigned char tempIndex) {
  IntType to_store = *sp;
  *(fp + 1 + tempIndex) = to_store;
}

void executePop() {
  --sp;
}
