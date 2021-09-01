/*
 * Project : hw2
 * Name    : Run Dong Lin
 * Date    : 2/4/2017
 * File    : asciiaverage.c
 * Notes   : Prints the avg. ascii value of chars in a string of inputs "something ...", so like c = getchar(), add that, and accumulate then divide.
 * 			 P.S. : I got 2 variables already told to me, use total for accumulate, and numchars to keep track of chars in a string, including space (\n).
 */

#include <stdio.h>

/*
Prints the average ascii value of the characters in an input string.
Note that newline '\n' has an ascii value of 10
(linefeed or LF in the ascii table)
*/
int main(void)
{
  int total, numchars;
  total = numchars = 0;

  for (int c = getchar(); c != EOF; c = getchar())
  {
    total+=c;
    ++numchars;
  }

  /*
  The output line uses casting to avoid integer division.
  Use the variables listed (total and numchars) to track your total ascii
  value and the number of charactes you've read.

  You can test your code by compiling this program to wordaverage and
  running the following:
  ./asciiaverage < asciiaverage.in
  This executes your program with the contents of the file asciiaverage.in as
  the input. You should get the following output:
  Average character value: 50.00
  */
  printf("Average character value: %.2f\n", (double)total/numchars);
}
