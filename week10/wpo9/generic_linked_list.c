// https://dodona.be/en/courses/5451/series/63966/activities/1541280757
#include <stdlib.h>
#include <stdio.h>

struct node_generic {
  void *info;
  struct node_generic *next;
};

typedef struct rat {
  int t;
  int n;
} Rat;

struct node_generic *insert_node(void *value, struct node_generic *node) {
  struct node_generic *new_node = malloc(sizeof(*new_node));
  if (!new_node) return NULL;
  new_node->info = value;
  new_node->next = node;
  return new_node;
}

void print_list(struct node_generic *node, void (*display)(void*)) {
  printf("[ ");
  struct node_generic *current = node;
  int first = 1;
  while (current) {
    if (!first) printf(", ");
    display(current->info);
    first = 0;
    current = current->next;
  }
  printf(", ]");
}

void print_int(void *i) {
  if (!i) return;
  printf("%d", *(int*)i);
}

void print_rat(void *rat) {
  if (!rat) return;
  Rat *r = (Rat*)rat;
  printf("%d/%d", r->t, r->n);
}