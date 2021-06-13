import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;
import java.util.regex.*;
import java.util.concurrent.*;
class Solution {
	static int makebeautiful(int[][] mat) {
		int count = 0;
		for(int i = 0; i < mat.length; i++) {
			for(int j = 0; j < mat[0].length; j++)
				if(mat[i][j] == 1) count = (Math.abs(j - ((mat[0].length + 1) / 2)) + Math.abs(i - ((mat.length + 1) / 2)));
		}
		return count;
	}
	public static void main(String[] args) throws IOException {
		Solution sol = new Solution();
		DataInputStream in = new DataInputStream(System.in);
		int n = Integer.parseInt(in.readLine());
		if(n % 2 == 0) throw new IllegalArgumentException("Please enter a valid odd integer");
		else {
			int[][] mat = new int[n][n];
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++)
					mat[i][j] = Integer.parseInt(in.readLine());
			}
			System.out.println(sol.makebeautiful(mat));
		}
	}
}
