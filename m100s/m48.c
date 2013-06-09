/*************************************************************************
    > File Name: 48.c
    > Author: improper4
    > Mail: improper4@gmail.com 
    > Created Time: Sun Jun  9 19:31:03 2013
 ************************************************************************/

#include "m100s.h"
int helper(int x, int* a, int fr , int to){
	int ans = -1;
	int mid = (fr + to)/ 2;
	if(fr <= to){
		if(a[mid]> a[fr]){
			if(x > a[mid] || x <= a[fr]){
				ans = helper(x, a, fr, mid -1);
			}else if(x < a[mid] && x > a[to]){
				ans = helper(x, a, mid +1, to);
			}else{
				return mid;
			}
		} else{ 
			if(x < a[mid] || x > a[fr]){
				
				ans = helper(x, a, mid+1, to);
			}else if(x > a[mid] && x <= a[fr]){
				ans = helper(x, a,fr, mid -1);
			}else{
				return mid;
			}
		}
	}
	return ans;
}
int findX(int * arr, int len, int x){
	return helper(x,arr, 0, len-1);
}

int main(){
	int a[] = {19,16,14,11,8,4,3,2,1,35,27,23,20};
	if(findX(a, 13, 35) != -1){
		printf("YES!\n");
	}else
		printf("NO!\n");
}
