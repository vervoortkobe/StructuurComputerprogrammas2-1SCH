#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/************************************************************************************************************
 *                                                Oefening 1                                                *
 ************************************************************************************************************/

struct Piece {
  char color;
  char type;
  int x;
  int y;
};

struct Piece *read_piece() {
  struct Piece *piece = malloc(sizeof(struct Piece));
  // ... Vul velden in
  return piece;
}

struct Piece **read_chess_pieces(int n) {
  struct Piece **array = calloc(n, sizeof(struct Piece*));
  for (int i = 0; i < n; i++) {
    struct Piece *piece = read_piece();
    array[i] = piece;
  }
  return array;
}

/************************************************************************************************************
 *                                                Oefening 5                                                *
 ************************************************************************************************************/

//
//  LinkedList
//
//  Created by Elisa Gonzalez Boix on 07/11/16.
//  Copyright © 2016 Elisa Gonzalez Boix. All rights reserved.
//

typedef struct node{
  int info;
  struct node *next;
} Node;

Node *readintlist();
void printintlist(Node *);
Node *searchintlist(int, Node *);
Node *deleteintlist(int, Node *);
void deleteAll(Node *p);

int get_int()
{
  int i;
  scanf("%d", &i);
  return i;
}

/*
 * Gegegeven (een pointer naar) de start van een lijst en een integer, voegt deze functie de gegeven integer op
 * de juiste plaats in de lijst toe en geeft de functie de nieuwe start van de lijst terug.
 */
Node *insert_node(Node *start, int value);

Node *readintlist() {
  Node *p = NULL;
  int i;

  while ((i = get_int()) != 0) {
    p = insert_node(p, i);
  }
  return p;
}

void printintlist(Node *p)
{
  Node *q = p;
  while (q != NULL){
    printf("%p: %d\n", q, q->info);
    q = q->next;
  }
}

/************************************************************************************************************
 *                                                Oefening 6                                                *
 ************************************************************************************************************/

typedef struct double_node {
  int value;
  struct double_node *prev;
  struct double_node *next;
} Double_Node;




int main(void) {
  Node *head = readintlist();
  //input: 23 65 73 45 36 28 12 0
  printintlist(head);
  return 0;
}
