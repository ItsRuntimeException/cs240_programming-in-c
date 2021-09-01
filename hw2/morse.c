/*
 * Project	: hw2
 * Name		: Run Dong Lin
 * Date		: 02/01/2017
 * File		: morse.c
 * Notes	: enter a string to be converted into morse code.
 *
 */

#include <stdio.h>

int main(void)
{
  char morse[]= 
		 "  .-\0"  "-...\0"  "-.-.\0"  " -..\0"  "   .\0"  "..-.\0"  /* a b c d e f */
         " --.\0"  "....\0"  "  ..\0"  ".---\0"  " -.-\0"  ".-..\0"  /* g h i j k l */
  	  	 "  --\0"  "  -.\0"  " ---\0"  ".--.\0"  "--.-\0"  " .-.\0"  /* m n o p q r */
  	  	 " ...\0"  "   -\0"  " ..-\0"  "...-\0"  " .--\0"  "-..-\0"  /* s t u v w x */
  	  	 "-.--\0"  "--..\0"  ;					     /* y z */

  int c;
  for (c = getchar(); c!= EOF; c = getchar()){
	if (c >= 'a' && c <= 'z')
	{
	  int i = c-'a';
	  printf("%c = %3s\n", c, &morse[5*i]);
	}
	else if (c == ' ')
	{
	  printf("\n");
	}
  }
}
