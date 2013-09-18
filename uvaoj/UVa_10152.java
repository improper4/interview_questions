import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class UVa_10152 {
	
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(in.readLine());
		for(int cas = 0; cas < T; cas++){
			int key = -1, max = -1;
			int len = Integer.parseInt(in.readLine());
			String[] src = new String[len];
			String[] dest = new String[len];
			for(int i = 0; i < len; i++){
				src[i] = in.readLine();
			}
			for(int i = 0; i < len; i++){
				dest[i] = in.readLine();
			}
			for(int i = 0; i < len; i++){
				int j;
				for(j = 0; j < len; j++){
					if(src[i].equals(dest[j])){
						break;
					}
				}
				if(j > max){
					max = j; 
				}else if(j > key) {
					key = j;
				}
			}
			for(int i = key; i >= 0; i--){
				System.out.println(dest[i]);
			}
			System.out.println();
		}
		in.close();
	}
}
