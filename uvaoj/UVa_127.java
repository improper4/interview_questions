import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.LinkedList;
import java.util.Scanner;

import org.omg.CosNaming.NamingContextExtPackage.AddressHelper;

public class UVa_127 {
	public static void main(String[] args) throws FileNotFoundException {

		Scanner in = new Scanner(System.in);
		while(true){
			String s1 = in.nextLine();
			if(s1.length() ==1){
				break;
			}
			String s2 = in.nextLine();
			LinkedList<Cards> lists = new LinkedList<Cards>();
			String[] tmp1 = s1.split(" ");
			for(int i = 0; i < tmp1.length; i++){
				lists.add(new Cards(tmp1[i]));
			}
			String[] tmp2 = s2.split(" ");
			for(int i = 0; i < tmp2.length; i++){
				lists.add(new Cards(tmp2[i]));
			}
out:		while(true){
				for(int i = 0; i <= lists.size(); i++){
					int lef = i-3;
					if(i == lists.size())
						break out;
					if(lef >= 0 && lists.get(i).compare(lists.get(lef))){
						if(lists.get(lef).add(lists.get(i)) == 1){
							lists.remove(i);
						}
						i = 0;
					}else if(i -1 >= 0 && lists.get(i).compare(lists.get(i-1))){
						if(lists.get(i-1).add(lists.get(i)) == 1){
							lists.remove(i);
						}
						i = 0;
					}
				}
			}
			if(lists.size() == 1){
				System.out.print("1 pile remaining:");
			}else {
				System.out.print(lists.size()+ " piles remaining:");
			}
			for(Cards c: lists)
				System.out.print(" "+c.pt);
			System.out.println();
		}
		in.close();
	}
}

class Cards{
	String[] list = new String[52];
	int pt = 0;
	public Cards(String what){
		this.list[this.pt++] = what;
	}
	boolean compare(Cards ca){
		String str1 = ca.list[ca.pt-1];
		String str2 = this.list[pt-1];
		if(str1.charAt(0) == str2.charAt(0) || str1.charAt(1) == str2.charAt(1))
			return true;
		return false;
	}
	int add(Cards ca){
		this.list[pt++] = ca.list[ca.pt-1];
		ca.pt--;
		if(ca.pt == 0)	return 1;
		return 0;
	}
}