import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.*;

public class UVa_532 {
	static int L, R, C;
	static char[][][] maze = new char[30][30][30];
	static int[][][] dis = new int[30][30][30];
	static int[] dl = {1, -1, 0, 0, 0, 0};
	static int[] dr = {0, 0, 1, -1, 0, 0};
	static int[] dc = {0, 0, 0, 0, 1, -1};

	static boolean isProper(int l, int r, int c){
		return l >= 0 && l < L && r >= 0 && r < R && c >= 0 && c < C && maze[l][r][c] != '#';
	}
	static int bfs(int l, int r, int c){
		for(int i = 0; i < L; i++)
		for(int j = 0; j < R; j++)
			Arrays.fill(dis[i][j], -1);
		dis[l][r][c] = 0;
		Queue<Integer> ql = new LinkedList<Integer>();
		Queue<Integer> qr = new LinkedList<Integer>();
		Queue<Integer> qc = new LinkedList<Integer>();
		ql.offer(l); qr.offer(r); qc.offer(c);
		while(!ql.isEmpty()){
			int i = ql.poll();
			int j = qr.poll();
			int k = qc.poll();
			for(int d = 0; d < 6; d++){
				int nl = i + dl[d];
				int nr = j + dr[d];
				int nc = k + dc[d];
				if(isProper(nl, nr, nc) && dis[nl][nr][nc] == -1){
					dis[i+ dl[d]][j+ dr[d]][k + dc[d]] = dis[i][j][k] +1;
					if(maze[nl][nr][nc] == 'E') return dis[nl][nr][nc];
					ql.offer(nl); qr.offer(nr); qc.offer(nc);
				}
			}
		}
		return -1;
	}
	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream("t.in"));
		Scanner in = new Scanner(System.in);
		while(true){
			L = in.nextInt();
			R = in.nextInt();
			C = in.nextInt();
			if(L == 0) break;
			for(int i = 0; i < L; i++)
				for(int j = 0; j < R; j++)
					Arrays.fill(maze[i][j], 'A');
			int sl =-1, sr = -1, sc = -1;

			for(int i = 0; i < L; i++){
				for(int j = 0; j < R; j++){
					maze[i][j] = in.next().toCharArray();
					if(sc == -1){
						for(int k = 0; k < C; k++) {
							if(maze[i][j][k] == 'S'){
								sl = i; sr = j; sc = k;
							}
						}
					}
				}
			}
			int res = bfs(sl, sr, sc);
			if(res == -1){
				System.out.println("Trapped!");
			}else {
				System.out.println("Escaped in "+ res +" minute(s).");
			}
		}
	}
}
