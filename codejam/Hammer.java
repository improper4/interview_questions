import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class Hammer {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("t.in"));
		PrintWriter out = new PrintWriter("ans.out");

		int T = in.nextInt();
		for(int cas = 1; cas <=T; cas++){
			int v = in.nextInt();
			int d = in.nextInt();
			double cc = d * 9.8;
			double c2 = cc/ v/ v;
			if(c2 > 1 && c2 < 1.0000001){
				c2 = 1.0;
			}
			double ans = Math.asin(c2)* 180 / Math.PI;
			out.printf("Case #%d: %.7f\n", cas, ans/2);
		}
		in.close();
		out.close();
	}
}
