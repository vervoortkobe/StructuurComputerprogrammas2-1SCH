// https://dodona.be/en/courses/5451/series/63961/activities/224857719

void convert_whitespace(char string[]) {
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == '\t' || string[i] == '\n' || string[i] == ' ') {
            string[i] = '_';
        }
    }
}