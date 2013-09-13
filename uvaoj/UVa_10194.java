import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;

public class UVa_10194 {
	static void track(String game, HashMap<String, Integer> clubMap, Club[] clubs){
		String[] tmp = game.split("#");
		String[] goal = tmp[1].split("@");
		clubs[clubMap.get(tmp[0])].update(Integer.parseInt(goal[0]),
				Integer.parseInt(goal[1]));
		clubs[clubMap.get(tmp[2])].update(Integer.parseInt(goal[1]),
				Integer.parseInt(goal[0]));
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in,"ISO-8859-1"));
		PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out, "ISO-8859-1"));
		int T = Integer.parseInt(in.readLine());
		for(int i = 0; i < T; i++){
			if(i > 0)
				out.println();
			String Tur = in.readLine();
			out.println(Tur);
			
			int totTeams = Integer.parseInt(in.readLine());
			HashMap<String,Integer> teamRank = new HashMap<String,Integer>();
			Club[] ans = new Club[totTeams];
			for(int j = 0; j < totTeams; j++){
				String name = in.readLine();
				teamRank.put(name, j);
				ans[j] = new Club(name);
			}
		
			int totMatchs = Integer.parseInt(in.readLine());
			for(int j = 0; j < totMatchs; j++){
				String game = in.readLine();
				track(game, teamRank, ans);
			}
			Arrays.sort(ans);
			
			for(int k = 0; k < ans.length; k++){
				Club c = ans[k];
				out.println(k+1 + ") "+ c.name +" "+c.pt+"p, "+ c.games
					+"g ("+ c.w+ "-"+ c.d+"-"+ c.l+"), "+ c.diff+ "gd ("+ c.goals+"-"+ c.goaled+")");
			}
		}
		in.close();
		out.close();
	}
}

class Club implements Comparable<Club>{
	String name;
	int pt = 0;
	int diff = 0;
	int goals = 0;
	int games = 0;
	int goaled = 0;
	int w, d, l;
	public Club(String str){
		w = d= l = 0;
		this.name = str;
	}
	void update(int n1, int n2){
		int tmp;
		this.games++;
		this.goals += n1;
		this.goaled += n2;
		this.diff = this.goals - this.goaled;
		tmp = n1 >n2? 3:(n1== n2? 1: 0);
	
		if(tmp == 3) this.w++;
		if(tmp == 1) this.d++;
		if(tmp == 0) this.l++;
		this.pt += tmp;
	}
	@Override
	public int compareTo(Club o) {
		if(this.pt != o.pt) return o.pt - this.pt;
		if(this.w != o.w) return o.w -this.w;
		if(this.diff != o.diff) return o.diff -this.diff ;
		if(this.goals != o.goals) return o.goals- this.goals;
		if(this.games != o.games) return this.games - o.games;
		return this.name.toLowerCase().compareTo(o.name.toLowerCase());
	}
}