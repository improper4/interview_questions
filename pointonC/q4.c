#include <math.h>
#include <stdio.h>
// 
double getSqrt(int x){
	double a = 1;
	double ans =(a + x/a)/2;
	double tmp;
	while(tmp = ans -a, (tmp > 0.000001 || tmp < -0.000001)){
		printf("ans: %f\n", ans);
		a = ans;
		ans = (a + x/ a) /2;
	}
	return ans;
}

void copy_n(char dst[], char src[], int n){
	int i, j;

	for(j = 0, i = 0; i < n; i++){
		dst[i] = src[j];
		if(src[j] != 0)
			j++;
	}
}


int main(){
	printf("%f\n",getSqrt(13));
}