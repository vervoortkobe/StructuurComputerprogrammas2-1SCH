// https://dodona.be/en/courses/5451/series/63962/activities/467311374
enum Boolean { FALSE, TRUE };
enum Boolean my_and(enum Boolean a, enum Boolean b) {
    return a * b;
}
enum Boolean my_or(enum Boolean a, enum Boolean b) {
    enum Boolean result = a + b;
    if (result > TRUE) {
        result = TRUE;
    }
    return result;
}