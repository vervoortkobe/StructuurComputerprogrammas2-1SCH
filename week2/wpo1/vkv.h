// https://dodona.be/en/courses/5451/series/63959/activities/509780662
#pragma once
#include <stdio.h>
#include <math.h>

void vkv(float a, float b, float c) {
    float D = b * b - 4 * a * c;

    if(D < 0) {
        printf("Geen oplossingen.");
    } else if(D == 0) {
        float opl = -b / (2 * a);
        printf("Oplossing %g", opl);
    } else if(D > 0) {
        float opl[] = {(-b - sqrtf(D)) / (2 * a), (-b + sqrtf(D)) / (2 * a)};
        printf("Oplossing 1 = %g en oplossing 2 = %g", opl[0], opl[1]);
    }
}
