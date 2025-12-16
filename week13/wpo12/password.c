#include <stdio.h>
void read_password(char *password) {
    int i = 0;
    char c;
    while  ((c = getchar()) != '\n') {
    password[i] = c;
        i++;
    }
    password[i] = '\0';
}