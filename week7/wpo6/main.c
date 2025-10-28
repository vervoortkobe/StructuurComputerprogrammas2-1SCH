#include <stdio.h>
#include "lowercase.h"
#include "generate_primes.h"

int main(void) {
    char string[] = "HELLO WORLD";
    char *lowercase_string = lowercase(string);
    printf("%s\n", lowercase_string);
    free(lowercase_string);

    int *array = generate_primes(50);
    print_primes(50);
    free(array);

    return 0;
}