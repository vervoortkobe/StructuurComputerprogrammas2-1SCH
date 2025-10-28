// https://dodona.be/en/courses/5451/series/63964/activities/686918398
#include <stdio.h>
#include <stdlib.h>

#include <ctype.h>
#include <string.h>

char *lowercase(char *string) {
    int string_length = strlen(string);
    char *new_string = malloc((string_length + 1) * sizeof(char)); //lengte van de string + 1 voor de null byte vanachter!
    if (new_string != NULL) {
        for (int i = 0; i < string_length; i++) {
            char c = string[i];
            char lowercase_c = tolower(c);
            new_string[i] = lowercase_c;
        }
        new_string[string_length] = '\0';
        return new_string;
    } else {
        return NULL;
    }
}