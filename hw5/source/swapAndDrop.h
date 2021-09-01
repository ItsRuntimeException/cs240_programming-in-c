#ifndef SWAPANDDROP_H
#define SWAPANDDROP_H

/*
Swap the values of two variables and subtract an int value from both.
args: ip1 - pointer to an int variable
      ip2 - pointer to an int variable
      n   - the amount to subtract

example:
int i = 0;
int j = 10;
int *ip = &i;
int *jp = &j;
swapAndDrop(ip, jp, 5);
result is that i = 5 and j = -5
*/
void swapAndDrop(int *ip1, int *ip2, int);

#endif
