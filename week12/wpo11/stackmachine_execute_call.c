// https://dodona.be/en/courses/5451/series/63968/activities/403923523
#include <stdlib.h>
#include "encoder.h"

#define DEBUG 1
#define StackSize 500
extern IntType *fp;
extern IntType *sp;
extern IntType baseStack[StackSize];
extern unsigned char * ip;

void executeCall(unsigned char *fun) {
  ++sp;
  *sp = ip;
  ++sp;
  *sp = fp;
  fp = sp;
  ip = fun;
}
