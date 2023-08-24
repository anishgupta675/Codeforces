/*
Problem Details:
    Contest Event Name: Codeforces Round 893 (Div. 2)
    Contest Event Link: https://codeforces.com/contest/1858
    Problem Statement Label Number: C
    Problem Statement Code Number: 1858C
    Problem Statement Link Number: https://codeforces.com/contest/1858/problem/C
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

vector<int> getPermutation(int n) {
    vector<int> res(n);
    return res;
}

void printList(vector<int> permutation, int n) {
    for(int i = 0; i < n; i++) cout << permutation[i] << " ";
    cout << endl;
}

void solve() {
    int n;
    cin >> n;
    printList(getPermutation(n), n);
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