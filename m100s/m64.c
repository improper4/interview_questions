/*************************************************************************
    > File Name: m64.c
    > Author: improper4
    > Mail: improper4@gmail.com 
    > Created Time: Tue Jun 11 09:59:01 2013
 ************************************************************************/

#include "m100s.h"
int min3(int a, int b, int c){
	int tmp = a < b ? a: b;
	return tmp < c ? tmp: c;
}
unsigned int uglyKth(int k){
	int u2, u3, u5, idx, val;
	int u[k];
	u[0] = 1;
	u2 = u3 = u5 = 0;
	idx = 1;
	while(idx < k){
		val = min3(u[u2]*2, u[u3] * 3, u[u5]* 5);
		if(val == u[u3] * 3)
			u3++;
		if(val == u[u2] * 2)
			u2++;
		if(val == u[u5] * 5)
			u5++;
		u[idx++] = val;
	}
	return u[k -1];
}
int main(int argc, char* argv[]){
	printf("ANS: %d\n",uglyKth(atoi(argv[1])));
}
