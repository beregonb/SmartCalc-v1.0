#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack {
    char *str;
    struct stack* next;
} stack;

stack *push(stack *top, char *c);
stack *pop(stack *top);
char *peek(const stack *top);
int isEmpty(const stack* top);
void clear(stack** top);
void destroy(stack** top);



#endif