import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;
import java.util.regex.*;
import java.util.concurrent.*;
class Solution {
	static int[][] getlight(int[][] light) {
		int[][] arr = new int[light.length][light[0].length];
		for(int i = 0; i < arr.length; i++) {
			for(int j = 0; j < arr[i].length; j++)
				arr[i][j] = 1;
		}
		for(int i = 0; i < arr.length; i++) {
			for(int j = 0; j < arr[0].length; j++) {
				if(light[i][j] % 2 == 0) continue;
				else {
					if(i == 0) {
						if(j == 0) {
							arr[i][j] = (arr[i][j] == 1) ? 0 : 1;
							arr[i][j + 1] = (arr[i][j + 1] == 1) ? 0 : 1;
							arr[i + 1][j] = (arr[i + 1][j] == 1) ? 0 : 1;
						}
						else if(j == (arr[0].length - 1)) {
							arr[i][j] = (arr[i][j] == 1) ? 0 : 1;
							arr[i][j - 1] = (arr[i][j - 1] == 1) ? 0 : 1;
							arr[i + 1][j] = (arr[i + 1][j] == 1) ? 0 : 1;
						}
						else {
							arr[i][j] = (arr[i][j] == 1) ? 0 : 1;
							arr[i][j + 1] = (arr[i][j + 1] == 1) ? 0 : 1;
							arr[i][j - 1] = (arr[i][j - 1] == 1) ? 0 : 1;
							arr[i + 1][j] = (arr[i + 1][j] == 1) ? 0 : 1;							
						}
					}
					else if(i == (arr.length - 1)) {
						if(j == 0) {
							arr[i][j] = (arr[i][j] == 1) ? 0 : 1;
							arr[i][j + 1] = (arr[i][j + 1] == 1) ? 0 : 1;
							arr[i - 1][j] = (arr[i - 1][j] == 1) ? 0 : 1;
						}
						else if(j == (arr[0].length - 1)) {
							arr[i][j] = (arr[i][j] == 1) ? 0 : 1;
							arr[i][j - 1] = (arr[i][j - 1] == 1) ? 0 : 1;
							arr[i - 1][j] = (arr[i - 1][j] == 1) ? 0 : 1;
						}
						else {
							arr[i][j] = (arr[i][j] == 1) ? 0 : 1;
							arr[i][j + 1] = (arr[i][j + 1] == 1) ? 0 : 1;
							arr[i][j - 1] = (arr[i][j - 1] == 1) ? 0 : 1;
							arr[i - 1][j] = (arr[i - 1][j] == 1) ? 0 : 1;							
						}
					}
					else {
						if(j == 0) {
							arr[i][j] = (arr[i][j] == 1) ? 0 : 1;
							arr[i][j + 1] = (arr[i][j + 1] == 1) ? 0 : 1;
							arr[i + 1][j] = (arr[i + 1][j] == 1) ? 0 : 1;
							arr[i - 1][j] = (arr[i - 1][j] == 1) ? 0 : 1;
						}
						else if(j == (arr[0].length)) {
							arr[i][j] = (arr[i][j] == 1) ? 0 : 1;
							arr[i][j - 1] = (arr[i][j - 1] == 1) ? 0 : 1;
							arr[i + 1][j] = (arr[i + 1][j] == 1) ? 0 : 1;
							arr[i - 1][j] = (arr[i - 1][j] == 1) ? 0 : 1;
						}
						else {
							arr[i][j] = (arr[i][j] == 1) ? 0 : 1;
							arr[i][j + 1] = (arr[i][j + 1] == 1) ? 0 : 1;
							arr[i][j - 1] = (arr[i][j - 1] == 1) ? 0 : 1;
							arr[i + 1][j] = (arr[i + 1][j] == 1) ? 0 : 1;
							arr[i - 1][j] = (arr[i - 1][j] == 1) ? 0 : 1;							
						}
					}
				}
			}
		}
		return arr;
	}
	public static void main(String[] args) throws IOException {
		Solution sol = new Solution();
		DataInputStream in = new DataInputStream(System.in);
		int n = 3;
		int[][] light = new int[n][n];
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++)
				light[i][j] = Integer.parseInt(in.readLine());
		}
		light = sol.getlight(light);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++)
				System.out.print(light[i][j]);
			System.out.println();
		}
	}
}
