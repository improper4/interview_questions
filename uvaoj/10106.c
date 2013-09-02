#include <stdio.h>
#include <string.h>

#define MAX 505

int main(){
	char buf1[MAX], buf2[MAX];
	int ans[MAX];
	int i, j, idx;
	while(scanf("%s%s", buf1, buf2) == 2){
		int len1 = strlen(buf1);
		int len2 = strlen(buf2);
		memset(ans, 0, sizeof(int) * MAX);	
		for(i = len1 -1; i >= 0; i--){
			for(j = len2 -1, idx = len1 -1 -i; j >= 0; j--){
				ans[idx++] += (buf1[i] - '0') * (buf2[j] - '0');
			}
		}	
		for(i = 0; i < MAX; i++){
			ans[i+1] += ans[i]/ 10;
			ans[i] %= 10;
		}
		for(i = MAX -1; i >= 0; i--) if(ans[i]) break;
		if(i == -1) printf("0");
		else for(; i>=0; i--) printf("%d", ans[i]);
		printf("\n");
	}
	return 0;
}