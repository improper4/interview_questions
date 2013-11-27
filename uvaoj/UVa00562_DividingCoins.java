import java.util.Scanner;


public class UVa00562_DividingCoins {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int cas = 0; cas < T; cas++){
			int n = in.nextInt();
			int sum = 0;
			int[] arr = new int[n];
			for(int i = 0; i < n; i++){
				arr[i] = in.nextInt();
				sum += arr[i];
			}
			int ans = solve(arr, n,(sum+1)/ 2);
			System.out.println(Math.abs(ans* 2 - sum));
		}
		in.close();
	}
	static int solve(int[] arr,int len, int x){
		int[][] dp = new int[len+1][x+1];
		for(int i = 1; i <= len; i++){
			for(int j = 1; j <= x; j++){
				dp[i][j] = dp[i -1][j];
				if(j >= arr[i-1]) dp[i][j] = Math.max(dp[i][j], dp[i-1][j - arr[i-1]] + arr[i-1]);
			}
		}
		return dp[len][x];
	}
}
