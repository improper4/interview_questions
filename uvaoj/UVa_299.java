import java.util.Scanner;


public class UVa_299 {
	static final int MAX = 55;
	int N;
	int[] carriage = new int[MAX];
	Scanner in = new Scanner(System.in);
	
	void read(){
		N = in.nextInt();
		for(int i = 0; i < N; i++){
			carriage[i] = in.nextInt();
		}
	}
	
	void solve(){
		int ans = 0;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N -1; j++){
				if(carriage[j]> carriage[j+1]){
					int tmp = carriage[j];
					carriage[j] = carriage[j+1];
					carriage[j+1] = tmp;
					ans++;
				}
			}
		}
		System.out.printf("Optimal train swapping takes %d swaps.\n", ans);
	}
	
	void run(){
		int caseN = in.nextInt();
		for(int i = 0; i < caseN; i++){
			read();
			solve();
		}
	}

	public static void main(String[] args) {
		new UVa_299().run();
	}
}
