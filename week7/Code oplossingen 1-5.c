#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <ctype.h>
#include <string.h>


/************************************************************************************************************
 *                                                Oefening 1                                                *
 ************************************************************************************************************/

char *lowercase(char *string) {
	/*
	 * Aangezien we een nieuwe string teruggeven moeten we eerst geheugen voor deze string gaan alloceren.
	 * Deze string is juist even lang als de oude, dus we berekenen eerst (via strlen) hoe groot deze oude
	 * string was en dan alloceren we zoveel nieuw geheugen vanop de heap.
	 * We alloceren bovendien nog een extra karakter, om het null-karakter '\0' waarmee elke string
	 * eindigt ook te kunnen opslaan.
	 */
	int string_length = strlen(string);
	char *new_string = calloc(string_length + 1, sizeof(char));
	if (new_string != NULL) {
		for (int i = 0; i < string_length; i++) {
			char c = string[i];
			char lowercase_c = tolower(c);
			new_string[i] = lowercase_c;
		}
		new_string[string_length] = '\0';
		return new_string;
	} else {
		return NULL;
	}
}


/************************************************************************************************************
 *                                                Oefening 2                                                *
 ************************************************************************************************************/

int *generate_primes(int n) {
  int *array = (int*) calloc(n, sizeof(int));
  int idx = 0;
  for (int i = 2; idx < n; i++) {
    int prime = 1;
    for (int j = 2; j < i; j++) {
      if (i % j == 0) {
        prime = 0;
        break;
      }
    }
    if (prime) {
      array[idx] = i;
      idx++;
    }
  }
  return array;
}

/************************************************************************************************************
 *                                                Oefening 3                                                *
 ************************************************************************************************************/

/* Het type van de union kan natuurlijk ook via een integer worden voorgesteld. */
enum type {
	INT, CHAR, STRING, ERROR
};

union poly {
	int integer;
	char character;
	char *string;
};

struct variant {
	union poly u;
	enum type type;
};

struct variant plus(struct variant a, struct variant b) {
	if (a.type != b.type) {
		/*
		 * De argumenten hebben niet hetzelfde type, dus print een waarschuwing en geef een standaard variant
		 * terug die aangeeft dat er iets is misgelopen.
		 */
		struct variant error;
		error.type = ERROR;
		printf("Argumenten hebben niet hetzelfde type!\n");
		return error;
	} else {
		struct variant result;
		if (a.type == INT) {
			int som = a.u.integer + b.u.integer;

			result.type = INT;
			result.u.integer = som;
		} else if (a.type == CHAR) {
			/*
			 * We maken m.b.v. dynamische allocatie een nieuwe string waar beide karakters in geplaatst worden.
			 * Een string is gewoon een array van karakters, eindigend met het karakter '\0'.
			 * De array moet daarom ook 3 karakters lang zijn: het karakter van beide argumenten plus
			 * het karakter '\0'.
			 */
			char *new_string = calloc(3, sizeof(char));
			new_string[0] = a.u.character;
			new_string[1] = b.u.character;
			new_string[2] = '\0';

			result.type = STRING;
			result.u.string = new_string;
		} else {
			/*
			 * We gebruiken opnieuw dynamische allocatie om een nieuwe string aan te maken.
			 * De grootte van de onderliggende array is gelijk aan de som van de groottes
			 * van beide strings, plus 1, omdat het karakter '\0' ook nog in de array moet
			 * gezet worden.
			 */
			int new_string_length = strlen(a.u.string) + strlen(b.u.string) + 1;
			char *concatenatie = calloc (new_string_length, sizeof(char));
			strcat(concatenatie, a.u.string);
			strcat(concatenatie, b.u.string);
			result.type = STRING;
			result.u.string = concatenatie;
		}
		return result;
	}
}

/************************************************************************************************************
 *                                                Oefening 4                                                *
 ************************************************************************************************************/

float calculate_average(float *grades, int length) {
  float sum = 0;
  for (int i = 0; i < length; i++) {
    sum += *grades;
    grades++;
  }
  return sum / length;
}

float *calculate_all_averages(float **all_grades, int *all_lengths, int nr_of_students) {
  float *all_results = (float *) calloc(nr_of_students, sizeof(float));
  for (int idx = 0; idx < nr_of_students; idx++) {
    all_results[idx] =  calculate_average(*all_grades, *all_lengths);
    all_grades++;
    all_lengths++;
  }
  return all_results;
}

/************************************************************************************************************
 *                                                Oefening 5                                                *
 ************************************************************************************************************/

enum Color {
	BLACK, WHITE
};
enum Type {
	PAWN, BISHOP, KNIGHT, ROOK, QUEEN, KING
};

struct Piece {
	enum Color color;
	enum Type type;
};

struct Piece *make_piece(enum Color color, enum Type type) {
	/* Aangezien de functie een pointer naar de student teruggeeft, moeten we dynamische allocatie gebruiken. */
	struct Piece *piece = malloc(sizeof(struct Piece));
	/* We zouden hier ook kunnen controleren of piece != NULL */

	/* Geef nu de juiste waarden aan de fields van de struct die net werd aangemaakt. */
	piece->color = color;
	piece->type = type;
	return piece;
}

/*
 * Maakt een array van n schaakstukken aan, leest ze in door input te vragen aan de gebruiker en geeft ze terug.
 */
struct Piece **read_chess_pieces(int n) {
	/*
	 * Aangezien we deze array willen teruggeven uit deze functie, moet de array blijven bestaan,
	 * ook nadat deze functie gereturnt is. We moeten dus dynamische allocatie gebruiken.
	 */
	struct Piece **array = calloc(n, sizeof(struct Piece*));
	for (int i = 0; i < n; i++) {
		char c;
		/* We lezen een karakter in dat het schaakstuk voorstelt. */
		scanf("%c", &c);
		switch(c) {
		case 'P': array[i] = make_piece(BLACK, PAWN); break; 	// 'P' -> zwarte pion
		case 'p': array[i] = make_piece(WHITE, PAWN); break; 	// 'p' -> witte pion
		case 'B': array[i] = make_piece(BLACK, BISHOP); break;	// ...
		case 'b': array[i] = make_piece(WHITE, BISHOP); break;
		case 'N': array[i] = make_piece(BLACK, KNIGHT); break;
		case 'n': array[i] = make_piece(WHITE, KNIGHT); break;
		case 'R': array[i] = make_piece(BLACK, ROOK); break;
		case 'r': array[i] = make_piece(WHITE, ROOK); break;
		case 'Q': array[i] = make_piece(BLACK, QUEEN); break;
		case 'q': array[i] = make_piece(WHITE, QUEEN); break;
		case 'K': array[i] = make_piece(BLACK, KING); break;
		case 'k': array[i] = make_piece(WHITE, KING); break;
		}
	}
	return array;
}

void deallocate_chess_pieces(struct Piece **array, int length) {
	for (int i = 0; i < length; i++) {
		free(array[i]);
	}
	free(array);
}




int main(void) {
	/* Oef 1 */
	printf("Oef 1\n");
	char *string = "HeLLo wORlD!";
	char *lowercase_string = lowercase(string);
	printf("%s -> %s\n", string, lowercase_string);
	/*
	 * Aangezien de "lowercase_string" hierna niet meer gaan gebruiken, dealloceren we ook weer het geheugen dat we
	 * voor deze string voorzien hadden.
	 */
	free(lowercase_string);

	/* Oef 2 */
	printf("\n\nOef 2\n");
	int *primes = generate_primes(10);
	for (int i = 0; i < 10; i++) {
		printf("%i is a prime number\n", primes[i]);
	}
	free(primes);

	/* Oef 3 */
	printf("\n\nOef 3\n");
	struct variant a = { { 3 }, INT }, b = { { 6 }, INT };
	printf("plus(a, b) = %i\n", plus(a, b).u.integer);

	struct variant c, d;
	c.type = CHAR;
	c.u.character = 'o';
	d.type = CHAR;
	d.u.character = 'k';
	struct variant result_1 = plus(c, d);
	printf("plus(c, d) = %s\n", result_1.u.string);
	/*
	 * We dealloceren de string die zich in het union-field van result_1 bevindt.
	 * Zowel result_1 als result_1.u moeten zelf NIET gedealloceerd worden.
	 * Enkel de string werd dynamisch gealloceerd, dus enkel deze moet ook weer gedealloceerd worden.
	 */
	free(result_1.u.string);

	struct variant e, f;
	e.type = STRING;
	e.u.string = "Hello ";
	f.type = STRING;
	f.u.string = "world!";
	struct variant result_2 = plus(e, f);
	printf("plus(e, f) = %s\n", result_2.u.string);
	/*
	 * We dealloceren ook hier de string die werd gealloceerd voor result_2.u.string.
	 */
	free(result_2.u.string);

	/* Oef 4 */
	printf("\n\nOef 4\n");
	float student1[] = {10, 20, 15};
	float student2[] = {14};
	float *all_grades[] = {student1, student2};
	int lengths[] = {3, 1};

	float *averages = calculate_all_averages(all_grades, lengths, 2);
	for (int idx = 0; idx < 2; idx++) {
		printf("Average is %g\n", averages[idx]);
	}
	free(averages);

	/* Oef 5 */
	printf("\n\nOef 5\n");
	int n_oef_5 = 4;
	// voorbeeldinput:
	// PrKn
	struct Piece** chess_pieces_array = read_chess_pieces(n_oef_5);
	deallocate_chess_pieces(chess_pieces_array, n_oef_5);
}
