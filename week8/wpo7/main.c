// https://dodona.be/en/courses/5451/series/63965/activities/362430177
#include <stdio.h>
#include <stdlib.h>
void main(int argc, char *argv[]) {
    if (argc == 4) {
        int result;
        switch (argv[2][0]) {
            case '+':
                result = atoi(argv[1]) + atoi(argv[3]);
                break;
            case '-':
                result = atoi(argv[1]) - atoi(argv[3]);
                break;
            case 'X':
                result = atoi(argv[1]) * atoi(argv[3]);
                break;
            case '/':
                result = atoi(argv[1]) / atoi(argv[3]);
                break;
            default:
                break;
        }
        printf("Result is %i", result);
    }
}
