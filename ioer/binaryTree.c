// 给出一个树的先序和中序，求出后序
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void getPostOrder(int *pre, int *mid, int *post, int len){
	int i;
	int idx = 0;
	
	for(i = 0; i < len; i++) if(mid[i] == pre[0]){
		idx = i;
		break;
	}
	if(len < 0) return;
	getPostOrder(pre +1,mid, post, idx);
	getPostOrder(pre + idx + 1, mid+ idx + 1, post + idx, len - idx -1);
	post[len -1] = pre[0];
}
int main(){
	int i;
	int cnt = 0;
	char c;
	int pre[100] = {-1};
	int mid[100] = {-1};
	int *post;
	while(scanf("%c", &c), c != '\n'){
		if(isdigit(c)){
			pre[cnt++] = c;
		}
	}
	cnt = 0;
	while(scanf("%c", &c), c != '\n'){
		if(isdigit(c)){
			mid[cnt++] = c;
		}
	}
	post = malloc(sizeof(int) * cnt);
	assert(post != NULL);
	getPostOrder(pre, mid, post, cnt);
	for(i = 0; i< cnt; i++){
		printf("%d\n", post[i]);
	}
	printf("\n");
}