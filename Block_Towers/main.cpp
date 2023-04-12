/*
Problem Details:
    Contest Event Name: Educational Codeforces Round 140 (Rated for Div. 2)
    Contest Event Link: https://codeforces.com/contest/1767
    Problem Statement Label Number: B
    Problem Statement Code Number: 1767B
    Problem Statement Link Number: https://codeforces.com/problemset/problem/1767/B
*/

/*
Short explanation: For every tower that is larger than the first one, the maximum amount of blocks
that can be moved over from that tower to the first one in each iteration is
(Number of blocks on that tower - Number of blocks on the first tower + 1) / 2
thus increasing the number of blocks currently present on the first tower to be exactly the same
as that amount as well.
*/

#include<bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

ll maximizeTower(vector<ll> &towers) {
    ll first = towers[0];
    sort(towers.begin(), towers.end());
    for(int i = 1; i < towers.size(); i++)
        if(towers[i] > first) first+= (towers[i] - first + 1) / 2;
    return first;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> towers(n);
    for(int i = 0; i < n; i++)
        cin >> towers[i];
    cout << maximizeTower(towers) << endl;
    towers.clear();
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