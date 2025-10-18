#include <stdio.h>
#include "my_and_or.h"
#include "my_strrchr.h"
#include "my_strpbrk.h"
#include "my_strcmp.h"
#include "string_span.h";

int main(void) {
    printf("%i", my_and(TRUE, TRUE));
    printf("%i", my_or(FALSE, FALSE));

    char *string = "www.vub.be";
    printf("%s", my_strrchr(string, '.'));

    char *p = my_strpbrk("Voorbeeld", "aeiou");
    printf("%s", p);
    printf("%i", my_strcmp("Scheme", "Scala"));
    printf("%i", my_strcmp("hello", "hellow"));

    char string1[] = "abcdefg";
    char accepted1[] = "fde";
    int length1;
    char *span1 = string_span(string1, accepted1, &length1);
    printf("%c", *span1);
    // length1 = 3 en span1 wijst naar het karakter 'd' in string1

    char string2[] = "ab_cdefg_cadg";
    char accepted2[] = "abcdef";
    int length2;
    char *span2 = string_span(string2, accepted2, &length2);
    printf("%c", *span2);
    // length2 = 4 en span2 wijst naar het eerste karakter 'c' in string2

    return 0;
}