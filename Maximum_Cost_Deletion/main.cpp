#include<filesystem>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
#include<queue>
#include<deque>
#include<bitset>
#include<iterator>
#include<list>
#include<stack>
#include<map>
#include<set>
#include<functional>
#include<numeric>
#include<utility>
#include<limits>
#include<time.h>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define SCD(t) scanf("%d", &t)
#define SCLD(t) scanf("%ld", &t)
#define SCLLD(t) scanf("%lld", &t)
#define SCC(t) scanf("%c", &t)
#define SCS(t) scanf("%s", t)
#define SCF(t) scanf("%f", &t)
#define SCLF(t) scanf("%lf", &t)
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for(i = j; i < k; i+= in)
#define RFOR(i, j, k, in) for(i = j; i >= k; i-= in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), con.begin()
#define FOREACH(it, l) for(auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert(B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define read(type) readInt<type>()
const int N = 3;
const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ll LINF = 1e18;
const double pi = acos(-1.0);
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef vector<array<int, N>> VA;
typedef map<int, int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef ll int int64;
typedef unsigned ll int uint64;
template<typename T, typename U> inline void amin(T &x, U y) {if(y < x) x = y;}
template<typename T, typename U> inline void amax(T &x, U y) {if(x < y) x = y;}
template<typename T> inline void write(T x) {
	int i = 20;
	char buf[21];
     //	buf[10] = 0;
	buf[20] = '\n';
	do {
		buf[--i] = x % 10 + '0';
		x/= 10;
	} while(x);
	do {
		putchar(buf[i]);
	} while(buf[i++] != '\n');
}
template <typename T> inline T readInt() {
	T n = 0, s = 1;
	char p = getchar();
	if(p == '-') s = -1;
	while((p < '0' || p > '9') && p != EOF && p != '-')
		p = getchar();
	if(p == '-') s = -1, p = getchar();
	while(p >= '0' && p <= '9') {
		n = (n << 3) + (n << 1) + (p - '0');
		p = getchar();
	}
	return n * s;
}
/* struct max_flow_graph {
	struct edge {
		int u, v, cap, flow;
	};
	int n;
	typedef vector<edge> VE;
	VE el;
	VVI adj;
	VI dist, par;
	max_flow_graph(int n) : n(n), adj(n + 1) {}
	void add_edge(int u, int v, int w) {
		adj[u].push_back(el.size());
		el.push_back({u, v, w, 0});
		adj[v].push_back(el.size());
		el.push_back({v, u, 0, 0});
	}
	int send_one_flow(int s, int e) {
		int nf = INF;
		for(int u = e; u != s; u = el[par[u]].u) {
			nf = min(nf, el[par[u]].cap - el[par[u]].flow);
		}
		for(int u = e; u != s; u = el[par[u]].u) {
			el[par[u]].flow+= nf;
			el[par[u] ^ 1].flow-= nf;
		}
		return nf;
	}
	bool bfs(int s, int e) {
		dist.assign(n + 1, INF);
		par.assign(n + 1, 0);
		queue<int> q;
		q.push(s); dist[s] = 0;
		while(q.size()) {
			int u = q.front(); q.pop();
			if(u == e) break;
			for(int idx : adj[u]) {
				if(el[idx].cap > el[idx].flow && dist[el[idx].v] > dist[el[idx].u] + 1) {
					dist[el[idx].v] = dist[el[idx].u] + 1;
					par[el[idx].v] = dist[el[idx].u] + 1;
					q.push(el[idx].v);
				}
			}
		}
		return dist[e] < INF;
	}
	int dfs(int s, int e, int f = INF) {
		if(s == e || f == 0) return f;
		for(int idx : adj[s]) {
			if(dist[el[idx].v] != dist[s] + 1) continue;
			if(int nf = dfs(el[idx].v, e, min(f, el[idx].cap - el[idx].flow))) {
				el[idx].flow+= nf;
				el[idx ^ 1].flow-= nf;
				return nf;
			}
		}
		return 0;
	}
	ll dinic(int s, int e) {
		ll mf = 0;
		while(bfs(s, e)) {
			while(int nf = dfs(s, e))
				mf+= nf;
		}
		return mf;
	}
}; */
#define DEBUG
#ifdef DEBUG
	#define debug(args...)	(Debugger()), args
	class Debugger {
		public:
			Debugger(const std::string & _separator = " - "):
				first(true), separator(_separator){}
			template<typename ObjectType> Debugger & operator, (const ObjectType & v) {
				if(!first) std:cerr << separator;
				std::cerr << v;
				first = false;
				return *this;
			}
			~Debugger() {std:cerr << endl;}
		private:
			bool first;
			std::string separator;
	};
#else
	#define debug(args...)
#endif
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
int n, m, num, par[MAX_N], visited[MAX_N];
VI adj[MAX_N], dist;
VA edges;
class Template {
	public:
		void dfs(int u) {
			visited[u] = 1;
			for(int v : adj[u])
				if(!visited[v]) dfs(v);
		}
		void bfs(int s) {
			dist.assign(n + 1, -1);
			queue<int> q;
			dist[s] = 0; q.push(s);
			while(q.size()) {
				int u = q.front(); q.pop();
				for(int v : adj[u]) {
					if(dist[v] == -1) {
						dist[v] = dist[u] + 1;
						q.push(v);
					}
				}
			}
		}
		int find(int u) {
			return u == par[u] ? u : par[u] = find(par[u]);
		}
		void kruskal() {
			int i;
			sort(edges.begin(), edges.end());
			FOR(i, 1, n + 1, 1)
				par[i] = i;
			ll cnt = 0, cost = 0;
			for(auto [w, u, v] : edges) {
				u = find(u), v = find(v);
				if(u != v) {
					par[u] = v;
					cost+= w;
					cnt++;
				}
			}
			if(cnt == n - 1) cout << cost << "\n";
			else cout << "IMPOSSIBLE\n";
		}
		int getmax(char *str, int n, int a, int b) {
			int m = unique(str[0], str[n-1]) - str[0];
			return ((n * a) + max((n * b), ((m / 2) + 1)));
		}
		void solve() {
		     /*	cin >> n >> m;
			REP(int i, m) {
				int u, v; cin >> u >> v;
				adj[u].push_back(v);
				adj[v].push_back(u);
			}
			FOR(int i, 1, n + 1, 1) {
				if(!visited[i]) {
					dfs(i);
					num++;
				}
			}
			cout << num << "\n"; */
		     /*	cin >> n >> m;
			REP(int i, m) {
				int u, v; cin >> u >> v;
				adj[u].push_back(v);
				adj[v].push_back(u);
			}
			bfs(1);
			FOR(int i, 1, n + 1, 1)
				cout << dist[i] << " ";
			cout << "\n"; */
		     /*	cin >> n >> m;
			REP(int i, 0, m, 1) {
				int u, v, w; cin >> u >> v >> w;
				edges.push_back({w, u, v});
			}
			kruskal(); */
		     /*	int n, m; cin >> n >> m;
			max_flow_graph adj(n);
			REP(int i, m) {
				int u, v, w; cin >> u >> v >> w; u--; v--;
				adj.add_edge(u, v, w);
			}
			cout << adj.dinic(0, n - 1) << "\n"; */
		}
};
int main() {
	Template temp;
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
     /*	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
     //	freopen("output.txt", "w", stdout);
	#endif */
	int tc, n, a, b;
	cin >> tc;
     //	tc = read(int);
	while(tc--) {
	     /*	write(tc)
		temp.solve(); */
		cin >> n >> a >> b;
		char *str = (char *) malloc(n * sizeof(int));
		cout << temp.getmax(str, n, a, b) << "\n";
	}
	return 0;
}
