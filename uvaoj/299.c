#include <stdio.h>
int main(){
	int i, j,k,T,N;
	int carr[55];
	scanf("%d", &T);
	for(k = 0; k < T; k++){
		scanf("%d", &N);
		for(i = 0; i < N; i++){
			scanf("%d", &carr[i]);
		}
		int ans = 0;
		for(i = 0; i < N; i++)
			for(j = 0; j < N-1; j++)
				if(carr[j] > carr[j+1]){
					int tmp = carr[j];
					carr[j] = carr[j+1];
					carr[j+1] = tmp;
					ans++;
				}
		printf("Optimal train swapping takes %d swaps.\n", ans);
	}
}