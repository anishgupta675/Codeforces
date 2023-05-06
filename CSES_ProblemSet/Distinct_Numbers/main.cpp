/*
Problem Details:
    Contest Event Name: CSES Problem Set Sorting and Searching
    Contest Event Link: https://codeforces.com/gym/102961
    Problem Statement Label Number: A
    Problem Statement Code Number: 102961A
    Problem Statement Link Number: https://codeforces.com/gym/102961/problem/A
*/

/*
Short explanation: Use a set
*/

#include<bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
    int n, cnt = 0;
    cin >> n;
    vector<int> a(n);
    unordered_set<int> uset;
    for(int i : a) {
        cin >> i;
        if(uset.find(i) == uset.end()) {
            cnt++;
            uset.insert(i);
        }
    }
    cout << cnt << endl;
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