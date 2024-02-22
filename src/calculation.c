#include "calculation.h"

#include "parser.h"
#include "stack.h"

double smart_calculation(const char *str, double x) {
  double result = 0;
  in_out myStruct = {NULL, NULL, NULL};

  char buffer[50];
  snprintf(buffer, sizeof(buffer), "%.2f", x);

  check_length(str, buffer);

  memory_in(&myStruct, str);
  printf("!!!%s!!!", buffer);
  memory_x(&myStruct, buffer);
  memory_out(&myStruct);

  printf("Input string: %s\n", myStruct.in);
  printf("Input string х: %s\n", myStruct.x);

  parser(&myStruct);
  printf("Output string: %s\n", myStruct.out);
  result = perser_calc(&myStruct, x);
  // Освобождение памяти после использования
  free(myStruct.in);
  free(myStruct.out);
  free(myStruct.x);

  return result;
}

double perser_calc(in_out *myStruct, double x) {
  double result = 0;
  stack *str = NULL;
  int i = 0;
  while (myStruct->out[i] != '\0') {
    if (isdigit(myStruct->out[i]) || myStruct->out[i] == 'x') {
      operand_calc(myStruct, &str, &i);
      printf("top - %s\n", peek(str));
    } else {
      printf("зашел\n");
      calculation(myStruct, &str, &i, x);
    }
    i++;
  }
  result = strtod(peek(str), NULL);
  destroy(&str);
  return result;
}

void calculation(in_out *myStruct, stack **top, int *i, double x) {
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
  printf("ВЕРХ%s\n", peek(*top));
  if (strcmp(peek(*top), "x") == 0) {
    a = x;

  } else {
    a = strtod(peek(*top), NULL);
  }
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
  if (strcmp(peek(*top), "x") == 0) {
    b = x;

  } else {
    b = strtod(peek(*top), NULL);
  }
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
         myStruct->out[*i] == ',' || myStruct->out[*i] == 'x') {
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
    result = fmod(b, a);
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

// int main() {
// for(double x = -5; x < 5; (x += 0.5)){
//   char str[] = "x^2";
//   double result;
//   result = smart_calculation(str, x);
//   printf("РЕЗУЛЬТАТ: %lf", result);
// }
//   return 0;
// }
