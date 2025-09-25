//
// Created by vervo on 25/09/2025.
//

#include <stdio.h>

int square(int n);

int squared(void) {
    const int a = 5;
    printf("%d squared equals %d\n", a, square(a));
    return square(a);
}

int square(const int n) {
    return n * n;
}