/*
 * Project: hw5
 * Name   : Run Dong Lin
 * Date   : 04/02/2017
 * File   : negate.c
 * Notes  : Swap i and j references, then minus 5 from each.
 */

#include "swap.h"
#include "swapAndDrop.h"

void swapAndDrop(int *ip1, int *ip2, int n)
{
	
	swap(&(*ip1), &(*ip2));
	*ip1 -= 5;
	*ip2 -= 5;
}