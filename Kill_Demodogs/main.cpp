/*
Short explanation: Refer to the notebook
*/

#include <iostream>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

unsigned ll killDemodogs(unsigned ll n) {
    /*
    ll res = 1;
    for(int i = 2; i <= n; i++)
        res = ((res % MOD) + (((((i % MOD) * (i % MOD)) % MOD) + (((i % MOD) * (((i % MOD) - (1 % MOD)) % MOD)) % MOD)) % MOD)) % MOD;
    return ((((1 % MOD) + ((((ll)((((((n % MOD) * (((n % MOD) + (1 % MOD)) % MOD)) % MOD) * (((((n % MOD) * (2 % MOD)) % MOD) + (1 % MOD)) % MOD)) % MOD) * (1 / 6.0)) % MOD) + ((ll)((((((n % MOD) * (((n % MOD) + (1 % MOD)) % MOD)) % MOD) * (((n % MOD) * (2 % MOD)) % MOD)) % MOD) * (1 / 3.0)) % MOD)) % MOD)) % MOD) * (2022 % MOD)) % MOD;
    */
    return ((((((n % MOD) * (337 % MOD)) % MOD) * (((n % MOD) + (1 % MOD)) % MOD)) % MOD) * (((((n % MOD) * (4 % MOD)) % MOD) - (1 % MOD)) % MOD)) % MOD;
}

void solve() {
    unsigned ll n;
    cin >> n;
    cout << killDemodogs(n) % MOD << endl;
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