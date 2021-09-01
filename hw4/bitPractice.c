/*
 * Project : hw4
 * Name    : Run Dong Lin
 * Date    : 3/3/2017
 * File    : bitPractice.c
 * Notes   : N/A
 */

#include "bitPractice.h"

/*
Uses bitwise operations to determine whether or not a number is even.
args    : num (unsigned integer)
returns : 1 if num is even
          0 if num is odd
*/
unsigned int isEven(unsigned int num)
{
	if ((num & 1) != 1)
		return 1; // even.
	else
		return 0; // odd.
}


/*
Uses bitwise operations to return one eighth of an unsigned integer.
(note that result will be integer division result)
args    : num (unsigned integer)
returns : one eighth of num with fractional part of value discarded
*/
unsigned int eighth(unsigned int num)
{
	return (num >> 3); // divide by 2^3 (8).
}


/*
Uses bitwise operations to determine whether or not the nth bit is on (1).
args    : num (unsigned integer)
        : n (index of bit to check)
returns : 1 if nth bit in num has a value of 1
          0 if nth bit in num has a value of 0
*/
unsigned int isNthBitOn(unsigned int num, unsigned int n)
{
	int i = 1 << n;

	if ((num & i) == i)
		return 1; // n-th bit is ON.
	else
		return 0; // n-th bit is OFF.
}



/*
Flips all leading 0s in input number.
args    : num (unsigned integer)
returns : num with all leading 0s flipped to 1
          Example input 2 returns 4294967294
                  2 = 00000000 00000000 00000000 00000010 
         4294967294 = 11111111 11111111 11111111 11111110
*/       
unsigned int flipLeading0s(unsigned int num)
{								     				   // --num----00000000 00000000 00000000 10101010 // 170
	unsigned int msb = 1 << INT_BITS-1;                // --msb-->>1------------------------>[1]0000000  HINT: Right shift to feed the 1 through to compare to num!
	unsigned int compare = num;	     				   // -compare-11111...0 00000000 00000000 10101010
													   //          00000000 00000000 00000000 10000000  --MASKING PROCEDURE;
	/*
	 * P.S: unsigned is very important, else the binary shift won't work
	 *
	 */
	 
	 
	/*
	 * MASKING PROCEDURE - mask lower bits except most significant bit.
	 */
	int i = 0;
	unsigned int n = num;
	while(n > 1) // keep shifting until 0001;
	{
		n >>= 1;
		i++;
		if(n == 1)
		{
			n <<= i;
			break;
		}
	}
	
	while ((msb^n) != 0) /* num ^ msb return 0010 ^ 0010 == 0 stop looping, else keep looping. (HINT ABOVE) */
	{
		compare |= msb;
		msb >>= 1;
	}
	return compare;
}
