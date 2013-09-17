import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;

public class UVa_101 {
	static int[] locate;
	static ArrayList<LinkedList<Integer>> bricks = new ArrayList<LinkedList<Integer>>();
	static boolean isProper(int a, int b){
		if(a == b) return false;
		if(locate[a] == locate[b]) return false;
		return true;
	}
	static void restore(LinkedList<Integer> list, int a, int rm){
		int tmp;
		while((tmp = list.pop()) != a){
			locate[tmp] = tmp;
			bricks.get(locate[tmp]).push(tmp);
		}
		if(rm == 0) list.push(a);
	}
	static void merge(LinkedList<Integer> list, int a, int b){
		ArrayList<Integer> out = new ArrayList<Integer>();
		int tmp;
		while((tmp = list.pop()) != a){
			out.add(tmp);
		}
		LinkedList<Integer> stack = bricks.get(locate[b]);
		stack.push(a);
		locate[a] = locate[b];
		for(int i = out.size()-1; i >= 0; i--){
			int mm = out.get(i);
			stack.push(mm);
			locate[mm] = locate[b];
		}
	}
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = Integer.parseInt(in.nextLine());
		locate = new int[n];
		
		for(int i = 0; i < n; i++){
			LinkedList<Integer> tmp = new LinkedList<Integer>();
			tmp.push(i);
			bricks.add(tmp);
			locate[i] = i;
		}
		
		String command; 
		while((command = in.nextLine()).length() != 4){
			String[] com = command.split(" ");
			int a = Integer.parseInt(com[1]);
			int b = Integer.parseInt(com[3]);
			if(!isProper(a, b))
				continue;
			if(com[0].equals("move")){
				if(com[2].equals("onto")){
					restore(bricks.get(locate[a]), a, 1);
					restore(bricks.get(locate[b]), b, 0);
					bricks.get(locate[b]).push(a);
					locate[a] = locate[b];
				}else {
					restore(bricks.get(locate[a]), a, 1);
					bricks.get(locate[b]).push(a);
					locate[a] = locate[b];
				}
			}else{
				if(com[2].equals("onto")){
					restore(bricks.get(locate[b]), b, 0);
					merge(bricks.get(locate[a]),a, b);
				}else {
					merge(bricks.get(locate[a]),a, b);
				}
			}
		}
		
		for(int i = 0; i < bricks.size(); i++){
			System.out.print(i+ ":");
			LinkedList<Integer> tstack = bricks.get(i);
			for(int j = tstack.size() -1; j>= 0; j--)
				System.out.print(" " + tstack.get(j));
			System.out.println();
		}
	}
}
