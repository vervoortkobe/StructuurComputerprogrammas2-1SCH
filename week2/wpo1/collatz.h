// https://dodona.be/en/courses/5451/series/63959/activities/1157383049
#include <stdio.h>

void collatz(int n) {
    printf("%d\n", n);

    if (n == 1) {
        return;
    }
    if (n % 2 == 0) {
        int m = n / 2;
        collatz(m);
    }
    else {
        int m = 3 * n + 1;
        collatz(m);
    }
}