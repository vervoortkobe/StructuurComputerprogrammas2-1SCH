// https://dodona.be/en/courses/5451/series/63960/activities/337605201
#include <stdio.h>

void print_perfect_numbers(int n) {
    for (int i = 1; i <= n; i++) {
        if (i == 1) continue;
        int sum = 0;
        for (int j = 1; j <= i / 2; j++) {
            if (i % j == 0) {
                sum += j;
            }
        }
        if (sum == i) {
            printf("%d\n", i);
        }
    }
}