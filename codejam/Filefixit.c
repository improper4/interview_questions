#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#define MAX 767
typedef struct HashItem *pHi;

struct HashItem{
	char * str;
	pHi next;
};
char buf[127];
int T, N, M;
pHi hashTbl[MAX];

unsigned int hash(char *str){
	unsigned int val;
	int i;
	for(i = 0; i < strlen(str); i++){
		val = val << 5 + str[i];
	}
	return val % MAX;
}
int find(char* str, int val){
	if(hashTbl[val] == NULL)
		return 0;
	pHi tmp = hashTbl[val];
	while(tmp != NULL){
		if(0 == strcmp(str, tmp->str))
			return 1;
		tmp = tmp->next;
	}
	return 0;
}

int insert(){
	int ans = 0, i;
	for(i = 1; i < strlen(buf); i++)if(buf[i] == '/'){
		buf[i] = '\0';
		unsigned int val = hash(buf);
		if(!find(buf, val)){
			pHi new = malloc(sizeof(struct HashItem));
			assert(new != NULL);
			new->str = malloc(sizeof(char) * 105);
			assert(new->str != NULL);
			strcpy(new->str, buf);
			new->next = hashTbl[val];
			hashTbl[val] = new;
			ans++;
		}
		buf[i] = '/';
		fflush(stdout); // why!!!!!!
	}
	return ans;
}
int main(){
	int i,j, now, lenBuf;
	freopen("t.in", "r", stdin);
	freopen("ans.out", "w", stdout);
	scanf("%d", &T);

	for(i = 0;i < T; i++){
		int res = 0;
		for(j = 0; j < MAX; j++){
			hashTbl[j] = NULL;
		}
		scanf("%d %d%*c", &N, &M);
		for(j = 0; j < N; j++){
			scanf("%s", buf);
			lenBuf = strlen(buf);
			buf[lenBuf] = '/';
			buf[lenBuf +1] = '\0';
			res += insert();
		}
		printf("Case #%d: ", i+1);
		now = res;

		for(j = 0; j < M; j++){
			scanf("%s", buf);
			int lenBuf = strlen(buf);
			buf[lenBuf] = '/';
			buf[lenBuf +1] = '\0';
			res += insert();
		}
		printf("%d\n", res - now);
	}
}