// https://dodona.be/en/courses/5451/series/63966/activities/1902492731
#include "stack.h" // Je kan gebruik maken van alle stackoperatie functies die je in hoofdstuk 3c gezien hebt voor de derde stack variant
#include <stdio.h>
#define STACK_SIZE 25

Stack createstack(size_t, int);
void destroystack(Stack);
int emptystack(Stack);
void push(Stack, void *);
void pop(Stack, void *);
void top(Stack, void *);
void printstackcontent(Stack, void (*display)(void *));
void printchar(void *vpi);

int check_balanced_brackets(char *string) {
    Stack stack = createstack(sizeof(char), STACK_SIZE);

    while (*string) {
        char current = *string;
        char last;

        switch (current) {
            case '{':
            case '(':
            case '[':
            case '<':
                push(stack, string);
                break;
            case '}':
                pop(stack, &last);
                if (last != '{') return 0;
                break;
            case ')':
                pop(stack, &last);
                if (last != '(') return 0;
                break;
            case ']':
                pop(stack, &last);
                if (last != '[') return 0;
                break;
            case '>':
                pop(stack, &last);
                if (last != '<') return 0;
                break;
        }
        string++;
    }
    return emptystack(stack);
}