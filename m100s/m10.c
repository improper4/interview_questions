/*************************************************************************
    > File Name: m10.c
    > Author: improper4
    > Mail: improper4@gmail.com 
    > Created Time: Fri Jun  7 21:06:44 2013
 ************************************************************************/

#include "m100s.h"
void reverse(char* str, int from, int to){
	int i;
	for(i = 0; i <= (to - from)/2; i++){
		int tmp = str[i+ from];
		str[i+ from] = str[to - i];
		str[to -i] = tmp;
	}
}

char* rotate(char* str, int len){
	int i, last, print, mark;
	last = -1;
	print = 0;
	reverse(str, 0, len-1);
	for(i = 0; i <= len; i++){
		if(isspace(str[i]) || str[i] == '\0'){
			mark = i;
			if(print){
				reverse(str,last +1, mark -1);
			}
			last = i;
		}else{
			print = 1;
		}
	}
	return str;
}

int main(){
	char str[] = "Keep Moving    aid	dbg ";
	printf("%s\n",str);
	char* ans = rotate(str, strlen(str));
	printf("%s\n", ans);
}
