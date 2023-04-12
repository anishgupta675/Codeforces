/*
Problem Details:
    Contest Event Name: Educational Codeforces Round 139 (Rated for Div. 2)
    Contest Event Link: https://codeforces.com/contest/1766
    Problem Statement Label Number: B
    Problem Statement Code Number: 1766B
    Problem Statement Link Number: https://codeforces.com/problemset/problem/1766/B
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

string s;

void solve() {
    ll n;
    cin >> n;
    cin.get();
    getline(cin, s);
    cout << (compareOperations(s) ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}