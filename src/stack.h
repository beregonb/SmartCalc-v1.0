#ifndef STACK_H
#define STACK_H

#define INIT_SIZE 10
#define MULTIPLIER 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack {
    char *str;
    struct stack* next;
} stack;

stack *push(stack *top, char *c);
stack *pop(stack *top);

#endif