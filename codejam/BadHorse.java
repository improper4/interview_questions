import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;


public class BadHorse {
	static boolean loop;
	static int[] colored;
	static boolean[][] edge;
	static int cnt;
	static boolean search(int idx){
		for(int i = 0; i < cnt; i++) if(edge[idx][i]){
			if(colored[i] == 0){
				colored[i] = colored[idx]%2+1;
				if(search(i)) return true;
			}else if(colored[i] == colored[idx])
					return true;
		}
		return false;
	}
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("t.in"));
		PrintWriter out = new PrintWriter("ans.out");

		int T = in.nextInt();in.nextLine();
		for(int cas = 1; cas <=T; cas++){
			String ans = "Yes";
			cnt =0; loop = false;
			edge = new boolean[201][201];
			HashMap<String, Integer> hmap = new HashMap<String, Integer>();

			int N = in.nextInt();in.nextLine();
			for(int i = 0; i < N; i++){
				String tmp = in.nextLine();
				String[] tmp2 = tmp.split(" ");
				for(int j = 0; j < 2;j++){
					if(!hmap.containsKey(tmp2[j])){
						hmap.put(tmp2[j], cnt++);
					}
				}
				int y = hmap.get(tmp2[1]);
				int x = hmap.get(tmp2[0]);
				edge[x][y] = true;
				edge[y][x] = true;
				
			}
			colored = new int[cnt];
			for(int i = 0; i < cnt; i++){
				if(colored[i] == 0){
					colored[i] = 1;
					if(search(i)){
						ans = "No";
						break;
					}
				}
			}
			out.printf("Case #%d: %s\n", cas, ans);
		}
		in.close();
		out.close();
	}
}
