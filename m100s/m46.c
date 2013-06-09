/*************************************************************************
    > File Name: m46.c
    > Author: improper4
    > Mail: improper4@gmail.com 
    > Created Time: Sat Jun  8 22:44:32 2013
 ************************************************************************/

#include "m100s.h"
int LEN;
char* P;
// left: remain left	right: remain right
void helper(int left, int right){
	if(left == 0 && right == 0){
		int i;
		for(i = 0; i < LEN; i++){
			printf("%c",P[i]);
		}
		printf("\n");
		return;
	}
	if(left < 0  || right < 0)
		return ;
	if(left == right){
		P[LEN - left - right] = '(';
		helper(left -1, right);
	}else if(left < right){
		P[LEN - left -right] = '(';
		helper(left -1, right);
		P[LEN - left -right] = ')';
		helper(left, right -1);
	}
	
}
void parentheses(int n){
	LEN = 2* n;
	P = malloc(sizeof(char) * LEN);
	IFOUT(P, 38);
	helper(n, n);
}
int main(int argc, char* argv[]){
	parentheses(atoi(argv[1]));
}
