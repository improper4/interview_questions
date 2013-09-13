import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.*;


public class UVa_755 {
	static int standEty(String str){
		int ans = 0;
		for(int i = 0; i < str.length(); i++){
			int c =0;
			switch (str.charAt(i)) {
			case 'A':case 'B':case 'C':case '2': c=2;break;
			case 'D':case 'E':case 'F':case '3': c=3;break;
			case 'G':case 'H':case 'I':case '4': c=4;break;
			case 'J':case 'K':case 'L':case '5': c=5;break;
			case 'M':case 'N':case 'O':case '6': c=6;break;
			case 'P':case 'R':case 'S':case '7': c=7;break;
			case 'T':case 'U':case 'V':case '8': c=8;break;
			case 'W':case 'X':case 'Y':case '9': c=9;break;
			case '1': c= 1;break; case '0': c=0;break;
			default:
				break;
			}
			if(str.charAt(i) != '-'){
				ans = ans*10 + c;
			}
		}
		return ans;
	}
	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream("t.in"));
		Scanner in = new Scanner(System.in);
		int T = Integer.parseInt(in.nextLine());
		in.nextLine();
		for(int cas = 1; cas <= T; cas++){
			if(cas > 1) System.out.println();
			int v = Integer.parseInt(in.nextLine());
			HashMap<Integer,Entry> dir = new HashMap<Integer,Entry>();
			ArrayList<Entry> lists = new ArrayList<Entry>();
			for(int i = 0; i < v; i++){
				String entry = in.nextLine();
				int key = standEty(entry);
				if(dir.containsKey(key)){
					Entry tmp = dir.get(key);
					if(tmp.cnt == 1)
						lists.add(tmp);
					tmp.cnt++;
				}else{
					dir.put(key, new Entry(key));
				}
			}
			if(lists.size() == 0){
				System.out.println("No duplicates.");
			}else{
				Collections.sort(lists);
				for(int i = 0; i < lists.size(); i++)
					System.out.println(lists.get(i));
			}
			
		}
	}
}

class Entry implements Comparable<Entry>{
	int cnt,num;
	public Entry(int num){
		this.num = num;
		this.cnt = 1;
	}
	
	@Override
	public int compareTo(Entry o) {
		return this.num - o.num;
	}
	@Override
	public String toString() {
		int t0 = num / 10000;
		int t1 = num % 10000;
		return t0+"-"+t1+ " "+cnt;
	}
}