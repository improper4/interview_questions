import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class Tomek {
	String[] tomek = new String[4];
	boolean iswin(char ch){
		boolean haswin = true;
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				haswin = (ch == tomek[i].charAt(j)||  tomek[i].charAt(j)== 'T') ? true: false;
				if(!haswin) break;
			}
			if(haswin) return true;
		}
		
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				haswin = (ch == tomek[j].charAt(i)|| tomek[j].charAt(i) == 'T')? true: false;
				if(!haswin) break;
			}
			if(haswin) return true;
		}

		for(int i = 0; i < 4; i++){
			haswin = (ch == tomek[i].charAt(i) || tomek[i].charAt(i)== 'T')? true: false;
			if(!haswin) break;
		}
		if(haswin) return true;

		for(int i = 0; i < 4; i++){
			haswin = (ch == tomek[i].charAt(3-i) || tomek[i].charAt(3-i)== 'T')? true: false;
			if(!haswin) break;
		}
		return haswin;
	}
	boolean hasDot(){
		for(int i = 0; i < 4; i++)
			for(int j = 0; j < 4; j++)
				if(tomek[i].charAt(j) == '.')
					return true;
		return false;
	}
	void solve() throws FileNotFoundException{
		Scanner in = new Scanner(new File("t.in"));
		PrintWriter out = new PrintWriter("ans.out");

		int T = in.nextInt();
		in.nextLine();
		for(int i = 0; i < T; i++){
			for(int j = 0; j < 4; j++){
				tomek[j]= in.nextLine(); 
			}
			in.nextLine();
			out.print("Case #"+ (i+1) + ": ");
			if(iswin('X')){
				out.println("X won");
			}else if(iswin('O')){
				out.println("O won");
			}else if(hasDot()){
				out.println("Game has not completed");
			}else{
				out.println("Draw");
			}
		}
		in.close();
		out.close();
	}
	public static void main(String[] args) throws FileNotFoundException {
		new Tomek().solve();
	}
}
