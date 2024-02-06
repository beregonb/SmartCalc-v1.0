#ifndef CALCULATION_H
#define CALCULATION_H

#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "parser.h"

void perser_calc(in_out *myStruct);
void operand_calc(in_out *myStruct, stack **top, int *i);
double function_math(double a, double b, char *sign);
void calculation(in_out *myStruct, stack **top, int *i);




//стек для чисел



#endif
