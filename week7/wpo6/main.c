#include <stdio.h>
#include "lowercase.h"

int main(void) {
    char string[] = "HELLO WORLD";
    char *lowercase_string = lowercase(string);
    printf("%s\n", lowercase_string);
    free(lowercase_string);



    return 0;
}