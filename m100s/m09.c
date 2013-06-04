/*************************************************************************
    > File Name: m09.c
    > Author: improper4
    > Mail: improper4@gmail.com 
    > Created Time: Tue Jun  4 16:06:33 2013
 ************************************************************************/

#include "m100s.h"
int helper(int* a, int fr, int to){
	int i, k;
	if(fr == to +1 || fr == to)
		return 1;

	for(i = to- 1; i >= fr && a[i] > a[to]; i--)
		;
	if (!helper(a, i+1, to-1))
			return 0;
	for(k = i;k >= fr && a[k] < a[to]; k--)
		;
	if(k +1 != fr)
		return 0;
	return helper(a,fr, i);
}
int isMatch(int* a, int len){
	return helper(a, 0, len-1);
}
int main(){
	int a[] = {0,2,4,3,7,9,8,10,6,5,1};
	if(isMatch(a, 11))
		printf("YES!\n");
	else
		printf("NO!\n");
}
