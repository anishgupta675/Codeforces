/*
Problem Details:
    Contest Event Name: Codeforces Round 734 (Div. 3)
    Contest Event Link: https://codeforces.com/contest/1551
    Problem Statement Label Number: B2
    Problem Statement Code Number: 1551B2
    Problem Statement Link Number: https://codeforces.com/problemset/problem/1551/B2
*/

/*
Short explanation: Store an unordered map to keep track of the frequency of unique elements. If the frequency of a distinct element is greater than or equal to k, then there is only one succinct order of arranging the colors for that particular element, the rest of which will be left as 0 (uncolored), else just store another extra('s) array/vector to store the elements until we can seek to form a full cluster of elements of size k.
*/

#include<bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

vector<int> getColor(vector<int> &seq, int n, int k) {
    vector<int> ans(n);
    unordered_map<int, int> freq;
    unordered_map<int, vector<int>> occ;
    for(int i = 0; i < n; i++) {
        freq[seq[i]]++;
        occ[seq[i]].push_back(i);
    }
    vector<int> toColor;
    for(int i = 1; i <= n; i++) {
        if(freq[i] >= k) for(int j = 0; j < k; j++) ans[occ[i][j]] = j + 1;
        else for(int j = 0; j < freq[i]; j++) toColor.push_back(occ[i][j]);
    }
    for(int i = 0; i <= toColor.size() - k; i+= k) for(int j = 0; j < k; j++) ans[toColor[i + j]] = j + 1;
    return ans;
}

void printList(vector<int> seq) {
    for(int i : seq) cout << i << " ";
    cout << endl;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> seq(n);
    for(int i = 0; i < n; i++) cin >> seq[i];
    printList(getColor(seq, n, k));
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