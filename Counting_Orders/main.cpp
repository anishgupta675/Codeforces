/*
Problem Details:
    Contest Event Name: Codeforces Round 873 (Div. 2)
    Contest Event Link: https://codeforces.com/contest/1828
    Problem Statement Label Number: C
    Problem Statement Code Number: 1828C
    Problem Statement Link Number: https://codeforces.com/contest/1828/problem/C
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

ll countReorder(vector<ll> &a, vector<ll> &b) {
    // TODO
    return 0;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    cout << countReorder(a, b) << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}