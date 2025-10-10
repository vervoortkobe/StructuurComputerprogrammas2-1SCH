#include <stdio.h>
#include "print_perfect_numbers.h"
#include "convert_whitespace.h"
#include "rotate.h"
#include "do_arithmetic.h"
#include "my_scanf.h"
#include "my_scanf_int.h"

int main(void) {
    /*
        print_perfect_numbers(100);
        convert_whitespace("Dit is een konijn en een kanarie.");
        int a = 1, b = 2, c = 3;
        rotate(&a, &b, &c);
        printf("a=%d, b=%d, c=%d\n", a, b, c);
        float numbers[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
        float sum, product;
        int contains_42;
        do_arithmetic(numbers, 5, &sum, &product, &contains_42);
        printf("Sum: %.2f, Product: %.2f, Contains 42: %d\n", sum, product, contains_42);

        char c;
        my_scanf("Enter a character: %c", &c);
        printf("You entered: %c", c);
    */
    int i;
    my_scanf_int("Enter an integer: %i", &i);
    printf("You entered: %i", i);
    return 0;
}