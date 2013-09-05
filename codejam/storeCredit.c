#include <stdio.h>

int main(){
	int i,j,k, state = 0;
	int cases, v, listLen;

	freopen("A-large-practice.in.txt","r", stdin);
	freopen("AA.out", "w", stdout);
	scanf("%d", &cases);

	for(i = 0; i < cases; i++){
		scanf("%d %d", &v, &listLen);
		for(j = 0; j < listLen; j++){
			int list[2000];
			scanf("%d", list + j);
			for(k = 0; k < j; k++){
				if(list[k] + list[j] == v){
					printf("Case #%d: %d %d\n",i+1, k+1,j+1);
				}
			}
		}
	}
}