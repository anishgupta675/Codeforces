import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;
import java.util.regex.*;
import java.util.concurrent.*;
class Solution {
	static int decode(String borze) {
		int i = 0, ternary = 0, n = borze.length();
		while(i < n) {
			if(borze.charAt(i) == '.') {
				ternary = (ternary * 10) + 0;
				i++;
			}
			else if(borze.charAt(i) == '-') {
				if(borze.charAt(i + 1) == '.') ternary = (ternary * 10) + 1;
				else if(borze.charAt(i + 1) == '-') ternary = (ternary * 10) + 2;
				i+= 2;
			}
		}
		return ternary;
	}
	public static void main(String[] args) throws IOException {
		Solution sol = new Solution();
		DataInputStream in = new DataInputStream(System.in);
		String borze = in.readLine();
		System.out.println(sol.decode(borze));
	}
}
