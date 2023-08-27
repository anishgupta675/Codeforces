/*
Problem Details:
    Contest Event Name: Codeforces Round 894 (Div. 3)
    Contest Event Link: https://codeforces.com/contest/1862
    Problem Statement Label Number: B
    Problem Statement Code Number: 1862B
    Problem Statement Link Number: https://codeforces.com/contest/1862/problem/B
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

vector<int> getSequence(vector<int> &b, int n) {
    vector<int> res;
    for(int i = 0; i < n; i++) {
        if(i && res.back() > b[i]) res.push_back(1);
        res.push_back(b[i]);
    }
    return res;
}

void printList(vector<int> sequence) {
    cout << sequence.size() << endl;
    for(int i = 0; i < sequence.size(); i++) cout << sequence[i] << " ";
    cout << endl;
}

void solve() {
    int n;
    cin >> n;
    vector<int> b(n);
    for(int i = 0; i < n; i++) cin >> b[i];
    printList(getSequence(b, n));
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