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

int getApartment(vector<int> &a, vector<int> &b, int n, int m, int k) {
    int i = 0, j = 0, cnt = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    while(j < m) {
        if(b[j] < a[i] - k) j++;
        else if(b[j] > a[i] + k) i++;
        else if(b[j] >= a[i] - k && b[j] <= a[i] + k) {
            cnt++;
            i++;
            j++;
        }
    }
    return cnt;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    cout << getApartment(a, b, n, m, k) << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}