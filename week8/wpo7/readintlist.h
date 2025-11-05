// https://dodona.be/en/courses/5451/series/63965/activities/1973015423
#include <stdlib.h>

#include "linked_list.h"

Node *insert_node(Node *start, int value) {
  Node *prev = NULL;
  Node *curr = start;

  Node *new_node = malloc(sizeof(Node));
  if (new_node != NULL) {
    new_node->info = value;

    while (curr != NULL && value >= curr->info) {
      prev = curr;
      curr = curr->next;
    }

    new_node->next = curr;

    if (prev != NULL) {
      prev->next = new_node;
    } else {
      start = new_node;
    }
    return start;
  } else {
    return NULL;
  }
}

Node *readintlist() {
  Node *p = NULL;
  int i;

  while ((i = get_int()) != 0) {
    p = insert_node(p, i);
  }
  return p;
}