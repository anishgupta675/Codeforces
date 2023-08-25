/*
Problem Details:
    Contest Event Name: Codeforces Round 893 (Div. 2)
    Contest Event Link: https://codeforces.com/contest/1858
    Problem Statement Label Number: B
    Problem Statement Code Number: 1858B
    Problem Statement Link Number: https://codeforces.com/contest/1858/problem/B
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

int getCookies(vector<int> &s, int n, int m, int d) {
    int ans = 0;
    for(int i = 1; i < m; i++) ans+= (s[i] - s[i - 1] - 1) / d;
    ans+= int(s.size()) - 2;
    return ans;
}

void solve() {
    int n, m, d, ans = 2e9;
    cin >> n >> m >> d;
    vector<int> s(m);
    vector<int> res;
    for(int i = 0; i < m; i++) cin >> s[i];
    s.insert(s.begin(), 1 - d);
    s.push_back(n + 1);
    for(int i = 1; i <= m; i++) {
        int a = s[i] - s[i - 1] - 1, b = s[i + 1] - s[i] - 1, c = s[i + 1] - s[i - 1] - 1, e = c / d - (a / d + b / d);
        if(e < ans) {
            ans = e;
            res.clear();
        }
        if(e == ans) res.push_back(s[i]);
    }
    cout << ans + getCookies(s, n, m, d) - 1 << " " << res.size() << endl;
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