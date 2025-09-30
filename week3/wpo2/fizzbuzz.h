// https://dodona.be/en/courses/5451/series/63960/activities/379956850
#include <stdio.h>

void fizzbuzz(int n) {
    for (int i = 1; i < 20; i++) {
        if (i % 3 == 0 && i % 5 == 0)
            printf("%d: FizzBuzz\n", i);
        else if (i % 3 == 0)
            printf("%d: Fizz\n", i);
        else if (i % 5 == 0)
            printf("%d: Buzz\n", i);
    }
}