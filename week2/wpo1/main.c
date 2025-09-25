#include <stdio.h>
#include "fac.h"
#include "ggd.h"

int main(void) {
    //fac
    const int n = 5;
    printf("fac %d: %d\n", n, fac(5));

    //ggd
    const int a = 15;
    const int b = 20;
    printf("ggd %d, %d: %d\n", a, b, ggd(a, b));

    return 0;
}