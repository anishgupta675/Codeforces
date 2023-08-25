/*
Problem Details:
    Contest Event Name: Codeforces Round 893 (Div. 2)
    Contest Event Link: https://codeforces.com/contest/1858
    Problem Statement Label Number: D
    Problem Statement Code Number: 1858D
    Problem Statement Link Number: https://codeforces.com/contest/1858/problem/D
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

vector<int> getBeauty(string s, int n, int k) {
    vector<int> ans(n + 1, -1e9);
    vector<int> max01(n + 1, -1e9);
    vector<vector<int>> pref0(n + 1, vector<int>(n + 1));
    vector<vector<int>> suf0(n + 1, vector<int>(n + 1));
    for(int i = 0; i < n; i++) {
        int cnt1 = 0;
        for(int j = i + 1; j <= n; j++) {
            cnt1+= s[j - 1] == '1';
            pref0[j][cnt1] = max(pref0[j][cnt1], j - i);
            suf0[i][cnt1] = max(suf0[i][cnt1], j - i);
        }
    }
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            if(i) pref0[i][j] = max(pref0[i][j], pref0[i - 1][j]);
            if(j) pref0[i][j] = max(pref0[i][j], pref0[i][j - 1]);
        }
    }
    for(int i = n; i >= 0; i--) {
        for(int j = 0; j <= n; j++) {
            if(i + 1 <= n) suf0[i][j] = max(suf0[i][j], suf0[i + 1][j]);
            if(j) suf0[i][j] = max(suf0[i][j], suf0[i][j - 1]);
        }
    }
    for(int i = 0; i <= n; i++) for(int j = 1; j <= n; j++) ans[j] = max(ans[j], i + max01[i] * j);
    return ans;
}

void printList(vector<int> beauty, int n) {
    for(int i = 0; i < n; i++) cout << beauty[i] << " ";
    cout << endl;
}

void solve() {
    int n, k;
    string s;
    cin >> n >> k;
    cin.get();
    getline(cin, s);
    printList(getBeauty(s, n, k), n);
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