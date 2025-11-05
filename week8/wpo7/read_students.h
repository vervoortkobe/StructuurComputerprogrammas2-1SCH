// https://dodona.be/en/courses/5451/series/63965/activities/1157212962
#include <stdlib.h>
#include <stdio.h>

struct Student {
    int id;
    float average;
};

struct Student **read_students(int n) {
    struct Student **array = malloc(n * sizeof(struct Student *));
    for (int i = 0; i < n; i++) {
        struct Student *student = malloc(sizeof(struct Student));
        scanf("%i %f", &student->id, &student->average);
        array[i] = student;
    }
    return array;
}

void deallocate_students(struct Student **students, int n) {
    for (int i = 0; i < n; i++) {
        free(students[i]);
    }
    free(students);
}
