#ifndef WPO12_TRAMPOLINE_H
#define WPO12_TRAMPOLINE_H
#include <stddef.h>
#include <stdlib.h>

typedef struct thunk_struct {
    struct thunk_struct *(*fun)(int, int);
    int arg1;
    int arg2;
} thunk;

thunk* make_thunk(thunk* (*f)(int, int), int, int);
void trampoline(thunk*);
thunk* printAndStop(int n, int acc);

thunk* make_thunk(thunk* (*f)(int, int), int a, int b)
{
    thunk* t = (thunk*) malloc(sizeof(thunk));
    if (t != NULL) {
        t->fun = f;
        t->arg1 = a;
        t->arg2 = b;
    }
    return t;
}

void trampoline(thunk* t)
{
    while (t != NULL) {
        thunk *temp = t->fun(t->arg1, t->arg2);
        free(t);
        t = temp;
    }
}

thunk* printAndStop(int n, int acc)
{
    printf("answer is %d\n", acc);
    return NULL;
}

#endif //WPO12_TRAMPOLINE_H