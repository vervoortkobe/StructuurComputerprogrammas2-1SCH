// https://dodona.be/en/courses/5451/series/63959/activities/63145091
int fac(int n) {
    if (n < 2) {
        return 1;
    }
    return n * fac(n - 1);
}
