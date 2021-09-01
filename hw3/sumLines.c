#include <stdio.h>
#include "numReader.h"


/*
This program reads from input. For each line that is comprised of a string
containing a valid number, it converts the string to an integer and adds it
to a running total. It then prints the total.

Notice that we've included numReader.h. This means that when we compile this
source code, we must provide the numReader.c file as well, since it contains
the definitions of the functions declared in numReader.h. We can do this as
follows:
gcc sumLines.c numReader.c -o sumLines

We've only used getLine1 and lineValue, but we could have used any of the
other functions declared in numReader.h and defined in numReader.c.
*/
int main(void)
{
  char line[MAX];  // the array where we store lines as they are read
  int total = 0;   // our running total
  int current = 0; // the value of the current line

  // this loop executes until there are no lines left in input
  while(getline1(line, MAX) != 0)
  {
    current = lineValue(line);  // store the value of the current line
    if (current >= 0) 			// current is -1 if the line was not valid
    {
      total += current;         // add valid value to running total
    }
  }
  printf("----------------------------------------------\n----------------------------------------------\n");
  printf("Total is: %d\n", total);  // output result
}
