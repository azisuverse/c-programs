#ifndef NERD_CALC_H
#define NERD_CALC_H

// define macros for operation case
#define ADDITION 1
#define SUBTRACTION 2
#define MULTIPLICATION 3
#define DIVISION 4

// define macros for input and operation
#define INPUT_X int
#define INPUT_Y int
#define OPERATION int

// Calc struct
struct Calc
{
  INPUT_X x;
  INPUT_Y y;
  OPERATION op;
};

// typedef for Calc
typedef struct Calc calc_t;

// implements some math function
extern int addition(INPUT_X* x, INPUT_Y* y);
extern int subtraction(INPUT_X* x, INPUT_Y* y);
extern int multiplication(INPUT_X* x, INPUT_Y* y);
extern int division(INPUT_X* x, INPUT_Y* y);

// implements calculation function
void calculation(INPUT_X* x, INPUT_Y* y, OPERATION* op);

#endif  // NERD_CALC_H
