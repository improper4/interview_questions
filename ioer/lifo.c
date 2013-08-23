// 从1到n个数进栈，出栈的时间任意，求给定一个出栈序列是否合法
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int islegal(int* arr, int len){
	
	int ok = 1;
	int now = 1;
	int idx = 0;
	int top = 0;	// when top is 0,
	int stack[50] = {0};

	while(idx < len){
		if(now == arr[idx]){idx++; now++;}
		else if(top && stack[top] == arr[idx]){top--; idx++;}
		else if(now < len){stack[++top] = now++;}
		else{ok = 0;break;}
	}
	return ok ? 1: 0;
}

int main(){
	char c;
	int i = 0;
	int a[100] = {0};
	while(scanf("%c", &c), c != '\n'){
		if(isdigit(c)){
			a[i++] = c;
		}
	}
	int res = islegal(a, i);
	printf("ANS: %d\n", res);
}