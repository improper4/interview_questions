/*************************************************************************
    > File Name: m21.c
    > Author: improper4
    > Mail: improper4@gmail.com 
    > Created Time: Sat Jun  8 14:26:05 2013
 ************************************************************************/

#include "m100s.h"

int helper(int remain, int max, int* visited, int len){
	int i, ans;	
	if(remain > (max * (max +1)/ 2) || remain < 0)
		return 0;
	if(remain == 0){
		printf("ANS: ");
		for(i = 0; i < len; i++) if(visited[i] ==1){
			printf("%d ", i);
		}
		printf("\n");
		return 1;
	}
	visited[max] = 1;
	ans |= helper(remain - max, max -1, visited, len);
	visited[max] = 0;
	ans |= helper(remain, max -1, visited, len);
	return ans;
}

int getSum(int m, int n){
	int i ;
	int visited[n+ 1];
	for(i = 0; i < n+1; i++){
		visited[i] = 0;
	}
	if(m > (n* (n +1)/ 2) || m < 1)
		return 0;		// no print
	return helper(m, n, visited, n+1);
}

int main(){
	if(getSum(29, 14) == 0){
		printf("NO!\n");
	}
}
