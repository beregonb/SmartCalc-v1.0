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
      parser_sign_and_functions(myStruct, &str, &lenght_out, &i);
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

void parser_sign_and_functions(in_out *myStruct, stack **str, int *lenght_out,
                               int *lenght_in) {
  int i = 0;
  if (strchr("+-*/m^cstal", myStruct->in[*lenght_in]) != NULL) {
    if (myStruct->in[*lenght_in] == '^') {
      *str = push(*str, "^");
    } else if (myStruct->in[*lenght_in] == '+') {
      *str = push(*str, "+");
    } else if (myStruct->in[*lenght_in] == '-') {
      *str = push(*str, "-");
    } else if (myStruct->in[*lenght_in] == '*') {
      *str = push(*str, "*");
    } else if (myStruct->in[*lenght_in] == '/') {
      *str = push(*str, "/");
    } else {
      int i = examination_functions(myStruct, lenght_in);
      if (i == 1) {
        *str = push(*str, "m");
      } else if (i == 2) {
        *str = push(*str, "C");
      } else if (i == 3) {
        *str = push(*str, "S");
      } else if (i == 4) {
        *str = push(*str, "q");
      } else if (i == 5) {
        *str = push(*str, "T");
      } else if (i == 6) {
        *str = push(*str, "c");
      } else if (i == 7) {
        *str = push(*str, "s");
      } else if (i == 8) {
        *str = push(*str, "t");
      } else if (i == 9) {
        *str = push(*str, "l");
      } else if (i == 10) {
        *str = push(*str, "L");
      } else {
        printf("Error\n");
      }
    }
    (*lenght_in)++;
  }
}
int examination_functions(in_out *myStruct, int *lenght_in) {
  int flag = 0;
  if (strncmp("mod", &myStruct->in[*lenght_in], 3) == 0) {
    flag = 1;
    (*lenght_in) += 2;
  }
  if (strncmp("cos", &myStruct->in[*lenght_in], 3) == 0) {
    flag = 2;
    (*lenght_in) += 2;
  }
  if (strncmp("sin", &myStruct->in[*lenght_in], 3) == 0) {
    flag = 3;
    (*lenght_in) += 2;
  }
  if (strncmp("sqrt", &myStruct->in[*lenght_in], 4) == 0) {
    flag = 4;
    (*lenght_in) += 3;
  }
  if (strncmp("tan", &myStruct->in[*lenght_in], 3) == 0) {
    flag = 5;
    (*lenght_in) += 2;
  }
  if (strncmp("acos", &myStruct->in[*lenght_in], 4) == 0) {
    flag = 6;
    (*lenght_in) += 3;
  }
  if (strncmp("asin", &myStruct->in[*lenght_in], 4) == 0) {
    flag = 7;
    (*lenght_in) += 3;
  }
  if (strncmp("atan", &myStruct->in[*lenght_in], 4) == 0) {
    flag = 8;
    (*lenght_in) += 3;
  }
  if (strncmp("log", &myStruct->in[*lenght_in], 3) == 0) {
    flag = 9;
    (*lenght_in) += 2;
  }
  if (strncmp("ln", &myStruct->in[*lenght_in], 2) == 0) {
    flag = 10;
    (*lenght_in) += 1;
  }
  return flag;
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
