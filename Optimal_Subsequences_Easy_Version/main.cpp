/*
Problem Details:
    Contest Event Name: Technocup 2020 - Elimination Round 3
    Contest Event Link: https://codeforces.com/contest/1227
    Problem Statement Label Number: D1
    Problem Statement Code Number: 1227D1
    Problem Statement Link Number: https://codeforces.com/problemset/problem/1227/D1
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

vector<int> getRequests(vector<int> &a, vector<vector<int>> &b, int n, int m) {
    vector<int> res(m);
    // TODO

    return res;
}

void printRequests(vector<int> requests, int m) { for(int i = 0; i < m; i++) cout << requests[i] << endl; }

void solve() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    vector<vector<int>> requests(m, vector<int>(2));
    for(int i = 0; i < m; i++) cin >> requests[i][0] >> requests[i][1];
    printRequests(getRequests(a, requests, n, m), m);
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