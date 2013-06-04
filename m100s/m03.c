/*************************************************************************
    > File Name: m03.c
    > Author: improper4
    > Mail: improper4@gmail.com 
    > Created Time: Mon Jun  3 20:30:37 2013
 ************************************************************************/

#include "m100s.h"

int getMax(int* arr, int len){
	int ans, minus, tmp, i;
	ans = tmp = 0;
	minus = INT_MIN;
	for(i = 0; i < len; i++){
		tmp += arr[i];
		if(arr[i] < 0 && arr[i] > minus){
			minus = arr[i];
		}
		if(tmp < 0){
			tmp = 0;
		}
		if(tmp > ans){
			ans = tmp;
		}
	}
	if(ans == 0){
		ans = minus;
	}
	return ans;
}

int main(){
	int arr1[] = {1, -2, 3, 10,-4, 7, 2, -5 };
	int arr2[] = {1,-2, -8, 3, 4, -6, 10, 2};
	int arr3[] = {-1333,-2, -8, -3, -4, -6, -10, -2};
	printf("%d\n",getMax(arr1, 8));
	printf("%d\n",getMax(arr2, 8));
	printf("%d\n",getMax(arr3, 8));

}
