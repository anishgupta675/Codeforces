/*
Problem Details:
    Contest Event Name: Codeforces Round 174 (Div. 1)
    Contest Event Link: https://codeforces.com/contest/283
    Problem Statement Label Number: B
    Problem Statement Code Number: 283B
    Problem Statement Link Number: https://codeforces.com/problemset/problem/283/B
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

vector<int> getSequence(vector<int> &a, int n) {
    vector<int> res(n - 1);
    // TODO

    return res;
}

void printSequence(vector<int> sequence, int n) { for(int i = 0; i < n; i++) cout << sequence[i] << endl; }

void solve() {
    int n;
    cin >> n;
    vector<int> a(n - 1);
    for(int i = 0; i < n - 1; i++) cin >> a[i];
    printSequence(getSequence(a, n), n - 1);
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