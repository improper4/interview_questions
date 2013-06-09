/*************************************************************************
    > File Name: m27.c
    > Author: improper4
    > Mail: improper4@gmail.com 
    > Created Time: Sat Jun  8 18:25:51 2013
 ************************************************************************/

#include "m100s.h"

int getWays(int n){
	int fr, se, ans, i;
	fr = 1;
	se = 2;
	if(n == 1)
		return 1;
	if(n == 2)
		return 2;
	for(i = 3; i <= n; i++){
		ans = fr + se;
		fr = ans;
		se = fr;
	}
	return ans;
}
int main(){
	printf("%d\n",getWays(4));
}
