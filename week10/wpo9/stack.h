#include <stdio.h>
#include <stdlib.h>
#define SIZE 20
typedef void *Voidptrs[];

typedef struct stack {
    Voidptrs *content;
    size_t elmtsize;
    int size;
    int ffree;
} *Stack;

Stack createstack(size_t, int);

void destroystack(Stack);

int emptystack(Stack);

void push(Stack, void *);

void pop(Stack, void *);

void top(Stack, void *);

void printstackcontent(Stack, void (*display)(void *));

int get_int();

typedef struct rat {
    int t;
    int n;
} Rat;

void printint(void *);

void printrat(void *);
