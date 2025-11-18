// https://dodona.be/en/courses/5451/series/63966/activities/653466354
#include <stdlib.h>

typedef struct tnode {
    int value;
    struct tnode *left, *right;
} Tnode;

Tnode *max_value_node(Tnode *tree) {
    Tnode *current = tree;
    if (tree == NULL) return NULL;
    while (current->right != NULL) {
        current = current->right;
    }
    return current;
}