// https://dodona.be/en/courses/5451/series/63964/activities/1882048874
#include <stdlib.h>

float *calculate_all_averages(float **all_grades, int *all_lengths, int nr_of_students) {
    float *all_averages = (float *)malloc(nr_of_students * sizeof(float));
    for (int i = 0; i < nr_of_students; ++i) {
        float sum = 0.0;
        for (int j = 0; j < all_lengths[i]; ++j) {
            sum += all_grades[i][j];
        }
        all_averages[i] = sum / all_lengths[i];
    }
    return all_averages;
}