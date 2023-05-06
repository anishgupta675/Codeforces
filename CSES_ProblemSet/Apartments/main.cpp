/*
Problem Details:
    Contest Event Name: CSES Problem Set Sorting and Searching
    Contest Event Link: https://codeforces.com/gym/102961
    Problem Statement Label Number: B
    Problem Statement Code Number: 102961B
    Problem Statement Link Number: https://codeforces.com/gym/102961/problem/B
*/

/*
Short explanation: Sort both applicants and appartments array each in non-decreasing order. This
infers that, starting from the applicant with the smallest appartment size and the appartment with
the smallest size at the beginning of the first and second arrays respectively, if the size of the
current appartment is less than the current applicant's lower bound appartment size requirement
threshold, then we can skip through that appartment entirely (because nobody wants it anyways). If
the size of the current appartment is more than the current applicant's upper bound appartment size
requirement threshold, then we can skip through that applicant entirely (because he will never
receive an appartment of his size requirement anyways).
*/

#include<bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int getApartment(vector<int> &a, vector<int> &b, int n, int m, int k) {
    int i = 0, j = 0, cnt = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    while(j < m) {
        if(b[j] < a[i] - k) j++;
        else if(b[j] > a[i] + k) i++;
        else if(b[j] >= a[i] - k && b[j] <= a[i] + k) {
            cnt++;
            i++;
            j++;
        }
    }
    return cnt;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    cout << getApartment(a, b, n, m, k) << endl;
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