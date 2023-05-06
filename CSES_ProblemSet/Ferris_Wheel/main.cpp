/*
Problem Details:
    Contest Event Name: CSES Problem Set Sorting and Searching
    Contest Event Link: https://codeforces.com/gym/102961
    Problem Statement Label Number: C
    Problem Statement Code Number: 102961C
    Problem Statement Link Number: https://codeforces.com/gym/102961/problem/C
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

int getGondolas(vector<int> &p, int n, int x) {
    int i = 0, j = p.size() - 1, cnt = 0;
    while(i <= j) {
        if(p[i] + p[j] <= x) {
            i++;
            j--;
        }
        j--;
        cnt++;
    }
    return cnt;
}

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    cout << getGondolas(p, n, x) << endl;
    p.clear();
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