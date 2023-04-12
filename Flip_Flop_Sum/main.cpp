/*
Problem Details:
    Contest Event Name: Codeforces Round #848 (Div. 2)
    Contest Event Link: https://codeforces.com/contest/1778
    Problem Statement Label Number: A
    Problem Statement Code Number: 1778A
    Problem Statement Link Number: https://codeforces.com/contest/1778/problem/A
*/

/*
Short explanation: 3 cases:
    1. If all elements are 1s, Maximum possible sum = Size of array - 4
    2. Else
        a. If there exists atleast one pair of adjacent -1s, Maximum possible sum = Number of 1s
            + 2 - (Number of -1s - 2)
        b. Else Maximum possible sum = Number of 1s
*/

#include<bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

ll max(ll a, ll b) { return (a > b) ? a : b; }

ll maximizeSum(vector<ll> &a) {
    bool count = 0;
    ll sum = max(a[0], 0);
    for(int i = 1; i < a.size(); i++) {
        if(a[i - 1] == -1 && a[i] == -1) count = 1;
        if(a[i] == 1) sum++;
    }
    if(sum == a.size()) return sum - 4;
    return sum + ((count) ? 2 : 0) - (a.size() - sum - ((count) ? 2 : 0));
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << maximizeSum(a) << endl;
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