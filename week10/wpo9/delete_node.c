// https://dodona.be/en/courses/5451/series/63966/activities/1487332666
#include <stdlib.h>

typedef struct tnode {
  int value;
  struct tnode *left, *right;
} Tnode;

Tnode *max_value_node(Tnode *tree) {
	Tnode *current = tree;
	while ( current && current->right)
		current = current->right;
	return current;
}

Tnode *delete_node(Tnode *tree, int value) {
	if (tree == NULL)
		return NULL;

	if (value < tree->value) {
		tree->left = delete_node(tree->left, value);
	} else if (value > tree->value) {
		tree->right = delete_node(tree->right, value);
	} else {
		if (tree->left == NULL && tree->right == NULL) {
			free(tree);
			return NULL;
		}

		if (tree->left == NULL) {
			Tnode *temp = tree->right;
			free(tree);
			return temp;
		} else if (tree->right == NULL) {
			Tnode *temp = tree->left;
			free(tree);
			return temp;
		}

		Tnode *maxNode = max_value_node(tree->left);
		tree->value = maxNode->value;
		tree->left = delete_node(tree->left, maxNode->value);
	}
	return tree;
}