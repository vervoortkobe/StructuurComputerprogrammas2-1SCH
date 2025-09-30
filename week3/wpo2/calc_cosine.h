// https://dodona.be/en/courses/5451/series/63960/activities/1334108571
#include <math.h>
int fac(int n); // Aan deze lijn moet je niets veranderen

double calc_cosine(double x, int n) {
    if (n == 0) return 0.0;
    if (n == 1) return 1.0;
    double output = 0.0;
    for (int i = 0; i <= n; i++) {
        output += (pow(-1, i) * (pow(x, 2 * i) / fac(2 * i)));
    }
    return output;
}