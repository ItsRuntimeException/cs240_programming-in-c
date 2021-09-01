#include <stdio.h>
#include "bitPractice.h"

int main(void)
{
  /*
  ****This file will not be collected.****

  Use it to write tests for the functions you implemented in bitPractice.c.

  For example, you might test eighth() like this:
    unsigned int num = 200;
    printf("one eighth of %u is:  %u\n", num, eighth(num));

  %u is the conversion code for an unsigned integer.
  */

	unsigned int num = 200;
	printf("one eighth of %u is:  %u\n", num, eighth(num));

	printf("Is nth bit on?:  %u\n", isNthBitOn(125, 4));
	printf("is even?: %u\n", isEven(num));
	printf("flip?: %u\n", flipLeading0s(170));
}
