/*
 * Project: hw5
 * Name   : Run Dong Lin
 * Date   : 04/02/2017
 * File   : main.c
 * Notes  : The core of func call and printf.
 */ 
#include <stdio.h>
#include "swap.h"
#include "negate.h"
#include "swapAndDrop.h"

int main(void)
{
  int i = 5;
  int j = -10;

  printf("original:\n");
  printf("i : %d\nj : %d\n\n", i, j);

  swap(&i, &j);
  printf("swapped:\n");
  printf("i : %d\nj : %d\n\n", i, j);

  negate(&j);
  printf("negated j:\n");
  printf("i : %d\nj : %d\n\n", i, j);

  swapAndDrop(&i, &j, 5);
  printf("swapped and dropped by 5:\n");
  printf("i : %d\nj : %d\n\n", i, j);
}
