// https://dodona.be/en/courses/5451/series/63963/activities/453498577
#include <stdlib.h>

char *substring(char *str1, char *str2) {
    while (*str1 != '\0') {
        char *temp_str1 = str1;
        char *temp_str2 = str2;
        while (*temp_str1 == *temp_str2 && *temp_str1 != '\0' && *temp_str2 != '\0') {
            temp_str1++;
            temp_str2++;
        }
        if (*temp_str2 == '\0') {
            return str1;
        }
        str1++;
    }
    return NULL;
}