import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Scanner;


public class UVa_10194 {
	static void track(String game, HashMap<String, Club> clubs){
		String[] tmp = game.split("#");
		String[] goal = tmp[1].split("@");
		clubs.get(tmp[0]).update(0, Integer.parseInt(goal[0]),
				Integer.parseInt(goal[1]));
		clubs.get(tmp[2]).update(2, Integer.parseInt(goal[0]),
				Integer.parseInt(goal[1]));
		
	}
	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream("t.in"));
		Scanner in = new Scanner(System.in);
		int T = Integer.parseInt(in.nextLine());
		for(int i = 0; i < T; i++){
			if(i > 0)
				System.out.println();
			String Tur = in.nextLine();
			System.out.println(Tur);
			
			int totTeams = Integer.parseInt(in.nextLine());
			HashMap<String,Club> clubs = new HashMap<String,Club>();
			ArrayList<Club> ans = new ArrayList<Club>();
			for(int j = 0; j < totTeams; j++){
				String name = in.nextLine();
				Club tmp = new Club(name);
				ans.add(tmp);
				clubs.put(name, tmp);
			}
		
			int totMatchs = Integer.parseInt(in.nextLine());
			for(int j = 0; j < totMatchs; j++){
				String tmp = in.nextLine();
				track(tmp, clubs);
			}
			
			Collections.sort(ans);
			
			for(int k = 0; k < ans.size(); k++){
				Club c = ans.get(k);
				System.out.printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",
					k+1, c.name, c.pt, c.games, c.w, c.d, c.l, c.diff, c.goals, c.goaled);
			}
		}
	}
}

class Club implements Comparable<Club>{
	String name;
	int pt = 0;
	int wins = 0;
	int diff = 0;
	int goals = 0;
	int games = 0;
	int goaled = 0;
	int w, d, l;
	public Club(String str){
		w = d= l = 0;
		this.name = str;
	}
	void update(int state, int n1, int n2){
		int tmp;
		this.games++;
		if(state == 0){
			this.goals += n1;
			this.goaled += n2;
			this.wins += n1 > n2? 1: 0;
			this.diff += n1 - n2;
			tmp = n1 >n2? 3:(n1== n2? 1: 0);
		}else{
			this.goals += n2;
			this.goaled += n1;
			this.wins += n2 > n1? 1:0;
			this.diff += n2 - n1;
			tmp= n2 > n1? 3:(n2 == n1? 1: 0);
		}
		if(tmp == 3) this.w++;
		if(tmp == 1) this.d++;
		if(tmp == 0) this.l++;
		this.pt += tmp;
	}
	@Override
	public int compareTo(Club o) {
		if(this.pt > o.pt) return -1;
		if(this.pt < o.pt) return 1;
		if(this.wins > o.wins) return -1;
		if(this.wins < o.wins) return 1;
		if(this.diff > o.diff) return -1;
		if(this.diff < o.diff) return 1;
		if(this.goals > o.goals) return -1;
		if(this.goals < o.goals) return 1;
		if(this.games < o.games) return -1;
		if(this.games > o.games) return 1;
		return this.name.compareTo(o.name);
	}
	
}