// https://dodona.be/en/courses/5451/series/63960/activities/544298707
#include <stdio.h>

void print_christmas_tree(int n) {
    for (int i = 1; i <= n; i++) {
        if (i == 1) printf("*");
        else {
            for (int j = 1; j <= i+1; j++) {
                printf("*");
            }
        }
        printf("\n");
    }

    for (int i = 1; i <= (n-1)/2; i++) {
        printf(" ");
    }
    printf("*\n");
    for (int i = 1; i <= (n-1)/2; i++) {
        printf(" ");
    }
    printf("*\n");
}