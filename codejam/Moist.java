import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.Scanner;


public class Moist {
	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("t.in"));
		PrintWriter out = new PrintWriter("ans.out");

		int T = Integer.parseInt(in.nextLine());
		for(int cas = 1; cas <=T; cas++){
			int ans = 0;
			int N = Integer.parseInt(in.nextLine());
			String[] cards = new String[N];
			for(int i = 0; i < N; i++){
				cards[i] = in.nextLine();
			}
			String max = " ";
			for(int i = 0; i < N; i++){
				if(cards[i].compareTo(max) < 0){
					ans++;
				}else{
					max = cards[i];
				}
			}
			out.printf("Case #%d: %d\n", cas, ans);
		}
		in.close();
		out.close();
	}
}
