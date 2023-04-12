#include<iostream>
#include<vector>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

ll maximizeMoney(vector<ll> &a) {
    ll res = 1;
    for(int i = 0; i < a.size(); i++)
        res*= a[i];
    return (res + (a.size() - 1)) * 2022;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << maximizeMoney(a) << endl;
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