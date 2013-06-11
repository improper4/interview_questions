/*************************************************************************
    > File Name: m68.c
    > Author: improper4
    > Mail: improper4@gmail.com 
    > Created Time: Mon Jun 10 16:01:51 2013
 ************************************************************************/

#include "m100s.h"
int cmp(const void * a, const void * b){
	char* str1 = malloc(sizeof(char) * 12);
	IFOUT(str1, 11);
	char* str2 = malloc(sizeof(char) * 12);
	IFOUT(str2, 13);
	sprintf(str1,"%d", *(int *)a);
	sprintf(str2,"%d", *(int *) b);
	return strcmp(str1, str2);
}
int getLen(int * a, int len){
	int i;
	int ans = 0;
	char* tmp = malloc(sizeof(char) *12);
	IFOUT(tmp, 22);
	for(i = 0; i < len; i++){
		sprintf(tmp, "%d",a[i]);
		ans += strlen(tmp);
	}
	return ans;
}
char* getMin(int * a, int len){
	int i;
	char* ans;
	int n = getLen(a, len);
	qsort(a, len, sizeof(int), cmp);
	ans = malloc(sizeof(char)* (n +1));
	for(i = 0; i < len; i++){
		char* tmp = malloc(sizeof(char) * 12);
		sprintf(tmp,"%d",a[i]);
		strcat(ans,tmp);
	}
	return ans;
}

int main(){
	int a[] = {12,23,4,546,111,345,456,3};
	char * ans = getMin(a, 8);
	printf("%s\n", ans);
}
