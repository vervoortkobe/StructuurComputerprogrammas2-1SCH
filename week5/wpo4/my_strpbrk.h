// https://dodona.be/en/courses/5451/series/63962/activities/578207579
#include <stddef.h>

char *my_strpbrk(char *string1, char *string2) {
    while (*string1 != '\0') {
        char *curr_str2 = string2;
        while (*curr_str2 != '\0') {
            if (*string1 == *curr_str2) {
                return string1;
            }
            curr_str2++;
        }
        *string1++;
    }
    return NULL;
}