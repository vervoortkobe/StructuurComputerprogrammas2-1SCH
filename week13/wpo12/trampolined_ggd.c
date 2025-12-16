// https://dodona.be/en/courses/5451/series/63969/activities/1662937612
#include <stdlib.h>

#include "trampoline.h"

// Onderstaande drie functies zijn al geïmplementeerd
thunk* make_thunk(thunk* (*f)(int, int), int, int);
void trampoline(thunk*);
thunk* printAndStop(int arg, int acc);

int ggd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        int c = a % b;
        return ggd(b, c);
    }
}

thunk *ggd_tramp(int a, int b) {
    if (b == 0) {
        return make_thunk(printAndStop, 0, a);
    } else {
        int c = a % b;
        return make_thunk(ggd_tramp, b, c);
    }
}