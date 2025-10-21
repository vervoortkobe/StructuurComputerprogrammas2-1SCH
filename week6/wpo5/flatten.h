// https://dodona.be/en/courses/5451/series/63963/activities/256700158
void flatten(int multi[][2], int single[], int length) {
    int idx = 0;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < 2; j++) {
            single[idx++] = multi[i][j];
        }
    }
}