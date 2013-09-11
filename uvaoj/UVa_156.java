import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class UVa_156{
	public static void main(String[] args) throws FileNotFoundException{
		Scanner in = new Scanner(System.in);
		int[] mark = new int[1010];
		String[] dicts = new String[1010];
		String tmpStr;
		int idx = 0;
		while(true){
			 tmpStr= in.next();
			 if(tmpStr.equals("#")) break;
			 mark[idx] = 0;
			 dicts[idx++] = tmpStr;
		}
		Arrays.sort(dicts, 0, idx);
		
		for(int i = 0; i < idx; i++)if(mark[i] == 0){
			char[] loStr = dicts[i].toLowerCase().toCharArray();
			Arrays.sort(loStr);
			
			boolean isanagram = false;
			for(int j = 0; j < idx; j++)if(i != j){
				char[] loStr2 = dicts[j].toLowerCase().toCharArray();
				Arrays.sort(loStr2);
				if(String.valueOf(loStr).equals(String.valueOf(loStr2))){
					isanagram = true;
					mark[i] = 1;
					mark[j] = 1;
					break;
				}
			}
			if(!isanagram) System.out.println(dicts[i]);
		}
	}
}
