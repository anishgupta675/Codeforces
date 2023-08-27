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

vector<int> getTree(vector<vector<int>> &tree, int n) {
    vector<int> res(n);
    // TODO
    
    return res;
}

void printTree(vector<int> tree, int n) {
    for(int i = 0; i < n; i++) cout << tree[i] << " ";
    cout << endl;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> tree(n - 1, vector<int>(2));
    for(int i = 0; i < n - 1; i++) cin >> tree[i][0] >> tree[i][1];
    printTree(getTree(tree, n), n);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}