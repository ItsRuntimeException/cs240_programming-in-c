# Project: hw5
# Name   : Run Dong Lin
# Date   : 04/02/2017
# File   : makefile.file
# Notes  : Makes an .file executable for testing.

cc = gcc
CFLAGS = -m32

main:	main.o negate.o swap.o swapAndDrop.o
		$(cc) $(CFLAGS) -g -o main main.o negate.o swap.o swapAndDrop.o

main.o:			main.c
				$(cc) $(CFLAGS) -c -o main.o main.c
negate.o:		negate.c negate.h
				$(cc) $(CFLAGS) -c -o negate.o negate.c
swap.o:			swap.c swap.h
				$(cc) $(CFLAGS) -c -o swap.o swap.c
swapAndDrop.o: 	swapAndDrop.c swapAndDrop.h swap.h
				$(cc) $(CFLAGS) -c -o swapAndDrop.o swapAndDrop.c
				
clean:
		rm *.o