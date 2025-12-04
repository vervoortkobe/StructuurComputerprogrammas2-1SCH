// https://dodona.be/en/courses/5451/series/63968/activities/967145928
#include <stdlib.h>
#include "encoder.h"

#define StackSize 500
extern IntType *fp;
extern IntType *sp;
extern IntType baseStack[StackSize];
extern unsigned char * ip;

void executeDefineTemps(unsigned char numTemps) {
      for (int i = 0; i < numTemps; i++) {
        sp++;
        *sp = 42;
    }
}

void executePushTemp(unsigned char tempIndex) {
    ++sp;
    *sp = *(fp + 1 + tempIndex);
}
