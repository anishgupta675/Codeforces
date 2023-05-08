/*
Problem Details:
    Contest Event Name: CSES Problem Set Sorting and Searching
    Contest Event Link: https://codeforces.com/gym/102961
    Problem Statement Label Number: E
    Problem Statement Code Number: 102961E
    Problem Statement Link Number: https://codeforces.com/gym/102961/problem/E
*/

/*
Short explanation: Use a map to keep track of the number of guests at each unit of time T = t,
where t = min(customers)...max(customers)
*/

#include<bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

pair<int, int> getBounds(vector<pair<int, int>> &customers) {
    pair<int, int> res;
    for(int i = 0; i < customers.size(); i++) {
        res.first = min(customers[i].first, res.first);
        res.second = max(customers[i].second, res.second);
    }
    return res;
}

int getCustomers(vector<pair<int, int>> &customers) {
    int max_customers = 0;
    pair<int, int> bounds = getBounds(customers);
    vector<int> map(bounds.second - bounds.first);
    for(int i = 0; i < customers.size(); i++) for(int j = customers[i].first; j <= customers[i].second; j++) map[j - bounds.first]++;
    for(int i = 0; i < map.size(); i++) max_customers = max(map[i], max_customers);
    return max_customers;
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> customers(n);
    for(int i = 0; i < n; i++) cin >> customers[i].first >> customers[i].second;
    cout << getCustomers(customers) << endl;
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