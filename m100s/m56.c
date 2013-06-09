/*************************************************************************
    > File Name: m56.c
    > Author: improper4
    > Mail: improper4@gmail.com 
    > Created Time: Mon Jun 10 13:15:53 2013
 ************************************************************************/

#include "m100s.h"

#define BIGGER(a, b) (a > b ? a: b)

int mylcs(char* a, char* b, int alen, int blen){
	int i,j;
	int dp[alen + 1][blen + 1];
	for(i = 0; i< alen +1; i++)
		dp[i][0] = 0;
	for(i = 0; i < blen +1; i++)
		dp[0][i] = 0;

	for(i = 1; i <= alen; i++){
		for(j = 1; j <= blen; j++){
			if(a[i] == b[j]){
				dp[i][j] = dp[i -1][j -1] +1;
			}else{
				dp[i][j] = BIGGER(dp[i -1][j],dp[i][j -1]);
			}
		}
	}
	return dp[alen][blen];
}
int main(){
	char* a = "afkdjhfsdkiwuejsdhfsdjf";
	char* b = "dafkjfhd";
	printf("%d\n",mylcs(a, b, strlen(a), strlen(b)));
}
