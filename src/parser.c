#include "parser.h"
#include "stack.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Функция для чтения строки и выделения памяти
void readLine(char **str) {
  size_t bufferSize = 0;
  size_t bytesRead = getline(str, &bufferSize, stdin);

  if (bytesRead == -1) {
    fprintf(stderr, "Error reading input.\n");
    exit(EXIT_FAILURE);
  }

  // Убираем символ новой строки, если он был считан
  if ((*str)[bytesRead - 1] == '\n') {
    (*str)[bytesRead - 1] = '\0';
  }
}

void memory_out(in_out *myStruct) {
  myStruct->out = malloc((strlen(myStruct->in) + 1) * sizeof(char));
  if (myStruct->out == NULL) {
    fprintf(stderr, "Memory allocation error.\n");
    free(myStruct->in); // Освобождение памяти, если произошла ошибка
    exit(EXIT_FAILURE);
  }
}

void parser(in_out *myStruct) {
  stack *str = NULL;
  int i = 0;
  int lenght_out = 0;
  while (myStruct->in[i] != '\0') {
    if (isdigit(myStruct->in[i])) {

      int start = i;
      while (isdigit(myStruct->in[i])) {
        i++;
      }
      int length = i - start;
      char *number = malloc((length + 1) * sizeof(char));
      if (number == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
      }

      strncpy(number, &myStruct->in[start], length);
      number[length] = '\0';

      out_copy(myStruct, number, &lenght_out);

      free(number);
    } else {
      str = push(str, "+");
      i++;
      printf("Top element of the stack: %s\n", peek(str));
    }
  }
  out_copy(myStruct, peek(str), &lenght_out);
}

void out_copy(in_out *myStruct, char *str, int *lenght_out) {

  for (int j = 0; j < strlen(str); j++) {
    myStruct->out[*lenght_out] = str[j];
    (*lenght_out)++;
  }
  myStruct->out[*lenght_out] = ' '; // Добавляем пробел после числа
  (*lenght_out)++;
}

int main() {
  in_out myStruct;

  printf("Enter input string: ");
  readLine(&(myStruct.in));
  memory_out(&myStruct);

  // Выделение памяти и инициализация для строки out (по вашему желанию)

  printf("Input string: %s\n", myStruct.in);

  parser(&myStruct);
  printf("Output string: %s\n", myStruct.out);

  // Освобождение памяти после использования
  free(myStruct.in);
  free(myStruct.out);

  return 0;
}
