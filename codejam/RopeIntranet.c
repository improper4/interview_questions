#include <stdio.h>
#define MAX 1010

int main(){
	int T;
	int left[MAX], right[MAX];
	int k, i, j, lines;

	freopen("t.in", "r", stdin);
	freopen("ans.out", "w", stdout);
	scanf("%d", &T);
	for(k = 0; k < T; k++){
		int ans = 0;
		scanf("%d", &lines);
		for(i = 0; i < lines; i++){
			scanf("%d%d", left+i, right+i);
			for(j = 0; j < i; j++){
				if((left[i] > left[j] && right[i] < right[j])||
					(left[i] < left[j] && right[i] > right[j])){
					ans++;
				}
			}
		}
		printf("Case #%d: %d\n", k+1, ans);
	}
}