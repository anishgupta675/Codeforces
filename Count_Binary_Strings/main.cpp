#include<iostream>
#include<vector>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 998244353;
const ll INF = 1e9;

ll countStrings(vector<vector<ll>> &arr) {
    
    return 0;
}

void solve() {
    int n, data;
    cin >> n;
    vector<vector<ll>> arr(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i + 1; j++) {
            cin >> data;
            arr[i].push_back(data);
        }
    }
    cout << countStrings(arr) << endl;
    arr.clear();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}