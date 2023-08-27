/*
Problem Details:
    Contest Event Name: Codeforces Round 381 (Div. 2)
    Contest Event Link: https://codeforces.com/contest/740
    Problem Statement Label Number: C
    Problem Statement Code Number: 740C
    Problem Statement Link Number: https://codeforces.com/problemset/problem/740/C
*/

/*
Short explanation: ?
*/

#include<bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int maximizeMex(vector<vector<int>> &b, int n, int m) {
    int max_mex = 0;
    for(int i = 0; i < m; i++) max_mex = max(max_mex, b[i][1] - b[i][0]);
    return max_mex;
}

void generateArray(vector<vector<int>> &b, int n, int m, int mex) {
    cout << mex << endl;
    for(int i = 0; i < n; i++) cout << i % mex << endl;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> b(m, vector<int>(2));
    for(int i = 0; i < m; i++) cin >> b[i][0] >> b[i][1];
    generateArray(b, n, m, maximizeMex(b, n, m));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}