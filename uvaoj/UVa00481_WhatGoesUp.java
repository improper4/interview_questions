import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;


public class UVa00481_WhatGoesUp {
	public static void main(String[] args) {
		ArrayList<Integer> list = new ArrayList<Integer>();
		Scanner in = new Scanner(System.in);
		while(in.hasNext()){
			list.add(in.nextInt());
		}
		ArrayList<Integer> ans = lisWithBiSearch(list);
		StringBuffer sb = new StringBuffer();
		sb.append(ans.size()+ "\n-\n");
		for(int x: ans)
			sb.append(x + "\n");
		System.out.print(sb);
		in.close();
	}
	
	static ArrayList<Integer> lisWithBiSearch(ArrayList<Integer> list){
		int n = list.size();
		ArrayList<Integer> m = new ArrayList<Integer>();
		
		int[] pa = new int[n];
		Arrays.fill(pa, -1);
		m.add(0);
		for(int i = 1; i < n; i++){
			int x = list.get(i);
			if( x > list.get(m.get(m.size() -1))){
				pa[i] = m.get(m.size() -1);
				m.add(i);
				
			}else {
				int left = 0, right = m.size() -1;
				while(left < right){
					int mid = (left + right)/ 2;
						
					if(list.get(m.get(mid)) > x) {
						right = mid;
					}else {
						left = mid +1;
					}
				}
				int now = left;
				if(x < list.get(m.get(now))){
					if(now > 0) pa[i] = m.get(now -1);
					m.set(now, i);
				}
			}
		}
		ArrayList<Integer> ans = new ArrayList<Integer>();
		int cur = m.get(m.size() -1);
		while(cur != -1){
			ans.add(0,list.get(cur));
			cur = pa[cur];
		}
		return ans;
	}
}
