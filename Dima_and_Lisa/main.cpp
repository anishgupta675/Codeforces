/*
Problem Details:
    Contest Event Name: Codeforces Round 324 (Div. 2)
    Contest Event Link: https://codeforces.com/contest/584
    Problem Statement Label Number: D
    Problem Statement Code Number: 584D
    Problem Statement Link Number: https://codeforces.com/problemset/problem/584/D
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

int getSet(int n) {
    // TODO
    
    return 0;
}

void printSet(int k, int n) {
    cout << k << endl;
    for(int i = 0; i < n; i++) cout << ++k << endl;
}

void solve() {
    int n;
    cin >> n;
    printSet(getSet(n), n);
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