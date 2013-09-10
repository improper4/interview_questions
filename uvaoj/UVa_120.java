import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class UVa_120 {
	void flip(int c, int[] num){
		for(int i = 0; i < (c+1)/2; i++){
			int tmp = num[i];
			num[i] = num[c -i];
			num[c-i] = tmp;
		}
	}
	void run(){
		Scanner in = new Scanner(System.in);
		int[] num = new int[55];

		while(in.hasNext()){
			String buf = in.nextLine();
			ArrayList<Integer> ans = new ArrayList<Integer>();
			Scanner numScanner = new Scanner(buf);
			int N = 0;
			while(numScanner.hasNext())
				num[N++] = numScanner.nextInt();
			
			int[] sorted = num.clone();
			Arrays.sort(sorted, 0, N);
			for(int i = N-1; i >= 0; i--){
				if(sorted[i] != num[i]){
					for(int j = 0; j < i; j++){
						if(num[j] == sorted[i]){
							if(j != 0){
								ans.add(N-j);
								flip(j, num);
							}
							ans.add(N-i);
							flip(i, num);
						}
					}
				}
			}
			System.out.println(buf);
			for(int m: ans)
				System.out.print(m + " ");
			System.out.println('0');
		}
	}
	public static void main(String[] args) {
		new UVa_120().run();
	}
}