// https://dodona.be/en/courses/5451/series/63967/activities/1850616268
#include <stdio.h>

int count_c(char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        return 0;
    }
    char c;
    int counter = 0;
    while ((c = fgetc(file)) != EOF) {
        if (c == 'c') {
            ++counter;
        }
    }
    fclose(file);
    return counter;
}