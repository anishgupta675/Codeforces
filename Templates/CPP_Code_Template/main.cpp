#include<bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

class Template {
	public:
		int getmin(int *arr, int n) {
			int min_val = arr[0];
			for(int i = 0; i < n; i++)
				if(arr[i] < min_val) min_val = arr[i];
			return min_val;
		}
	
		int getmax(int *arr, int n) {
			int max_val = 0, min_val = getmin(arr, n);
			for(int i = 0; i < n; i++)
				if(arr[i] != min_val) max_val++;
			return max_val;
		}
		
		void solve() {
			// solution here
		}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	Template temp;
	int tc = 1, n;
	cin >> tc;
	for(int t = 1; t <= tc; t++) {
		// cout << "Case #" << t << ": ";
		cin >> n;
		int *arr = (int *) malloc(n * sizeof(int));
		for(int i = 0; i < n; i++)
			cin >> arr[i];
		cout << temp.getmax(arr, n) << endl;
		temp.solve();
	}
	return 0;
}
