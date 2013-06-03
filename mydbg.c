/*************************************************************************
    > File Name: mydbg.c
    > Author: improper4
    > Mail: improper4@gmail.com 
    > Created Time: Mon Jun  3 14:26:06 2013
 ************************************************************************/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#define MYDBG

void mydbg(const char* fmt,...){
#ifdef MYDBG
	va_list ap;
	va_start(ap,fmt);
	vprintf(fmt,ap);
	va_end(ap);
#endif
}

void myerr(const char* fmt,...){

	va_list ap;
	va_start(ap,fmt);
	vprintf(fmt,ap);
	va_end(ap);
	exit(127);
}
