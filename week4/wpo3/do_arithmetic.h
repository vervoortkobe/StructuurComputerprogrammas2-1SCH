// https://dodona.be/en/courses/5451/series/63961/activities/378909611
void do_arithmetic(float numbers[], int length, float *p_sum, float *p_product, int *p_contains_42) {
    *p_sum = 0;
    *p_product = 1;
    *p_contains_42 = 0;
    for (int i = 0; i < length; i++) {
        *p_sum += numbers[i];
        *p_product *= numbers[i];
        if (numbers[i] == 42 || numbers[i] == 42.0)
            *p_contains_42 = 1;
    }
}