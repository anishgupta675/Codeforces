/*
Problem Details:
    Contest Event Name: Codeforces Round 358 (Div. 2)
    Contest Event Link: https://codeforces.com/contest/682
    Problem Statement Label Number: A
    Problem Statement Code Number: 682A
    Problem Statement Link Number: https://codeforces.com/contest/682/problem/A
*/

/*
Short explanation: For all distinct values x from 1 to n, we need to find the number of distinct values y from 1 to m such that (x + y) is a multiple of 5.
*/

#include<bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long
#define MOD_ALT 5

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int findMultiple(int index, int radix = MOD_ALT) { return (index - (index % radix)) / radix; }

int findNearestMultiple(int index, int radix = MOD_ALT) {
    int remainder = index % radix;
    if(remainder < radix - remainder) return (index - remainder) / radix;
    return (index + (radix - remainder)) / radix;
}

int countPairs(int n, int m) {
    int count = 0;
    for(int i = 1; i < n; i++) count+= findMultiple(i + m) - findMultiple(i);
    return count + findNearestMultiple(m);
}

void solve() {
    int n, m;
    cin >> n >> m;
    cout << countPairs(n, m) << endl;
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