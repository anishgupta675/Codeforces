/*
Problem Details:
    Contest Event Name: 2022-2023 ICPC, NERC, Northern Eurasia Onsite (Unrated, Online Mirror, ICPC
    Rules, Teams Preferred)
    Contest Event Link: https://codeforces.com/contest/1773
    Problem Statement Label Number: E
    Problem Statement Code Number: 1773E
    Problem Statement Link Number: https://codeforces.com/problemset/problem/1773/E
*/

/*
Short explanation: Index the matrix elements in such a way that the value of each element is
exactly the same as what it would've been the cardinality of it's index if it was in a sorted
order. Minimum number of split operations that are absolutely necessary are the same as the number
of places in the initial towers where a block with index x is followed by a block with index y and
x + 1 != y, whereas the minimum number of combine operations = number of towers + minimum number
of splits that are absolutely necessary - 1
*/

#include<bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

bool sortByFirst(const pair<ll, ll> &a, const pair<ll, ll> &b) {
    return (a.first < b.first);
}

bool sortBySecond(const pair<ll, ll> &a, const pair<ll, ll> &b) {
    return (a.second < b.second);
}

vector<vector<ll>> indexList(vector<vector<ll>> &b) {
    int count = 0;
    vector<pair<ll, ll>> index;
    for(int i = 0; i < b.size(); i++) {
        for(int j = 0; j < b[i].size(); j++)
            index.push_back(make_pair(b[i][j], count++));
    }
    sort(index.begin(), index.end(), sortByFirst);
    count = 0;
    for(int i = 0; i < index.size(); i++)
        index[i].first = count++;
    sort(index.begin(), index.end(), sortBySecond);
    count = 0;
    for(int i = 0; i < b.size(); i++) {
        for(int j = 0; j < b[i].size(); j++)
            b[i][j] = index[count++].first;
    }
    return b;
}

pair<ll, ll> getOperations(vector<vector<ll>> &b) {
    pair<ll, ll> res(0, 0);
    b = indexList(b);
    /*
    for(int i = 0; i < b.size(); i++) {
        for(int j = 0; j < b[i].size(); j++)
            cout << b[i][j] << " ";
        cout << "\n";
    }
    */
    for(int i = 0; i < b.size(); i++) {
        for(int j = 1; j < b[i].size(); j++)
            if(b[i][j] != b[i][j - 1] + 1) res.first++;
    }
    res.second = b.size() + res.first - 1;
    return res;
}

void solve() {
    ll n, k, data;
    cin >> n;
    vector<vector<ll>> b(n);
    for(int i = 0; i < n; i++) {
        cin >> k;
        for(int j = 0; j < k; j++) {
            cin >> data;
            b[i].push_back(data);
        }
    }
    pair<ll, ll> res = getOperations(b);
    cout << res.first << " " << res.second << endl;
    b.clear();
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