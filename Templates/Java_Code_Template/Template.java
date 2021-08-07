import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;
public class Template {
	static class FastScanner {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer("");

		String next() throws IOException {
			while(!st.hasMoreTokens())
				try {
					st = new StringTokenizer(br.readLine());
				} catch(IOException e) {}
			return st.nextToken();
		}

		String nextLine() throws IOException {
			return br.readLine();
		}
		
		int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		long nextLong() throws IOException {
			return Long.parseLong(next());
		}
	}
	static PrintStream out = new PrintStream(System.out);
	static FastScanner fs = new FastScanner();
	static Template temp = new Template();
	public static void main(String[] args) throws IOException {
		int t = fs.nextInt();
		for(int i = 0; i < t; i++) {
			// driver code
		}
		out.close();
	}
}
