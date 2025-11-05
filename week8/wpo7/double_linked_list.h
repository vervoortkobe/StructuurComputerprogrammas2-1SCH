// https://dodona.be/en/courses/5451/series/63965/activities/416059530
#include <stdlib.h>

typedef struct double_node {
	int value;
	struct double_node *prev;
	struct double_node *next;
} Double_Node;

Double_Node *insert_before(int value, Double_Node *node) {
	Double_Node *new_node = malloc(sizeof(Double_Node));
	new_node->value = value;
	new_node->next = node;

	if (node == NULL) {
		new_node->prev = NULL;
	} else {
		new_node->prev = node->prev;
		if (node->prev != NULL) {
			node->prev->next = new_node;
		}
		node->prev = new_node;
	}

	return new_node;
}

Double_Node *insert_after(int value, Double_Node *node) {
	Double_Node *new_node = malloc(sizeof(Double_Node));
	new_node->value = value;
	new_node->prev = node;

	if (node == NULL) {
		new_node->next = NULL;
	} else {
		new_node->next = node->next;
		if (node->next != NULL) {
			node->next->prev = new_node;
		}
		node->next = new_node;
	}

	return new_node;
}

Double_Node *delete_node(int value, Double_Node *start) {
	if (start == NULL) {
		return NULL;
	}

	Double_Node *current = start;
	while (current != NULL && current->value != value) {
		current = current->next;
	}

	if (current == NULL) {
		return start;
	}

	if (current->next != NULL) {
		current->next->prev = current->prev;
	}

	if (current->prev != NULL) {
		current->prev->next = current->next;
	}

	Double_Node *new_start = start;
	if (current == start) {
		new_start = current->next;
	}

	free(current);

	return new_start;
}