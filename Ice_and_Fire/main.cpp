/*
Problem Details:
    Contest Event Name: Polynomial Round 2022 (Div. 1 + Div. 2, Rated, Prizes!)
    Contest Event Link: https://codeforces.com/contest/1774
    Problem Statement Label Number: C
    Problem Statement Code Number: 1774C
    Problem Statement Link Number: https://codeforces.com/problemset/problem/1774/C
*/

/*
Short explanation: First element is always 1. Run loop from index 1 to total length of binary
string. If current element of string same as previous element, current count same as previous
count, else current count = current index + 1
*/

#include<iostream>
#include<vector>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

string binary_string;

vector<ll> getWinners(string binary_string) {
    vector<ll> res(binary_string.length());
    res[0] = 1;
    for(int i = 1; i < binary_string.length(); i++) {
        if(binary_string[i] == binary_string[i - 1]) res[i] = res[i - 1];
        else res[i] = i + 1;
    }
    return res;
}

void printList(vector<ll> winners) {
    for(int i = 0; i < winners.size(); i++)
        cout << winners[i] << " ";
    cout << "\n";
}

void solve() {
    ll n;
    cin >> n;
    cin.get();
    getline(cin, binary_string);
    if(n == 2) cout << "1" << endl;
    else printList(getWinners(binary_string));
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