/*************************************************************************
    > File Name: m53.c
    > Author: improper4
    > Mail: improper4@gmail.com 
    > Created Time: Sun Jun  9 21:48:31 2013
 ************************************************************************/

#include "m100s.h"
int  alpha[26] = {0};
void helper(int step, char* ans, int len){
	int i;
	if(step == len){
		//print
		ans[len] = '\0';
		printf("%s\n", ans);
		return;
	}
	//	for循环：巧妙排除了重复元素
	for(i = 0; i < 26; i++){
		if(alpha[i] > 0){
			alpha[i]--;
			ans[step] = i + 'a';
			helper(step +1, ans, len);
			alpha[i]++;
		}
	}

}
void printAll(char* str){
	int i;
	int len = strlen(str);
	char* ans = malloc(sizeof(char) * (len +1));
	IFOUT(ans, 24);
	for(i = 0; i < len; i++){
		alpha[str[i]- 'a']++;
	}
	helper(0, ans, len);
}
int main(int argc, char* argv[]){
	printAll(argv[1]);
}
