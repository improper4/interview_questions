/*************************************************************************
    > File Name: m47.c
    > Author: improper4
    > Mail: improper4@gmail.com 
    > Created Time: Sun Jun  9 18:52:07 2013
 ************************************************************************/

#include "m100s.h"

int getLastX(int* arr, int len){
	int i;
	for(i = 0; i < len; i++)
		if(arr[i] == INT_MAX)
			break;
	return arr[i -1];
}

int getLen(int* arr, int len){
	int i;
	for(i = 0; i < len; i++)
		if(arr[i] == INT_MAX)
			break;
	return i;
}

int MaxDecSub(int* arr, int len){
	int i, j, k, tmpLen, maxLen, ansLen, idx, ansIdx;
	int dp[len][len]; 
	ansLen = 1;

	for(i = 0; i < len; i++){
		for(j = 0; j < len; j++){
			dp[i][j] = INT_MAX;
		}
	}
	dp[0][0] = arr[0];
	for(i = 1; i < len; i++){
		maxLen = 1;
		for(j = 0; j < i; j++){
			int x = getLastX(dp[j], j);
			if(x > arr[i]){
				tmpLen = getLen(dp[j], j)+1;
				if(maxLen < tmpLen){
					maxLen = tmpLen;
					idx = j;
				}
			}
		}
		for(k = 0; k < maxLen -1; k++){
			dp[i][k] = dp[idx][k];
		}
		dp[i][k] = arr[i];
		if(ansLen < maxLen){
			ansLen = maxLen;
			ansIdx = i;
		}
	}
	return ansLen;
}
int main(){
	int arr[] = {12, 43, 34, 23, 44, 22, 38, 19, 
		85, 33, 12, 6, 2, 17, 68};
	printf("%d\n", MaxDecSub(arr, 15));
}
