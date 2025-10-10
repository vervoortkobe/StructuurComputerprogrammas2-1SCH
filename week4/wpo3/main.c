#include <stdio.h>
#include "print_perfect_numbers.h"
#include "convert_whitespace.h"
#include "rotate.h"

int main(void) {
    printf("Hello, World!\n");
    print_perfect_numbers(100);
    convert_whitespace("Dit is een konijn en een kanarie.");
    int a = 1, b = 2, c = 3;
    rotate(&a, &b, &c);
    return 0;
}