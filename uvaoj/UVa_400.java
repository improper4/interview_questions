import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class UVa_400 {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(System.in);
		while(in.hasNext()){
			int max = 0;
			int len = in.nextInt();
			String[] ls = new String[len];
			
			for(int i = 0; i < len; i++){
				ls[i] = in.next();
				max = Math.max(max, ls[i].length());
			}
			Arrays.sort(ls);
			
			int cols = 1+(60-max) / (max+2);
			int rows = (len+ cols-1)/ cols;

			for(int i = 0; i < 60; i++)
				System.out.print("-");
			System.out.println();
			
			for(int i = 0; i < rows; i++){
				for(int j = 0; j < cols; j++) if(j*rows+i < len){
					System.out.printf("%s", ls[j*rows+i]);
					for(int k = 0; k < max- ls[j*rows+i].length(); k++)
						System.out.print(" ");
					if(j < cols -1) System.out.print("  ");
				}
				System.out.println();
			}
		}
	}
}
