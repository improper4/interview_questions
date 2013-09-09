import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class Consonants {
	void solve() throws FileNotFoundException{
		Scanner in = new Scanner(new File("t.in"));
		PrintWriter out = new PrintWriter("ans.out");
		int T = in.nextInt();
		for(int c = 1; c <= T; c++){
			String s = in.next();
			int n = in.nextInt();
			int cnt = 0;
			int thisturn = 0;
			long ans = 0;
			for(int i = 0; i < s.length(); i++){
				char ch = s.charAt(i);
				if(ch == 'a'|| ch == 'e'|| ch == 'i'|| ch== 'o' || ch == 'u'){
					cnt = 0;
				}else{
					cnt++;
				}
				if(cnt >= n){
					thisturn = i -n+ 2;
				}
				ans += thisturn;
			}
			out.printf("Case #%d: %d\n", c, ans);
		}
		in.close();
		out.close();
	}
	public static void main(String[] args) throws FileNotFoundException {
		new Consonants().solve();
	}
}
