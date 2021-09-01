/*
 * Project : hw2
 * Name    : Run Dong Lin
 * Date    : 2/4/2017
 * File    : ordered.c
 * Notes   : N/A
 */

#include <stdio.h>
#include <ctype.h>
/* The ctype.h header is included so we can use the isspace() function.
   This function takes a character argument and returns a true value if
   the character is a whitespace character. */

/*
 * Read in a list of 1 or more single-digit numbers until reaching EOF.
 *   If the numbers are in ascending order, print, "True".
 *   Otherwise print "False".
 * Assume valid input.
 */
int main(void)
{
  /*
   * YOUR CODE HERE
   * Suggestions:
   * 1. Review how to scan characters from input
   * 2. Review how to convert a digit character to its value using '0'. 			*P.S: char c = getchar(), c - '0' = convert ascii value to numerical value.
   * 3. Keep track of the last digit you read in and the current one.
   * 4. Compare them. If they're out of order, you can just print False
   *    and return 0 to end execution of the program.
   * 5. Make sure to account for whitespace characters. You can use isspace()
   *    to test a character. If you store a scanned character in a variable c,
   *    isspace(c) will return a nonzero (i.e., true) value if c's value is
   *    the ascii code for a whitespace character.
   *
   * Test your code using the provided ordered1.in and ordered2.in files.
   * ./ordered < ordered1.in          should print True
   * ./ordered < ordered2.in          should print False
   */

	int a,b;
        a = getchar();
	for (int b = getchar(); b != EOF; b = getchar()) // scan.
	{
	  while (isspace(b)) // skip over white-space.
	  {
	    b = getchar();
	  }
	  while (isspace(a)) // skip over white-space.
	  {
	    a = getchar();
	  }
	  if (!isspace(b) && !isspace(a)) // if not white-space... getInt(), and compare.
	  {
		a-= '0'; // convert to numerical value;
		b-= '0'; // convert to numerical value;
	    if (a > b)
	    {
	      printf("False\n");
	      return 0;
	    }
	    a = b + '0'; // convert back to ascii for isspace() to check for white-space.
	  }
	}
	printf("True\n");
}
