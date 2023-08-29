/*
Problem Details:
    Contest Event Name: Technocup 2020 - Elimination Round 3
    Contest Event Link: https://codeforces.com/contest/1227
    Problem Statement Label Number: C
    Problem Statement Code Number: 1227C
    Problem Statement Link Number: https://codeforces.com/problemset/problem/1227/C
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

vector<vector<int>> getOperations(string &s, int n, int k) {
    vector<vector<int>> res;
    for(int i = 0; i < n; i++) {
        int j = i;
        if(i % 2) {
            if(s[i] == '(') {
                vector<int> data;
                while(j < n && s[j] != ')') j++;
                reverse(s.begin() + i, s.begin() + j + 1);
                data[0] = i + 1;
                data[1] = j + 1;
                res.push_back(data);
            }
        } else {
            if(s[i] == ')') {
                vector<int> data;
                while(j < n && s[j] != '(') j++;
                reverse(s.begin() + i, s.begin() + j + 1);
                data[0] = i + 1;
                data[1] = j + 1;
                res.push_back(data);
            }
        }
    }
    return res;
}

void printOperations(vector<vector<int>> operations) {
    cout << operations.size() << endl;
    for(int i = 0; i < operations.size(); i++) cout << operations[i][0] << operations[i][1] << endl;
}

void solve() {
    int n, k;
    string s;
    cin >> n >> k;
    getline(cin, s);
    printOperations(getOperations(s, n, k));
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