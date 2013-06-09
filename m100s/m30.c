/*************************************************************************
    > File Name: m30.c
    > Author: improper4
    > Mail: improper4@gmail.com 
    > Created Time: Sat Jun  8 19:22:48 2013
 ************************************************************************/

#include "m100s.h"
int getDigit(int x, int digit){
	int ans;
	ans = x/ pow(10,digit -1);
	ans = ans % 10;
	return ans;
}
int howMany1(int x){
	int digits, cc, i, ans, tmp;
	cc = 1;
	digits = 0;
	while(cc){
		digits++;
		cc = x / pow(10, digits);
	}
	for(i = 1; i<= digits; i++){
		cc = x / pow(10, i);
		tmp = getDigit(x, i);
		if(tmp > 1)
			cc++;
		else if(tmp == 1){
			ans += x % (int)pow(10, i -1);
			ans++;
		}
		ans += cc * pow(10, i -1);
	}
	return ans;
}
int main(int argc, char* argv[]){
	printf("ANS: %d\n",howMany1(atoi(argv[1])));
}
