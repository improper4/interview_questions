#include <stdio.h>
#include <string.h>

#define MAX 
int game[50][50];
int N,K;
int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,-1,0,1,1,-1,-1,1};
int getK(){
	int i, j,k, m,ans = 0;
	for(i = N -1; i >= 0; i--){
		for(j = N-1; j >= 0; j--){
			for(k = 0; k < 8; k++)if((i + dy[k]* (K-1)) >=0 && (i + dy[k]* (K-1)) < N &&
				(j + dx[k]* (K-1)) < N && (j + dx[k]*(K-1)) >= 0){
				int fail = 0;
				for(m = 1; m < K; m++){
					if(game[i][j] != game[i + dy[k]* m][j + dx[k]* m]){
						fail = 1;
						break;
					}
				}
				if(fail == 0){
					ans |= game[i][j];
					break;
				}
			}
			if(ans == 3){
				return 3;
			}
		}
	}
	return ans;
}
int main(){
	freopen("t.in", "r", stdin);
	freopen("ans.out", "w", stdout);
	int T, k, i, j;
	char buf[55];
	scanf("%d", &T);
	for(k = 0; k < T; k++){
		memset(game, 0, sizeof(game));
		scanf("%d%d", &N, &K);
		for(i = 0; i < N; i++){
			scanf("%s", buf);

			int kth = N -1;
			for(j = kth; j >= 0; j--){
				if(buf[j] == 'B'){
					game[i][kth--] = 1;
				}else if(buf[j] == 'R'){
					game[i][kth--] = 2;
				}
			}
		}
		printf("Case #%d: ", k+1);
		int res = getK();
		if(res == 0){
			printf("Neither\n");
		}else if(res == 3){
			printf("Both\n");
		}else if(res == 2){
			printf("Red\n");
		}else{
			printf("Blue\n");
		}
	}
}