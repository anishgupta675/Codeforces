/*
Problem Details:
    Contest Event Name: Codeforces Round 894 (Div. 3)
    Contest Event Link: https://codeforces.com/contest/1862
    Problem Statement Label Number: C
    Problem Statement Code Number: 1862C
    Problem Statement Link Number: https://codeforces.com/contest/1862/problem/C
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

bool checkSymmetrical(vector<int> &a, int n) {
    if(a[0] != n) return false;
    vector<int> b;
    for(int i = n; i >= 1; i--) while(b.size() < a[i - 1]) b.push_back(i);
    for(int i = 0; i < n; i++) if(a[i] != b[i]) return false;
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << ((checkSymmetrical(a, n)) ? "YES" : "NO") << endl;
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