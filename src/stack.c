#include "stack.h"

stack *push(stack *top, char *c) {
  stack *new = malloc(sizeof(stack));
  new->str = c;
  new->next = top;
  return new;
}

stack *pop(stack *top) {
  if (top == NULL) {
    return top;
  }
  printf("Del: - %s\n", top->str);
  stack *new_top = top->next;
  free(top);

  return new_top;
}