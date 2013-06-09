/*************************************************************************
    > File Name: m54.c
    > Author: improper4
    > Mail: improper4@gmail.com 
    > Created Time: Mon Jun 10 11:26:21 2013
 ************************************************************************/

#include "m100s.h"

void swap(int * a, int i, int j){
	int tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

void oddEven(int* a, int len){
	int i, j;
	j = 0;
	for(i = 0; i < len; i++){
		if(i % 2 == 0){
			j++;
			// swap
			swap(a, i, j);
		}
	}
	// swap
	swap(a, 0, j);
}
int main(){
	int i;
	int a[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
	oddEven(a, 15);
	for(i = 0; i < 15; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}
