/*
This is a header file. It can contain function declarations and macros,
but nothing that causes memory to be allocated.

We will #include this file in the numReader.c file, which means that all the
functions in that file are declared and we can define them without declaring
them in that file.

Once we have all of our functions defined in numReader.c, we can include this
header file in other source files and have access to the functions declared
here. If we include this header file in another source file, we'll need
to provide numReader.c when we compile it so that the compiler has access to
our function definitions.

For our custome header files, the include directive looks like this:
#include "numReader.h"

Notice the quotation marks instead of angle brackets. This tells the
compile to look for the header file in a different way then it looks for
standard library header files. We'll cover this later.
*/

// note that we can declare a constant with a macro here as it does not
// cause any memory to be allocated.
#define MAX 1000

/*
getline1: read a line into s
          return length of line (not including '\0')
*/
int getline1(char s[], int lim);

/*
lastCharIndex:
  args    : s (an input character array)
  returns : the index of the last non-newline character in the array
*/
int lastCharIndex(char s[]);

/*
power: raise base to n-th power; n >= 0
*/
int power(int base, int n);

/*
validOctal determines if an ascii code is a valid octal digit
   args: c (an ascii code)
returns: 1 if c is 0 - 7
         0 otherwise
*/
int validOctal(int c);

/*
validDecimal determines if an ascii code is a digit
   args: c (an ascii code)
returns: 1 if c is 0 - 9
         0 otherwise
*/
int validDecimal(int c);

/*
validHexDigit determines if an ascii code is a hex digit
   args: c (an ascii code)
returns: 1 if c is 0 - 9 or A - F
         0 otherwise
*/
int validHex(int c);

/*
Returns the decimal value of a hex digit.
Returns -1 if c is not a valid hex digit.
*/
int decValofHex(int c);

/*
Converts input character array to a decimal value.
For an input array to be valid, the following must be true:
  -the array must contain only a number and newline character
  -the number must be in octal, decimal, or hex
  -if the number is in hex, the letter component must be capitalized
   args : line (character array to convert)
returns : decimal value of a valid input array
          -1 if the input array is not valid
*/
int lineValue(char line[]);
