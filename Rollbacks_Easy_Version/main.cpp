/*
Problem Details:
    Contest Event Name: Codeforces Round 893 (Div. 2)
    Contest Event Link: https://codeforces.com/contest/1858
    Problem Statement Label Number: E1
    Problem Statement Code Number: 1858E1
    Problem Statement Link Number: https://codeforces.com/contest/1858/problem/E1
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

stack<pair<char, int>> st;
unordered_set<int> umap;

void addBack(int query) {
    st.push(make_pair('+', query));
    umap.insert(query);
}

void removeBack(int query) {
    
}

void rollBack() {

}

void updateBack() {

}

void solve() {
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        string query;
        getline(cin, query);
        if(query[0] == '+') addBack(int(query[query.size() - 1]));
        else if(query[0] == '!') rollBack();
        else if(query[0] == '?') updateBack();
        else removeBack(int(query[query.size() - 1]));
    }
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