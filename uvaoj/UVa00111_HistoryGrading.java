import java.util.ArrayList;
import java.util.Scanner;


public class UVa00111_HistoryGrading {
	public static void main(String[] args) {
		ArrayList<Integer> ans = new ArrayList<Integer>();
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] bench = new int[n];
		for(int i = 0; i < n; i++){
			bench[i] = in.nextInt() -1;
		}
		int[] obj = new int[n];
		while(in.hasNext()){
			for(int i = 0; i < n; i++){
				obj[in.nextInt() -1] = i; 
			}
			int tmp = solve(bench, obj, n);
			ans.add(tmp);
		}
		for(int x: ans)
			System.out.println(x);
		in.close();
	}
	static int solve(int[] ben, int[] obj, int m){
		int[] dp = new int[m];
		int ans = 0;
		for(int i = 0; i < m; i++){
			int max = 0;
			for(int j = 0; j < i; j++){
				if(ben[obj[i]] > ben[obj[j]]){
					max = Math.max(max, dp[j]); 
				}
			}
			dp[i]= max + 1; 
			ans = Math.max(ans, dp[i]);
		}
		return ans; 
	}
}
