#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Stack createstack(size_t elmtsize, int size) {
    Voidptrs *P;
    Stack T;
    P = (Voidptrs *) calloc(size, elmtsize);
    if (P != NULL) {
        T = (Stack) malloc(sizeof(struct stack));
        if (T != NULL) {
            T->content = P;
            T->ffree = 0;
            T->size = size;
            T->elmtsize = elmtsize;
            return T;
        }
    }
    exit(1);
}

void push(Stack S, void *e) {
    void *p;
    if (S->ffree < S->size) {
        p = (void *) (S->content) + (S->ffree * S->elmtsize);
        memcpy(p, e, S->elmtsize);
        S->ffree += 1;
    }
}

void pop(Stack S, void *e) {
    void *p;
    if (S->ffree > 0) {
        S->ffree -= 1;
        p = (void *) (S->content) + (S->ffree * S->elmtsize);
        memcpy(e, p, S->elmtsize);
    }
}

void top(Stack S, void *e) {
    void *p;
    if (S->ffree > 0) {
        p = (void *) (S->content) + ((S->ffree - 1) * S->elmtsize);
        memcpy(e, p, S->elmtsize);
    }
}

void destroystack(Stack S) {
    free(S->content);
    free(S);
}

void printstackcontent(Stack S, void (*display)(void *)) {
    void *p, *q;
    p = S->content; //address of the table
    printf("[");
    for (int i = 0; i < S->ffree; i++) {
        q = (void *) p + (i * S->elmtsize); //pointer to ith elem
        display(q);
    }
    printf("]\n");
}
