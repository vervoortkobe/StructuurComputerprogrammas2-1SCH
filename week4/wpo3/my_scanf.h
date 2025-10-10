// https://dodona.be/en/courses/5451/series/63961/activities/274178038
#include <stdio.h>
void my_scanf(char string[], char *c) {
    int i = 0;
    int found = 0;

    while (string[i] != '\0') {
        if (string[i] == '%' && string[i + 1] == 'c') {
            found = 1;
            *c = getchar();
            i += 2;
        } else {
            printf("%c", string[i]);
            i++;
        }
    }
}