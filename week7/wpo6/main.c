#include <stdio.h>
#include "lowercase.h"
#include "generate_primes.h"
#include "poly_plus.h"

int main(void) {
    char string[] = "HELLO WORLD";
    char *lowercase_string = lowercase(string);
    printf("%s\n", lowercase_string);
    free(lowercase_string);

    int *array = generate_primes(50);
    print_primes(50);
    free(array);

    struct variant a = {.u.integer = 5, .type = INT};
    struct variant b = {.u.integer = 10, .type = INT};
    struct variant *result = plus(a, b);
    free(result);

    return 0;
}