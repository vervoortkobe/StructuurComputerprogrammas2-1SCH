// https://dodona.be/en/courses/5451/series/63959/activities/509780662
#include <stdio.h>
#include "fac.h"
#include "ggd.h"
#include "vkv.h"
#include "collatz.h"

int main(void) {
    //fac
    const int n = 5;
    printf("fac %d: %d\n", n, fac(5));

    //ggd
    const int a = 15;
    const int b = 20;
    printf("ggd %d, %d: %d\n", a, b, ggd(a, b));

    //vkv
    const float x = 1.0;
    const float y = -3.0;
    const float z = 2.0;
    vkv(x, y, z);

    //collatz
    const int m = 5;
    collatz(m);

    return 0;
}