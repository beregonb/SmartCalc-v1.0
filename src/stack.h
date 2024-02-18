#ifndef STACK_H
#define STACK_H

#include "parser.h"


//строки
stack *push(stack *top, const char *c);
stack *pop(stack *top);
char *peek(const stack *top);
int isEmpty(const stack *top);
void clear(stack **top);
void destroy(stack **top);
void free_stack_top(stack **top);

#endif