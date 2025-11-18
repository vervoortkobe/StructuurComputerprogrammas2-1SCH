#include <stdio.h>
#include <stdlib.h>

#include <string.h>

/************************************************************************************************************
 *                                                Oefening 1                                                *
 ************************************************************************************************************/

// Zie slides Oef 1
// Hoeveelheid geheugen statisch gealloceerd in read_chess_pieces: 24 byte
// Totale hoeveelheid geheugen dynamisch gealloceerd in read_chess_pieces(n): n*8 + n*10

/************************************************************************************************************
 *                                                Oefening 2                                                *
 ************************************************************************************************************/

/*
 * Zie ook de main-functie voor de rest van de oplossing voor deze oefening.
 */

int do_calculation(char operator, int number1, int number2) {
	int result;
	switch(operator) {
	case '+':
		result = number1 + number2;
		break;
	case '-':
		result = number1 - number2;
		break;
	case 'X':
		result = number1 * number2;
		break;
	case '/':
		result = number1 / number2;
		break;
	}
	return result;
}

/************************************************************************************************************
 *                                                Oefening 3                                                *
 ************************************************************************************************************/

int *filter(int *array, int *p_length, int (*f)(int)) {
	/*
	 * De functie moet een nieuwe array teruggeven, dus gebruiken we dynamische allocatie.
	 * We weten echter nog niet hoe groot de nieuwe array zal zijn, dus gaan we er van uit
	 * dat de nieuwe array even groot zal zijn als de meegegeven array.
	 */
	int *filtered_array = malloc(*p_length * sizeof(int));
	int filtered_array_length = 0;
	for (int idx = 0; idx < *p_length; idx++) {
		int element = array[idx];
		if (f(element)) {
			filtered_array[filtered_array_length] = element;
			filtered_array_length++;
		}
	}
	/*
	 * Nu we de grootte van de nieuwe array kennen, alloceren we een nieuwe array van de juiste grootte.
	 */
	int *resized_array = malloc(filtered_array_length * sizeof(int));
	for (int idx = 0; idx < filtered_array_length; idx++) {
		resized_array[idx] = filtered_array[idx];
	}
	/*
	 * We dealloceren de vorige array.
	 */
	free(filtered_array);
	*p_length = filtered_array_length;
	return resized_array;
}

/*
 * Alternatieve implementatie die gebruik maakt van realloc om een bestaande, dynamisch
 * gealloceerde array groter of kleiner te maken.
 */
int *filter_with_realloc(int *array, int *p_length, int (*f)(int)) {
	/*
	 * Eerste stuk is gelijkaardig aan de andere implementatie.
	 */
	int *filtered_array = malloc(*p_length * sizeof(int));
	int filtered_array_length = 0;
	for (int idx = 0; idx < *p_length; idx++) {
		int element = array[idx];
		if (f(element)) {
			filtered_array[filtered_array_length] = element;
			filtered_array_length++;
		}
	}
	*p_length = filtered_array_length;
	/*
	 * In plaats van 1) een nieuwe array met de juiste grootte te alloceren, 2) alle
	 * elementen te kopiëren naar die array, 3) de eerste array te dealloceren,
	 * gebruiken we realloc om dit alles voor ons te doen.
	 *
	 * Merk op realloc mogelijk een volledig nieuwe array heeft moeten maken op een
	 * andere plaats in het geheugen. De filtered_array pointer is dus niet
	 * noodzakelijk dezelfde pointer als die dat teruggegeven wordt door realloc.
	 */
	return realloc(filtered_array, filtered_array_length * sizeof(int));
}

/************************************************************************************************************
 *                                                Oefening 4                                                *
 ************************************************************************************************************/

struct Student {
	int id;
	float average;
};

struct Student *read_student() {
	int id;
	float average;
	/* Lees het id en het puntengemiddelde in. */
	scanf("%i", &id);
	scanf("%f", &average);

	struct Student *student = malloc(sizeof(struct Student));
	/* We zouden hier ook kunnen controleren of student != NULL */

	student->id = id;
	student->average = average;

	return student;
}

/*
 * Maakt een array van n studenten aan, leest ze in door input te vragen aan de gebruiker en geeft ze terug.
 */
struct Student **read_students(int n) {
	struct Student **array = calloc(n, sizeof(struct Student *));

	for (int i = 0; i < n; i++) {
		/* We lezen een student in uit de console en plaatsen een pointer naar die student in de array. */
		struct Student *student = read_student();
		array[i] = student;
	}
	return array;
}

void deallocate_students(struct Student **array, int n) {
	for (int i = 0; i < n; i++) {
		/* Dealloceer elk van de n studenten die werden aangemaakt. */
		free(array[i]);
	}
	/* Dealloceer de array zelf. */
	free(array);
}

void print_students(struct Student **array, int n) {
	for (int i = 0; i < n; i++) {
		printf("id: %i, avg: %f\t", array[i]->id, array[i]->average);
	}
}

/************************************************************************************************************
 *                                                Oefening 5                                                *
 ************************************************************************************************************/

typedef struct node{
	int info;
	struct node *next;
} Node;

Node *readintlist();
void printintlist(Node *);
int get_int();

/*
 * Gegegeven (een pointer naar) de start van een lijst en een integer, voegt deze functie de gegeven integer op
 * de juiste plaats in de lijst toe en geeft de functie de nieuwe start van de lijst terug.
 */
Node *insert_node(Node *start, int value) {
	Node *prev = NULL;
	Node *curr = start;

	Node *new_node = (Node *) malloc(sizeof(Node));
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

/*
 * Deze functie maakt nu gewoon gebruik van de insert_node-hulpfunctie om
 * nodes meteen op de juiste plaats in de gelinkte lijst te zetten.
 */
Node *readintlist() {
	Node *p = NULL;
	int i;

	while ((i = get_int()) != 0) {
		p = insert_node(p, i);
	}
	return p;
}

/*
 * Onveranderd tov. de versie uit het HOC.
 */
void printintlist(Node *p) {
	Node *q = p;
	while (q != NULL){
		printf("%p: %d\n", q, q->info);
		q = q->next;
	}
}

/*
 * Onveranderd tov. de versie uit het HOC.
 */
int get_int() {
	int i;
	scanf("%d", &i);
	return i;
}

/************************************************************************************************************
 *                                                Oefening 6                                                *
 ************************************************************************************************************/

typedef struct double_node {
	int value;
	struct double_node *prev;
	struct double_node *next;
} Double_Node;

Double_Node *insert_before(int value, Double_Node *node) {
	Double_Node *new_node = malloc(sizeof(Double_Node));
	new_node->value = value;
	new_node->next = node;
	if (node != NULL) {
		Double_Node *prev_node = node->prev;
		node->prev = new_node;
		new_node->prev = prev_node;
		if (prev_node != NULL) {
			prev_node->next = new_node;
		}
	} else {
		new_node->prev = NULL;
	}
	return new_node;
}

Double_Node *insert_after(int value, Double_Node *q) {
	Double_Node *p = malloc(sizeof(Double_Node));
	p->value = value;
	p->prev = q;
	if (q != NULL) {
		Double_Node *next = q->next;
		q->next = p;
		p->next = next;
		if (next != NULL) {
			next->prev = p;
		}
	} else {
		p->next = NULL;
	}
	return p;
}

Double_Node *delete_node(int key, Double_Node *start) {
	Double_Node *p;
	p = start;
	while (p != NULL && (p->value != key)) {
		p = p->next;
	}
	if (p != NULL) {
		Double_Node *next = p->next;
		Double_Node *prev = p->prev;
		if (prev != NULL) {
			prev->next = next;
			if (next != NULL) {
				next->prev = prev;
			}
		} else {
			start = p->next;
			if (next != NULL) {
				next->prev = NULL;
			}
		}
		free(p);
	}
	return start;
}

/*
 * Debugging functie.
 */
void print_double_linked_list(Double_Node *p) {
	while (p != NULL) {
		printf("%p: value: %i, prev: %p, next: %p\n", p, p->value, p->prev, p->next);
		p = p->next;
	}
}


int is_larger_than_10(int x) {
	return x > 10;
}
int is_smaller_than_3(int x) {
	return x < 3;
}

void print_int_array(int *array, int length) {
	printf("[");
	for (int idx = 0; idx < length; idx++) {
		printf("%i", array[idx]);
		if (idx != length - 1) {
			printf(", ");
		}
	}
	printf("]\n");
}

/*
 * Als we de command line argumenten van het programma willen gebruiken, moeten we de main-functie op
 * de volgende manier schrijven.
 * argc geeft hier aan hoeveel argumenten er werden meegegeven, argv is een array die de eigenlijke
 * argumenten bevat. Dit is een array van strings: elk command line argument wordt dus meegegeven als string.
 */
int main(int argc, char *argv[]) {
	/* Oef 1 */
	// Zie slides Oef 1
	// Hoeveelheid geheugen statisch gealloceerd in read_chess_pieces: 24 byte
	// Totale hoeveelheid geheugen dynamisch gealloceerd in read_chess_pieces(n): n*8 + n*10

	/* Oef 2 */
	printf("Oef 2\n");
	/*
	 * Er wordt altijd automatisch een argument meegegeven: het pad van het programma (m.a.w. de executable)
	 * dat wordt uitgevoerd. Dit argument is steeds het eerste element van de array.
	 * Als je dus drie argumenten nodig hebt voor je programma, zal je eigenlijk vier argumenten krijgen.
	 */
	if (argc == 4) {
		/* Het eerste getal bevindt zich dus op de tweede plaats in de array (argv[1] dus). */

		/*
		 * Beide getallen worden voorgesteld als strings in argv, we moeten ze dus eerst converteren naar
		 * een integer via bv. de atoi functie.
		 */
		int number1 = atoi(argv[1]);
		char operator = argv[2][0];
		int number2 = atoi(argv[3]);
		int result = do_calculation(operator, number1, number2);
		printf("Result is %i", result);
	}

	/* Oef 3 */
	printf("\n\nOef 3\n");
	int array_1[] = {1, 14, 27, 4, 17};
	int array_1_length = 5;
	int array_2[] = {3, 2, 1};
	int array_2_length = 3;

	int *filtered_array_1 = filter(array_1, &array_1_length, is_larger_than_10);
	printf("filtered_array_1: ");
	print_int_array(filtered_array_1, array_1_length);
	free(filtered_array_1);

	int *filtered_array_2 = filter_with_realloc(array_2, &array_2_length, is_smaller_than_3);
	printf("filtered_array_2: ");
	print_int_array(filtered_array_2, array_2_length);
	free(filtered_array_2);

	/* Oef 4 */
	printf("\n\nOef 4\n");
	// voorbeeldinput:
	// 56789 99.9 59876 11.1

	/*
	 * De lengte van de array wordt hier ook buiten de read_students-functie opgeslagen.
	 */
	struct Student **student_array = read_students(2);
	print_students(student_array, 2);
	deallocate_students(student_array, 2);

	/* Oef 5 */
	printf("\n\nOef 5\n");
	// voorbeeldinput:
	// 7 5 9 8 0
	Node *head = readintlist();
	printintlist(head);

	/* Oef 6 */
	printf("\n\nOef 6\n");
	/* Maak een double_linked list door handmatig een aantal elementen toe te voegen. */
	Double_Node *oef_6a = insert_before(1, NULL);
	Double_Node *oef_6b = insert_after(2, oef_6a);
	Double_Node *oef_6d = insert_after(4, oef_6b);
	Double_Node *oef_6g = insert_after(7, oef_6d);
	Double_Node *oef_6h = insert_after(8, oef_6g);
	Double_Node *oef_6c = insert_before(3, oef_6d);
	Double_Node *oef_6f = insert_before(6, oef_6g);
	Double_Node *oef_6e = insert_after(5, oef_6d);
	print_double_linked_list(oef_6a);
	printf("\n\n");
	Double_Node *oef_6aa = delete_node(1, oef_6a);
	Double_Node *oef_6bb = delete_node(6, oef_6aa);
	Double_Node *oef_6cc = delete_node(8, oef_6bb);
	print_double_linked_list(oef_6cc);

}
