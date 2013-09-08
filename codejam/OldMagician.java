import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class OldMagician {
	void solve() throws FileNotFoundException{
		Scanner in = new Scanner(new File("t.in"));
		PrintWriter out = new PrintWriter("ans.out");
		int T = in.nextInt();
		for(int i = 0; i < T; i++){
			int w = in.nextInt();
			int b = in.nextInt();
			out.print("Case #" + (i+1) + ": ");
			if(w == 1 && b == 0){
				out.println("WHITE");
			}else if(w == 0 && b == 1){
				out.println("BLACK");
			}else if(b % 2 == 0){
				out.println("WHITE");
			}else{
				out.println("BLACK");
			}
		}
		in.close();
		out.close();
	}
	public static void main(String[] args) throws FileNotFoundException {
		
		new OldMagician().solve();
	}
}
