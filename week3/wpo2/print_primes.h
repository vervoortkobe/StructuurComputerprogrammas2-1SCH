// https://dodona.be/en/courses/5451/series/63960/activities/186115338
#include <stdio.h>

void print_primes(int x) {
    for (int i = 2; i <= x; i++) {
        int is_prime = 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime) {
            printf("%d\n", i);
        }
    }
}

void print_primes_oplossing(int x) {
    int i = 2;
    while (i < x) {
        //loop over alle getallen van 2 tot x
        int prime = 1;
        // prime == 1 -> i is een priemgetal
        // ga er eerst van uit dat i inderdaad priem is
        int j = 2;
        while (j < i) {
            // zoek een getal waardoor i deelbaar is
            if (i % j == 0) {
                // i deelbaar door j, dus toch niet priem
                prime = 0;
            }
            j++;
        }
        if (prime) {
            printf("%i\n", i);
        }
    i++;
    }
}