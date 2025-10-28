// https://dodona.be/en/courses/5451/series/63964/activities/1997436939
#include <stdio.h>
#include <stdlib.h>

int *generate_primes(int n) {
  int *array = calloc(n, sizeof(int));
  int idx = 0;
  for (int i = 2; idx < n; i++) {
    int prime = 1;
    for (int j = 2; j < i; j++) {
      if (i % j == 0) {
        prime = 0;
        break;
      }
    }
    if (prime) {
      array[idx] = i;
      idx++;
    }
  }
  return array;
}

void print_primes(int n) {
  int i;
  for (i = 2; i < n; i++) {
    int prime = 1;
    int j;
    for (j = 2; j < i; j++) {
      if (i % j == 0) {
        prime = 0;
      }
    }
    if (prime) {
      printf("%i\n", i);
    }
  }
}

