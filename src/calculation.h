#ifndef CALCULATION_H
#define CALCULATION_H

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"
#include "stack.h"

double smart_calculation(const char *str, double x);

double perser_calc(in_out *myStruct, double x);
void operand_calc(in_out *myStruct, stack **top, int *i);
double function_func(double a, char *sign);
double function_math(double a, double b, char *sign);
void calculation(in_out *myStruct, stack **top, int *i, double x);

//стек для чисел

#endif
