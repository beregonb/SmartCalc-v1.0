#include "calculation.h"

#include "parser.h"
#include "stack.h"

void perser_calc(in_out *myStruct) {
  stack *str = NULL;
  int i = 0;
  while (myStruct->out[i] != '\0') {
    if (isdigit(myStruct->out[i])) {
      operand_calc(myStruct, &str, &i);
      printf("top - %s\n", peek(str));
    } else {
      printf("зашел\n");
      calculation(myStruct, &str, &i);
    }
    i++;
  }
  printf("%s\n", peek(str));
  destroy(&str);
}

void calculation(in_out *myStruct, stack **top, int *i) {
  //разделить на унарные и бинарные рассчеты
  int start = *i;
  double a, b, result;
  char str[20];
  while (myStruct->out[*i] != ' ') {
    (*i)++;
  }
  int length = *i - start;
  char *sign = malloc((length + 1) * sizeof(char));
  strncpy(sign, &myStruct->out[start], length);
  sign[length] = '\0';
   printf("%s",peek(*top));
  a = strtod(peek(*top), NULL);
  *top = pop(*top);
  printf("sign = %s\n", sign);
  if (strcmp(sign, "C") == 0 || strcmp(sign, "S") == 0 ||
      strcmp(sign, "q") == 0 || strcmp(sign, "T") == 0 ||
      strcmp(sign, "c") == 0 || strcmp(sign, "s") == 0 ||
      strcmp(sign, "t") == 0 || strcmp(sign, "l") == 0 ||
      strcmp(sign, "L") == 0) {
    printf("a = %lf\n", a);
    result = function_func(a, sign);
    printf("resultUN = %lf\n", result);
  } else {
    
    b = strtod(peek(*top), NULL);
    printf("a = %lf\n", a);
    printf("b = %lf\n", b);
    *top = pop(*top);
    result = function_math(a, b, sign);
    printf("resultBIN = %lf\n", result);
  }
  snprintf(str, sizeof(str), "%lf", result);
  *top = push(*top, str);
  free(sign);
}

void operand_calc(in_out *myStruct, stack **top, int *i) {
  int start = *i;
  while (isdigit(myStruct->out[*i]) || myStruct->out[*i] == '.' ||
         myStruct->out[*i] == 'x') {
    (*i)++;
  }
  int length = *i - start;
  char *number = malloc((length + 1) * sizeof(char));
  if (number == NULL) {
    fprintf(stderr, "Memory allocation error.\n");
    exit(EXIT_FAILURE);
  }
  strncpy(number, &myStruct->out[start], length);
  number[length] = '\0';
  printf("number = %s\n", number);
  *top = push(*top, number);

  free(number);
}

double function_math(double a, double b, char *sign) {
  double result;
  if (strcmp(sign, "+") == 0) {
    result = a + b;
  } else if (strcmp(sign, "-") == 0) {
    result = b - a;
  } else if (strcmp(sign, "*") == 0) {
    result = a * b;
  } else if (strcmp(sign, "/") == 0) {
    result = b / a;
  } else if (strcmp(sign, "m") == 0) {
    result = fmod(a, b);
  } else {
    result = pow(b, a);
  }
  return result;
}

double function_func(double a, char *sign) {
  double result;
  if (strcmp(sign, "C") == 0) {
    result = cos(a);
  } else if (strcmp(sign, "S") == 0) {
    result = sin(a);
  } else if (strcmp(sign, "T") == 0) {
    result = tan(a);
  } else if (strcmp(sign, "q") == 0) {
    result = sqrt(a);
  } else if (strcmp(sign, "c") == 0) {
    result = acos(a);
  } else if (strcmp(sign, "s") == 0) {
    result = asin(a);
  } else if (strcmp(sign, "t") == 0) {
    result = atan(a);
  } else if (strcmp(sign, "l") == 0) {
    result = log10(a);
  } else {
    result = log(a);
  }
  return result;
}

int main() {
  in_out myStruct = {NULL, NULL};
  printf("Enter input string: ");
  readLine(&(myStruct.in));
  memory_out(&myStruct);

  // Выделение памяти и инициализация для строки out (по вашему желанию)

  printf("Input string: %s\n", myStruct.in);

  parser(&myStruct);
  printf("Output string: %s\n", myStruct.out);
  perser_calc(&myStruct);

  // Освобождение памяти после использования
  free(myStruct.in);
  free(myStruct.out);

  return 0;
}
