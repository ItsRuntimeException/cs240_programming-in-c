/*
 * Project: hw5
 * Name   : Run Dong Lin
 * Date   : 04/02/2017
 * File   : swap.c
 * Notes  : Swap i and j references.
 */ 
 
#include "swap.h"

void swap(int *pI, int *pJ)
{
	int temp; // temp var.
	
	temp = *pJ; // NOTE : ( * ) dereferences to whatever ipj is pointing to.
	*pJ = *pI;
	*pI =  temp;
}