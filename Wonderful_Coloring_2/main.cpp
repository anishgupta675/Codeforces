/*
Problem Details:
    Contest Event Name: Codeforces Round 734 (Div. 3)
    Contest Event Link: https://codeforces.com/contest/1551
    Problem Statement Label Number: B2
    Problem Statement Code Number: 1551B2
    Problem Statement Link Number: https://codeforces.com/problemset/problem/1551/B2
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

int ans = 0;
vector<pair<int, int>> v;
set<pair<int, int>> ss;
unordered_map<int, stack<int>> col;

bool check(int k, int mid) {
    set<pair<int, int>> sss;
    unordered_map<int, int> cnt;
    for(auto i : ss) sss.insert(make_pair(-1 * i.second, i.first));
    for(int i = 0; i < k; i++) {
        set<pair<int, int>> del;
        if(sss.size() < mid) return false;
        for(int j = 0; j < mid; j++) {
            pair<int, int> p = *sss.begin();
            sss.erase(sss.begin());
            if(p.first == -1) continue;
            else del.insert(make_pair(-1 * (-1 * p.first - 1), p.second));
        }
        for(auto j : del) sss.insert(j);
    }
    return true;
}

void binarySearch(int k, int low, int high) {
    if(low > high) return;
    int mid = (low + high) >> 1;
    if(check(k, mid)) {
        ans = mid;
        binarySearch(k, mid + 1, high);
    } else binarySearch(k, low, mid - 1);
}

void color(int k, int mid) {
    set<pair<int, int>> sss;
    unordered_map<int, int> cnt;
    for(auto i : ss) sss.insert(make_pair(-1 * i.second, i.first));
    for(int i = 0; i < k; i++) {
        set<pair<int, int>> del;
        for(int j = 0; j < mid; j++) {
            pair<int, int> p = *sss.begin();
            sss.erase(sss.begin());
            col[p.second].push(i + 1);
            if(p.first == -1) continue;
            else del.insert(make_pair(-1 * (-1 * p.first - 1), p.second));
        }
        for(auto j : del) sss.insert(j);
    }
}

vector<int> getColor(vector<int> &seq, int k) {
    int c1 = 0, c2 = 0;
    vector<int> res;
    unordered_map<int, int> m;
    for(int i = 0; i < seq.size(); i++) {
        if(m[seq[i]] == k - 1) {
            c1++;
            m[seq[i]]++;
        } else m[seq[i]]++;
    }
    for(int i = 0; i < seq.size(); i++) if(m[seq[i]] < k) ss.insert(make_pair(seq[i], m[seq[i]]));
    sort(v.begin(), v.end());
    binarySearch(k, 0, seq.size() - c1);
    color(k, ans);
    int ind = 1;
    unordered_map<int, int> col2;
    for(int i = 0; i < seq.size(); i++) {
        if(m[seq[i]] >= k && col2[seq[i]] + 1 <= k) {
            res.push_back(col2[seq[i]] + 1);
            col2[seq[i]]++;
        } else if(!col[seq[i]].empty()) {
            res.push_back(col[seq[i]].top());
            col[seq[i]].pop();
        } else res.push_back(0);
    }
    return res;
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
    printList(getColor(seq, k));
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