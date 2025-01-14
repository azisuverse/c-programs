#include "calc.h"

#include <stdio.h>
#include <stdlib.h>

// addition function
int addition(int *x, int *y) { return (*x) + (*y); }

// subtraction function
int subtraction(int *x, int *y) { return (*x) - (*y); }

// multiplication function
int multiplication(int *x, int *y) { return (*x) * (*y); }

// division function
int division(int *x, int *y) { return *y == 0 ? *x : (*x) / (*y); }

// calculation function
void calculation(int *x, int *y, int *op)
{
  int *result;
  result = (int *)malloc(sizeof(int));
  switch (*op)
  {
    // addition = 1
    case ADDITION:
      *result = addition(x, y);
      printf("The result of %d + %d is: %d\n", *x, *y, *result);
      break;
    // subtraction = 2
    case SUBTRACTION:
      *result = subtraction(x, y);
      printf("the result of %d - %d is: %d\n", *x, *y, *result);
      break;
    // multiplication = 3
    case MULTIPLICATION:
      *result = multiplication(x, y);
      printf("the result of %d x %d is: %d\n", *x, *y, *result);
      break;
    // division = 4
    case DIVISION:
      *result = division(x, y);
      printf("the result of %d x %d is: %d\n", *x, *y, *result);
      break;
    // default
    default:
      return;
  }
  free(result);
}
