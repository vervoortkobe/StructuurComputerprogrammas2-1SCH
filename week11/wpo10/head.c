// https://dodona.be/en/courses/5451/series/63967/activities/910442311
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LINE_SIZE 1000

void head(char *file_path) {
    FILE *file = fopen(file_path, "r");
    if(file == NULL) {
        return;
    }

    for (int i = 0; i < 10; i++) {
        char buffer[MAX_LINE_SIZE];
        if(fgets(buffer, MAX_LINE_SIZE, file) != NULL) {
            printf("%s", buffer);
        } else {
            break;
        }
    }
    fclose(file);
}