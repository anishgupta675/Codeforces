/*
Problem Details:
    Contest Event Name: Codeforces Round #839
    Contest Event Link: https://codeforces.com/contest/1772
    Problem Statement Label Number: D
    Problem Statement Code Number: 1772D
    Problem Statement Link Number: https://codeforces.com/problemset/problem/1772/D
*/

#include<bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

ll min(int a, int b) { return (a < b) ? a : b; }

ll max(int a, int b) { return (a > b) ? a : b; }

ll getSorted(vector<ll> &a) {
    ll low = 0, high = INF;
    for(int i = 0; i < a.size() - 1; i++) {
        /*
        if(a[i] == a[i + 1]) continue;
        else if(a[i] < a[i + 1]) {
            ll x = (a[i] + a[i + 1]) / 2;
            high = min(high, x);
        } else {
            ll x = (a[i] + a[i + 1] + 1) / 2;
            low = max(low, x);
        }
        */
        if(a[i] < a[i + 1]) high = min(high, (a[i] + a[i + 1]) / 2);
        else if(a[i] > a[i + 1]) low = max(low, (a[i] + a[i + 1] + 1) / 2);
    }
    // if(high >= low) return high;
    if(low <= high) return low;
    return -1;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << getSorted(a) << endl;
    a.clear();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}