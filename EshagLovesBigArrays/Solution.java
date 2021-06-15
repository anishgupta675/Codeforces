import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;
public class Solution {
	static int getmax(int[] arr) {
		int count = 0, min_val = arr[0];
		for(int i = 0; i < arr.length; i++) {
			if(arr[i] != min_val) count++;
			if(arr[i] < min_val) min_val = arr[i];
		}
		return count;
	}
	public static void main(String[] args) throws IOException {
		Solution sol = new Solution();
		DataInputStream in = new DataInputStream(System.in);
		int t = Integer.parseInt(in.readLine());
		for(int i = 0; i < t; i++) {
			int n = Integer.parseInt(in.readLine());
			int[] arr = new int[n];
			for(int j = 0; j < n; j++)
				arr[j] = Integer.parseInt(in.readLine());
			System.out.println(sol.getmax(arr));
		}
	}
}
