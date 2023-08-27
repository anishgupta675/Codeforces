/*
Problem Details:
    Contest Event Name: ?
    Contest Event Link: ?
    Problem Statement Label Number: ?
    Problem Statement Code Number: ?
    Problem Statement Link Number: ?
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

int low = 0;
int high = 2e9;

bool checkBalls(int n, int mid) { return mid * (mid - 1) / 2 + mid < n; }

void minimizeBalls(int n) {
    if(low >= high) return;
    int mid = (low + high) >> 1;
    if(checkBalls(n, mid)) low = mid;
    else high = mid;
    minimizeBalls(n);
}

void solve() {
    int n, a;
    cin >> n;
    high = min<int>(high, 2 * n);
    minimizeBalls(n);
    a = n - high * (high - 1) / 2;
    if((high + 1) * high / 2 <= n) cout << min(high + a, high + 1 + n - (high + 1) * high / 2) << endl;
    else cout << high + a << endl;
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