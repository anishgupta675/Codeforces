import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;
import java.util.regex.*;
import java.util.concurrent.*;
class Solution {
     /*	static int findlength(int n) {
		int count = 0;
		for(int i = n; i > 0; i/= 10)
			c++;
		return c;
	}
	static int finddigit(int n, int c) {
		int len = findlength(n);
		for(int i = n; i > 0; i/= 10)
			if(--c == 0) return (i % 10);
		return 0;
	}
	static int facevalue(int n) {
		for(int i = n; i > 0; i/= 10) {
			if(i % 10) return (i % 10);
		}
		return 0;
	}
	static int makebeautiful(int year) {
		int n = findlength(year);
		int[] arr = new int[n];
		for(int i = 0; i < n; i++)
			arr[n - i] = finddigit(year, i);
		int sum = arr[0], prev = arr[0];
		for(int i = 0; i < n; i++) {
			if(arr[i] <= prev) {
				prev+= 1;
				sum+= prev;
			} else {
				sum+= arr[i];
				prev = arr[i];
			}
		}
		return sum;
	} */
	static int makebeautiful(int year) {
		while(true) {
			year++;
			int a = year % 10;
			int b = (year / 10) % 10;
			int c = (year / 100) % 10;
			int d = (year / 1000) % 10;
			if(a != b && a != c && a != d && b != c && b != d && c != d) return year;
		}
	}
	public static void main(String[] args) throws IOException {
		Solution sol = new Solution();
		DataInputStream in = new DataInputStream(System.in);
		int year = Integer.parseInt(in.readLine());
		System.out.println(sol.makebeautiful(year));
	}
}
