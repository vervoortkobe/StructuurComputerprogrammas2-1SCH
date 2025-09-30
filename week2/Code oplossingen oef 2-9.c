#include <stdio.h>
#include <stdlib.h>

/*
 * Indien je een variant van Linux gebruikt, zal je waarschijnlijk ook de stappen beschreven op https://stackoverflow.com/a/40178250
 * moeten volgen.
 */
#include <math.h>

int fac(int);
int fib(int);
int ggd(int, int);
void vkv(float, float, float);
void collatz(int);
double calc_sine(double, int);
long ackermann(short, short);
void print_difference(int, int, int, int, int, int);

int main(void) {
	/* Oef 2 */
	printf("Oef 2\n");
	/* Dit werkt gewoon */
	printf("%i\n", 1);
	/*
	 * Dit werkt niet: een integer wordt geprint als een floating-point getal,
	 * wat de compiler dwingt om de integer 1 foutief te interpreteren als een float of een double.
	 */
	printf("%g\n", 1);

	/* Dit werkt gewoon */
	printf("%g\n", 3.14);
	/*
	 * Dit werkt niet omwille van dezelfde reden als hierboven. Alleen wordt er nu een floating-point getal
	 * geïnterpreteerd als een integer.
	 */
	printf("%i\n", 3.14);

	/*
	 * Voor de laatste specifier wordt random garbage geprint.
	 * De waarde die daar getoond wordt is gewoon een waarde die toevallig op een bepaalde plaats in het geheugen
	 * van de computer zit.
	 */
	printf("Te veel format specifiers: %i %i %i\n", 1, 2);

	/* Het laatste argument wordt nu gewoon niet geprint. */
	printf("Te weinig format specifiers: %i %i\n", 1, 2, 3);

	/* Met deze print zou het programma crashen. */
//	printf("String printen: %s", 1);

	/* Oef 3 */
	printf("\n\nOef 3\n");
	printf("fac(%i) is %i\n", 5, fac(5));

	/* Oef 4 */
	printf("\n\nOef 4\n");
	printf("De ggd van %i en %i is %i\n", 1, 1, ggd(1, 1));
	printf("De ggd van %i en %i is %i\n", 4, 1, ggd(4, 1));
	printf("De ggd van %i en %i is %i\n", 48, 6, ggd(48, 6));
	printf("De ggd van %i en %i is %i\n", 128, 96, ggd(128, 96));
	printf("De ggd van %i en %i is %i\n", 76, 608, ggd(76, 608));


	/* Oef 5 */
	printf("\n\nOef 5\n");
	vkv(1, -3, 2);

	/* Oef 6 */
	printf("\n\nOef 6\n");
	printf("De collatz reeks van 5:\n");
	collatz(5);

	/* Oef 7 */
	printf("\n\nOef 7\n");
	printf("De sinus van %g is ongeveer %g\n", 3.1416, calc_sine(3.1416, 5));
	printf("De sinus van %g is ongeveer %g\n", 1.5708, calc_sine(1.5708, 3));

	/* Oef 8 */
	printf("\n\nOef 8\n");
	printf("Ackermann(3, 2) is %li\n", ackermann(3, 2));

	/* Oef 9 */
	printf("\n\nOef 9\n");
	print_difference(10, 0, 0, 11, 2, 3);

	return EXIT_SUCCESS;
}

/************************************************************************************************************************
 *														Oefening 3														*
 ************************************************************************************************************************/

int fac(int n) {
	if (n < 2) {
		return 1;
	} else {
		return n * fac(n - 1);
	}
}

/************************************************************************************************************************
 *														Oefening 4														*
 ************************************************************************************************************************/

int ggd(int a, int b) {
	if (b == 0) {
		return a;
	} else {
		int c = a % b;
		return ggd(b, c);
	}
}

/************************************************************************************************************************
 *														Oefening 5														*
 ************************************************************************************************************************/

/*
 * Een functie met 'void' als returntype is een functie die helemaal niets teruggeeft.
 * Het returntype is dus 'void', leeg.
 */

/*
 * Indien je een variant van Linux gebruikt, zal je waarschijnlijk ook de stappen beschreven op https://stackoverflow.com/a/40178250
 * moeten volgen.
 */
void vkv(float a, float b, float c) {
	float D = (b * b) - (4 * a * c);
	if (D < 0) {
		printf("Geen oplossingen");
	} else if (D == 0) {
		float sol = -b / (2 * a);
		printf("Oplossing = %g", sol);
	} else {
		/* D > 0, dus zijn er twee oplossingen */
		float sol1 = (-b - sqrt(D)) / (2 * a);
		float sol2 = (-b + sqrt(D)) / (2 * a);
		printf("Oplossing 1 = %g en oplossing 2 = %g", sol1, sol2);
	}
}

/************************************************************************************************************************
 *														Oefening 6														*
 ************************************************************************************************************************/

void collatz(int n) {
  printf("%i\n", n);
  if (n == 1) {
    return;
  } else if (n % 2 == 0) {
    collatz(n / 2);
  } else {
    collatz(n * 3 + 1);
  }
}

/************************************************************************************************************************
 *														Oefening 7														*
 ************************************************************************************************************************/

double calc_sine_aux(double x, int n, int i) {
	if (i > n) {
		return 0;
	} else {
		int exponent = i * 2 - 1;
		double numerator = pow(x, exponent);
		int denominator = fac(exponent);
		double term = numerator / denominator;
		if (i % 2 == 1) {
			return calc_sine_aux(x, n, i + 1) + term;
		} else {
			return calc_sine_aux(x, n, i + 1) - term;
		}
	}
}

double calc_sine(double x, int n) {
	return calc_sine_aux(x, n, 1);
}

/************************************************************************************************************************
 *														Oefening 8														*
 ************************************************************************************************************************/

long ackermann(short m, short n) {
	if (m == 0) {
		return n + 1;
	} else if (m > 0 && n == 0) {
		return ackermann(m - 1, 1);
	} else {
		return ackermann(m - 1, ackermann(m, n - 1));
	}
}

/************************************************************************************************************************
 *														Oefening 9														*
 ************************************************************************************************************************/

void print_difference(int h1, int m1, int s1, int h2, int m2, int s2) {
	int total_seconds1 = s1 + (m1 * 60) + (h1 * 3600);
	int total_seconds2 = s2 + (m2 * 60) + (h2 * 3600);
	int difference = total_seconds1 - total_seconds2;

	int h_difference = difference / 3600;
	int m_difference = (difference % 3600) / 60;
	int s_difference = difference % 60;

	if (total_seconds1 < total_seconds2) {
		// We berekenen het verschil in absolute waarden.
		h_difference = -h_difference;
		m_difference = -m_difference;
		s_difference = -s_difference;
	}

	printf("%i uren, %i minuten, %i seconden", h_difference, m_difference, s_difference);
}
