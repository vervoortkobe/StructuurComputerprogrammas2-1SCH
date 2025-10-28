#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/************************************************************************************************************
 *                                                Oefening 1                                                *
 ************************************************************************************************************/

/*
 * Het belangrijkste hier is dat, omwille van de manier waarop FALSE en TRUE geordend zijn, FALSE automatisch de
 * waarde 0 krijgt, en TRUE de waarde 1.
 * Je kan dit ook expliciet maken door het volgende te schrijven:
 * enum Boolean { FALSE = 0, TRUE = 1 };
 */
enum Boolean {
	FALSE, TRUE
};

enum Boolean my_and(enum Boolean a, enum Boolean b) {
	return a * b;
}

enum Boolean my_or(enum Boolean a, enum Boolean b) {
	enum Boolean result = a + b;
	// Als a en b TRUE (1) zijn, zal result gelijk zijn aan 1 + 1 = 2, maar 2 is niet gelijk aan TRUE.
	// M.a.w. or(TRUE, TRUE) zou ongelijk zijn aan TRUE.
	// Om dit te vermijden, reassignen we het resultaat naar TRUE als blijkt dat het resultaat groter zou zijn dan TRUE (1).
	if (result > TRUE) {
		result = TRUE;
	}
	return result;
}

/************************************************************************************************************
 *                                                Oefening 2                                                *
 ************************************************************************************************************/

char *my_strrchr(char *string, char c) {
	char *p = string + strlen(string);
	while (p >= string) {
		if (*p == c) {
			return p;
		}
		p--;
	}
	return NULL;
}

/************************************************************************************************************
 *                                                Oefening 3                                                *
 ************************************************************************************************************/

char *my_strpbrk(char *string1, char *string2) {
	while (*string1 != '\0') {
		char *curr_str2 = string2;
		while (*curr_str2 != '\0') {
			if (*string1 == *curr_str2) {
				return string1;
			}
			curr_str2++;
		}
		string1++;
	}
	return NULL;
}

/************************************************************************************************************
 *                                                Oefening 4                                                *
 ************************************************************************************************************/

int my_strcmp(char *str_1, char *str_2) {
	for (; ; str_1++, str_2++) {
		char c_1 = *str_1;
		char c_2 = *str_2;
		if (c_1 == '\0' && c_2 == '\0') {
			return 0;
		} else if (c_1 == c_2) {
			continue;
		} else {
			return c_1 - c_2;
		}
	}
}

/************************************************************************************************************
 *                                                Oefening 5                                                *
 ************************************************************************************************************/

// Zie slides oefening 5

/************************************************************************************************************
 *                                                Oefening 6                                                *
 ************************************************************************************************************/

int is_accepted(char *accepted, char character) {
	for (; *accepted != '\0'; accepted++) {
		if (*accepted == character) {
			return 1;
		}
	}
	return 0;
}

char *string_span(char *string, char *accepted, int *length) {
	int max_length = 0;
	char *points_to_max_span;
	char *loop_over_string = string;
	int current_span_length = 0;
	for (; *loop_over_string != '\0'; loop_over_string++) {
		if (is_accepted(accepted, *loop_over_string)) {
			current_span_length++; // huidige span gaat verder
			if (current_span_length > max_length) {
				max_length = current_span_length;
				points_to_max_span = loop_over_string - current_span_length + 1;
			}
		} else {
			current_span_length = 0; // breek huidige span af
		}
	}
	*length = max_length;
	if (max_length == 0) {
		return loop_over_string;
	} else {
		return points_to_max_span;
	}
}



int main(void) {
	/* Oef 1 */
	printf("Oef 1\n");
	printf("AND: %i, %i, %i, %i\n", my_and(FALSE, FALSE), my_and(FALSE, TRUE), my_and(TRUE, FALSE), my_and(TRUE, TRUE));
	printf("OR: %i, %i, %i, %i\n", my_or(FALSE, FALSE), my_or(FALSE, TRUE), my_or(TRUE, FALSE), my_or(TRUE, TRUE));

	/* Oef 2 */
	printf("\n\nOef 2\n");
	char *string_oef2 = "www.vub.be";
	char *ret_oef2 = my_strrchr(string_oef2, '.');
	printf("Top-level domain name is %s\n", ret_oef2);

	/* Oef 3 */
	printf("\n\nOef 3\n");
	char *string_oef3 = "Voorbeeldstring";
	char *vowels = "aeiou";
	char *ret2 = my_strpbrk(string_oef3, vowels);
	if(ret2) {
	  printf("First matching character: %c\n", *ret2);
	} else {
	  printf("No matching characters found");
	}

	/* Oef 4 */
	printf("\n\nOef 4\n");
	printf("%i\n", my_strcmp("Scheme", "Scala"));
	printf("%i\n", my_strcmp("hello", "hellow"));

	/* Oef 5 */
	printf("\n\nOef 5\n");
	printf("Zie slides oefening 5\n");

	/* Oef 6 */
	printf("\n\nOef 6\n");
	char oef6_string1[] = "abcdefg";
	char oef6_accepted1[] = "fde";
	int span_length1 = -1;
	char *span_start1 = string_span(oef6_string1, oef6_accepted1, &span_length1);
	printf("span_start: %c (index: %li), span_length = %i\n", *span_start1, span_start1 - oef6_string1, span_length1);
}
