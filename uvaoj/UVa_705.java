import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class UVa_705 {
	static char[][] maze;
	static int[][] color;
	static int[] dx = {1, 0, -1, 0};
	static int[] dy = {0, 1, 0, -1};
	static int mLen = 0, C, R, res = 0, kr, kc , kk;
	
	static int getDir(char ch, int k){
		int dir;
		if(ch != '/'){
			if(k == 0) dir = 1; 
			else if(k == 1) dir = 0; 
			else if(k == 2) dir = 3; 
			else dir = 2;
		}else {
			if(k == 0) dir = 3; 
			else if(k == 1) dir = 2; 
			else if(k == 2) dir = 1; 
			else dir = 0;
		}
		return dir;
	}
	static void dfs(int r, int c, int k, int cnt){
		int nr = r + dy[k];
		int nc = c + dx[k];
		
		if(!(nr >= 0 && nr< R && nc >= 0 && nc < C)) return;
		
		if(nr == kr && nc == kc && k == kk){
			res++;
			mLen = mLen < cnt ? cnt: mLen;
			return;
		}

		int dir = getDir(maze[nr][nc], k);

		if((color[nr][nc] & (1 << k)) == 0){
			color[nr][nc] |= 1 << k;
			dfs(nr, nc, dir, cnt+1);
		}
	}
	public static void main(String[] args) throws FileNotFoundException {
		int c = 0;
		System.setIn(new FileInputStream("t.in"));
		Scanner in = new Scanner(System.in);
		while(true){
			C = in.nextInt();
			R = in.nextInt();
			res = 0;
			mLen = 0;
			if(R == 0) break;
			maze = new char[R][];
			color = new int[R][C];
			for(int i = 0; i < R; i++){
				maze[i] = in.next().toCharArray();
			}
			
			for(int i = 0; i < R; i++){
				for(int j = 0; j < C; j++) {
					for(int k = 0; k < 4; k++)	if((color[i][j] & (1<< k)) == 0){
						color[i][j] |= (1 << k);
						kr = i;	kc = j;
						kk = k;
						int rdir = getDir(maze[i][j], k);
						dfs(i, j, rdir, 1);
					}
				}
			}
			if(res == 0){
				System.out.printf("Maze #%d:\nThere are no cycles.\n\n", ++c);
			}else {
				System.out.printf("Maze #%d:\n%d Cycles; the longest has length %d.\n\n",++c, res/2, mLen);
			}
		}
	}
}
