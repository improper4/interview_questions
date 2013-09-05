#include <stdio.h>
#include <stdlib.h>

#define MAX 850
int firVec[MAX];
int secVec[MAX];

int cmp(const void * a1, const void * b1){
	int a = *(int*) a1;
	int b = *(int*) b1;
	return a - b;
}
double getMinScalarProduct(int len){
	int i;
	double sum;
	qsort(firVec, len, sizeof(int), cmp);
	qsort(secVec, len, sizeof(int), cmp);
	for(i = 0; i < len; i++)
		sum += ((double)firVec[i]) *((double) secVec[len -1 -i]);
	return sum;
}

int main(){
	int N, vecLen, k, i;

	freopen("A-small-practice.in.txt", "r", stdin);
	freopen("a-small.out", "w", stdout);
	scanf("%d", &N);

	for(k = 0;k < N; k++){
		scanf("%d", &vecLen);
		for(i = 0; i < vecLen; i++)
			scanf("%d", &firVec[i]);
		for(i = 0; i < vecLen; i++)
			scanf("%d", &secVec[i]);
		double res = getMinScalarProduct(vecLen);
		printf("Case #%d: %.0f\n",k+1, res );
	}
}