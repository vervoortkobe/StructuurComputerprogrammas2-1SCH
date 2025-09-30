//
// Created by vervo on 30/09/2025.
//

#include <stdio.h>

void print_spaces(int n) {
    while (n > 0) {
        printf(" ");
        n--;
    }
}

void print_stars(int n) {
    while (n > 0) {
        printf("*");
        n--;
    }
}

void print_christmas_tree_oplossing(int n) {
    int i = 1;
    while (i <= n) {
        print_spaces(n - i);
        print_stars(2 * i - 1);
        printf("\n");
        i++;
    }
    int j = 1;
    while (j <= 2) {
        print_spaces(n - 1);
        printf("*\n");
        j++;
    }
}