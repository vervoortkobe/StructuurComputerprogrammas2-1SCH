#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static void write_number(FILE *file, long number) {
	for (int i = 0; i < 8; i++) {
		long n = number >> (8 * (8 - i - 1));
		unsigned char c = n % 256;
		fprintf(file , "%c", c);
	}
}

int main(int argc, char **argv) {
	assert(sizeof(long) == 8);
	FILE *file = fopen("./input", "w");
	for (int i = 1; i < argc; i++) {
		long value = strtol(argv[i], NULL, 0);
		write_number(file, value);
	}
	write_number(file, 0);
	return 0;
}
