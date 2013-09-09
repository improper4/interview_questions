import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class Osmos {
	void solve() throws FileNotFoundException{
		Scanner in = new Scanner(new File("t.in"));
		PrintWriter out = new PrintWriter("ans.out");
		int[] lists = new int[110];
		int T = in.nextInt();
		for(int c = 1; c <= T; c++){
			int mote = in.nextInt();
			int listLen = in.nextInt();

			for(int i = 0; i < listLen; i++){
				lists[i]= in.nextInt(); 
			}
			Arrays.sort(lists, 0, listLen);
			for(int i = 0; i < listLen; i++){
				System.out.print(lists[i]+" " );
			}
			System.out.println();
			int ans = listLen;
			int now = 0;
			for(int i = 0; i < listLen; i++){
				if((now + listLen -i) < ans){
					ans = now + listLen -i;
				}
				while(lists[i] >= mote && now <= ans){
					mote = mote + mote -1;
					now++;
				}
				if(now > ans) break;
				mote += lists[i];
			}
			if(now < ans)
				ans = now;
			out.printf("Case #%d: %d\n",c, ans);
		}
		in.close();
		out.close();
	}
	public static void main(String[] args) throws FileNotFoundException {
		new Osmos().solve();
	}
}
