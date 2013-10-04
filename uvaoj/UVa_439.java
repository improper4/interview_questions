import java.io.*;
import java.util.*;

public class UVa_439 {
	static int[] dx = {1, 2, 2, 1, -1, -2, -2, -1};
	static int[] dy = {-2, -1, 1, 2, 2, 1, -1, -2};
	
	static int[][] bfs(int r, int c){
		int[][] dis = new int[8][8];
		
		for(int i = 0; i < 8; i++)
			Arrays.fill(dis[i], -1);

		
		Queue<Integer> qr = new LinkedList<Integer>();
		Queue<Integer> qc = new LinkedList<Integer>();
		dis[r][c] = 0;
		qr.offer(r);
		qc.offer(c);
		
		while(!qr.isEmpty()){
			int sr = qr.poll();
			int sc = qc.poll();
			
			for(int i = 0; i < 8; i++){
				int nr = sr + dy[i];
				int nc = sc + dx[i];
				if(nr >= 0 && nr < 8 && nc >= 0 && nc < 8 && dis[nr][nc] == -1){
					dis[nr][nc] = dis[sr][sc]+1;
					qr.offer(nr);
					qc.offer(nc);
				}
			}
		}
		return dis;
	}
	public static void main(String[] args) throws IOException {
		System.setIn(new FileInputStream("t.in"));
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String str;
		while((str = in.readLine()) != null){
			String[] col = str.split(" ");
			int ac = str.charAt(0) - 'a';
			int ar = str.charAt(1) - '1';
			int bc = str.charAt(3) - 'a';
			int br = str.charAt(4) - '1';
			int[][] ans = bfs(ar, ac);
			System.out.println("To get from " + col[0] + " to " + col[1] + 
					" takes " + ans[br][bc] + " knight moves.");
		}
	}
}
