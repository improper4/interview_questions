/*************************************************************************
    > File Name: m28.c
    > Author: improper4
    > Mail: improper4@gmail.com 
    > Created Time: Sat Jun  8 19:03:37 2013
 ************************************************************************/

#include "m100s.h"

int howMany1(int x){
	int i = 0;
	while(x > 0){
		x &= x -1;
		i++;
	}
	return i;
}

int main(int argc, char* argv[]){
	printf("%d\n",howMany1(atoi(argv[1])));
}
