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

enum Charset {
    alphabet,
    numeral,
    alphanumeral,
    special_alphabet,
    special_numeral,
    special_alphanumeral
};

int generateInteger(int low, int high) {
    return low + (rand() % (high - low + 1));
}

char generateCharacter() {
    return (char)generateInteger(21, 126);
}

char generateCharacter(Charset charset) {
    if(charset == alphabet) return (char)generateInteger(97, 122);
    return (char)generateInteger(48, 57);
}

string generateString(int size) {
    string s;
    for(int i = 0; i < size; i++)
        s.push_back(generateCharacter());
    return s;
}

string generateString(Charset charset, int size) {
    string s;
    for(int i = 0; i < size; i++)
        s.push_back(generateCharacter(charset));
    return s;
}

void solve() {
    int n = generateInteger(1, 20);
    cout << n << endl;
    for(int i = 0; i < n; i++)
        cout << generateInteger(1, 80) << " ";
    cout << endl;
    cout << generateInteger(1, 20) << " " << generateInteger(1, 20) << endl;
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