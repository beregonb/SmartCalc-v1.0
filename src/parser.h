#ifndef PARSER_H
#define PARSER_H

typedef struct in_out {
  char *in;
  char *out;
} in_out;

typedef struct stack {
  char *str;
  struct stack *next;
} stack;


void readLine(char **str);
void memory_out(in_out *myStruct);
void parser(in_out *myStruct);
void out_copy(in_out *myStruct, char *str, int *lenght_out);
char *parser_sign_and_functions(in_out *myStruct, int *lenght_out,
                                int *lenght_in);
char *examination_functions(in_out *myStruct, int *lenght_in);
void operand(in_out *myStruct, int *i, int *lenght_out);
int priority(char *stack);
void push_stack_priority(stack **top, in_out *myStruct, char *stack,
                         int *lenght_out);

#endif