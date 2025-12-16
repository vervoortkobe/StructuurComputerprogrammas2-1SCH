#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//  tree
//
//  Created by Elisa Gonzalez Boix on 07/11/16.
//  Copyright © 2016 Elisa Gonzalez Boix. All rights reserved.
//
typedef struct tnode {
	int value;
	struct tnode *left, *right;
} Tnode;

enum tside {RIGHT,LEFT};

Tnode *insert_tree(Tnode *, int);
Tnode *readinttree();
void printinttree(Tnode *tree);
Tnode *insert_tree(Tnode *tree, int i);

int get_int()
{
	int i;
	scanf("%d", &i);
	return i;
}

Tnode *insert_tree(Tnode *tree, int i)
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

Tnode *readinttree() {
	int i;
	Tnode *root = NULL;
	while ((i = get_int()) != 0){
		root = insert_tree(root,i);
	}
	return root;
}

void printinttree(Tnode *tree)
{
	if (tree == NULL)
		return;
	printf("(");
	printinttree(tree->left);
	printf(" %d ", tree->value);
	printinttree(tree->right);
	printf(")");
}

/************************************************************************************************************
 *                                                Oefening 1                                                *
 ************************************************************************************************************/

Tnode *max_value_node(Tnode *tree){
	Tnode *current = tree;
	// We gebruiken gesorteerde binaire bomen, dus het rechterkind van een Tnode, als dat kind bestaat,
	// is altijd groter dan de node zelf.
	while (current != NULL && current->right != NULL) {
		current = current->right;
	}
	return current;
}

/************************************************************************************************************
 *                                                Oefening 2                                                *
 ************************************************************************************************************/

typedef struct rat {
	int t;
	int n;
} Rat;

int rat_smaller_than(void *x, void *y) {
	Rat *a = (Rat *) x;
	Rat *b = (Rat *) y;
	return ((a->t * b->n) < (b->t * a->n));
}
int rat_equal_to(void *x, void *y) {
	Rat *a = (Rat *) x;
	Rat *b = (Rat *) y;
	return ((a->t * b->n) == (b->t * a->n));
}

int int_smaller_than(void *x, void *y) {
	int *a = (int *) x;
	int *b = (int *) y;
	return a < b;
}
int int_equal_to(void *x, void *y) {
	int *a = (int *) x;
	int *b = (int *) y;
	return a == b;
}

typedef struct tnode_generic {
	void *value;
	struct tnode_generic *left, *right;
} Tnode_Generic;

Tnode_Generic *insert_generic(Tnode_Generic *tree, void *value,
             int smaller_than(void*, void*),
             int equal_to(void*, void*)) {
	Tnode_Generic *new, *rest, *prev;
	enum tside side;
	new = (Tnode_Generic*) malloc(sizeof(Tnode_Generic));
	new->value = value;
	new->left = NULL; new->right = NULL;
	if (tree == NULL) {
		return new;
	}
	rest = tree;
	while (rest){
		if (equal_to(rest->value, value)){
			free(new);
			return tree;
		}
		if (smaller_than(rest->value, value)) {
			side = RIGHT; prev = rest;
			rest = rest->right;
		} else {
			side = LEFT; prev = rest;
			rest = rest->left;
		}
	}
	if (side) {
		prev->left = new;
	} else {
		prev->right = new;
	}
	return tree;
}

/*
 * Dit is geen deel van de oefening: print_tree_generic is een functie om een generische boom uit te printen,
 * gegeven een parameter "print" dat een generische waarde correct uitprint.
 */
void print_tree_generic(Tnode_Generic *tree, void print(void*)) {
	if (tree == NULL) {
		return;
	}
	printf("(");
	print_tree_generic(tree->left, print);
	printf(" ");
	print(tree->value);
	printf(" ");
	print_tree_generic(tree->right, print);
	printf(")");
}


/************************************************************************************************************
 *                                                Oefening 3                                                *
 ************************************************************************************************************/

//  stackVersion3
//
//  Created by Elisa Gonzalez Boix on 14/11/16.
//  Copyright © 2016 Elisa Gonzalez Boix. All rights reserved.
//
// Version 3: An Extended generic version with table of pointe pointers

typedef void *Voidptrs[];

typedef struct stack{
	Voidptrs *content;
	size_t elmtsize;
	int size;
	int ffree;
} *Stack;

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

int check_balanced_brackets(char *program) {
  Stack s = createstack(sizeof(char), 1000);
  for (char *j = program; *j != '\0'; j++) {
    switch (*j) {
      case '(':
      case '{':
      case '[':
      case '<':
        push(s, j);
        break;
      case ')':
      case '}':
      case ']':
      case '>':
        if (emptystack(s)){
          destroystack(s);
          return 0;
        } else {
          char top_bracket;
          pop(s, &top_bracket);
          if ((top_bracket == '(' && *j == ')') ||
              (top_bracket == '{' && *j == '}') ||
              (top_bracket == '[' && *j == ']') ||
              (top_bracket == '<' && *j == '>')) {
            break;
          } else {
            destroystack(s);
            return 0;
          }
        }
    }
  }
  int balanced = emptystack(s);
  destroystack(s);
  return balanced;
}


/************************************************************************************************************
 *                                                Oefening 4                                                *
 ************************************************************************************************************/
//
// queue
//
//  Created by Elisa Gonzalez Boix on 14/11/16.
//  Copyright © 2016 Elisa Gonzalez Boix. All rights reserved.
//

#define     QUEUE_SIZE  100
#define     ARRAY_SIZE  ( QUEUE_SIZE + 1 )

typedef struct queue {
	void *content;
	size_t elmtsize;
	size_t front;
	size_t rear;
} *Queue;

Queue  create_queue( size_t elmtsize);
void   destroy_queue( Queue q  );

void  insert(Queue q, void* e );
void  delete( Queue q  );
void  first( Queue q, void *e );
int   is_empty( Queue q  );
int   is_full( Queue q  );

void print_int(void *p);

void print_double(void *p) {
	double d;
	memcpy(&d, p, sizeof(double));
	printf("%g ", d);
}

void print_char(void *p) {
	char c;
	memcpy(&c, p, sizeof(char));
	printf("%c ", c);
}

Queue create_queue(size_t elmtsize) {
	Queue q = malloc(sizeof(struct queue));
	if ( q != NULL){
		q->content = calloc(ARRAY_SIZE, elmtsize);
		q->elmtsize = elmtsize;
		q->front = 1;
		q->rear  = 0;
		return q;
	}
	return NULL;
}

void  destroy_queue(Queue q) {
	free(q->content);
	free(q);
}

void insert(Queue q, void *e) {
	if (!is_full(q)) {
		q->rear = ( q->rear + 1 ) % ARRAY_SIZE;
		memcpy((char*) q->content + (q->rear * q->elmtsize), e, q->elmtsize);
	};
}
void delete(Queue q)
{
	if (!is_empty(q))
		q->front = ( q->front + 1 ) % ARRAY_SIZE;
}

void first(Queue q, void *e) {
	if (!is_empty(q)) {
		memcpy(e, (char*) q->content + (q->front * q->elmtsize), q->elmtsize);
	}
}

int is_empty( Queue q )
{
	return ( q->rear + 1 ) % ARRAY_SIZE == q->front;
}

int is_full( Queue q )
{
	return ( q->rear + 2 ) % ARRAY_SIZE == q->front;
}

// Generic print function which
// dispatches to a display function
// how to print the element
void print_queue_content_type(Queue q, void(*display)(void*))
{
	printf("queue content = [ ");
	for (int index = q->front; index <= q->rear; index++) {
		display((q->content) + (index * q->elmtsize));
	}
	printf("]\n");
}

/************************************************************************************************************
 *                                                Oefening 5                                                *
 ************************************************************************************************************/

Tnode *delete_node(Tnode *tree, int i) {
	Tnode *temp = NULL;

	if (tree == NULL) {
		return tree;
	}

	// locate the value i
	if (i < tree->value) {
		tree->left = delete_node(tree->left, i);
	} else if (i > tree->value) {
		tree->right = delete_node(tree->right, i);
	} else {
		// element found , i.e. tree->value == i
		// there are 3 possibilities:
		if (tree->left == NULL && tree->right == NULL) {
			// case 1: it is a leaf node , simply remove it.
			free(tree);
			return temp;
		}
		else if (tree->left == NULL || tree->right == NULL) {
			// case 2: the node has only one child,
			// copy the child to the node, and delete the child
			if (tree->left != NULL) {
				temp = tree->left;
			} else {
				temp = tree->right;
			}
			free(tree);
			return temp;
		} else {
			// case 3: the node has 2 children
			// 1) Find the child node with largest value from its left subtree
			// i.e. get the inorder predecessor
			temp = max_value_node(tree->left);
			// 2) copy the inorder predecessor value to the node
			tree->value = temp->value;
			// 3) delete the inorder predecessor node
			tree->left = delete_node(tree->left, temp->value);
			return tree;
		}
	}
	return tree;
}

/************************************************************************************************************
 *                                                Oefening 6                                                *
 ************************************************************************************************************/

struct node_generic {
  void *info;
  struct node_generic *next;
};

/*
 * De insert-functie neemt als argumenten een pointer naar de waarde die, de grootte van
 * zo'n waarde en de start van de lijst waarin we de waarde gaan zetten.
 *
 * Net zoals gedaan werd in de tweede versie van het stack ADT, gaan we een kopie maken van
 * de waarde die we willen toevoegen, zodat, als er iets gebeurt met de oorspronkelijke waarde
 * (als deze bv. door de gebruiker ergens wordt gedealloceerd) we de kopie kunnen blijven gebruiken
 * in de lijst.
 */
struct node_generic *insert_node(void *element, struct node_generic *p) {
	struct node_generic *new_node = malloc(sizeof(struct node_generic));
	new_node->info = element;
	new_node->next = p;
	return new_node;
}

/*
 * Print (pointer naar) een waarde, door de pointer te casten naar het juiste type,
 * de waarde te dereferencen en de waarde uit te printen.
 */
void print_int(void *x) {
 printf("%i", *((int*) x));
}

void print_rat(void *x) {
	Rat *a = (Rat *) x;
	printf("%i/%i", a->t, a->n);
}

/*
 * Aangezien we niet weten wat elk waarde is, kunnen we ook niet vanzelf weten
 * hoe elk element zou moeten geprint worden. We geven daarom een functie mee
 * die, gegeven een pointer naar de waarde, zelf kiest hoe deze waarde moet
 * geprint worden.
 */
void print_list(struct node_generic *n, void(*display)(void*)) {
	printf("[ ");
	while (n != NULL) {
		display(n->info);
		printf(", ");
		n = n->next;
	}
	printf("]");
}


int main(void) {
	/* Oef 1 */
	printf("Oef 1\n");
	printf("Vul de boom voor oef 1 in\n");
	printf("Voorbeeldinput: 4 7 2 8 6 3 1 9 5 0\n");
	Tnode *root = readinttree();
	// voorbeeld input: 4 7 2 8 6 3 1 9 5 0
	Tnode *max_node = max_value_node(root);
	printf("Highest value in tree: %i\n", (max_node != NULL) ? max_node->value : 0);

	/* Oef 2 */
	printf("\n\nOef 2\n");
	int oef_2a_int = 1, oef_2b_int = 2, oef_2c_int = 3, oef_2d_int = 4, oef_2e_int = 5;
	Rat oef_2a_rat = {50, 100}, oef_2b_rat = {35, 100}, oef_2c_rat = {65, 100}, oef_2d_rat = {70, 100}, oef_2e_rat = {30, 100}, oef_2f_rat = {31, 100};

	Tnode_Generic *tree_int = insert_generic(NULL, &oef_2a_int, int_smaller_than, int_equal_to);
	tree_int = insert_generic(tree_int, &oef_2b_int, int_smaller_than, int_equal_to);
	tree_int = insert_generic(tree_int, &oef_2c_int, int_smaller_than, int_equal_to);
	tree_int = insert_generic(tree_int, &oef_2d_int, int_smaller_than, int_equal_to);
	tree_int = insert_generic(tree_int, &oef_2e_int, int_smaller_than, int_equal_to);

	print_tree_generic(tree_int, print_int);
	printf("\n\n");

	Tnode_Generic *tree_rat = insert_generic(NULL, &oef_2a_rat, rat_smaller_than, rat_equal_to);
	tree_rat = insert_generic(tree_rat, &oef_2b_rat, rat_smaller_than, rat_equal_to);
	tree_rat = insert_generic(tree_rat, &oef_2c_rat, rat_smaller_than, rat_equal_to);
	tree_rat = insert_generic(tree_rat, &oef_2d_rat, rat_smaller_than, rat_equal_to);
	tree_rat = insert_generic(tree_rat, &oef_2e_rat, rat_smaller_than, rat_equal_to);
	tree_rat = insert_generic(tree_rat, &oef_2f_rat, rat_smaller_than, rat_equal_to);

	print_tree_generic(tree_rat, print_rat);

	/* Oef 3 */
	printf("\n\nOef 3\n");
	char *string_1 = "Deze (string { is } <[correct] gebalanceerd>)";
	int balanced_1 = check_balanced_brackets(string_1);
	printf("\"%s\" is balanced? %i\n", string_1, balanced_1);

	char *string_2 = "{ Deze <string (is >) niet } correct";
	int balanced_2 = check_balanced_brackets(string_2);
	printf("\"%s\" is balanced? %i\n", string_2, balanced_2);

	/* Oef 4 */
	printf("\n\nOef 4\n");
	Queue q_int = create_queue(sizeof(int));
	if( is_empty(q_int) ) {
		printf("queue is empty\n");
	}
	int a_int = 1, b_int = 2, c_int = 3;
	insert(q_int, &a_int);
	insert(q_int, &b_int);
	insert(q_int, &c_int);

	int res_int;
	print_queue_content_type(q_int, print_int);
	delete(q_int);
	first(q_int, &res_int);
	printf("first = %i\n", res_int);
	print_queue_content_type(q_int, print_int);
	delete(q_int);
	first(q_int, &res_int);
	printf("first = %i\n", res_int);
	print_queue_content_type(q_int, print_int);
	delete(q_int);
	print_queue_content_type(q_int, print_int);
	if( is_empty(q_int) ) {
		printf("queue is empty\n");
	}

	Queue q_char = create_queue(sizeof(char));
	char a_char = 'a', b_char = 'b';
	insert(q_char, &a_char);
	insert(q_char, &b_char);

	char res_char;
	print_queue_content_type(q_char, print_char);
	first(q_char, &res_char);
	printf("res2 = %c\n", res_char);
	delete(q_char);
	first(q_char, &res_char);
	printf("res2 = %c\n", res_char);
	print_queue_content_type(q_char, print_char);
	delete(q_char);
	if( is_empty(q_char) ) {
		printf("queue is empty\n");
	}

	/* Oef 5 */
	printf("\n\nOef 5\n");
	printf("Vul de boom voor oef 5 in\n");
	printf("Voorbeeldinput: 4 7 2 8 6 3 1 9 5 0\n");
	// voorbeeld input: 4 7 2 8 6 3 1 9 5 0
	Tnode *root_oef5 = readinttree();

	printf("Deleting value 7 from tree\n");
	root_oef5 = delete_node(root_oef5, 7);
	printinttree(root_oef5);

	/* Oef 6 */
	printf("\n\nOef 6\n");
	int oef_6a = 3;
	int oef_6b = 2;
	int oef_6c = 1;
	int oef_6d = 4;
	struct node_generic *oef_6a_node = insert_node(&oef_6a, NULL);
	struct node_generic *oef_6b_node = insert_node(&oef_6b, oef_6a_node);
	struct node_generic *oef_6c_node = insert_node(&oef_6c, oef_6b_node);
	struct node_generic *oef_6d_node = insert_node(&oef_6d, oef_6c_node);

	print_list(oef_6d_node, print_int);

	return EXIT_SUCCESS;
}

