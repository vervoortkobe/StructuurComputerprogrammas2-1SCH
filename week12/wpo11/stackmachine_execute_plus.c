// https://dodona.be/en/courses/5451/series/63968/activities/776718338
#include <stdlib.h>
#include "encoder.h"

#define StackSize 500
extern IntType *fp;
extern IntType *sp;
extern IntType baseStack[StackSize];
extern unsigned char * ip;

void executePlus(void) {
  IntType a = *sp;
  --sp;
  IntType b = *sp;
  *sp = a + b;
}
