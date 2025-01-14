#include "util.h"

#include <stdio.h>
#include <stdlib.h>

// validate_input_choice
void validate_input_choice(int* in)
{
  int result;
  result = scanf("%d", in);

  // check if the result is not a number
  if (result != 1)
  {
    printf("Input is not a number!\nProgram stopped.\n");

    while (getchar() != '\n');
    exit(1);
  }
}

// validate_operation_choice
void validate_operation_choice(int* op)
{
  char result_op;
  result_op = scanf("%d", op);

  // check if the result_op is not a number
  if (result_op != 1)
  {
    printf("Choice is not a number!\nProgram stopped.");

    while (getchar() != '\n');
    exit(1);
  }
}
