/*
 * Project : hw3
 * Name    : Run Dong Lin
 * Date    : 2/21/2017
 * File    : numReader.c
 * Notes   : Read decimal, hex, and octal ascii into numbers then perform addition(+) and return the total.
 */

#include <stdio.h>
#include "numReader.h"

/******************************************************************************
In this file we define the functions we declared in the numReader.h file.

There are several helper functions here that you can use in the lineValue
function.

Notice there is no main function in this file. We need to call these
functions in another file, often referred to as a driver.

In this case the driver is provided for you: sumLines.c

sumLines.c makes use of the lineValue function you'll define in this file
to read from an input file and calculate the total value of the numbers
on each line.
*******************************************************************************/

/*
getline1: read a line from stdin into the array s
          return length of line (not including '\0')
This is the code from K&R that we went over in class. Make sure you understand
what it is doing. Note that the constant MAX is declared in numReader.h and
you can assume no input line will be longer than MAX.
*/
int getline1(char s[], int lim)
{
  int c, i;
  for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

/*
lastCharIndex:
  args    : s (an input character array)
  returns : the index of the last non-newline character in the array
*/
int lastCharIndex(char s[])
{
	int i;
	for (i = 0; s[i] != '\n'; ++i)
	{
		;
	}
	return --i;
}

/*
power: raise base to n-th power; n >= 0

This code is from K&R. Make sure you understand how it works.
*/
int power(int base, int n)
{
  int i, p;
  p = 1;
  for (i = 1; i <= n; ++i) {
    p = p * base;
  }
  return p;
}

/*
validOctal determines if an ascii code is a valid octal digit
   args: c (an ascii code)
returns: 1 if c is 0 - 7
         0 otherwise
*/
int validOctal(int c)
{
	int num = c - '0';
	if (num >= 0 && num <= 7)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*
validDecimal determines if an ascii code is a digit
   args: c (an ascii code)
returns: 1 if c is 0 - 9
         0 otherwise
*/
int validDecimal(int c)
{
	if (c >= '0' && c <= '9')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*
validHexDigit determines if an ascii code is a hex digit
   args: c (an ascii code)
returns: 1 if c is 0 - 9 or A - F
         0 otherwise
*/
int validHex(int c)
{
	/*
  	  Note for this assignment all hex inputs will use capital letters.
  	  This means 0XFF is a valid hex number
  	  and 0xff is not.
	*/

	int num = c - '0';
	if ((num >= 0 && num <= 9) || (c >= 'A' && c <= 'F'))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*
Returns the decimal value of a hex digit.
Returns -1 if c is not a valid hex digit.
*/
int decValofHex(int c)
{
  /*
	Notes: --FOR LETTERS ONLY--

		   A = 10 (number value)
    	  'A' = 65 dec.
		  *if c = 'A', then c = 65, so c - 'A' + 10;
  */

	if (c >= 'A' && c <= 'F')
	{
		return (c - 'A' + 10);
	}
	else
	{
		if (c >= '0' && c <= '9')
		{
			return (c - '0');
		}
		else
		{
			return -1;
		}
	}
}

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
int lineValue(char line[])
{
  /*
  YOUR CODE HERE
  You'll need to provide control statements that process numbers with
  different bases appropriately.

  To determine the value of a number string we work backwards from the end of
  the string. We multiply each digit by the number's base to ascending powers,
  starting with 0. So, if we have the octal number 01234:
    We start with 4 and multiply by 8^0 = 4 * 1   =   4
             then 3                 8^1 = 3 * 8   =  24
             then 2                 8^2 = 2 * 64  = 128
             then 1                 8^3 = 1 * 512 = 512
             and sum them:       1 + 8 + 64 + 512 = 668

  We can determine the base by looking at the beginning of the string:
    -if it starts with 1-9 it's a decimal number
    -if it starts with 0, it could be octal or hex, depending on the second
     character
       -if the second character is an octal digit (0-7) it's octal
       -if the second character is an X, it's hex

  If at any point we find an invalid character, we can return -1.
  */

 int sum = 0;
 int count = 0;
 printf("\n");

	if (line[0] - '0' >= 1 && line[0] - '0' <= 9) // decimal == true.
	{
		for (int i = lastCharIndex(line); i >= 0; i--)
		{
			if (validDecimal(line[i]) == 1)
			{
				sum+= ((line[i] - '0') * power(10, count));
				count+= 1;
				printf("Debug@Index:%d  Debug_Value [dec]:%s  Debug_Per_Line-Sum:%d \n", i, &line[i], sum);
			}
			else
				return -1;
		}
			return sum;
	}
	else if (line[0] - '0' == 0) // if leading decimal is 0;
	{
	    if (validOctal(line[1]) == 1) // if octal == true.
		{
			for (int i = lastCharIndex(line); i > 0; i--)
			{
				if (validOctal(line[i]) == 1)
				{
					sum+= ((line[i] - '0') * power(8, count));
					count+= 1;
					printf("Debug@Index:%d  Debug_Value [oct]:%s  Debug_Per_Line-Sum:%d \n", i, &line[i], sum);
				}
				else
				{
					return -1;
				}
			}
				return sum;
		}
	    else if (line[1] == 'X') // if hex == true.
	    {
			for (int i = lastCharIndex(line); i > 1; i--)
			{
				if (validHex(line[i]) == 1)
				{
					sum+= (decValofHex(line[i]) * power(16, count));
					count+= 1;
					printf("Debug@Index:%d  Debug_Value [hex]:%s  Debug_Per_Line-Sum:%d \n", i, &line[i], sum);
				}
				else
				{
					return -1;
				}
			}
				return sum;
		}
		else
		{
			return -1;
		}
	}
	else
	{
		return -1;
	}
}
