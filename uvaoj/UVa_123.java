import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;


public class UVa_123 {
	static boolean isProper(String str, ArrayList<String> igWords){
		for(String s: igWords)
			if(str.equals(s))
				return false;
		return true;
	}
	public static void main(String[] args) throws IOException {
		System.setIn(new FileInputStream("t.in"));
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String buf;
		boolean isTitle = false;
		ArrayList<String> igWords = new ArrayList<String>();
		ArrayList<String> titles = new ArrayList<String>();
		
		while((buf = in.readLine()) != null){
			if(isTitle){
				titles.add(buf.toLowerCase());
			}else if(buf.equals("::")){
				isTitle = true;
			}else{
				igWords.add(buf);
			}
		}
		ArrayList<Keyword> keyList = new ArrayList<Keyword>();
		for(int i = 0; i < titles.size(); i++){
			String[] words = titles.get(i).split(" ");
			for(int j = 0; j < words.length; j++) if(isProper(words[j], igWords)){
				keyList.add(new Keyword(words[j], i, j));
			}
		}
		Collections.sort(keyList);
		for(int i = 0; i < keyList.size(); i++){
			Keyword tmp = keyList.get(i);
			String[] target = titles.get(tmp.seq).split(" ");
			for(int j = 0; j < target.length; j++){
				if(j > 0) System.out.print(" ");
				if(j == tmp.idx){
					System.out.print(tmp.str.toUpperCase());
				}else {
					System.out.print(target[j]);
				}
			}
			System.out.println();
		}
	}
}
class Keyword implements Comparable<Keyword>{
	String str;
	int idx;
	int seq;
	public Keyword(String str, int seq, int idx ){
		this.str = str;
		this.idx = idx;
		this.seq = seq;
	}
	@Override
	public int compareTo(Keyword o) {
		int ans = this.str.compareTo(o.str);
		if(ans == 0){
			return this.seq - o.seq;
		}
		return ans;
	}
}
