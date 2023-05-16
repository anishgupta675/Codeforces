/*
Problem Details:
    Contest Event Name: Codeforces Round 873 (Div. 2)
    Contest Event Link: https://codeforces.com/contest/1828
    Problem Statement Label Number: B
    Problem Statement Code Number: 1828B
    Problem Statement Link Number: https://codeforces.com/contest/1828/problem/B
*/

/*
Short explanation: Use binary search to evaluate optimal number of swaps required:
    lower_bound = 0 (already sorted),
    upper_bound = n - 1 (can only swap elements on either end of the given permutation)
**(Not sure, could be subject to changes in the future)**
*/

#include<bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int ans = 0;

bool checkSwaps(vector<int> &p, int mid) {
    // TODO
    return false;
}

void binarySearch(vector<int> &p, int low, int high) {
    if(low > high) return;
    int mid = (low + high) >> 1;
    if(checkSwaps(p, mid)) {
        ans = mid;
        binarySearch(p, mid + 1, high);
    } else binarySearch(p, low, mid - 1);
}

int maximizeK(vector<int> &p) {
    binarySearch(p, 0, p.size() - 1);
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    cout << maximizeK(p) << endl;
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