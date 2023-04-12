/*
Problem Details:
    Contest Event Name: Codeforces Round #839 (Div. 3)
    Contest Event Link: https://codeforces.com/contest/1772
    Problem Statement Label Number: C
    Problem Statement Code Number: 1772C
    Problem Statement Link Number: https://codeforces.com/problemset/problem/1772/C
*/

/*
Short explanation: Start the series with 1 as the first minimal element and 2 as the second minimal
element, thus establishing 1 as the first minimal difference. Then, depending on whether or not
there are enough slots left to fill in all the remaining elements necessary to fill, increment the
consecutive elements by either diff++ or just 1.
*/

#include<bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

vector<ll> a;

vector<ll> getIncreasing(ll k, ll n) {
    ll j = 1, diff = 1;
    for(int i = 0; i < k; i++) {
        a.push_back(j);
        if(n - (j + diff) >= (k - (i + 1))) j+= diff++;
        else j++;
    }
    return a;
}

void printList(vector<ll> a) {
    for(int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << "\n";
}

void solve() {
    ll k, n;
    cin >> k >> n;
    printList(getIncreasing(k, n));
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