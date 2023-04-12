#include<iostream>
#include<vector>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

bool checkCoordinates(ll x1, ll x2, ll y2, ll y3) {
    if(x1 == x2 && y2 == y3) return false;
    return true;
}

bool checkTriangle(vector<pair<ll, ll>> &coordinates) {
    if(!checkCoordinates(coordinates[0].first, coordinates[1].first, coordinates[1].second, coordinates[2].second)) return false;
    if(!checkCoordinates(coordinates[1].first, coordinates[2].first, coordinates[2].second, coordinates[0].second)) return false;
    if(!checkCoordinates(coordinates[2].first, coordinates[0].first, coordinates[0].second, coordinates[1].second)) return false;
    if(!checkCoordinates(coordinates[2].first, coordinates[1].first, coordinates[1].second, coordinates[0].second)) return false;
    if(!checkCoordinates(coordinates[0].first, coordinates[2].first, coordinates[2].second, coordinates[1].second)) return false;
    if(!checkCoordinates(coordinates[1].first, coordinates[0].first, coordinates[0].second, coordinates[2].second)) return false;
    return true;
}

void solve() {
    int x, y;
    vector<pair<ll, ll>> coordinates;
    cin.get();
    for(int i = 0; i < 3; i++) {
        cin >> x >> y;
        coordinates.push_back(make_pair(x, y));
    }
    cout << ((checkTriangle(coordinates)) ? "YES" : "NO") << "\n";
    coordinates.clear();
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