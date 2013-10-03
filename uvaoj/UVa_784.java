import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;


public class UVa_784 {
	static int[] dx = {1, 0, -1, 0};
	static int[] dy = {0, -1, 0, 1};
	static char[][] maze = new char[30][];
	static void dfs(int sr, int sc, int row, int col){
		
		if(!(sc >= 0 && sc < col && sr >= 0 && sr < row && maze[sr][sc] == ' '))
			return;
			
		maze[sr][sc] = '#';
		dfs(sr-1, sc, row, col);
		dfs(sr+1, sc, row, col);
		dfs(sr, sc-1, row, col);
		dfs(sr, sc+1, row, col);
	}
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(in.readLine());
		for(int cas = 0; cas < T; cas++){
			String tmp;
			int cnt = 0, sc = 0, sr = 0;
			while(true){
				tmp = in.readLine();
				if(tmp.charAt(0) == '_') break;
				maze[cnt++] = tmp.toCharArray();
			}
		out:	for(sr = 0; sr< cnt; sr++){
				for(sc = 0; sc < maze[sr].length;sc++)
					if(maze[sr][sc] == '*') break out;
			}
			maze[sr][sc] = ' ';
			dfs(sr, sc, cnt, maze[sr].length);
			
			for(int i = 0; i < cnt; i++){
				System.out.println(String.valueOf(maze[i]));
			}
			System.out.println(tmp);
		}
	}
}
