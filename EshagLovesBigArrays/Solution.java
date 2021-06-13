import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;
public class Solution {
	static int getmin(List<Integer> arr) {
		int min_val = Integer.MAX_VALUE;
		for(int i = 0; i < arr.size(); i++)
			if(arr.get(i) < min_val) min_val = arr.get(i);
		return min_val;
	}
	static int getmax(List<Integer> arr) {
	     /*	for(int mask = 0; mask < (1 << arr.size()); mask++) {
			for(int i = 0; i < arr.size(); i++) {
				if(mask & (1 << i)) {
				}
			}
		} */
		int count = 0, min_val = getmin(arr);
		for(int i = 0; i < arr.size(); i++)
			if(arr.get(i) > min_val) count++;
		return count;
	}
	public static void main(String[] args) throws IOException {
		Solution sol = new Solution();
		DataInputStream in = new DataInputStream(System.in);
		int t = Integer.parseInt(in.readLine());
		for(int i = 0; i < t; i++) {
			int n = Integer.parseInt(in.readLine());
			List<Integer> arr = new ArrayList<Integer>(n);
			while(n-- != 0) {
				int data = Integer.parseInt(in.readLine());
				arr.add(data);
			}
			System.out.println(sol.getmax(arr));
		}
	}
}
