/*
Problem Details:
    Contest Event Name: Codeforces Round 873 (Div. 2)
    Contest Event Link: https://codeforces.com/contest/1828
    Problem Statement Label Number: A
    Problem Statement Code Number: 1828A
    Problem Statement Link Number: https://codeforces.com/contest/1828/problem/A
*/

/*
Short explanation: If n % 2 == 0, create an array of contiguous even integers starting from 2,
else create an array of contiguous integers starting from 1.
*/

#include<bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

vector<int> getPerfect(int n) {
    vector<int> res(n);
    if(n % 2) {
        int count = 1;
        for(int i = 0; i < n; i++) {
            res[i] = count;
            count++;
        }
    } else {
        int count = 2;
        for(int i = 0; i < n; i++) {
            res[i] = count;
            count+= 2;
        }
    }
    return res;
}

void printList(vector<int> a) {
    for(int i : a) cout << i << " ";
    cout << endl;
}

void solve() {
    int n;
    cin >> n;
    printList(getPerfect(n));
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