#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

char num1[300],num2[300];
int main(){
	char c;
	double a, b, res;
	while (scanf("%s %c %s", num1, &c, num2) == 3){
		printf("%s %c %s\n", num1, c, num2);
        
		int a1= 0, b1 = 0;
		a = atof(num1);
		b = atof(num2);
		if (a > INT_MAX) {printf("first number too big\n"); a1 = 1;}
		if (b > INT_MAX) {printf("second number too big\n");b1 = 1;}
        //		if(a1 || b1) printf("result too big\n");
        //		else{
        res = (c == '+') ? a + b : a * b;
        if (res > INT_MAX) printf("result too big\n");
        //		}
        
	}
	return 0;
}
/*
 * I do not know why a1 and b1 flag makes wrong answer.
 */