// https://dodona.be/en/courses/5451/series/63965/activities/1738596541
#include <stdlib.h>

int is_larger_than_10(int x);

int *filter(int *array, int *p_length, int (*f)(int)) {
    int *filtered_array = malloc(*p_length * sizeof(int));
    int filtered_array_length = 0;
    for (int idx = 0; idx < *p_length; idx++) {
        int element = array[idx];
        if (f(element)) {
            filtered_array[filtered_array_length] = element;
            filtered_array_length++;
        }
    }
    int *resized_array = malloc(filtered_array_length * sizeof(int));
    for (int idx = 0; idx < filtered_array_length; idx++) {
        resized_array[idx] = filtered_array[idx];
    }
    free(filtered_array);
    *p_length = filtered_array_length;
    return resized_array;
}

int is_larger_than_10(int x) {
    return x > 10;
}