// https://dodona.be/en/courses/5451/series/63959/activities/2072643834
int ggd(int a, int b) {
    if (b == 0) {
        return a;
    }
    int c = a % b;
    return ggd(b, c);
}
