import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;
import java.util.regex.*;
import java.util.concurrent.*;
class Solution {
	static boolean getvector(int[][] vector) {
		int x_sum = 0, y_sum = 0, z_sum = 0;
		for(int i = 0; i < vector.length; i++) {
			x_sum+= vector[i][0];
			y_sum+= vector[i][1];
			z_sum+= vector[i][2];
		}
		if(x_sum == 0 && y_sum == 0 && z_sum == 0) return true;
		return false;
	}
	public static void main(String[] args) throws IOException {
		Solution sol = new Solution();
		DataInputStream in = new DataInputStream(System.in);
		int n = Integer.parseInt(in.readLine());
		int[][] vector = new int[n][3];
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < 3; j++) {
				vector[i][j] = Integer.parseInt(in.readLine());
			}
		}
		if(sol.getvector(vector)) System.out.println("YES");
		else System.out.println("NO");
	}
}
