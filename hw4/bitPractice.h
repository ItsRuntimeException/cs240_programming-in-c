#ifndef BITPRACTICE_H
#define BITPRACTICE_H
/*
The above preprocessor directives are what is called an "include guard".

They prevent compilation errors due to the same header file being included
multiple times.
*/

/*
This macro contains the number of bits in an int for the current implementation.
The sizeof() operator returns the number of bytes required to store its
argument. We then multiply that by 8 (8 bits = 1 byte).
*/
#define INT_BITS sizeof(int) * 8

/*
Uses bitwise operations to determine whether or not a number is even.
args    : num (unsigned integer)
returns : 1 if num is even
          0 if num is odd
*/
unsigned int isEven(unsigned int num);


/*
Uses bitwise operations to return one eighth of an unsigned integer.
(note that result will be integer division result)
args    : num (unsigned integer)
returns : one eighth of num with fractional part of value discarded
*/
unsigned int eighth(unsigned int num);


/*
Uses bitwise operations to determine whether or not the nth bit is on (1).
args    : num (unsigned integer)
        : n (index of bit to check)
returns : 1 if nth bit in num has a value of 1
          0 if nth bit in num has a value of 0
*/
unsigned int isNthBitOn(unsigned int num, unsigned int n);


/*
Flips all leading 0s in input number.
args    : num (unsigned integer)
returns : num with all leading 0s flipped to 1
*/
unsigned int flipLeading0s (unsigned int num);

#endif
