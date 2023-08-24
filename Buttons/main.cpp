/*
Problem Details:
    Contest Event Name: Codeforces Round 893 (Div. 2)
    Contest Event Link: https://codeforces.com/contest/1858/problem/A
    Problem Statement Label Number: A
    Problem Statement Code Number: 1858A
    Problem Statement Link Number: https://codeforces.com/contest/1858/problem/A
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

bool getWinner(int a, int b, int c) { return (a + (int)ceil(c / 2.0f)) > (b + (int)floor(c / 2.0f)); }

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << ((getWinner(a, b, c)) ? "First" : "Second") << endl;
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