// https://dodona.be/en/courses/5451/series/63969/activities/970555492
int fac(int n) {
    int result = 1;
    loop:
        if (n > 1) {
            result *= n;
            n--;
            goto loop;
        }
    return result;
}