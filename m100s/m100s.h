/*************************************************************************
    > File Name: m100s.h
    > Author: improper4
    > Mail: improper4@gmail.com 
    > Created Time: Mon Jun  3 14:33:22 2013
 ************************************************************************/
#ifndef M100S_H
#define M100S_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdarg.h>
#include <ctype.h>

// my simple dbg funcs.

void mydbg(char* str, ...);
void myerr(char* str, ...);

#define IFOUT(X, NUMLINE)	\
{ \
	if(X == NULL) \
		myerr("OUTSPACE IN %d\n",NUMLINE); \
} 

#endif
