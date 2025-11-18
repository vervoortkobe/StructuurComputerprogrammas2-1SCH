// https://dodona.be/en/courses/5451/series/63966/activities/107262211
#include <stdlib.h>

typedef struct tnode {
  int value;
  struct tnode *left, *right;
} Tnode;

typedef struct tnode_generic {
  void *value;
  struct tnode_generic *left, *right;
} Tnode_Generic;

enum tside {RIGHT,LEFT};

/*
 * Een pointer naar de boom waarin de waarde moet toegevoegd worden
 * De waarde die moet toegevoegd worden (deze waarde heeft het type void*)
 * Een function-pointer smaller_than van het type int (*smaller_than)(void*, void*) die twee waarden met elkaar vergelijkt en 1 teruggeeft indien de eerste kleiner is dan de tweede, en 0 indien niet
 * Een function-pointer equal_to van hetzelfde type als het vorige argument, die 1 teruggeeft indien beide waarden gelijk zijn en 0 indien niet.
 */
Tnode_Generic* insert_generic(Tnode_Generic* root, void *value, int (*smaller_than)(void*,void*), int (*equal_to)(void*,void*))
{
	Tnode_Generic *new, *rest, *prev;
	int side;
	
	new = (Tnode_Generic *) malloc(sizeof(Tnode_Generic));
	if (!new) return root;
	new->value = value;
	new->left = NULL; new->right = NULL;
	
	if (root == NULL)
		return new;
	
	rest = root;
	while (rest) {
		if (equal_to(rest->value, value)) {
			free(new);
			return root;
		}
		if (smaller_than(rest->value, value)) {
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
	
	return root;
}