/*
Problem Details:
    Contest Event Name: Codeforces Round #837 (Div. 2)
    Contest Event Link: https://codeforces.com/contest/1771
    Problem Statement Label Number: B
    Problem Statement Code Number: 1771B
    Problem Statement Link Number: https://codeforces.com/problemset/problem/1771/B
*/

/*
Short explanation: The upper bound of any 'pair' element such that every element between the lower
and upper bound are friends is given the by the shortest element given by the second value of any
'pair' from that point. Create a multiset housing the second values of all 'pair' elements in
ascending order, and remove the element when it's respective 'pair' has been evaluated for.
*/

#include<bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

ll min(ll a, ll b) { return (a < b) ? a : b; }

void swap(ll *xp, ll *yp) {
    ll temp = *xp;
    *xp = *yp;
    *yp = temp;
}

ll getSubSegments(vector<pair<ll, ll>> &a, ll n) {
    int ans = 0, j = 0;
    multiset<ll> ms;
    a.push_back(make_pair(n + 1, n + 1));
    sort(a.begin(), a.end());
    for(auto it : a)
        ms.insert(it.second);
    for(int i = 0; i < n; i++) {
        ans+= *ms.begin() - (i + 1);
        while(j < a.size() - 1 && a[j].first == i + 1) {
            ms.erase(ms.find(a[j].second));
            j++;
        }
    }
    return ans;
}

void solve() {
    ll n, m, x, y;
    cin >> n >> m;
    vector<pair<ll, ll>> a(m);
    for(int i = 0; i < m; i++) {
        cin >> x >> y;
        a[i] = make_pair(min(x, y), max(x, y));
    }
    cout << getSubSegments(a, n) << endl;
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