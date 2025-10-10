// https://dodona.be/en/courses/5451/series/63961/activities/1757319789
#include <stdio.h>

void my_scanf_int(char string[], int *i) {
    int idx = 0;

    while (string[idx] != '\0') {
        if (string[idx] == '%' && string[idx + 1] == 'i') {
            int result = 0;
            char c;

            c = getchar();

            while (c != '\n') {
                result = result * 10 + (c - '0');
                c = getchar();
            }

            *i = result;

            idx += 2;
        } else {
            printf("%c", string[idx]);
            idx++;
        }
    }
}
