/*
Problem Details:
    Contest Event Name: Codeforces Round 894 (Div. 3)
    Contest Event Link: https://codeforces.com/contest/1862
    Problem Statement Label Number: A
    Problem Statement Code Number: 1862A
    Problem Statement Link Number: https://codeforces.com/contest/1862/problem/A
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

bool checkCarpet(vector<string> &carpets, int n, int m) {
    int fnd = 0;
    string vika = "vika";
    for(int i = 0; i < m; i++) {
        bool check = false;
        for(int j = 0; j < n; j++) if(carpets[j][i] == vika[fnd]) check = true;
        if(check) {
            ++fnd;
            if(fnd == 4) break;
        }
    }
    return (fnd == 4);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> carpets(n);
    cin.get();
    for(int i = 0; i < n; i++) getline(cin, carpets[i]);
    cout << ((checkCarpet(carpets, n, m)) ? "YES" : "NO") << endl;
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