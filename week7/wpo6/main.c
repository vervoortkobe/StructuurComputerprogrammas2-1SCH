#include <stdio.h>
#include "lowercase.h"
#include "generate_primes.h"
#include "poly_plus.h"
#include "calculate_all_averages.h"
#include "read_chess_pieces.h"

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

    float student1[] = {14.5, 9, 11, 16.5};
    float student2[] = {18, 7};
    float student3[] = {7, 11.5, 13};
    float *all_grades[] = {student1, student2, student3};
    int lengths[] = {4, 2, 3};
    float *all_avgs = calculate_all_averages(all_grades, lengths, 3);
    free(all_avgs);

    struct Piece **arr = read_chess_pieces(5); // "input: PpkNK"
    free_chess_pieces(arr, 5);

    return 0;
}