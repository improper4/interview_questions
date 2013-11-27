import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class UVa10098_GeneratingFast {
	static StringBuffer sb;
	public static void main(String[] args) throws IOException{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		sb = new StringBuffer();
		int T = Integer.parseInt(in.readLine());
		for(int cas = 0; cas < T; cas++){
			String tmp = in.readLine();
			char[] str = tmp.toCharArray();
			Arrays.sort(str);
			String suffix = new String(str);
			solve("",suffix);
			sb.append('\n');
		}
		System.out.print(sb.toString());
	}
	static void solve(String prefix, String suffix){
		if(suffix.length() == 0){
			sb.append(prefix);
			sb.append('\n');
		}else{
			char prev = '#';
			for(int i = 0; i < suffix.length(); i++){
				char ch = suffix.charAt(i);
				if(prev != ch){
					solve(prefix+ ch, suffix.substring(0,i) + suffix.substring(i+1));
					prev = ch;
				}
			}
		}
	}
}
