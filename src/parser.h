#ifndef PARSER_H
#define PARSER_H

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct in_out {
  char *in;
  char *out;
  char *x;
} in_out;

typedef struct stack {
  char *str;
  struct stack *next;
} stack;

void check_length(const char *str, const char *x);
void memory_in(in_out *myStruct, const char *str);
void memory_x(in_out *myStruct, const char *str);
void memory_out(in_out *myStruct);

void parser(in_out *myStruct);
void out_copy(in_out *myStruct, char *str, int *lenght_out);
char *parser_sign_and_functions(in_out *myStruct, int *lenght_out,
                                int *lenght_in, int unar);
char *examination_functions(in_out *myStruct, int *lenght_in);
void operand(in_out *myStruct, int *i, int *lenght_out);
int priority(char *stack);
void push_stack_priority(stack **top, in_out *myStruct, char *stack,
                         int *lenght_out);

#endif