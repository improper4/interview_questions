import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class UVa_572 {
	static char[][] oils ;
	static int[][] color ;
	static int row;
	static int col;
	static int[] dx = {1, 1, 0, -1, -1, -1, 0, 1};
	static int[] dy = {0, -1, -1, -1, 0, 1, 1, 1};
	static void dfs(int r, int c){
		color[r][c] = 1;
		for(int i = 0; i < 8; i++){
			int nR = r + dy[i];
			int nC = c + dx[i];
			if( nC >= 0 && nC < col && nR >= 0 && nR < row && oils[nR][nC] == '@'){
				if(color[nR][nC] == 0){
					dfs(nR, nC);
				}
			}
		}
		
	}
	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream("t.in"));
		Scanner in = new Scanner(System.in);
		while(in.hasNext()){
			row = in.nextInt();
			col = in.nextInt();
			if(row == 0) break;
			oils = new char[row][col];
			color = new int[row][col];
			for(int i = 0; i < row; i++){
				oils[i] = in.next().toCharArray();
			}
			int ans = 0;
			for(int i = 0; i < row; i++)
				for(int j = 0; j < col; j++){
					if(oils[i][j] == '@' && color[i][j] == 0){
						dfs(i, j);
						ans++;
					}
				}
			System.out.println(ans);
		}
	}
}
