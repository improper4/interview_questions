/*************************************************************************
    > File Name: m05.c
    > Author: improper4
    > Mail: improper4@gmail.com 
    > Created Time: Mon Jun  3 20:51:32 2013
 ************************************************************************/

#include "m100s.h"
void swap(int* a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int median3(int* a, int fr, int to){
	int ans;
	int mid = (fr + to)/2;
	if(a[fr] > a[mid])
		swap(&a[fr], &a[mid]);
	if(a[fr]> a[to])
		swap(&a[fr], &a[to]);
	if(a[mid] >a[to])
		swap(&a[mid], &a[to]);
	return mid;
}
int qSelect(int* a, int k, int from, int to){
	int x, i ,idx, ans;
	if(from > to)
		return -1;	//something wrong

	swap(&a[median3(a, from, to)], &a[from]);	// get the pivot
	idx = from;
	x = a[from];
	for(i = from + 1; i <= to; i++)
		if(a[i] < x)
			swap(&a[++idx], &a[i]);
	swap(&a[idx], &a[from]);

	if(idx+1 < k){
		ans = qSelect(a, k ,idx +1, to);
	}else if(idx + 1 > k){
		ans = qSelect(a,k,from,idx -1);
	}else{
		ans = a[idx];
	}
	return ans;
}

int minK(int * a, int len, int k){
	return qSelect(a, k, 0, len -1);
}

int main(){
	int arr[] = {12,32,97,6,45,77,23,33,
		85,66,19,37,89,14,76,90,1,36,11,7};
	printf("%d\n",minK(arr,20, 7));
}
