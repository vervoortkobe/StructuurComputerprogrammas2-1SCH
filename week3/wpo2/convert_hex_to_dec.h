// https://dodona.be/en/courses/5451/series/63960/activities/822015033

#include "stdio.h"
#include <math.h>
#include <string.h>

int convert_hex_to_dec(char hex[]) {
    int output = 0;
    int countdown = strlen(hex) - 1;
    for (int i = 0; i < strlen(hex); i++) {
        int value = 0;
        if (hex[i] >= 'A' && hex[i] <= 'F') {
            value = hex[i] - 'A' + 10;
        } else if (hex[i] >= '0' && hex[i] <= '9') {
            value = hex[i] - '0';
        }
        output += value * pow(16, countdown);
        countdown--;
    }
    printf("%d", output);
    return output;
}