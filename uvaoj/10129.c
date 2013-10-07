#include <stdio.h>
#include <string.h>
#include <math.h>

int vis[26], maze[26][26];
int dfs(int x){
	int i;
	vis[x] = 1;
	for(i = 0; i < 26; i++) 
		if(maze[x][i] && !vis[i])
			dfs(i);
}

int main(){
	int T, i, j, cas, words[2][26];
	char buf[1024];
	freopen("t.in", "r", stdin);
	scanf("%d", &T);
	for(cas = 0; cas < T; cas++){
		int N, canOpen = 1,diff = 0, head, tail, s;
		scanf("%d", &N);

		memset(words, 0, sizeof(words));
		memset(vis, 0, sizeof(vis));
		memset(maze, 0, sizeof(maze));

		for(j = 0; j < N; j++){
			scanf("%s", buf);
			head = buf[0] -'a';
			tail = buf[strlen(buf) -1] -'a';
			maze[head][tail] = 1;
			words[0][head]++;
			words[1][tail]++;
		}
		
		for(i = 0; i < 26; i++){
			diff += fabs(words[0][i] - words[1][i]);
		}

		if( diff > 2) canOpen = 0;

		if(canOpen){
			for(i = 0; i < 26; i++)if(words[0][i]){
				s = i;
				if(words[0][i] > words[1][i]){
					break;
				}
			}
			dfs(s);
			for(i = 0; i < 26; i++) if(words[0][i] && !vis[i]){
				canOpen = 0;
				break;
			}
		}
		
		if(canOpen) printf("Ordering is possible.\n");
		else printf("The door cannot be opened.\n");
	}
	return 0;
}