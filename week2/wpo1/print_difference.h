// https://dodona.be/en/courses/5451/series/63959/activities/1775322514
void print_difference(int h1, int m1, int s1, int h2, int m2, int s2) {
    int total_seconds1 = h1 * 3600 + m1 * 60 + s1;
    int total_seconds2 = h2 * 3600 + m2 * 60 + s2;
    int diff = total_seconds1 - total_seconds2;
    if (diff < 0) {

        h2 = abs(diff) / 3600;
        diff %= 3600;
        m2 = abs(diff) / 60;
        s2 = abs(diff) % 60;

        printf("%d uren, %d minuten, %d seconden", h2, m2, s2);
        return;
    }
    h1 = abs(diff) / 3600;
    diff %= 3600;
    m1 = abs(diff) / 60;
    s1 = abs(diff) % 60;

    printf("%d uren, %d minuten, %d seconden", h1, m1, s1);
}