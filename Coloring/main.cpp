/*
Problem Details:
    Contest Event Name: Polynomial Round 2022 (Div. 1 + Div. 2, Rated, Prizes!)
    Contest Event Link: https://codeforces.com/contest/1774
    Problem Statement Label Number: B
    Problem Statement Code Number: 1774B
    Problem Statement Link Number: https://codeforces.com/contest/1774/problem/B
*/

/*
Short explanation: If n % k == 0, then divide the paper tape into k segments where length of each
segment is (n / k) and the maximum number of elements that can have that frequency exactly equal to
that is k. Else if n % k != 0, then divide the tape into k segments where length of every segment
except the last is ((n / k) + 1), length of the last segment is n % k, and the maximum number of
elements that can have that frequency equal to that maximum length of the longest segment is n % k.
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

bool checkSchemeUtil(vector<ll> &a, ll n, ll m, ll k) {
    /*
    ll maximum_frequency = (!(n % k)) ? (n / k) : ((n / k) + 1), maximum_elements = (!(n % k)) ? k : n % k;
    for(int i = 0; i < m; i++) {
        if(a[i] > maximum_frequency) {
            // return "NO";
            maximum_elements = -1;
            // cout << "NO" << endl;
            break;
        }
        if(a[i] == maximum_frequency) maximum_elements--;
    }
    return (maximum_elements < 0) ? "YES" : "NO";
    */
    return false;
}

string checkScheme(vector<ll> &a, ll n, ll m, ll k) {
    return (checkSchemeUtil(a, n, m, k)) ? "YES" : "NO";
}

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(m);
    for(int i = 0; i < m; i++)
        cin >> a[i];
    // cout << checkScheme(a, n, m, k) << endl;
    ll maximum_frequency = (!(n % k)) ? (n / k) : ((n / k) + 1), maximum_elements = (!(n % k)) ? k : n % k;
    for(int i = 0; i < m; i++) {
        if(a[i] > maximum_frequency) {
            // return "NO";
            maximum_elements = -1;
            // cout << "NO" << endl;
            break;
        }
        if(a[i] == maximum_frequency) maximum_elements--;
    }
    cout << ((maximum_elements < 0) ? "NO" : "YES") << endl;
    a.clear();
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