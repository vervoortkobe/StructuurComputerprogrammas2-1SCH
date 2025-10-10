#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fib(int);

int main() {
	printf("fib(7): %i\n", fib(7));
	return EXIT_SUCCESS;
}

int fib(int n) {
	int fib_n = 1, fib_n1 = 1, i = 1;
	while (i < n) {
		int temp = fib_n;
		fib_n = fib_n1;
		fib_n1 += temp; // fib_n1 = fib_n1 + temp
		i++;
	}
	return fib_n;
}

