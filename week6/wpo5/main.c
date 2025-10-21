#include <stdio.h>
#include "flatten.h"
#include "substring.h"
#include "increment_day.h"
#include "encode_decode.h"

int main(void) {
    int multi[][2] = {{1, 2},{3, 4},{5, 6},{7, 8}};
    int length = sizeof(multi) / sizeof(multi[0]);
    int single[length * 2];
    flatten(multi, single, length);

    char *string1 = "abcdefgh";
    char *string2 = "def";
    char *result = substring(string1, string2);
    printf("%p", &result);

    struct date d = {.year = 2020, .month = 10, .day = 31};
    increment_day(&d);

    printf("%i", encode((struct Small_Point){3, 5}));
    printf("%s", decode(0b10100101));

    return 0;
}