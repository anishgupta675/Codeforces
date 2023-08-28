/*
Problem Details:
    Contest Event Name: Codeforces Round 324 (Div. 2)
    Contest Event Link: https://codeforces.com/contest/584
    Problem Statement Label Number: C
    Problem Statement Code Number: 584C
    Problem Statement Link Number: https://codeforces.com/problemset/problem/584/C
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

string getString(string &s1, string &s2, int n, int t) {
    int ham_dist = 0;
    for(int i = 0; i < n; i++) ham_dist+= (s1[i] != s2[i]);
    if(ham_dist != t) return "-1";
    string res;
    for(int i = 0; i < t; i++) res+= ((s2[i] + 1) % 26) + 97;
    for(int i = t; i < n; i++) res+= s2[i];
    return res;
}

void solve() {
    int n, t;
    string s1, s2;
    cin >> n >> t;
    cin.get();
    getline(cin, s1);
    getline(cin, s2);
    cout << getString(s1, s2, n, t) << endl;
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