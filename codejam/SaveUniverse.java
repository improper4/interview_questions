import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;

public class SaveUniverse {
	void solve() throws FileNotFoundException{
		Scanner in = new Scanner(new File("t.in"));
		PrintWriter out = new PrintWriter("ans.out");
		int cases = in.nextInt();
		for(int i = 0; i < cases; i++){
			int ans = 0;
			int engines = in.nextInt();
			in.nextLine();
			for(int j = 0; j < engines; j++)
				in.nextLine();
			int queries = in.nextInt();
			in.nextLine();
			HashSet<String> sets = new HashSet<String>();
			for(int j = 0; j < queries; j++){
				String tmp = in.nextLine();
				sets.add(tmp);
				if(sets.size() == engines){
					ans++;
					sets.removeAll(sets);
					sets.add(tmp);
				}

			}
			out.print("Case #" + (i+1)+ ": ");
			out.println(ans);
		}
		in.close();
		out.close();
	}
	public static void main(String[] args) throws FileNotFoundException{
		new SaveUniverse().solve();
	}
}
