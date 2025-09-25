// https://dodona.be/en/courses/5451/series/63959/activities/509780662
#pragma once
#include <stdio.h>
#include <math.h>

void vkv(float a, float b, float c) {
    float d = b * b - 4 * a * c;

    if(d < 0) {
        printf("Geen oplossingen.");
    } else if(d == 0) {
        float opl = -b / (2 * a);
        printf("Oplossing %g", opl);
    } else if(d > 0) {
        float opl[] = {(-b + sqrtf(b * b - 4 * a * c)) / (2 * a), (-b - sqrtf(b * b - 4 * a * c)) / (2 * a)};
        printf("Oplossing 1 = %g en oplossing 2 = %g", opl[1], opl[0]);
    }
}
