#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#define MAX 67
typedef struct HashItem *pHi;

struct HashItem{
	char * str;
	pHi next;
};
char buf[127];
int T, N, M;
pHi hashTbl[MAX];

unsigned int hash(char *str){
	unsigned int hashVal = 0;
	while(*str != '\0')
		hashVal = (hashVal << 5) + *(str++);
	
	return hashVal % MAX;
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
	for(i = 1; i <= strlen(buf); i++)if(buf[i] == '/' || buf[i] == '\0'){
		char c = buf[i];
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
		if(c == '/')
			buf[i] = '/';

	}
	return ans;
}
int main(){
	int i,j, now, lenBuf,res;
	freopen("t.in", "r", stdin);
	freopen("ans.out", "w", stdout);
	scanf("%d", &T);

	for(i = 0;i < T; i++){
		res = 0;
		for(j = 0; j < MAX; j++){
			hashTbl[j] = NULL;
		}
		scanf("%d %d", &N, &M);

		for(j = 0; j < N; j++){
			scanf("%s", buf);
			res += insert();
		}
		printf("Case #%d: ", i+1);
		now = res;

		for(j = 0; j < M; j++){
			scanf("%s", buf);
			res += insert();
		}
		printf("%d\n", res - now);
	}
}