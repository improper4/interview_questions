#include <stdio.h>
#include <string.h>

int V, E;
int G[201][201];
int clr[201];

int isBicolor = 1;

void bfs(int s){
	int i, front = 0, rear = 0;
	int q[210];
	q[rear++] = s;
	clr[s] = 1;
	while(front < rear){
		int x = q[front++];
		for(i = 0; i < V; i++) if(G[x][i]){
			if(clr[i] == 0){
				clr[i] = 3 - clr[x];
				q[rear++] = i;
			}else if(clr[i] == clr[x]){
				isBicolor = 0;
				return;
			}
		}
	}
}

int main(){
	while(~scanf("%d", &V) && V){	
		memset(clr, 0, sizeof(clr));
		memset(G, 0, sizeof(G));
		scanf("%d", &E);
		while(E--){
			int a, b;
			scanf("%d%d", &a, &b);
			G[a][b] = 1;
		}
		isBicolor = 1;
		bfs(0);			
		if(isBicolor){
			printf("BICOLORABLE.\n");
		}else{
			printf("NOT BICOLORABLE.\n");
		}
	}
	return 0;
}