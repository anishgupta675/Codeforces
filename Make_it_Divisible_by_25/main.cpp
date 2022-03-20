#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int getCount(int n, int digit_index) {
    int digit_count = 0;
    for(int i = n; i > 0; i/= 10) {
        if(digit_count-- > 0) continue;
        if(i % 10) digit_count++;
    }
    return digit_count;
}

int getK(int n) {
    int isZero = -1, digit_index = 0;
    for(int i = n; i > 0; i/= 10) {
        if(isZero == 1)
            if(i % 10 == 0 || i % 10 == 5) return getCount(n, digit_index);
        else if(isZero == 0)
            if(i % 10 == 2 || i % 10 == 7) return getCount(n, digit_index);
        if(i % 10 == 0) isZero = 1;
        else if(i % 10 == 5) isZero = 0;
        else isZero = -1;
        digit_index++;
    }
    return digit_index;
}

void solve() {
    int n;
    cin >> n;
    cout << getK(n) << endl;
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
