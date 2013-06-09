/*************************************************************************
    > File Name: m51.c
    > Author: improper4
    > Mail: improper4@gmail.com 
    > Created Time: Sun Jun  9 21:25:48 2013
 ************************************************************************/

#include "m100s.h"
// 不知道这种算法正确不
//
void printProper(int n){
	int c1, c2, c3 ,i;
	int ceil =1+ sqrt(n);
	for(i = 2; i <= ceil;i++){
		if(i%2 == 1){
			if(n%i == 0){
				c1 = n/i;
				c2 = c1;
				c1 -= i/2;
				c2 += i/2;
				printf("ans: %d-%d\n", c1, c2);	
			}
		}else{
			c1 = n/i;
			c2 = c1 + c1 +1;
			if(n% c2 ==  0){
				c3 = n/c2/2;
				c2 = c1 +1;
				c1 -= c3;
				c2 += c3;
				printf("ans: %d-%d\n", c1, c2);
			}
		}
	}
}
int main(int argc, char* argv[]){
	printProper(atoi(argv[1]));
}
