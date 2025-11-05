// https://dodona.be/en/courses/5451/series/63965/activities/362430177
#include <stdio.h>
#include <stdlib.h>
#include "filter.h"

int do_calculation(char operator, int number1, int number2);

int main(int argc, char *argv[]) {
    if (argc == 4) {
        int number1 = atoi(argv[1]);
        char operator = argv[2][0];
        int number2 = atoi(argv[3]);
        int result = do_calculation(operator, number1, number2);
        printf("Result is %i", result);
    }

    int array[] = {1, 14, 27, 4, 17};
    int length = 5;
    int *filtered_array = filter(array, &length, is_larger_than_10);
    // filtered_array is {14, 27, 17}
    // length is 3
}

int do_calculation(char operator, int number1, int number2) {
    int result;
    switch (operator) {
        case '+':
            result = number1 + number2;
            break;
        case '-':
            result = number1 - number2;
            break;
        case 'X':
            result = number1 * number2;
            break;
        case '/':
            result = number1 / number2;
            break;
    }
    return result;
}