#include <stdio.h>
#include <string.h>
#define MAX 5000
char buf[500];
char words[MAX][17];
int alph[15][26];
int L, D, N;
int match(){
	int ans = 0, i,j;
	int len = strlen(buf);
	int idx = 0;
	for(i = 0; i < len; i++){
		if(buf[i] == '('){
			for(j = i+1; j < len; j++){
				if(buf[j] == ')'){
					i = j;
					idx++;
					break;
				}else{
					alph[idx][buf[j] - 'a'] = 1;
				}
			}
		}else{
			alph[idx++][buf[i] -'a'] = 1;
		}
	}
	for(i = 0; i < D; i++){
		int passit =0;
		for(j = 0; j < L; j++){
			if(alph[j][words[i][j] -'a'] != 1){
				passit = 1;
				break;
			}
		}
		if(!passit)
			ans++;
	}
	return ans;
}
int main(){
	int i;
	freopen("t.in", "r", stdin);
	freopen("ans.out", "w", stdout);
	scanf("%d%d%d%*c", &L, &D, &N);

	for(i = 0; i < D; i++){
		scanf("%s", words[i]);
	}
	for(i = 0; i < N; i++){
		scanf("%s", buf);
		memset(alph, 0, sizeof(alph));
		int ans = match();
		printf("Case #%d: %d\n", i+1, ans);
	}
}