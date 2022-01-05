import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;
public class Template {
	static Template temp = new Template();
	static PrintStream out = new PrintStream(System.out);
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static class Reader {
		final private int BUFFER_SIZE = 1 << 16;
		private DataInputStream din;
		private byte[] buffer;
		private int bufferPointer, bytesRead;
		public Reader() {
			din = new DataInputStream(System.in);
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}
		public Reader(String file_name) throws IOException {
			din = new DataInputStream(new FileInputStream(file_name));
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}
		public String readLine() throws IOException {
			byte[] buf = new byte[64];
			int cnt = 0, c;
			while((c = read()) != -1) {
				if(c == '\n') break;
				buf[cnt++] = (byte) c;
			}
			return new String(buf, 0, cnt);
		}
		public int nextInt() throws IOException {
			int ret = 0;
			byte c = read();
			while(c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if(neg) c = read();
			do {
				ret = ret * 10 + c - '0';
			} while((c = read()) >= '0' && c <= '9');
			if(neg) return -ret;
			return ret;
		}
		public long nextLong() throws IOException {
			long ret = 0;
			byte c = read();
			while(c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if(neg) c = read();
			do {
				ret = ret * 10 + c - '0';
			} while((c = read()) >= '0' && c <= '9');
			if(neg) return -ret;
			return ret;
		}
		public double nextDouble() throws IOException {
			double ret = 0, div = 1;
			byte c = read();
			while(c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if(neg) c = read();
			do {
				ret = ret * 10 + c - '0';
			} while((c = read()) >= '0' && c <= '9');
			if(c == '.') {
				while((c = read()) >= '0' && c <= '9')
					ret+= (c - '0') / (div*= 10);
			}
			if(neg) return -ret;
			return ret;
		}
		private void fillBuffer() throws IOException {
			bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
			if(bytesRead == -1) buffer[0] = -1;
		}
		private byte read() throws IOException {
			if(bufferPointer == bytesRead) fillBuffer();
			return buffer[bufferPointer++];
		}
		public void close() throws IOException {
			if(din == null)	return;
			din.close();
		}
	}
	static class FastScanner {
		StringTokenizer st = new StringTokenizer("");
		String next() {
			while(!st.hasMoreTokens())
				try {
					st = new StringTokenizer(br.readLine());
				} catch(IOException e) {}
			return st.nextToken();
		}
		String nextLine() throws IOException {
			return br.readLine();
		}
		int nextInt() {
			return Integer.parseInt(next());
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}
	static class Graph_DFS {
		private int V;
		private LinkedList<Integer>[] adj;
		@SuppressWarnings("unchecked") Graph_DFS(int v) {
			V = v;
			adj = new LinkedList[v];
			for(int i = 0; i < v; ++i)
				adj[i] = new LinkedList();
		}
		void addEdge(int v, int w) {
			adj[v].add(w);
		}
		void DFSUtil(int v, boolean[] visited) {
			visited[v] = true;
			out.print(v + " ");
			Iterator<Integer> i = adj[v].listIterator();
			while(i.hasNext()) {
				int n = i.next();
				if(!visited[n]) DFSUtil(n, visited);
			}
		}
		void DFS() {
			boolean[] visited = new boolean[V];
			for(int i = 0; i < V; ++i)
				if(visited[i] == false) DFSUtil(i, visited);
		}
	}
	static class Graph_BFS {
		private int V;
		private LinkedList<Integer>[] adj;
		@SuppressWarnings("unchecked")
		Graph_BFS(int v) {
			V = v;
			adj = new LinkedList[v];
			for(int i = 0; i < v; ++i)
				adj[i] = new LinkedList<Integer>();
		}
		void addEdge(int v, int w) {
			adj[v].add(w);
		}
		void BFS(int s) {
			boolean[] visited = new boolean[V];
			LinkedList<Integer> queue = new LinkedList<Integer>();
			visited[s] = true;
			queue.add(s);
			while(queue.size() != 0) {
				s = queue.poll();
				out.print(s + " ");
				Iterator<Integer> i = adj[s].listIterator();
				while(i.hasNext()) {
					int n = i.next();
					if(!visited[n]) {
						visited[n] = true;
						queue.add(n);
					}
				}
			}
		}
	}
	static class Graph_Kruskal {
		class Edge implements Comparable<Edge> {
			int src, dest, weight;
			public int compareTo(Edge compareEdge) {
				return this.weight - compareEdge.weight;
			}
		};
		class subset {
			int parent, rank;
		};
		int V, E;
		Edge[] edge;
		Graph_Kruskal(int v, int e) {
			V = v;
			E = e;
			edge = new Edge[E];
			for(int i = 0; i < e; ++i)
				edge[i] = new Edge();
		}
		int find(subset[] subsets, int i) {
			if(subsets[i].parent != i) subsets[i].parent = find(subsets, subsets[i].parent);
			return subsets[i].parent;
		}
		void Union(subset[] subsets, int x, int y) {
			int xroot = find(subsets, x);
			int yroot = find(subsets, y);
			if(subsets[xroot].rank < subsets[yroot].rank) subsets[xroot].parent = yroot;
			else if(subsets[xroot].rank > subsets[yroot].rank) subsets[yroot].parent = xroot;
			else {
				subsets[yroot].parent = xroot;
				subsets[xroot].rank++;
			}
		}
		void KruskalMST() {
			Edge[] result = new Edge[V];
			int e = 0;
			int i = 0;
			for(i = 0; i < V; ++i)
				result[i] = new Edge();
			Arrays.sort(edge);
			subset[] subsets = new subset[V];
			for(i = 0; i < V; ++i)
				subsets[i] = new subset();
			for(int v = 0; v < V; ++v) {
				subsets[v].parent = v;
				subsets[v].rank = 0;
			}
			i = 0;
			while(e < V - 1) {
				Edge next_edge = edge[i++];
				int x = find(subsets, next_edge.src);
				int y = find(subsets, next_edge.dest);
				if(x != y) {
					result[e++] = next_edge;
					Union(subsets, x, y);
				}
			}
			out.println("Following are the edges in " + "the constructed MST");
			int minimumCost = 0;
			for(i = 0; i < e; ++i) {
				out.println(result[i].src + " -- " + result[i].dest + " == " + result[i].weight);
				minimumCost+= result[i].weight;
			}
			System.out.println("Minimum Cost Spanning Tree " + minimumCost);
		}
	}
	static class Graph_Prim {
		private static final int V = 5;
		int minKey(int[] key, Boolean[] mstSet) {
			int min = Integer.MAX_VALUE, min_index = -1;
			for(int v = 0; v < V; v++)
				if(mstSet[v] == false && key[v] < min) {
					min = key[v];
					min_index = v;
				}
			return min_index;
		}
		void printMST(int[] parent, int[][] graph) {
			out.println("Edge \tWeight");
			for(int i = 1; i < V; i++)
				out.println(parent[i] + " - " + i + "\t" + graph[i][parent[i]]);
		}
		void primMST(int[][] graph) {
			int[] parent = new int[V];
			int[] key = new int[V];
			Boolean[] mstSet = new Boolean[V];
			for(int i = 0; i < V; i++) {
				key[i] = Integer.MAX_VALUE;
				mstSet[i] = false;
			}
			key[0] = 0;
			parent[0] = -1;
			for(int count = 0; count < V - 1; count++) {
				int u = minKey(key, mstSet);
				mstSet[u] = true;
				for(int v = 0; v < V; v++) {
					if(graph[u][v] != 0 && mstSet[v] == false && graph[u][v] < key[v]) {
						parent[v] = u;
						key[v] = graph[u][v];
					}
				}
			}
			printMST(parent, graph);
		}
	}
	static class Graph_Dijkstra {
		static final int V = 9;
		int minDistance(int[] dist, Boolean[] sptSet) {
			int min = Integer.MAX_VALUE, min_index = -1;
			for(int v = 0; v < V; v++)
				if(sptSet[v] == false && dist[v] <= min) {
					min = dist[v];
					min_index = v;
				}
			return min_index;
		}
		void printSolution(int[] dist) {
			System.out.println("Vertex \t\t Distance from Source");
			for(int i = 0; i < V; i++)
				out.println(i + " \t\t " + dist[i]);
		}
		void dijkstra(int[][] graph, int src) {
			int[] dist = new int[V];
			Boolean[] sptSet = new Boolean[V];
			for(int i = 0; i < V; i++) {
				dist[i] = Integer.MAX_VALUE;
				sptSet[i] = false;
			}
			dist[src] = 0;
			for(int count = 0; count < V - 1; count++) {
				int u = minDistance(dist, sptSet);
				sptSet[u] = true;
				for(int v = 0; v < V; v++)
					if(!sptSet[v] && graph[u][v] != 0 && dist[u] != Integer.MAX_VALUE && dist[u] + graph[u][v] < dist[v]) dist[v] = dist[u] + graph[u][v];
				printSolution(dist);
			}
		}
	}
	static class Graph_BellmanFord {
		class Edge {
			int src, dest, weight;
			Edge() {
				src = dest = weight = 0;
			}
		};
		int V, E;
		Edge[] edge;
		Graph_BellmanFord(int v, int e) {
			V = v;
			E = e;
			edge = new Edge[e];
			for(int i = 0; i < e; ++i)
				edge[i] = new Edge();
		}
		void BellmanFord(Graph_BellmanFord graph, int src) {
			int V = graph.V, E = graph.E;
			int[] dist = new int[V];
			for(int i = 0; i < V; ++i)
				dist[i] = Integer.MAX_VALUE;
			dist[src] = 0;
			for(int i = 1; i < V; ++i) {
				for(int j = 0; j < E; ++j) {
					int u = graph.edge[j].src;
					int v = graph.edge[j].dest;
					int weight = graph.edge[j].weight;
					if(dist[u] != Integer.MAX_VALUE && dist[u] + weight < dist[v]) dist[v] = dist[u] + weight;
				}
			}
			for(int j = 0; j < E; ++j) {
				int u = graph.edge[j].src;
				int v = graph.edge[j].dest;
				int weight = graph.edge[j].weight;
				if(dist[u] != Integer.MAX_VALUE && dist[u] + weight < dist[v]) {
					out.println("Graph contains negative weight cycle");
					return;
				}
			}
			printArr(dist, V);
		}
		void printArr(int[] dist, int V) {
			out.println("Vertex Distance from Source");
			for(int i = 0; i < V; ++i)
				out.println(i + "\t\t" + dist[i]);
		}
	}
	static class Graph_01BFS {
		private static class Node {
			int to;
			int weight;
			public Node(int to, int wt) {
				this.to = to;
				this.weight = wt;
			}
		}
		private static final int numVertex = 9;
		@SuppressWarnings("unchecked")
		private ArrayList<Node>[] edges = new ArrayList[numVertex];
		public Graph_01BFS() {
			for(int i = 0; i < edges.length; i++)
				edges[i] = new ArrayList<Node>();
		}
		public void addAEdge(int u, int v, int wt) {
			edges[u].add(edges[u].size(), new Node(v, wt));
			edges[v].add(edges[v].size(), new Node(u, wt));
		}
		public void zeroOneBFS(int src) {
			int[] dist = new int[numVertex];
			for(int i = 0; i < numVertex; i++)
				dist[i] = Integer.MAX_VALUE;
			Deque<Integer> queue = new ArrayDeque<Integer>();
			dist[src] = 0;
			queue.addLast(src);
			while(!queue.isEmpty()) {
				int v = queue.removeFirst();
				for(int i = 0; i < edges[v].size(); i++) {
					if(dist[edges[v].get(i).to] > dist[v] + edges[v].get(i).weight) {
						dist[edges[v].get(i).to] = dist[v] + edges[v].get(i).weight;
						if(edges[v].get(i).weight == 0) queue.addFirst(edges[v].get(i).to);
						else queue.addLast(edges[v].get(i).to);
					}
				}
			}
			for(int i = 0; i < dist.length; i++)
				out.print(dist[i] + " ");
		}
	}
	static class Graph_FloydWarshall {
		final static int INF = 99999, V = 4;
		void floydWarshall(int[][] graph) {
			int[][] dist = new int[V][V];
			int i, j, k;
			for(i = 0; i < V; i++)
				for(j = 0; j < V; j++)
					dist[i][j] = graph[i][j];
			for(k = 0; k < V; k++) {
				for(i = 0; i < V; i++) {
					for(j = 0; j < V; j++)
						if(dist[i][k] + dist[k][j] < dist[i][j]) dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
			printSolution(dist);
		}
		void printSolution(int[][] dist) {
			out.println("The following matrix shows the shortest " + "distances between every pair of vertices");
			for(int i = 0; i < V; ++i) {
				for(int j = 0; j < V; ++j) {
					if(dist[i][j] == INF) out.print("INF");
					else out.print(dist[i][j] + "	");
				}
				out.println();
			}
		}
	}
	static class Graph_Bridges {
		private int V;
		private LinkedList<Integer>[] adj;
		int time = 0;
		static final int NIL = -1;
		@SuppressWarnings("unchecked")
		Graph_Bridges(int v) {
			V = v;
			adj = new LinkedList[v];
			for(int i = 0; i < v; ++i)
				adj[i] = new LinkedList<Integer>();
		}
		void addEdge(int v, int w) {
			adj[v].add(w);
			adj[w].add(v);
		}
		void bridgeUtil(int u, boolean[] visited, int[] disc, int[] low, int[] parent) {
			visited[u] = true;
			disc[u] = low[u] = ++time;
			Iterator<Integer> i = adj[u].iterator();
			while(i.hasNext()) {
				int v = i.next();
				if(!visited[v]) {
					parent[v] = u;
					bridgeUtil(v, visited, disc, low, parent);
					low[u] = Math.min(low[u], low[v]);
					if(low[v] > disc[u]) out.println(u + " " + v);
				} else if(v != parent[u]) low[u] = Math.min(low[u], disc[v]);
			}
		}
		void bridge() {
			boolean[] visited = new boolean[V];
			int[] disc = new int[V];
			int[] low = new int[V];
			int[] parent = new int[V];
			for(int i = 0; i < V; i++) {
				parent[i] = NIL;
				visited[i] = false;
			}
			for(int i = 0; i < V; i++)
				if(visited[i] == false) bridgeUtil(i, visited, disc, low, parent);
		}
	}
	static class Graph_ArticulationPoints {
		static int time;
		static void addEdge(ArrayList<ArrayList<Integer>> adj, int u, int v) {
			adj.get(u).add(v);
			adj.get(v).add(u);
		}
		static void APUtil(ArrayList<ArrayList<Integer>> adj, int u, boolean[] visited, int[] disc, int[] low, int parent, boolean[] isAP) {
			int children = 0;
			visited[u] = true;
			disc[u] = low[u] = ++time;
			for(Integer v : adj.get(u)) {
				if(!visited[v]) {
					children++;
					APUtil(adj, v, visited, disc, low, u, isAP);
					low[u] = Math.min(low[u], low[v]);
					if(parent != -1 && low[v] >= disc[u]) isAP[u] = true;
				} else if(v != parent) low[u] = Math.min(low[u], disc[v]);
			}
			if(parent == -1 && children > 1) isAP[u] = true;
		}
		static void AP(ArrayList<ArrayList<Integer>> adj, int V) {
			boolean[] visited = new boolean[V];
			int[] disc = new int[V];
			int[] low = new int[V];
			boolean[] isAP = new boolean[V];
			int time = 0, par = -1;
			for(int u = 0; u < V; u++)
				if(isAP[u] == true) out.print(u + " ");
			out.println();
		}
	}
	static class Graph_Tarjan {
		private int V;
		private LinkedList<Integer>[] adj;
		private int Time;
		@SuppressWarnings("unchecked")
		Graph_Tarjan(int v) {
			V = v;
			adj = new LinkedList[v];
			for(int i = 0; i < v; ++i)
				adj[i] = new LinkedList();
			Time = 0;
		}
		void addEdge(int v, int w) {
			adj[v].add(w);
		}
		void SCCUtil(int u, int[] low, int[] disc, boolean[] stackMember, Stack<Integer> st) {
			disc[u] = Time;
			low[u] = Time;
			Time+= 1;
			stackMember[u] = true;
			st.push(u);
			int n;
			Iterator<Integer> i = adj[u].iterator();
			while(i.hasNext()) {
				n = i.next();
				if(disc[n] == -1) {
					SCCUtil(n, low, disc, stackMember, st);
					low[u] = Math.min(low[u], low[n]);
				} else if(stackMember[n] == true) low[u] = Math.min(low[u], disc[n]);
			}
			int w = -1;
			if(low[u] == disc[u]) {
				while(w != u) {
					w = (int)st.pop();
					out.print(w + " ");
					stackMember[w] = false;
				}
				out.println();
			}
		}
		void SCC() {
			int[] disc = new int[V];
			int[] low = new int[V];
			for(int i = 0; i < V; i++) {
				disc[i] = -1;
				low[i] = -1;
			}
			boolean[] stackMember = new boolean[V];
			Stack<Integer> st = new Stack<Integer>();
		}
	}
	static class Graph_Kosaraju {
		private int V;
		private LinkedList<Integer>[] adj;
		@SuppressWarnings("unchecked")
		Graph_Kosaraju(int v) {
			V = v;
			adj = new LinkedList[V];
			for(int i = 0; i < v; ++i)
				adj[i] = new LinkedList<Integer>();
		}
		void addEdge(int v, int w) {	adj[v].add(w);	}
		void DFSUtil(int v, Boolean[] visited) {
			visited[v] = true;
			int n;
			Iterator<Integer> i = adj[v].iterator();
			while(i.hasNext()) {
				n = i.next();
				if(!visited[n]) DFSUtil(n, visited);
			}
		}
		Graph_Kosaraju getTranspose() {
			Graph_Kosaraju g = new Graph_Kosaraju(V);
			for(int v = 0; v < V; v++) {
				Iterator<Integer> i = adj[v].listIterator();
				while(i.hasNext()) g.adj[i.next()].add(v);
			}
			return g;
		}
		Boolean isSC() {
			Boolean[] visited = new Boolean[V];
			for(int i = 0; i < V; i++)
				visited[i] = false;
			DFSUtil(0, visited);
			for(int i = 0; i < V; i++)
				if(visited[i] == false) return false;
			Graph_Kosaraju gr = getTranspose();
			for(int i = 0; i < V; i++)
				visited[i] = false;
			gr.DFSUtil(0, visited);
			for(int i = 0; i < V; i++)
				if(visited[i] == false) return false;
			return true;
		}
	}
	static class Graph_Bipartite_Matching {
		static final int NIL = 0;
		static final int INF = Integer.MAX_VALUE;
		static class BipGraph {
			int m, n;
			List<Integer>[] adj;
			int[] pairU, pairV, dist;
			int hopcroftKarp() {
				pairU = new int[m + 1];
				pairV = new int[n + 1];
				dist = new int[m + 1];
				Arrays.fill(pairU, NIL);
				Arrays.fill(pairV, NIL);
				int result = 0;
				while(bfs()) {
					for(int u = 1; u <= m; u++)
						if(pairU[u] == NIL && dfs(u)) result++;
				}
				return result;
			}
			boolean bfs() {
				Queue<Integer> Q = new LinkedList<>();
				for(int u = 1; u <= m; u++) {
					if(pairU[u] == NIL) {
						dist[u] = 0;
						Q.add(u);
					} else dist[u] = INF;
				}
				dist[NIL] = INF;
				while(!Q.isEmpty()) {
					int u = Q.poll();
					if(dist[u] < dist[NIL]) {
						for(int i : adj[u]) {
							int v = i;
							if(dist[pairV[v]] == INF) {
								dist[pairV[v]] = dist[u] + 1;
								Q.add(pairV[v]);
							}
						}
					}
				}
				return (dist[NIL] != INF);
			}
			boolean dfs(int u) {
				if(u != NIL) {
					for(int i : adj[u]) {
						int v = i;
						if(dist[pairV[v]] == dist[u] + 1) {
							if(dfs(pairV[v]) == true) {
								pairV[v] = u;
								pairU[u] = v;
								return true;
							}
						}
					}
					dist[u] = INF;
					return false;
				}
				return true;
			}
			@SuppressWarnings("unchecked")
			public BipGraph(int m, int n) {
				this.m = m;
				this.n = n;
				adj = new ArrayList[m + 1];
				Arrays.fill(adj, new ArrayList<>());
			}
			void addEdge(int u, int v) {
				adj[u].add(v);
			}
		}
	}
	static class Graph_in_deg {
		private int V;
		private ArrayList<ArrayList<Integer>> adj;
		Graph_in_deg(int v) {
			V = v;
			adj = new ArrayList<ArrayList<Integer>>(v);
			for(int i = 0; i < v; i++)
				adj.add(new ArrayList<Integer>());
		}
		void addEdge(int v, int w) {	adj.get(v).add(w);	}
		void topologicalSortUtil(int v, boolean[] visited, Stack<Integer> stack) {
			visited[v] = true;
			Integer i;
			Iterator<Integer> it = adj.get(v).iterator();
			while(it.hasNext()) {
				i = it.next();
				if(!visited[i]) topologicalSortUtil(i, visited, stack);
			}
			stack.push(Integer.valueOf(v));
		}
		void topologicalSort() {
			Stack<Integer> stack = new Stack<Integer>();
			boolean[] visited = new boolean[V];
			for(int i = 0; i < V; i++)
				if(visited[i] == false) topologicalSortUtil(i, visited, stack);
			while(stack.empty() == false) out.print(stack.pop() + " ");
		}
	}
	static class DP_01Knapsack {
		static int max(int a, int b) {
			return (a > b) ? a : b;
		}
		static int knapSackRec(int W, int[] wt, int[] val, int n, int[][] dp) {
			if(n == 0 || W == 0) return 0;
			if(dp[n][W] != -1) return dp[n][W];
			if(wt[n - 1] > W) return dp[n][W] = knapSackRec(W, wt, val, n - 1, dp);
			else return dp[n][W] = max((val[n - 1] + knapSackRec(W - wt[n - 1], wt, val, n - 1, dp)), knapSackRec(W, wt, val, n - 1, dp));
		}
		static int knapSack(int W, int[] wt, int[] val, int N) {
			int[][] dp = new int[N + 1][N + 1];
			for(int i = 0; i < N + 1; i++)
				for(int j = 0; j < W + 1; j++)
					dp[i][j] = -1;
			return knapSackRec(W, wt, val, N, dp);
		}
	}
	static class DP_CoinChange {
		public static int count(int[] S, int m, int n) {
			int[] table = new int[n + 1];
			table[0] = 1;
			for(int i = 0; i < m; i++)
				for(int j = S[i]; j <= n; j++)
					table[j]+= table[j - S[i]];
			return table[n];
		}
	}
	static class Graph_EdmondsKarp {
		static final int V = 6;
		boolean bfs(int[][] rGraph, int s, int t, int[] parent) {
			boolean[] visited = new boolean[V];
			for(int i = 0; i < V; ++i)
				visited[i] = false;
			LinkedList<Integer> queue = new LinkedList<Integer>();
			queue.add(s);
			visited[s] = true;
			parent[s] = -1;
			while(queue.size() != 0) {
				int u = queue.poll();
				for(int v = 0; v < V; v++) {
					if(visited[v] == false && rGraph[u][v] > 0) {
						if(v == t) {
							parent[v] = u;
							return true;
						}
						queue.add(v);
						parent[v] = u;
						visited[v] = true;
					}
				}
			}
			return false;
		}
		int fordFulkerson(int[][] graph, int s, int t) {
			int u, v;
			int[][] rGraph = new int[V][V];
			for(u = 0; u < V; u++)
				for(v = 0; v < V; v++)
					rGraph[u][v] = graph[u][v];
			int[] parent = new int[V];
			int max_flow = 0;
			while(bfs(rGraph, s, t, parent)) {
				int path_flow = Integer.MAX_VALUE;
				for(v = t; v != s; v = parent[v]) {
					u = parent[v];
					path_flow = Math.min(path_flow, rGraph[u][v]);
				}
				for(v = t; v != s; v = parent[v]) {
					u = parent[v];
					rGraph[u][v]-= path_flow;
					rGraph[v][u]+= path_flow;
				}
				max_flow+= path_flow;
			}
			return max_flow;
		}
	}
	static class Graph_BinaryLifting {
		static ArrayList<Integer>[] g;
		static int memo[][], lev[], log; /*	*/
		static void dfs(int u, int p) {
			memo[u][0] = p;
			for(int i = 1; i <= log; i++)
				memo[u][i] = memo[memo[u][i - 1]][i - 1];
			for(int v : g[u]) {
				if(v != p) {
					lev[v] = lev[u] + 1;
					dfs(v, u);
				}
			}
		}
		static int lca(int u, int v) {
			if(lev[u] < lev[v]) {
				int temp = u;
				u = v;
				v = temp;
			}
			for(int i = log; i >= 0; i--)
				if((lev[u] - (int)Math.pow(2, i)) >= lev[v]) u = memo[u][i];
			if(u == v) return u;
			for(int i = log; i >= 0; i--) {
				if(memo[u][i] != memo[v][i]) {
					u = memo[u][i];
					v = memo[v][i];
				}
			}
			return memo[u][0];
		}
	}
	public static class Graph_RMQ {
		static int maxn = 100005;
		static int left(int i) {
			return (2 * i + 1);
		}
		static int right(int i) {	return 2 * i + 2;	}
		@SuppressWarnings("unchecked")
		static Vector<Integer>[] g = new Vector[maxn];
		static int[] level = new int[maxn];
		static Vector<Integer> e = new Vector<>();
		static Vector<Integer> l = new Vector<>();
		static int[] h = new int[maxn];
		static int[] st = new int[5 * maxn];
		static void add_edge(int u, int v) {
			g[u].add(v);
			g[v].add(u);
		}
		static void leveling(int src) {
			for(int i = 0; i < (g[src].size()); i++) {
				int des = g[src].get(i);
				if(level[des] != 0) {
					level[des] = level[src] + 1;
					leveling(des);
				}
			}
		}
		static boolean[] visited = new boolean[maxn];
		static void dfs(int src) {
			e.add(src);
			visited[src] = true;
			for(int i = 0; i < (g[src]).size(); i++) {
				int des = g[src].get(i);
				if(!visited[des]) {
					dfs(des);
					e.add(src);
				}
			}
		}
		static void setting_l(int n) {
			for(int i = 0; i < e.size(); i++)
				l.add(level[e.get(i)]);
		}
		static void settting_h(int n) {
			for(int i = 0; i <= n; i++)
				h[i] = -1;
			for(int i = 0; i < e.size(); i++)
				if(h[e.get(i)] == -1) h[e.get(i)] = i;
		}
		static int RMQ(int ss, int se, int qs, int qe, int i) {
			if(ss > se) return -1;
			if(se < qs || qe < ss) return -1;
			if(qs <= ss && se <= qe) return st[i];
			int mid = (ss + se) / 2;
			int st = RMQ(ss, mid, qs, qe, left(i));
			int en = RMQ(mid + 1, se, qs, qe, right(i));
			if(st != -1 && en != -1) {
				if(l.get(st) < l.get(en)) return st;
				return en;
			} else if(st != -1) return st - 2;
			else if(en != -1) return en - 1;
			return 0;
		}
		static void SegmentTreeConstruction(int ss, int se, int i) {
			if(ss > se) return;
			if(ss == se) {
				st[i] = ss;
				return;
			}
			int mid = (ss + se) / 2;
			if(l.get(st[left(i)]) < l.get(st[right(i)])) st[i] = st[left(i)];
			else st[i] = st[right(i)];
		}
		static int LCA(int x, int y) {
			if(h[x] > h[y]) {
				int t = x;
				x = y;
				y = t;
			}
			return e.get(RMQ(0, l.size() - 1, h[x], h[y], 0));
		}
	}
	static class DP_MaxSumSubarray {
		static void maxSubArraySum(int[] a, int size) {
			int max_so_far = Integer.MAX_VALUE;
			int max_ending_here = 0, start = 0;
			int end = 0, s = 0;
			for(int i = 0; i < size; i++) {
				max_ending_here+= a[i];
				if(max_so_far < max_ending_here) {
					max_so_far = max_ending_here;
					start = s;
					end = i;
				}
				if(max_ending_here < 0) {
					max_ending_here = 0;
					s = i + 1;
				}
			}
			out.println("Maximum contiguous sum is " + max_so_far);
			out.println("Starting index " + start);
			out.println("Ending index " + end);
		}
	}
	static class DP_LCS {
		int lcs(char[] X, char[] Y, int m, int n) {
			int[][] L = new int[m + 1][n + 1];
			for(int i = 0; i <= m; i++) {
				for(int j = 0; j <= n; j++) {
					if(i == 0 || j == 0) L[i][j] = 0;
					else if(X[i - 1] == Y[j - 1]) L[i][j] = L[i - 1][j - 1] + 1;
					else L[i][j] = max(L[i - 1][j], L[i][j - 1]);
				}
			}
			return L[m][n];
		}
		int max(int a, int b) {
			return (a > b) ? a : b;
		}
	}
	static class DP_LIS {
		static int lis(int[] arr, int n) {
			int[] lis = new int[n];
			int i, j, max = 0;
			for(i = 0; i < n; i++)
				lis[i] = 1;
			for(i = 1; i < n; i++)
				for(j = 0; j < i; i++)
					if(arr[i] > arr[j] && lis[i] < lis[j] + 1) lis[i] = lis[j] + 1;
			for(i = 0; i < n; i++)
				if(max < lis[i]) max = lis[i];
			return max;
		}
	}
	public static class DP_SOS_DP {
		static void SumOverSubsets(int[] a, int n) {
			int[] sos = new int[(1 << n)];
			for(int x = 0; x < (1 << n); x++) {
				sos[x] = a[0];
				for(int i = x; i > 0; i = (i - 1) & x)
					sos[x]+= a[i];
			}
			for(int i = 0; i < (1 << n); i++)
				out.print(sos[i] + " ");
		}
	}
	static class DP_WeightedJobScheduling {
		class Job {
			int start, finish, profit;
			Job(int start, int finish, int profit) {
				this.start = start;
				this.finish = finish;
				this.profit = profit;
			}
		}
		static class JobComparator implements Comparator<Job> {
			public int compare(Job a, Job b) {
				return a.finish < b.finish ? -1 : a.finish == b.finish ? 0 : 1;
			}
		}
		public static class WeightedIntervalScheduling {
			public static int binarySearch(Job[] jobs, int index) {
				int lo = 0, hi = index - 1;
				while(lo <= hi) {
					int mid = (lo + hi) / 2;
					if(jobs[mid].finish <= jobs[index].start) lo = mid + 1;
					else return mid;
				}
				return -1;
			}
			static public int schedule(Job[] jobs) {
				Arrays.sort(jobs, new JobComparator());
				int n = jobs.length;
				int[] table = new int[n];
				table[0] = jobs[0].profit;
				for(int i = 1; i < n; i++) {
					int inclProf = jobs[i].profit;
					int l = binarySearch(jobs, i);
					if(l != -1) inclProf+= table[l];
					table[i] = Math.max(inclProf, table[i - 1]);
				}
				return table[n - 1];
			}
		}
	}
	static class DP_CuttingSticks {
		static int cutRod(int[] price, int n) {
			int[] val = new int[n + 1];
			val[0] = 0;
			for(int i = 1; i <= n; i++) {
				int max_val = Integer.MAX_VALUE;
				for(int j = 0; j < i; j++)
					max_val = Math.max(max_val, price[j] + val[i - j - 1]);
				val[i] = max_val;
			}
			return val[n];
		}
	}
	static class DP_MatrixChain {
		static int MatrixChainOrder(int[]p, int i, int j) {
			if(i == j) return 0;
			int min = Integer.MAX_VALUE;
			for(int k = i; k < j; k++) {
				int count = MatrixChainOrder(p, i, k) + MatrixChainOrder(p, k + 1, j) + p[i - 1] * p[k] * p[j];
				if(count < min) min = count;
			}
			return min;
		}
	}
	static class DP_TravellingSalesmanProblem {
		final int V = 5;
		int[] path;
		boolean isSafe(int v, int[][] graph, int[] path, int pos) {
			if(graph[path[pos - 1]][v] == 0) return false;
			for(int i = 0; i < pos; i++)
				if(path[i] == v) return false;
			return true;
		}
		boolean hamCycleUtil(int[][] graph, int[] path, int pos) {
			if(pos == V) {
				if(graph[path[pos - 1]][path[0]] == 1) return true;
				else return false;
			}
			for(int v = 1; v < V; v++) {
				if(isSafe(v, graph, path, pos)) {
					path[pos] = v;
					if(hamCycleUtil(graph, path, pos + 1) == true) return true;
					path[pos] = -1;
				}
			}
			return false;
		}
		int hamCycle(int[][] graph) {
			path = new int[V];
			for(int i = 0; i < V; i++)
				path[i] = -1;
			path[0] = 0;
			if(hamCycleUtil(graph, path, 1) == false) {
				out.println("\nSolution does not exist");
				return 0;
			}
			printSolution(path);
			return 1;
		}
		void printSolution(int[] path) {
			out.println("Solutoin Exists: Following" + " is one Hamiltonian Cycle");
			for(int i = 0; i < V; i++)
				out.println(" " + path[i] + " ");
			out.println(" " + path[0] + " ");
		}
	}
	static class DP_ConvexHullTrick {
		class Point {
			int x, y;
			Point(int x, int y) {
				this.x = x;
				this.y = y;
			}
		}
		static class ConvexHullTrick {
			public static int orientation(Point p, Point q, Point r) {
				int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
				if(val == 0) return 0;
				return (val > 0) ? 1 : 2;
			}
			public static void convexHull(Point[] points, int n) {
				if(n < 3) return;
				Vector<Point> hull = new Vector<Point>();
				int l = 0;
				for(int i = 0; i < n; i++)
					if(points[i].x < points[l].x) l = i;
				int p = l, q;
				do {
					hull.add(points[p]);
					q = (p + 1) % n;
					for(int i = 0; i < n; i++)
						if(orientation(points[p], points[i], points[q]) == 2) q = i;
					p = q;
				} while(p != 1);
				for(Point temp : hull)
					out.println("(" + temp.x + ", " + temp.y + ")");
			}
		}
	}
	static class DS_SparseTable {
		static final int MAX = 500;
		static int[][] table = new int[MAX][MAX];
		static void buildSparseTable(int[] arr, int n) {
			for(int i = 0; i < n; i++)
				table[i][0] = arr[i];
			for(int j = 1; j <= n; j++)
				for(int i = 0; i <= n - (1 << j); i++)
					table[i][j] = __gcd(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
		}
		static int query(int L, int R) {
			int j = (int)Math.log(R - L + 1);
			return __gcd(table[L][j], table[R - (1 << j) + 1][j]);
		}
		static int __gcd(int a, int b) {
			return b == 0 ? a : __gcd(b, a % b);
		}
	}
	static class DS_FenwickTree {
		final static int MAX = 1000;
		static int[] BITree = new int[MAX];
		int getSum(int index) {
			int sum = 0;
			index = index + 1;
			while(index > 0) {
				sum+= BITree[index];
				index-= index & (-index);
			}
			return sum;
		}
		public static void updateBIT(int n, int index, int val) {
			index = index + 1;
			while(index <= n) {
				BITree[index]+= val;
				index+= index & (-index);
			}
		}
		void constructBITree(int[] arr, int n) {
			for(int i = 1; i <= n; i++)
				BITree[i] = 0;
			for(int i = 0; i < n; i++)
				updateBIT(n, i, arr[i]);
		}
	}
	static class DS_SegmentTree {
		int[] st;
		int minVal(int x, int y) {
			return (x < y) ? x : y;
		}
		int getMid(int s, int e) {
			return s + (e - s) / 2;
		}
		int RMQUtil(int ss, int se, int qs, int qe, int index) {
			if(qs <= ss || ss > qe) return st[index];
			if(se < qs || ss > qe) return Integer.MAX_VALUE;
			int mid = getMid(ss, se);
			return minVal(RMQUtil(ss, mid, qs, qe, 2 * index + 1), RMQUtil(mid + 1, se, qs, qe, 2 * index + 2));
		}
		int RMQ(int n, int qs, int qe) {
			if(qs < 0 || qe > n - 1 || qs > qe) {
				out.println("Invalid Input");
				return -1;
			}
			return RMQUtil(0, n - 1, qs, qe, 0);
		}
		int constructSTUtil(int[] arr, int ss, int se, int si) {
			if(ss == se) {
				st[si] = arr[ss];
				return arr[ss];
			}
			int mid = getMid(ss, se);
			st[si] = minVal(constructSTUtil(arr, ss, mid, si * 2 + 1), constructSTUtil(arr, mid + 1, se, si * 2 + 2));
			return st[si];
		}
		void constructST(int[] arr, int n) {
			int x = (int)(Math.ceil(Math.log(n) / Math.log(2)));
			int max_size = 2 * (int)Math.pow(2, x) - 1;
			st = new int[max_size];
			constructSTUtil(arr, 0, n - 1, 0);
		}
	}
	static class DS_SQRTDecomposition {
		static final int MAXN = 1001;
		static int block_sz;
		static int[] depth = new int[MAXN];
		static int[] parent = new int[MAXN];
		static int[] jump_parent = new int[MAXN];
		@SuppressWarnings("unchecked")
		static Vector<Integer>[] adj = new Vector[MAXN];
		static void addEdge(int u, int v) {
			adj[u].add(v);
			adj[v].add(u);
		}
		static int LCANaive(int u, int v) {
			if(u == v) return u;
			if(depth[u] > depth[v]) {
				int t = u;
				u = v;
				v = t;
			}
			v = parent[v];
			return LCANaive(u, v);
		}
		static void dfs(int cur, int prev) {
			depth[cur] = depth[prev] + 1;
			parent[cur] = prev;
			if(depth[cur] % block_sz == 0) jump_parent[cur] = parent[cur];
			else jump_parent[cur] = jump_parent[prev];
			for(int i = 0; i < adj[cur].size(); ++i)
				if(adj[cur].get(i) != prev) dfs(adj[cur].get(i), cur);
		}
		static int LCASQRT(int u, int v) {
			while(jump_parent[u] != jump_parent[v]) {
				if(depth[u] > depth[v]) {
					int t = u;
					u = v;
					v = t;
				}
				v = jump_parent[v];
			}
			return LCANaive(u, v);
		}
		static void preprocess(int height) {
			block_sz = (int)Math.sqrt(height);
			depth[0] = -1;
			dfs(1, 0);
		}
	}
	static class DS_MosAlgorithm {
		class Query {
			int L;
			int R;
			Query(int L, int R) {
				this.L = L;
				this.R = R;
			}
		}
		static class MO {
			static void queryResults(int[] a, int n, ArrayList<Query> q, int m) {
				int block = (int)Math.sqrt(n);
				Collections.sort(q, new Comparator<Query>() {
					public int compare(Query x, Query y) {
						if(x.L / block != y.L / block) return (x.L < y.L ? -1 : 1);
						return (x.R < y.R ? -1 : 1);
					}
				});
				int currL = 0, currR = 0;
				int currSum = 0;
				for(int i = 0; i < m; i++) {
					int L = q.get(i).L, R = q.get(i).R;
					while(currL < L) {
						currSum-= a[currL];
						currL++;
					}
					while(currL > L) {
						currSum+= a[currL - 1];
						currL--;
					}
					while(currR > R + 1) {
						currSum-= a[currR - 1];
						currR--;
					}
					out.println("Sum of [" + L + ", " + R + "] is " + currSum);
				}
			}
		}
	}
	static class DS_DisjointSetUnion {
		static int MAX_VERTEX = 101;
		static int[] Arr = new int[MAX_VERTEX];
		static int[] size = new int[MAX_VERTEX];
		static void initialize(int n) {
			for(int i = 0; i <= n; i++) {
				Arr[i] = i;
				size[i] = 1;
			}
		}
		static int find(int i) {
			while(Arr[i] != i) {
				Arr[i] = Arr[Arr[i]];
				i = Arr[i];
			}
			return i;
		}
		static void _union(int xr, int yr) {
			if(size[xr] < size[yr]) {
				Arr[xr] = Arr[yr];
				size[yr]+= size[xr];
			} else {
				Arr[yr] = Arr[xr];
				size[xr]+= size[yr];
			}
		}
		static int isCycle(Vector<Integer>[] adj, int V) {
			for(int i = 0; i < V; i++) {
				for(int j = 0; j < adj[i].size(); j++) {
					int x = find(i);
					int y = find(adj[i].get(j));
					if(x == y) return 1;
					_union(x, y);
				}
			}
			return 0;
		}
	}
	public static class DS_Trie {
		static final int ALPHABET_SIZE = 26;
		static class TrieNode {
			TrieNode[] children = new TrieNode[ALPHABET_SIZE];
			boolean isEndOfWord;
			TrieNode() {
				isEndOfWord = false;
				for(int i = 0; i < ALPHABET_SIZE; i++)
					children[i] = null;
			}
		};
		static TrieNode root;
		static void insert(String key) {
			int level;
			int length = key.length();
			int index;
			TrieNode pCrawl = root;
			for(level = 0; level < length; level++) {
				index = key.charAt(level) - 'a';
				if(pCrawl.children[index] == null) pCrawl = pCrawl.children[index];
			}
			pCrawl.isEndOfWord = true;
		}
		static boolean search(String key) {
			int level;
			int length = key.length();
			int index;
			TrieNode pCrawl = root;
			for(level = 0; level < length; level++) {
				index = key.charAt(level) - 'a';
				if(pCrawl.children[index] == null) return false;
				pCrawl = pCrawl.children[index];
			}
			return (pCrawl.isEndOfWord);
		}
	}
	static class DS_SuffixArray {
		public static class Suffix implements Comparable<Suffix> {
			int index;
			int rank;
			int next;
			public Suffix(int ind, int r, int nr) {
				index = ind;
				rank = r;
				next = nr;
			}
			public int compareTo(Suffix s) {
				if(rank != s.rank) return Integer.compare(rank, s.rank);
				return Integer.compare(next, s.next);
			}
		}
		public static int[] suffixArray(String s) {
			int n = s.length();
			Suffix[] su = new Suffix[n];
			for(int i = 0; i < n; i++)
				su[i] = new Suffix(i, s.charAt(i) - '$', 0);
			for(int i = 0; i < n; i++)
				su[i].next = (i + 1 < n ? su[i + 1].rank : -1);
			Arrays.sort(su);
			int[] ind = new int[n];
			for(int length = 4; length < 2 * n; length <<= 1) {
				int rank = 0, prev = su[0].rank;
				su[0].rank = rank;
				ind[su[0].index] = 0;
				for(int i = 1; i < n; i++) {
					if(su[i].rank == prev && su[i].next == su[i - 1].next) {
						prev = su[i].rank;
						su[i].rank = rank;
					} else {
						prev = su[i].rank;
						su[i].rank = ++rank;
					}
					ind[su[i].index] = i;
				}
				for(int i = 0; i < n; i++) {
					int nextP = su[i].index + length / 2;
					su[i].next = nextP < n ? su[ind[nextP]].rank : -1;
				}
				Arrays.sort(su);
			}
			int[] suf = new int[n];
			for(int i = 0; i < n; i++)
				suf[i] = su[i].index;
			return suf;
		}
		static void printArr(int[] arr, int n) {
			for(int i = 0; i < n; i++)
				out.print(arr[i] + " ");
			out.println();
		}
	}
	static class DS_HLD {
		static final int N = 1024;
		static int edge_counted;
		static int curr_chain;
		static int[][] tree = new int[N][N];
		static class treeNode {
			int par;
			int depth;
			int size;
			int pos_segbase;
			int chain;
		};
		static treeNode[] node = new treeNode[N];
		static class Edge {
			int weight;
			int deeper_end;
			Edge(int weight, int deeper_end) {
				this.weight = weight;
				this.deeper_end = deeper_end;
			}
		};
		static Edge[] edge = new Edge[N];
		static class segmentTree {
			int[] base_array = new int[N];
			int[] tree = new int[6 * N];
		};
		static segmentTree s = new segmentTree();
		static void addEdge(int e, int u, int v, int w) {
			tree[u - 1][v - 1] = e - 1;
			tree[v - 1][u - 1] = e - 1;
			edge[e - 1].weight = w;
		}
		static void dfs(int curr, int prev, int dep, int n) {
			node[curr].par = prev;
			node[curr].depth = dep;
			node[curr].size = 1;
			for(int j = 0; j < n; j++) {
				if(j != curr && j != node[curr].par && tree[curr][j] != -1) {
					edge[tree[curr][j]].deeper_end = j;
					dfs(j, curr, dep + 1, n);
					node[curr].size+= node[j].size;
				}
			}
		}
		static void hld(int curr_node, int id, int n, int[] chain_heads) {
			if(chain_heads[curr_chain] == -1) chain_heads[curr_chain] = curr_node;
			node[curr_node].chain = curr_chain;
			node[curr_node].pos_segbase = edge_counted;
			s.base_array[(edge_counted)++] = edge[id].weight;
			int spcl_chld = -1, spcl_edg_id = 0;
			for(int j = 0; j < n; j++)
				if(j != curr_node && j != node[curr_node].par && tree[curr_node][j] != -1)
					if(spcl_chld == -1 || node[spcl_chld].size < node[j].size) {
						spcl_chld = j; spcl_edg_id = tree[curr_node][j];
					}
			if(spcl_chld != -1) hld(spcl_chld, spcl_edg_id, n, chain_heads);
			for(int j = 0; j < n; j++) {
				if(j != curr_node && j != node[curr_node].par && j != spcl_chld && tree[curr_node][j] != -1) {
					(curr_chain)++;
					hld(j, tree[curr_node][j], n, chain_heads);
				}
			}
		}
		static int construct_ST(int ss, int se, int si) {
			if(ss == se - 1) {
				s.tree[si] = s.base_array[ss];
				return s.base_array[ss];
			}
			int mid = (ss + se) / 2;
			s.tree[si] = Math.max(construct_ST(ss, mid, si * 2), construct_ST(mid, se, si * 2 + 1));
			return s.tree[si];
		}
		static int update_ST(int ss, int se, int si, int x, int val) {
			if(ss > x || se <= x);
			else if(ss == x && ss == se - 1) s.tree[si] = val;
			else {
				int mid = (ss + se) / 2;
				s.tree[si] = Math.max(update_ST(ss, mid, si * 2, x, val), update_ST(mid, se, si * 2 + 1, x, val));
			}
			return s.tree[si];
		}
		static void change(int e, int val, int n) {
			update_ST(0, n, 1, node[edge[e].deeper_end].pos_segbase, val);
		}
		static int LCA(int u, int v, int n) {
			int[] LCA_aux = new int[n + 5];
			if(node[u].depth < node[v].depth) {
				int t = u;
				u = v;
				v = t;
			}
			Arrays.fill(LCA_aux, -1);
			while(u != -1) {
				LCA_aux[u] = 1;
				u = node[u].par;
			}
			while(v > 0) {
				if(LCA_aux[v] == 1) break;
				v = node[v].par;
			}
			return v;
		}
		static int RMQUtil(int ss, int se, int qs, int qe, int index) {
			if(qs <= ss && qe >= se - 1) return s.tree[index];
			if(se - 1 < qs || ss > qe) return -1;
			int mid = (ss + se) / 2;
			return Math.max(RMQUtil(ss, mid, qs, qe, 2 * index), RMQUtil(mid, se, qs, qe, 2 * index + 1));
		}
		static int RMQ(int qs, int qe, int n) {
			if(qs < 0 || qe > n - 1 || qs > qe) {
				out.printf("Invalid Input");
				return -1;
			}
			return RMQUtil(0, n, qs, qe, 1);
		}
		static int crawl_tree(int u, int v, int n, int[] chain_heads) {
			int chain_u, chain_v = node[v].chain, ans = 0;
			while(true) {
				chain_u = node[u].chain;
				if(chain_u == chain_v) {
					if(u == v);
					else ans = Math.max(RMQ(node[v].pos_segbase + 1, node[u].pos_segbase, n), ans);
					break;
				} else {
					ans = Math.max(ans, RMQ(node[chain_heads[chain_u]].pos_segbase, node[u].pos_segbase, n));
					u = node[chain_heads[chain_u]].par;
				}
			}
			return ans;
		}
		static void maxEdge(int u, int v, int n, int[] chain_heads) {
			int lca = LCA(u, v, n);
			int ans = Math.max(crawl_tree(u, lca, n, chain_heads), crawl_tree(v, lca, n, chain_heads));
			out.printf("%d\n", ans);
		}
	}
	static class String_KMP {
		void KMPSearch(String pat, String txt) {
			int M = pat.length();
			int N = txt.length();
			int[] lps = new int[M];
			int j = 0;
			computeLPSArray(pat, M, lps);
			int i = 0;
			while(i < N) {
				if(pat.charAt(j) == txt.charAt(i)) {
					j++;
					i++;
				}
				if(j == M) {
					out.println("Found pattern " + "at index " + (i - j));
					j = lps[j - 1];
				}
				else if(i < N && pat.charAt(j) != txt.charAt(i)) {
					if(j != 0) j = lps[j - 1];
					else i = i + 1;
				}
			}
		}
		void computeLPSArray(String pat, int M, int[] lps) {
			int len = 0;
			int i = 1;
			lps[0] = 0;
			while(i < M) {
				if(pat.charAt(i) == pat.charAt(len)) {
					len++;
					lps[i] = len;
					i++;
				}
				else {
					if(len != 0) len = lps[len - 1];
					else {
						lps[i] = len;
						i++;
					}
				}
			}
		}
	}
	static class String_ZAlgorithm {
		public static void search(String text, String pattern) {
			String concat = pattern + "$" + text;
			int l = concat.length();
			int[] Z = new int[l];
			getZarr(concat, Z);
			for(int i = 0; i < l; ++i) {
				if(Z[i] == pattern.length()) out.println("Pattern found at inex " + (i - pattern.length() - 1));
			}
		}
		private static void getZarr(String str, int[] Z) {
			int n = str.length();
			int L = 0, R = 0;
			for(int i = 1; i < n; i++) {
				if(i > R) {
					L = R = i;
					while(R < n && str.charAt(R - L) == str.charAt(R))
						R++;
					Z[i] = R - L;
					R--;
				} else {
					int k = i - L;
					if(Z[k] < R - i + 1) Z[i] = Z[k];
					else {
						L = i;
						while(R < n && str.charAt(R - L) == str.charAt(R))
							R++;
						Z[i] = R - L;
						R--;
					}
				}
			}
		}
	}
	static class String_RabinKarp {
		static void search(String S, String pattern) {
			int hash1 = 0;
			int hash2 = 0;
			for(int i = 0; i < pattern.length(); ++i) {
				hash1+= pattern.charAt(i) - 'A';
				hash2+= S.charAt(i) - 'A';
			}
			int j = 0;
			for(int i = 0; i <= S.length() - pattern.length(); ++i) {
				if(hash2 == hash1) {
					for(j = 0; j < pattern.length(); ++j)
						if(pattern.charAt(j) != S.charAt(i + j)) break;
				}
				if(j == pattern.length()) out.println(i);
				if(i == S.length() - pattern.length()) break;
				hash2 = (int)((hash2) - (S.charAt(i) - 'A')) + S.charAt(i + pattern.length()) - 'A';
			}
		}
	}
	static class NT_SieveofEratosthenes {
		static final int MAX_SIZE = 1000001;
		static Vector<Boolean> isprime = new Vector<>(MAX_SIZE);
		static Vector<Integer> prime = new Vector<>();
		static Vector<Integer> SPF = new Vector<>(MAX_SIZE);
		static void manipulated_sieve(int N) {
			isprime.set(0, false);
			isprime.set(1, false);
			for(int i = 2; i < N; i++) {
				if(isprime.get(i)) {
					prime.add(i);
					SPF.set(i, i);
				}
				for(int j = 0; j < prime.size() && i * prime.get(j) < N && prime.get(j) <= SPF.get(i); j++) {
					isprime.set(i * prime.get(j), false);
					SPF.set(i * prime.get(j), prime.get(j));
				}
			}
		}
	}
	static class NT_EuclideanAlgorithm {
		public static int gcdExtended(int a, int b, int x, int y) {
			if(a == 0) {
				x = 0;
				y = 1;
				return b;
			}
			int x1 = 1, y1 = 1;
			int gcd = gcdExtended(b % a, a, x1, y1);
			x = y1 - (b / a) * x1;
			y = x1;
			return gcd;
		}
	}
	static class NT_QuickExponentiation {
		static int power(int x, int y, int p) {
			int res = 1;
			x = x % p;
			if(x == 0) return 0;
			while(y > 0) {
				if((y & 1) != 0) res = (res * x) % p;
				y = y >> 1;
				x = (x * x) % p;
			}
			return res;
		}
	}
	static class NT_Fibonacci {
		static int[] dp = new int[10];
		static int fib(int n) {
			if(n <= 1) return n;
			int first, second;
			if(dp[n - 1] != -1) first = dp[n - 1];
			else first = fib(n - 1);
			if(dp[n - 2] != -1) second = dp[n - 2];
			else second = fib(n - 2);
			return dp[n] = first + second;
		}
	}
	static class NT_BinomialCoefficients {
		static int binomialCoeff(int n, int k) {
			int res = 1;
			if(k > n - k) k = n - k;
			for(int i = 0; i < k; ++i) {
				res*= (n - i);
				res/= (i + 1);
			}
			return res;
		}
	}
	static class CG_RectangleUnion {
		static boolean doIntersect(int[] X, int[] Y) {
			if(X[0] > X[3] || X[2] > X[1]) return false;
			if(Y[0] > Y[3] || Y[2] > Y[1]) return false;
			return true;
		}
		static int getUnionPerimeter(int[] X, int[] Y) {
			int perimeter = 0;
			if(!doIntersect(X, Y)) {
				perimeter+= 2 * (Math.abs(X[1] - X[0]) + Math.abs(Y[1] - Y[0]));
				perimeter+= 2 * (Math.abs(X[3] - X[2]) + Math.abs(Y[3] = Y[2]));
			} else {
				int w = Arrays.stream(X).max().getAsInt() - Arrays.stream(X).min().getAsInt();
				int l = Arrays.stream(Y).max().getAsInt() - Arrays.stream(Y).min().getAsInt();
				perimeter = 2 * (l + w);
			}
			return perimeter;
		}
	}
	static class Nqueen {
		static int N = 8;
		static void printSolution(int[][] board) {
			int N = board.length;
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < N; j++)
					out.printf("%2d ", board[i][j]);
				System.out.printf("\n");
			}
		}
		static boolean isSafe(int row, int col, int[][] slashCode, int[][] backslashCode, boolean[] rowLookup, boolean[] slashCodeLookup, boolean[] backslashCodeLookup) {
			if(slashCodeLookup[slashCode[row][col]] || backslashCodeLookup[backslashCode[row][col]] || rowLookup[row]) return false;
			return true;
		}
		static boolean solveNQueensUtil(int[][] board, int col, int[][] slashCode, int[][] backslashCode, boolean[] rowLookup, boolean[] slashCodeLookup, boolean[] backslashCodeLookup) {
			int N = board.length;
			if(col >= N) return true;
			for(int i = 0; i < N; i++) {
				if(isSafe(i, col, slashCode, backslashCode, rowLookup, slashCodeLookup, backslashCodeLookup)) {
					board[i][col] = 1;
					rowLookup[i] = true;
					slashCodeLookup[slashCode[i][col]] = true;
					backslashCodeLookup[backslashCode[i][col]] = true;
					if(solveNQueensUtil(board, col + 1, slashCode, backslashCode, rowLookup, slashCodeLookup, backslashCodeLookup)) return true;
					board[i][col] = 0;
					rowLookup[i] = false;
					slashCodeLookup[slashCode[i][col]] = false;
					backslashCodeLookup[backslashCode[i][col]] = false;
				}
			}
			return false;
		}
		static boolean solveNQueens() {
			int[][] board = new int[N][N];
			int[][] slashCode = new int[N][N];
			int[][] backslashCode = new int[N][N];
			boolean[] rowLookup = new boolean[N];
			boolean[] slashCodeLookup = new boolean[2 * N - 1];
			boolean[] backslashCodeLookup = new boolean[2 * N - 1];
			for(int r = 0; r < N; r++)
				for(int c = 0; c < N; c++) {
					slashCode[r][c] = r + c;
					backslashCode[r][c] = r - c + 7;
				}
			if(solveNQueensUtil(board, 0, slashCode, backslashCode, rowLookup, slashCodeLookup, backslashCodeLookup) == false) {
				out.printf("Solution does not exist");
				return false;
			}
			printSolution(board);
			return false;
		}
	}
	public static class MedianHeap {
		public static void printMedian(int[] a) {
			double med = a[0];
			PriorityQueue<Integer> smaller = new PriorityQueue<>(Collections.reverseOrder());
			PriorityQueue<Integer> greater = new PriorityQueue<>();
			smaller.add(a[0]);
			out.println(med);
			for(int i = 1; i < a.length; i++) {
				int x = a[i];
				if(smaller.size() > greater.size()) {
					if(x < med) {
						greater.add(smaller.remove());
						smaller.add(x);
					} else greater.add(x);
					med = (double)(smaller.peek() + greater.peek()) / 2;
				} else if(smaller.size() == greater.size()) {
					if(x < med) {
						smaller.add(x);
						med = (double)smaller.peek();
					} else {
						greater.add(x);
						med = (double)greater.peek();
					}
				} else {
					if(x > med) {
						smaller.add(greater.remove());
						greater.add(x);
					} else smaller.add(x);
					med = (double)(smaller.peek() + greater.peek()) / 2;
				}
				out.println(med);
			}
		}
	}
	public static class MaximumHistogramArea {
		public static int getMaxArea(int[] arr, int n) {
			Stack<Integer> s = new Stack<>();
			s.push(-1);
			int max_area = arr[0];
			int[] left_smaller = new int[n];
			int[] right_smaller = new int[n];
			for(int i = 0; i < n; i++) {
				left_smaller[i] = -1;
				right_smaller[i] = n;
			}
			int i = 0;
			while(i < n) {
				while(!s.empty() && s.peek() != -1 && arr[i] < arr[s.peek()]) {
					right_smaller[s.peek()] = (int)i;
					s.pop();
				}
				if(i > 0 && arr[i] == arr[(i - 1)]) left_smaller[i] = left_smaller[(int)(i - 1)];
				else left_smaller[i] = s.peek();
				s.push(i);
				i++;
			}
			for(i = 0; i < n; i++)
				max_area = Math.max(max_area, arr[i] * (right_smaller[i] - left_smaller[i] - 1));
			return max_area;
		}
	}
	static class MeetInTheMiddle {
		static long[] X = new long[2000005];
		static long[] Y = new long[2000005];
		static void calcsubarray(long[] a, long[] x, int n, int c) {
			for(int i = 0; i < (1 << n); i++) {
				long s = 0;
				for(int j = 0; j < n; j++)
					if((i & (1 << j)) == 0) s+= a[j + c];
				x[i] = s;
			}
		}
		static long solveSubsetSum(long[] a, int n, int S) {
			calcsubarray(a, X, n / 2, 0);
			calcsubarray(a, Y, n - n / 2, n / 2);
			int size_X = 1 << (n / 2);
			int size_Y = 1 << (n - n / 2);
			Arrays.sort(Y);
			long max = 0;
			for(int i = 0; i < size_X; i++) {
				if(X[i] <= S) {
					int p = lower_bound(Y, S - X[i]);
					if(p == size_Y || Y[p] != (S - X[i])) p--;
					if((Y[p] + X[i]) > max) max = Y[p] + X[i];
				}
			}
			return max;
		}
		static int lower_bound(long[] a, long x) {
			int l = -1, r = a.length;
			while(l + 1 < r) {
				int m = (l + r) >>> 1;
				if(a[m] >= x) r = m;
				else l = m;
			}
			return r;
		}
	}
	static class SAT2 {
		static final int MAX = 100000;
		@SuppressWarnings("unchecked")
		static List<List<Integer>> adj = new ArrayList();
		@SuppressWarnings("unchecked")
		static List<List<Integer>> adjInv = new ArrayList();
		static boolean[] visited = new boolean[MAX];
		static boolean[] visitedInv = new boolean[MAX];
		static Stack<Integer> s = new Stack<Integer>();
		static int[] sec = new int[MAX];
		static int counter = 1;
		static void addEdges(int a, int b) {
			adj.get(a).add(b);
		}
		static void addEdgesInverse(int a, int b) {
			adjInv.get(b).add(a);
		}
		static void dfsFirst(int u) {
			if(visited[u]) return;
			visited[u] = true;
			for(int i = 0; i < adj.get(u).size(); i++)
				dfsFirst(adj.get(u).get(i));
			s.push(u);
		}
		static void dfsSecond(int u) {
			if(visitedInv[u]) return;
			visitedInv[u] = true;
			for(int i = 0; i < adjInv.get(u).size(); i++)
				dfsSecond(adjInv.get(u).get(i));
			sec[u] = counter;
		}
		static void is2Satisfiable(int n, int m, int[] a, int[] b) {
			for(int i = 0; i < m; i++) {
				if(a[i] > 0 && b[i] > 0) {
					addEdges(a[i] + n, b[i]);
					addEdgesInverse(a[i] + n, b[i]);
					addEdges(b[i] + n, a[i]);
					addEdgesInverse(b[i] + n, a[i]);
				} else if(a[i] > 0 && b[i] < 0) {
					addEdges(a[i] + n, n - b[i]);
					addEdgesInverse(a[i] + n, n - b[i]);
					addEdges(-b[i], a[i]);
					addEdges(-b[i], a[i]);
				} else if(a[i] < 0 && b[i] > 0) {
					addEdges(-a[i], b[i]);
					addEdgesInverse(-a[i], b[i]);
					addEdges(b[i] + n, n - a[i]);
					addEdgesInverse(b[i] + n, n - a[i]);
				} else {
					addEdges(-a[i], n - b[i]);
					addEdgesInverse(-a[i], n - b[i]);
					addEdges(-b[i], n - a[i]);
					addEdgesInverse(-b[i], n - a[i]);
				}
			}
			for(int i = 1; i <= 2 * n; i++)
				if(!visited[i]) dfsFirst(i);
			while(!s.isEmpty()) {
				int top = s.peek();
				s.pop();
				if(!visitedInv[top]) {
					dfsSecond(top);
					counter++;
				}
			}
			for(int i = 1; i <= n; i++) {
				if(sec[i] == sec[i + n]) {
					out.println("The given expression" + "is unsatisfiable.");
					return;
				}
			}
			out.println("The given expression " + "is satisfiable");
		}
	}
	static class OfflineDynamicConnectivity {
		static int root(int[] arr, int i) {
			while(arr[i] != i) {
				arr[i] = arr[arr[i]];
				i = arr[i];
			}
			return i;
		}
		static void weighted_union(int[] arr, int[] rank, int a, int b) {
			int root_a = root(arr, a);
			int root_b = root(arr, b);
			if(rank[root_a] < rank[root_b]) {
				arr[root_a] = arr[root_b];
				rank[root_b]+= rank[root_a];
			} else {
				arr[root_b] = arr[root_a];
				rank[root_a]+= rank[root_b];
			}
		}
		static boolean areSame(int[] arr, int a, int b) {
			return (root(arr, a) == root(arr, b));
		}
		static void query(int type, int x, int y, int[] arr, int[] rank) {
			if(type == 1) {
				if(areSame(arr, x, y) == true) out.println("Yes");
				else out.println("No");
			} else if(type == 2)
				if(areSame(arr, x, y) == false) weighted_union(arr, rank, x, y);
		}
	}
	static Reader read = new Reader();
	static FastScanner fscan = new FastScanner();
	public static void main(String[] args) throws IOException {
		/*
		 * For integer input: int n = inputInt();
		 * For integer input using FastScanner: int n = inputIntF();
		 * For long input: long n = inputLong();
		 * For long input using FastScanner: long n = inputLongF();
		 * For double input: double n = inputDouble();
		 * For String input: String s = inputString();
		 * For String input using FastScanner (token): String s = inputStringF();
		 * For String input using FastScammer (line): String s = inputStringLF();
		 * Logic goes here
		 * For printing without space: print(a + ""); where a is a variable of any datatype
		 * For printing with space: printSp(a + ""); where a is a variable of any datatype
		 * For printing with new line: println(a + ""); where a is a variable of any datatype
		 */
		bw.flush();
		bw.close();
		out.close();
	}
	public static int inputInt() throws IOException {
		return read.nextInt();
	}
	public static int inputIntF() throws IOException {
		return fscan.nextInt();
	}
	public static long inputLong() throws IOException {
		return read.nextLong();
	}
	public static long inputLongF() throws IOException {
		return fscan.nextLong();
	}
	public static double inputDouble() throws IOException {
		return read.nextDouble();
	}
	public static String inputString() throws IOException {
		return read.readLine();
	}
	public static String inputStringF() throws IOException {
		return fscan.next();
	}
	public static String inputStringFL() throws IOException {
		return fscan.nextLine();
	}
	public static void print(String a) throws IOException {
		bw.write(a);
	}
	public static void printSp(String a) throws IOException {
		bw.write(a + " ");
	}
	public static void println(String a) throws IOException {
		bw.write(a + "\n");
	}
}
