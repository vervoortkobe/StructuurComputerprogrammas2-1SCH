#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/************************************************************************************************************
 *                                                Oefening 1                                                *
 ************************************************************************************************************/

int fib(int n) {
	int fib_n = 1, fib_n1 = 1, i = 1;
	while (i < n) {
		int temp = fib_n;
		fib_n = fib_n1;
		fib_n1 += temp;
		i++;
	}
	return fib_n;
}

/************************************************************************************************************
 *                                                Oefening 2                                                *
 ************************************************************************************************************/

void convert_whitespace(char string[]) {
	for (int idx = 0; string[idx] != '\0'; idx++) {
		switch (string[idx]) {
		case ' ':
			string[idx] = '_';
			break;
		case '\t':
			string[idx] = '_';
			break;
		case '\n':
			string[idx] = '_';
			break;
		}
		/*
		 * Het volgende is ook mogelijk:
		 * 		switch (string[idx]) {
		case ' ':
		case '\t':
		case '\n':
			string[idx] = '_';
			break;
		}
		 */
	}
}

/************************************************************************************************************
 *                                                Oefening 3                                                *
 ************************************************************************************************************/

void print_perfect_numbers(int n) {
	int i = 1;
	while (i < n) {
		// loop over alle getallen van 1 tot n
	    int sum = 0; // houdt de som van de factoren bij
	    int j = 1;
	    while (j < i) {
		      // loop over alle getallen kleiner dan i
		      // en zoek de factoren
		      if (i % j == 0) {
		         // j is een factor van i, dus tel j bij sum op
		        sum = sum + j;
		      }
	    	j++;
	    }
	    if (sum == i) {
	       // i is een perfect getal
	      printf("%i\n", i);
	    }
		i++;
	}
}

/************************************************************************************************************
 *                                                Oefening 4                                                *
 ************************************************************************************************************/

void rotate(int *a, int *b, int *c) {
	int temp_a = *a;
	*a = *b;
	*b = *c;
	*c = temp_a;
}

/************************************************************************************************************
 *                                                Oefening 5                                                *
 ************************************************************************************************************/

void do_arithmetic(float numbers[], int length, float *p_sum, float *p_product, int *p_contains_42) {
	float sum = 0, product = 1;
	int contains_42 = 0;
	for (int i = 0; i < length; i++) {
		float number = numbers[i];
		sum += number;
		product *= number;
		if (number == 42) {
			contains_42 = 1;
		}
	}
	*p_sum = sum;
	*p_product = product;
	*p_contains_42 = contains_42;
}

/************************************************************************************************************
 *                                                Oefening 6                                                *
 ************************************************************************************************************/

void my_scanf(char string[], char *pc) {
	for (int idx = 0; string[idx] != '\0'; idx++) {
		if (string[idx] == '%' && string[idx + 1] == 'c') {
			*pc = getchar();
			idx++;
		} else {
			printf("%c", string[idx]);
		}
	}
}

/************************************************************************************************************
 *                                                Oefening 7                                                *
 ************************************************************************************************************/

int read_number() {
	int result = 0;
	char c = getchar();
	/*
	 * Blijf cijfers inlezen tot je het newline karakter tegenkomt:
	 * dit karakter geeft aan wanneer de gebruiker op enter heeft gedrukt.
	 */
	while (c != '\n') {
		result = result * 10;
		c = c - '0';
		result = result + c;
		c = getchar();
	}
	return result;
}

void my_scanf_int(char string[], int *pi) {
	for (int idx = 0; string[idx] != '\0'; idx++) {
		if (string[idx] == '%' && string[idx + 1] == 'i') {
			*pi = read_number();
			idx++;
		} else {
			printf("%c", string[idx]);
		}
	}
}



int main() {
	/* Oef 2 */
	printf("Oef 2\n");
	char string_oef_2[] = "H\nello world\t\t";
	convert_whitespace(string_oef_2);
	printf("%s\n", string_oef_2);

	/* Oef 3 */
	printf("\n\nOef 3\n");
	print_perfect_numbers(10000);

	/* Oef 4 */
	printf("\n\nOef 4\n");
	int c = 1, d = 2, e = 3;
	printf("c = %i, d = %i, e = %i\n", c, d, e);
	rotate(&c, &d, &e);
	printf("Geroteerd: c = %i, d = %i, e = %i\n", c, d, e);

	/* Oef 5 */
	printf("\n\nOef 5\n");
	float sum = 0, product = 0;
	int contains_42 = 0;
	float numbers[] = {123.0, 42, 99.42};
	int length = 3;
	do_arithmetic(numbers, length, &sum, &product, &contains_42);
	printf("sum = %g, product = %g, contains_pi = %i\n", sum, product, contains_42);

	/* Oef 6 */
	printf("\n\nOef 6\n");
	char oef_6;
	my_scanf("Enter a char: %c \n", &oef_6);
	printf("Char is %c\n", oef_6);

	/* Oef 7 */
	printf("\n\nOef 7\n");
	int oef_7_int;

	/*
	 * De lijn hieronder is geen deel van de oefening: we lezen hier alle input van de gebruiker in zodat de "inputbuffer"
	 * volledig leeg is op het moment dat we de gebruiker vragen om een getal in te lezen.
	 * Als we dit niet zouden doen, zou er mogelijk nog data in de inputbuffer staan die de gebruiker bv. in oef 6 heeft ingegeven,
	 * maar die we nu niet willen inlezen.
	 */
	while (getchar() != '\n') {}

	my_scanf_int("Enter an integer: %i", &oef_7_int);
	printf("Integer is %i\n", oef_7_int);

	return EXIT_SUCCESS;
}
