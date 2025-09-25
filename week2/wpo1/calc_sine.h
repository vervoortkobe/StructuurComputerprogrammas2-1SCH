// https://dodona.be/en/courses/5451/series/63959/activities/465766777
#include <math.h>

double calc_sine_helper(double x, int n, int i) {
    if (i >= n) {
        return 0;
    } else {
        int exponent = i * 2 + 1;
        double numerator = pow(x, exponent);
        int denominator = fac(exponent);
        double term = numerator / denominator;
        if (i % 2 == 1) {
            return calc_sine_helper(x, n, i + 1) - term;
        } else {
            return calc_sine_helper(x, n, i + 1) + term;
        }
    }
}

double calc_sine(double x, int n) {
    return calc_sine_helper(x, n, 0);
}
