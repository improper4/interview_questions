import java.util.Scanner;

public class UVa_133 {
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int l, m, k;
		while((l = in.nextInt()) != 0){
			m = in.nextInt();
			k = in.nextInt();
			int rig = 0, lef = l -1;
			int cnt = 0;
			boolean[] cir = new boolean[l];
			for(int i = 0; i < l; i++)
				cir[i] = true;
			
			while(cnt < l){
				int c = 0;
				int idx = rig;
				while(c < m){
					if(idx == l) idx = 0;
					if(cir[idx++]) c++;
				}
				rig = idx -1;
				c = 0;
				idx = lef;
				while(c < k){
					if(idx == -1) idx = l-1;
					if(cir[idx--]) c++;
				}
				lef = idx+1;
				
				if(cnt > 0) System.out.print(",");
				if(lef == rig){
					cnt+= 1;
					System.out.printf("%3d", lef+1);
				}else {
					cnt+= 2;
					System.out.printf("%3d%3d",rig+1, lef+1);
				}
				
				cir[rig] = false;
				cir[lef] = false;
				
			}
			System.out.println();
		}
	}
}
