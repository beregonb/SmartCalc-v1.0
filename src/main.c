#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *result;
  result = malloc(100 * sizeof(char));

  stack *str = NULL;

  str = push(str, "3");
  str = push(str, "cos");
  str = push(str, "5");
  str = push(str, "ct");

  int i = 0;
  while (str) {
    if (str) {
      strcpy(result + i, str->str);
      i += strlen(str->str);
    }
    str = pop(str);
  }

  result[i] = '\0'; // Добавляем завершающий нуль-символ

  printf("Result: %s\n", result);

  free(result);
  return 0;
}
