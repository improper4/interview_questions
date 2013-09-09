import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class Bullseye {

	boolean check(long r, long t, long k){
		return 2*r*k + (2*k -1)*k <= t;
	}
	
	void solve() throws FileNotFoundException{
		Scanner in = new Scanner(new File("t.in"));
		PrintWriter out = new PrintWriter("ans.out");
		int T = in.nextInt();
		in.nextLine();
		for(int i = 0; i < T; i++){
			out.printf("Case #%d: ", i+1);
			long r = in.nextLong();
			long t = in.nextLong();
			long lef = 0, rig = 1;
			while(check(r, t, rig)){
				lef = rig;
				rig *= 2;
			}
			while(rig -lef >1){
				long k = (lef +rig)/2;
				if(check(r,t, k)){
					lef = k;
				}else {
					rig = k;
				}
			}
			out.println(lef);
		}
		in.close();
		out.close();
	}
	public static void main(String[] args) throws FileNotFoundException {
		new Bullseye().solve();
		System.out.println(Integer.MAX_VALUE);
		System.out.println(Long.MAX_VALUE);
		System.out.println(Double.MAX_VALUE);
	}
}
