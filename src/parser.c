#include "parser.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

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
    free(myStruct->in);  // Освобождение памяти, если произошла ошибка
    exit(EXIT_FAILURE);
  }
}

void parser(in_out *myStruct) {
  stack *str = NULL;
  int i = 0;
  int lenght_out = 0;
  char *sign_stack = NULL;
  int unar = 1;
  while (myStruct->in[i] != '\0') {
    if (myStruct->in[i] == '(') {
      unar = 1;
    }
    if (isdigit(myStruct->in[i]) || myStruct->in[i] == '.' ||
        myStruct->in[i] == 'x') {
      operand(myStruct, &i, &lenght_out);
      unar = 0;
    } else {
      sign_stack = parser_sign_and_functions(myStruct, &lenght_out, &i, unar);
      if (sign_stack != NULL) {
        push_stack_priority(&str, myStruct, sign_stack, &lenght_out);
      }
    }
  }
  while (!isEmpty(str)) {
    if (strcmp(peek(str), "(") == 0) {
      str = pop(str);
    } else {
      out_copy(myStruct, peek(str), &lenght_out);
      str = pop(str);
    }
  }
  myStruct->out[lenght_out] = '\0';
}
void operand(in_out *myStruct, int *i, int *lenght_out) {
  int start = *i;
  while (isdigit(myStruct->in[*i]) || myStruct->in[*i] == '.' ||
         myStruct->in[*i] == 'x') {
    (*i)++;
  }
  int length = *i - start;
  char *number = malloc((length + 1) * sizeof(char));
  if (number == NULL) {
    fprintf(stderr, "Memory allocation error.\n");
    exit(EXIT_FAILURE);
  }

  strncpy(number, &myStruct->in[start], length);
  number[length] = '\0';

  out_copy(myStruct, number, lenght_out);

  free(number);
}

void out_copy(in_out *myStruct, char *str, int *lenght_out) {
  for (int j = 0; j < strlen(str); j++) {
    myStruct->out[*lenght_out] = str[j];
    (*lenght_out)++;
  }
  myStruct->out[*lenght_out] = ' ';  // Добавляем пробел после числа
  (*lenght_out)++;
}

char *parser_sign_and_functions(in_out *myStruct, int *lenght_out,
                                int *lenght_in, int unar) {
  char *sign = NULL;
  if (strchr("+-*/m^cstal()", myStruct->in[*lenght_in]) != NULL) {
    if (strchr("+-*/^()", myStruct->in[*lenght_in]) != NULL) {
      if (myStruct->in[*lenght_in] == '^') {
        sign = "^";
      } else if (myStruct->in[*lenght_in] == '+') {
        if (unar == 1) {
          out_copy(myStruct, "0", lenght_out);
        }
        sign = "+";
      } else if (myStruct->in[*lenght_in] == '-') {
        if (unar == 1) {
          out_copy(myStruct, "0", lenght_out);
        }
        sign = "-";
      } else if (myStruct->in[*lenght_in] == '*') {
        sign = "*";
      } else if (myStruct->in[*lenght_in] == '(') {
        sign = "(";
      } else if (myStruct->in[*lenght_in] == ')') {
        sign = ")";
      } else {
        sign = "/";
      }
    } else {
      sign = examination_functions(myStruct, lenght_in);
    }
    (*lenght_in)++;
  }
  return sign;
}

char *examination_functions(in_out *myStruct, int *lenght_in) {
  char *flag = NULL;
  if (strncmp("mod", &myStruct->in[*lenght_in], 3) == 0) {
    flag = "m";
    (*lenght_in) += 2;
  }
  if (strncmp("cos", &myStruct->in[*lenght_in], 3) == 0) {
    flag = "C";
    (*lenght_in) += 2;
  }
  if (strncmp("sin", &myStruct->in[*lenght_in], 3) == 0) {
    flag = "S";
    (*lenght_in) += 2;
  }
  if (strncmp("sqrt", &myStruct->in[*lenght_in], 4) == 0) {
    flag = "q";
    (*lenght_in) += 3;
  }
  if (strncmp("tan", &myStruct->in[*lenght_in], 3) == 0) {
    flag = "T";
    (*lenght_in) += 2;
  }
  if (strncmp("acos", &myStruct->in[*lenght_in], 4) == 0) {
    flag = "c";
    (*lenght_in) += 3;
  }
  if (strncmp("asin", &myStruct->in[*lenght_in], 4) == 0) {
    flag = "s";
    (*lenght_in) += 3;
  }
  if (strncmp("atan", &myStruct->in[*lenght_in], 4) == 0) {
    flag = "t";
    (*lenght_in) += 3;
  }
  if (strncmp("log", &myStruct->in[*lenght_in], 3) == 0) {
    flag = "l";
    (*lenght_in) += 2;
  }
  if (strncmp("ln", &myStruct->in[*lenght_in], 2) == 0) {
    flag = "L";
    (*lenght_in) += 1;
  }
  return flag;
}

int priority(char *stack) {
  int prior;
  if (strcmp(stack, "+") == 0 || strcmp(stack, "-") == 0) {
    prior = 1;
  } else if (strcmp(stack, "*") == 0 || strcmp(stack, "/") == 0 ||
             strcmp(stack, "m") == 0) {
    prior = 2;
  } else if (strcmp(stack, "^") == 0 || strcmp(stack, "~") == 0) {
    prior = 3;
  } else if (strcmp(stack, "C") == 0 || strcmp(stack, "S") == 0 ||
             strcmp(stack, "q") == 0 || strcmp(stack, "T") == 0 ||
             strcmp(stack, "c") == 0 || strcmp(stack, "s") == 0 ||
             strcmp(stack, "t") == 0 || strcmp(stack, "l") == 0 ||
             strcmp(stack, "L") == 0) {
    prior = 4;
  } else {
    prior = 0;
  }
  return prior;
}

void push_stack_priority(stack **top, in_out *myStruct, char *stack,
                         int *length_out) {
  if (isEmpty(*top) || (priority(stack) > priority(peek(*top))) ||
      strcmp(stack, "(") == 0) {
    *top = push(*top, stack);
  } else if (strcmp(stack, ")") == 0) {
    while (!isEmpty(*top) && strcmp(peek(*top), "(") != 0) {
      out_copy(myStruct, peek(*top), length_out);
      *top = pop(*top);
    }
    if (!isEmpty(*top) && strcmp(peek(*top), "(") == 0) {
      *top = pop(*top);
    }
  } else {
    while (!isEmpty(*top) && priority(stack) <= priority(peek(*top))) {
      out_copy(myStruct, peek(*top), length_out);
      *top = pop(*top);
    }
    *top = push(*top, stack);
  }
}
