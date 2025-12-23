// https://dodona.be/en/courses/5451/series/63970/activities/725417876
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replace_line(char *path, int line_nr, char *new_line) {
    char file_buffer[1000];
    char *file_buffer_pointer = file_buffer;
    FILE *file = fopen(path, "r");
    char line_buffer[100];
    int nr_of_lines_encountered = 0;
    while (fgets(line_buffer, 100, file) != NULL) {
        if (nr_of_lines_encountered == line_nr) {
            strcpy(file_buffer_pointer, new_line);
            file_buffer_pointer += strlen(new_line);
        } else {
            strcpy(file_buffer_pointer, line_buffer);
            file_buffer_pointer += strlen(line_buffer);
        }
        nr_of_lines_encountered++;
    }
    fclose(file);
    file = fopen(path, "w");
    fputs(file_buffer, file);
    fclose(file);
}