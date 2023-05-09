/*
Problem Details:
    Contest Event Name: CSES Problem Set Sorting and Searching
    Contest Event Link: https://codeforces.com/gym/102961
    Problem Statement Label Number: F
    Problem Statement Code Number: 102961F
    Problem Statement Link Number: https://codeforces.com/gym/102961/problem/F
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

bool checkOverlap(pair<int, int> &movie1, pair<int, int> &movie2) {
    if(movie1.first < movie2.first && movie1.second > movie2.second) return true;
    if(movie2.first < movie1.first && movie2.second > movie1.second) return true;
    if(movie1.first > movie2.second || movie2.first > movie1.second) return true;
    return false;
}

int getMovies(vector<pair<int, int>> &movies) {
    if(movies.size() == 1) return 1;
    if(movies.size() == 2) return checkOverlap(movies[0], movies[1]) + 1;
    int movie0 = 1, movie1 = checkOverlap(movies[0], movies[1]) + 1;
    for(int i = 1; i < movies.size(); i++) {
        int movie2 = max(checkOverlap(movies[i], movies[i - 1]), movie1);
        movie0 = movie1;
        movie1 = movie2;
    }
    return movie1;
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> movies(n);
    for(int i = 0; i < n; i++) cin >> movies[i].first >> movies[i].second;
    cout << getMovies(movies) << endl;
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