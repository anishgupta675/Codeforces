/*
Problem Details:
    Contest Event Name: Educational Codeforces Round 124 (Rated for Div. 2)
    Contest Event Link: https://codeforces.com/contest/1651
    Problem Statement Label Number: A
    Problem Statement Code Number: 1651A
    Problem Statement Link Number: https://codeforces.com/problemset/problem/1651/A
*/

/*
Short explanation: Count the number of zeroes and ones in the binary string. Print all valid
natural numbers from (2 ^ number of ones) to ((2 ^ length of string) - (2 ^ number of zeroes) + 1)
*/

#include<bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

string binary_string;
vector<ll> res;

vector<ll> getWinners(string binary_string, ll n) {
    ll zero = 0, one = 0;
    for(int i = 0; i < binary_string.length(); i++) {
        if(binary_string[i] == '0') zero++;
        else one++;
    }
    for(int i = pow(2, one); i <= (pow(2, n) - pow(2, zero) + 1); i++)
        res.push_back(i);
    return res;
}

void printList(vector<ll> res) {
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
}

void solve() {
    int n;
    cin >> n;
    cin.get();
    getline(cin, binary_string);
    printList(getWinners(binary_string, n));
    binary_string.clear();
    res.clear();
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