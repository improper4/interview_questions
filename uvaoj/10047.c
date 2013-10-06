#include <stdio.h>
#include <string.h>
struct node{
	int r;
	int c;
	int color;
	int d;
	int t;
};

struct node q[12550];

char maze[30][30];
int visited[30][30][5][4],M, N, res, flag;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int bfs(int r, int c){

	int rear = 0, front = 0;
	struct node s, u;
	s.r = r; s.c = c; s.d = 0; s.color = 0; s.t = 0;
	visited[r][c][0][0] = 1;
	q[rear++] = s;

	while(front < rear){
		s = q[front++];
		
		if(maze[s.r][s.c] == 'T' && s.color == 0) {flag = 1; return s.t;}
		
		int	nr = s.r + dr[s.d];
		int nc = s.c + dc[s.d];

		if(nc >= 0 && nc < N && nr >= 0 && nr < M && !visited[nr][nc][(s.color+ 1) %5][s.d] 
			&& maze[nr][nc] != '#'){

			u.r = nr;
			u.c = nc;
			u.color = (s.color + 1) % 5;
			u.d = s.d;
			u.t = s.t +1;
			q[rear++] = u;
			visited[nr][nc][u.color][u.d] = 1;
				
		}

		if(!visited[s.r][s.c][s.color][(s.d+ 3)% 4]){

			u.r = s.r;
			u.c = s.c;
			u.d = (s.d+3)% 4;
			u.color = s.color;
			u.t = s.t +1;
			q[rear++] = u;
			visited[u.r][u.c][u.color][u.d] = 1;
		}
		if(!visited[s.r][s.c][s.color][(s.d+ 1)% 4]){
			u.r = s.r;
			u.c = s.c;
			u.d = (s.d+1)% 4;
			u.t = s.t +1;
			u.color = s.color;
			q[rear++] = u;
			visited[u.r][u.c][u.color][u.d] = 1;
		}
	}
	return -1;
}
int main(){
	freopen("t.in", "r", stdin);
	int i, j, cnt = 0, sr, sc;

	while(scanf("%d%d", &M, &N) == 2){
		if(M == 0 && N == 0) return;

		for(i = 0; i < M; i++){
			scanf("%s", maze[i]);
				for(j = 0; j < N; j++) if(maze[i][j] == 'S'){
						sc = j; sr = i;
				}	
		}

		memset(visited,0,sizeof(visited));
		flag = 0;
		res = bfs(sr, sc);

		if(cnt) printf("\n");
		if(flag == 0)
			printf("Case #%d\ndestination not reachable\n", ++cnt);
		else
			printf("Case #%d\nminimum time = %d sec\n", ++cnt, res);
		
	}
	return 0;
}