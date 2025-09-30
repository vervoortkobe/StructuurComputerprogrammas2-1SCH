// https://dodona.be/en/courses/5451/series/63960/activities/544298707
#include <stdio.h>

#include <stdio.h>

void print_christmas_tree(int n) {
  for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n - i; j++) {
          printf(" ");
      }
      if (i == 1) {
          printf("*");
      } else {
          for (int j = 1; j <= 2 * i - 1; j++) {
              printf("*");
          }
      }
      printf("\n");
  }

  for (int h = 0; h < 2; h++) {
      for (int i = 0; i < n - 1; i++) {
          printf(" ");
      }
      printf("*\n");
  }
}