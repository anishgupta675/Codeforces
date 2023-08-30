/*
Problem Details:
    Contest Event Name: Codeforces Round 174 (Div. 1)
    Contest Event Link: https://codeforces.com/contest/283
    Problem Statement Label Number: A
    Problem Statement Code Number: 283A
    Problem Statement Link Number: https://codeforces.com/problemset/problem/283/A
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

vector<float> getAverage(vector<vector<int>> &operations, int n) {
    int ct = 1;
    double sum = 0;
    vector<int> arr(n + 1);
    vector<float> os(n + 1);
    vector<float> res(n);
    for(int i = 0; i < n; i++) {
        if(operations[i].size() == 2) {
            os[operations[i][0]] = operations[i][1];
            sum+= operations[i][0] * operations[i][1];
        }
        else if(operations[i].size() == 1) {
            arr[ct] = operations[i][0];
            ct++;
            sum+= operations[i][0];
        } else {
            sum-= arr[ct - 1] - os[ct - 1];
            arr[ct - 1] = 0;
            os[ct - 2]+= os[ct - 1];
            os[ct - 1] = 0;
            ct--;
        }
        res.push_back(sum);
    }
    return res;
}

void printAverage(vector<float> average, int n) {
    for(int i = 0; i < n; i++) cout << average[i] << " ";
    cout << endl;
}

void solve() {
    int n, t;
    cin >> n;
    vector<vector<int>> operations(n, vector<int>());
    for(int i = 0; i < n; i++) {
        cin >> t;
        if(t == 1) {
            operations[i].resize(2);
            cin >> operations[i][0] >> operations[i][1];
        } else if(t == 2) {
            operations[i].resize(1);
            cin >> operations[i][0];
        }
    }
    printAverage(getAverage(operations, n), n);
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