/*
Problem Details:
    Contest Event Name: Educational Codeforces Round 139 (Rated for Div. 2)
    Contest Event Link: https://codeforces.com/contest/1766
    Problem Statement Label Number: C
    Problem Statement Code Number: 1766C
    Problem Statement Link Number: https://codeforces.com/problemset/problem/1766/C
*/

/*
Short explanation: Check for the first column from the left with a black cell, then traverse the
strings from left to right. If we find any column since the initial starting point such that:
    a. No cell in that column is black
    b. The next black side does not share a common side with the current one
    c. The next 2 black sides do not share a common side with each other
it will not be possible to traverse the string without violating the postulates.
Therefore, we will return NO as answer.
*/

#include<bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

ll b1 = 0, b2 = 0;

ll countB(vector<string> &c) {
    ll count = 0;
    for(int i = 0; i < c.size(); i++)
        for(int j = 0; j < c[i].length(); j++)
            count++;
    return count;
}

void fillVisited(vector<vector<bool>> &v) {
    for(int i = 0; i < v.size(); i++)
        for(int j = 0; j < v[i].size(); j++)
            v[i][j] = false;
}

void start(vector<vector<bool>> &v, ll r, ll c) {
    b2++;
    v[r][c] = true;
    if(r == 0) {
        if(v[1][c] == 'B' && v[1][c] == false) start(v, 1, c);
        else if(v[0][c + 1] == 'B') start(v, 0, c + 1);
    } else {
        if(v[0][c] == 'B' && v[0][c] == false) start(v, 0, c);
        else if(v[1][c + 1] == 'B') start(v, 1, c + 1);
    }
}

bool checkWall(vector<string> &c) {
    /*
    bool ans = false;
    vector<vector<bool>> v(c.size(), vector<bool>(c[0].length(), false));
    b1 = countB(c);
    for(int i = 0; i < c[0].length(); i++) {
        if(c[0][i] == 'B' && c[1][i] == 'B') {
            b2 = 0;
            start(v, 0, i);
            if(b1 == b2) ans = true;
            fillVisited(v);
            b2 = 0;
            start(v, 1, i);
            if(b1 == b2) ans = true;
        } else if(c[0][i] == 'B') {
            b2 = 0;
            start(v, 0, i);
            if(b1 == b2) ans = true;
        } else {
            b2 = 0;
            start(v, 1, i);
            if(b1 == b2) ans = true;
        }
    }
    return ans;
    */
    bool ok = true;
    ll pos = -1, cur = 0;
    for(int i = 0; i < c[0].length(); i++)
        if(c[0][i] != c[1][i]) pos = i;
    if(pos == -1) return true;
    ok = true;
    cur = (c[0][pos] == 'B') ? 0 : 1;
    for(int i = pos + 1; i < c[0].length(); i++) {
        if(c[cur][i] == 'W') ok = false;
        if(c[cur ^ 1][i] == 'B') cur^= 1;
    }
    cur = (c[0][pos] == 'B') ? 0 : 1;
    for(int i = pos - 1; i >= 0; i--) {
        if(c[cur][i] == 'W') ok = false;
        if(c[cur ^ 1][i] == 'B') cur^= 1;
    }
    return ok;
}

void solve() {
    ll m;
    vector<string> c(2);
    cin >> m;
    cin.get();
    for(int i = 0; i < c.size(); i++) {
        getline(cin, c[i]);
        // cin.get();
    }
    cout << (checkWall(c) ? "YES" : "NO") << endl;
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