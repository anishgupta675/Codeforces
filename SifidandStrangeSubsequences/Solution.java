import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;
import java.util.regex.*;
import java.util.concurrent.*;
class Solution {
	static void merge(int[] a, int low, int mid, int high) {
		int n1 = mid - low + 1;
		int n2 = high - mid;
		int[] L = new int[n1];
		int[] R = new int[n2];
		for(int i = 0; i < n1; i++)
			L[i] = a[low + i];
		for(int j = 0; j < n2; j++)
			R[j] = a[mid + 1 + j];
		int i = 0, j = 0, k = low;
		while(i < n1 && j < n2) {
			if(L[i] <= R[j]) {
				a[k] = L[i];
				i++;
			} else {
				a[k] = R[j];
				j++;
			}
			k++;
		}
		while(i < n1) {
			a[k] = L[i];
			i++;
			k++;
		}
		while(j < n2) {
			a[k] = R[j];
			j++;
			k++;
		}
	}
	static void sort(int[] a, int low, int high) {
		if(low < high) {
			int mid = low + ((high - low) / 2);
			sort(a, low, mid);
			sort(a, mid + 1, high);
			merge(a, low, mid, high);
		}
	}
	static int getstrange(int[] a, int ans) {
		int min_val = Integer.MAX_VALUE;
		sort(a, 0, a.length - 1);
		for(int i = 0; i < a.length; i++)
			if(a[i] > 0) min_val = Math.min(min_val, a[i]);
		int flag = (min_val < Integer.MAX_VALUE) ? 1 : 0;
		for(int i = 1; i < a.length; i++)
			if(a[i] <= 0) flag&= (a[i] - a[i - 1] >= min_val) ? 1 : 0;
		if(flag != 0) return ans + 1;
		else return ans;
	}
	public static void main(String[] args) throws IOException {
		Solution sol = new Solution();
		DataInputStream in = new DataInputStream(System.in);
		int t = Integer.parseInt(in.readLine());
		for(int i = 0; i < t; i++) {
			int n = Integer.parseInt(in.readLine());
			int[] a = new int[n];
			int ans = 0;
			for(int j = 0; j < n; j++) {
				a[j] = Integer.parseInt(in.readLine());
				ans+= (a[j] <= 0) ? 1 : 0;
			}
			System.out.println(sol.getstrange(a, ans));
		}
	}
}
