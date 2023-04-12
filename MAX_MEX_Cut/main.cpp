/*
Problem Details:
    Contest Event Name: Codeforces Global Round 16
    Contest Event Link: https://codeforces.com/contest/1566
    Problem Statement Label Number: C
    Problem Statement Code Number: 1566C
    Problem Statement Link Number: https://codeforces.com/problemset/problem/1566/C
*/

/*
Short explanation: ?
*/

#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

string bin_str1, bin_str2;

int getMEX(string bin_str1, string bin_str2) {
    
}

void solve() {
    int n;
    cin >> n;
    getline(cin, bin_str1);
    getline(cin, bin_str2);
    cout << getMEX(bin_str1, bin_str2) << endl;
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
