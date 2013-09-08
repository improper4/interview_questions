#include <stdio.h>
#include <string.h>

char alien[100];
char src[100];
char dest[100];
int getIdx(char cc){
	int i;
	for(i = 0; i < strlen(src); i++)
		if(src[i] == cc)
			return i;
	return -1;
}
int main(){
	int i, j, N;
	freopen("t.in", "r", stdin);
	freopen("ans.out", "w", stdout);
	scanf("%d", &N);
	for(i = 0; i < N; i++){
		int ans = 0, idx = 0;
		char res[100] = {'0'};
		scanf("%s%s%s", alien, src, dest);
		int srcLen = strlen(src);
		int destLen = strlen(dest);
		int alienLen = strlen(alien);

		for(j = 0; j < alienLen; j++)
			ans = getIdx(alien[j]) + ans * srcLen;
		
		while(ans > 0){
			res[idx++] = dest[ans % destLen];
			ans /= destLen;
		}
		printf("Case #%d: ", i+1);
		for(j = idx -1; j >= 0; j--)
			printf("%c", res[j]);
		printf("\n");
	}
}