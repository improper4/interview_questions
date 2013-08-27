#include <stdio.h>

// n种物品，每种一个，每种价值分别为vi，容量为wi，将这些物品放置到容量为C的包里面，求最大价值
// 将前i个物品装到容量为j的包里的最大价值为dp[i][j]
int v[10] = {1,2,4,5,2,3,2,3,4,5};
int w[10] = {6,7,2,5,8,1,7,3,1,7};
int n = 10;
int c = 25;
int dp[11][100];

int max(int a, int b){
	if(a< b)
		return b;
	return a;
}
int helper(int len, int c){
	int i, j;
	for(i = 1; i <= len; i++){
		for(j = 0; j <= c; j++){
			dp[i][j] = (i == 1? 0: dp[i -1][j]);
			if(w[i-1] <= j) dp[i][j] = max(dp[i][j],dp[i -1][j - w[i -1]] + v[i -1]);
			printf("HH\n");
		}
	}
	return dp[len][c];
}
int helper2(int n, int remain){
	int i, j;

	for(i = n; i >= 1; i--){

		for(j = 0; j <= remain; j++){
			dp[i][j] = (i == n? 0:dp[i+ 1][j]);
			if(w[i -1] <= j) dp[i][j] = max(dp[i][j], dp[i + 1][j - w[i- 1]]+ v[i -1]);
			if(i == n){
				printf("%d: %d  %d\n",i, dp[i][j], dp[i+ 1][j - w[i -1]]);
			}
		}
	}
	return dp[1][remain];
}
int main(){
	int i,ans;
	ans = 0;
	printf("%d\n", helper2(n, c));
	for(i = 0; i < 10; i++){
		ans += v[i];
	}
	printf("%d\n", ans);
}