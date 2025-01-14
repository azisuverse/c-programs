#include <stdio.h>
#include <stdlib.h>

#include "calc.h"
#include "util.h"

int main(void)
{
  calc_t* nc;
  int q = 0;

  nc = (calc_t*)malloc(sizeof(calc_t));

  while (q != 1)
  {
    printf("============ NERD CALC ===========");
    printf("\n");

    printf(
        "Choose one of the number of these operators:\n1. +\t2. -\n3. x\t4. "
        "÷\nChoose: ");

    validate_operation_choice(&nc->op);

    printf("Add first num: ");
    validate_input_choice(&nc->x);

    printf("Add last num: ");
    validate_input_choice(&nc->y);

    calculation(&nc->x, &nc->y, &nc->op);

    printf("============ NERD CALC ===========");
    printf("\n");

    q++;
  }
  free(nc);
  return 0;
}
