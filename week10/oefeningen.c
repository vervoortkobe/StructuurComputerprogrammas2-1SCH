#include <stdio.h>
#include <stdlib.h>

/************************************************************************************************************
 *                                                Oefening 1                                                *
 ************************************************************************************************************/

typedef struct tnode {
  int value;
  struct tnode *left, *right;
} Tnode;

typedef struct tnode_generic {
  void *value;
  struct tnode_generic *left, *right;
} Tnode_Generic;

enum tside {RIGHT,LEFT};

Tnode *insert(Tnode *tree, int i)
{
  Tnode *new, *rest, *prev;
  int side;
  
  new = (Tnode *) malloc(sizeof(Tnode));
  new->value = i;
  new->left = NULL; new->right = NULL;
  
  if (tree == NULL)
    return new;
  
  rest = tree;
  while (rest){
    if (rest->value == i){
      free(new);
      return tree;
    }
    if (rest->value < i) {
      side = RIGHT; prev = rest;
      rest = rest->right;
    } else {
      side = LEFT; prev = rest;
      rest = rest->left;
    }
  }
  if (side)
    prev->left = new;
  else prev->right = new;
  
  return tree;
}

/************************************************************************************************************
 *                                                Oefening 3                                                *
 ************************************************************************************************************/

#define STACK_SIZE 25

//
//  stackVersion3
//
//  Created by Elisa Gonzalez Boix on 14/11/16.
//  Copyright © 2016 Elisa Gonzalez Boix. All rights reserved.
//
// Version 3: An Extended generic version with table of pointe pointers

/*
 This is an extended version to the generic Stack (version 2)
 that can store values of any type.
 
 To the question how to obtain memory to store that values,
 this version uses also a stack implemented with a dynamically
 allocated array.
 This version also allocates an array of pointers whose
 size is defined at runtime at creation time.
 This version increases the complexity of its implementation
 since we need to keep track of the size, and calculate the address
 where to push/pop elements by means of the element size.
 
 */
#include <string.h>

typedef void *Voidptrs[];

typedef struct stack{
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
int get_int(void);

Stack createstack(size_t elmtsize, int size)
{
  Voidptrs *P;
  Stack T;
  
  // it first allocates an array of size elements each of which ‘elmtsize’ size_t
  // and initializes memory to zero
  P = (Voidptrs *)calloc(size, elmtsize);
  if (P != NULL) {
    T = (Stack) malloc(sizeof(struct stack));
    if ( T != NULL){
      T->content = P;
      T->ffree = 0;
      T->size = size;
      T->elmtsize = elmtsize;
      return T;
    }
  }
  exit(1);
}

void printstackcontent(Stack S, void(*display)(void*))
{
  void *p,*q;
  p= S->content; //address of the table
  printf("[");
  for (int i = 0; i < S->ffree; i++){
    q = (char*)p + (i * S->elmtsize); //pointer to ith elem
    display(q);
  }
  printf("]\n");
}

void destroystack(Stack S)
{
  free(S->content);
  free(S);
}

int emptystack(Stack S)
{
  return (S->ffree == 0);
}

void push(Stack S, void *e)
{
  void *p;
  if ( S->ffree < S->size) {
    // we need to calculate the address of the top element
    p = (char *)(S->content) + (S->ffree * S->elmtsize);
    memcpy(p,e,S->elmtsize);
    S->ffree += 1;
  }
}

void pop(Stack S, void *e)
{
  void *p;
  if (S->ffree > 0) {
    S->ffree -= 1;
    p = (char *)(S->content) + (S->ffree * S->elmtsize);
    memcpy(e,p,S->elmtsize);
  }
}

void top(Stack S, void *e)
{
  void *p;
  if (S->ffree > 0){
    p = (char*)(S->content) + ((S->ffree -1)* S->elmtsize);
    memcpy(e,p, S->elmtsize);
  }
}


/************************************************************************************************************
 *                                                Oefening 6                                                *
 ************************************************************************************************************/

struct node_generic {
  void *info;
  struct node_generic *next;
};

typedef struct rat {
  int t;
  int n;
} Rat;

int main() {
  
}
