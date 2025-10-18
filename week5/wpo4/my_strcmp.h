// https://dodona.be/en/courses/5451/series/63962/activities/1364768428
int my_strcmp(char str_1[], char str_2[]) {
    for (; ; str_1++, str_2++) {
        char c_1 = *str_1;
        char c_2 = *str_2;
        if (c_1 == '\0' && c_2 == '\0') {  // fixed == instead of =
            return 0;
        } else if (c_1 == c_2) {
            continue;
        } else {
            return c_1 - c_2;
        }
    }
}
