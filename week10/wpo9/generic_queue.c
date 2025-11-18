// https://dodona.be/en/courses/5451/series/63966/activities/1451383649
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define     QUEUE_SIZE  100
#define     ARRAY_SIZE  ( QUEUE_SIZE + 1 )
typedef struct queue {
  void *content;
  size_t elmtsize;
  size_t front;
  size_t rear;
} *Queue;
int is_empty( Queue q );
int is_full( Queue q );

Queue create_queue(size_t elmtsize) {
  Queue q = malloc(sizeof(struct queue));
  if (q != NULL) {
    q->content = calloc(ARRAY_SIZE, elmtsize);
    if ( q->content != NULL ) {
      q->elmtsize = elmtsize;
      q->front = 1;
      q->rear = 0;
      return q;
    }
    free(q);
  }
  return NULL;
}

void insert(Queue q, void* e ) {
  if (!is_full(q)) {
    q->rear = (q->rear + 1) % ARRAY_SIZE;
    memcpy((char*)q->content + (q->rear * q->elmtsize), e, q->elmtsize);
  };
}

void first(Queue q, void *e) {
  if (!is_empty(q)) {
    memcpy(e, (char*)q->content + (q->front * q->elmtsize), q->elmtsize);
  }
}