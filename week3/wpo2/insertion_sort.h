// https://dodona.be/en/courses/5451/series/63960/activities/726260036

void insertion_sort(char string[]) {
    char gesorteerd[strlen(string) + 1];
    gesorteerd[strlen(string)] = '\0';
    gesorteerd[0] = string[0];

    for (int i = 1; i < strlen(string); i++) {
        char key = string[i];
        int j = i - 1;

        while (j >= 0 && key < string[j]) {
            string[j + 1] = string[j];
            j -= 1;
        }
        string[j + 1] = key;
        gesorteerd[j + 1] = key;
    }

    printf(gesorteerd);
}