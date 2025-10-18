// https://dodona.be/en/courses/5451/series/63962/activities/1996148750
#include <stddef.h>
#include <string.h>

char *my_strrchr(char *string, char c) {
    char *p = string + strlen(string);
    while (p >= string) {
        if (*p == c) {
            return p;
        }
        p--;
    }
    return NULL;
}
