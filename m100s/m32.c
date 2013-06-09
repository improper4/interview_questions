/*************************************************************************
    > File Name: m32.c
    > Author: improper4
    > Mail: improper4@gmail.com 
    > Created Time: Sat Jun  8 20:11:59 2013
 ************************************************************************/

#include "m100s.h"
//	不知道这种算法对不对!!!
//

int getDiff(int* a, int* b. int len){
	int sum1, sum2, c1, c2;
	int arr[len * 2], n1[len], n2[len];
	sum1 = sum2 = c1 = c2 = 0;
	for(i = 0; i < len; i++){
		arr[2 *i] = a[i];
		arr[2* i +1] = b[i];
		n1[i] = 0;
		n2[i] = 0;
	}
	sort(arr, 2* len, sizeof(int), cmp);
	for(i = len * 2 -1; i <= 0; i--){
		if(sum1 > sum2){
			sum2 += arr[i];
			n2[c2++] = arr[i];
		}else{
			sum1 += arr[i];
			n1[c1++] = arr[i];
		}
	}
	return abs(sum1, sum2);
}
