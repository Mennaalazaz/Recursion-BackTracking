#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;
#define intCeil(a,b) (ll(a)+ll(b-1))/ll(b)

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
ll n, m;
vector<vector<ll>> grid;
ll fun(ll i, ll j) {
    //Base case
    if (i >= n || j >= m) return -1e7;

    if (i == n - 1 && j == m - 1) return grid[i][j];

    // Transition
    ll sum1 = fun(i + 1, j);
    ll sum2 = fun(i, j + 1);
    // Return the current cell value plus the maximum of the two paths
    return grid[i][j] + max(sum1, sum2);
}

void solve() {
    cin >> n >> m;
    grid.assign(n, vector<ll>(m)); // Initialize the grid

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // Start from the top-left corner (0, 0)
    cout << fun(0, 0) << endl;
}


int main() {
    fastIO();
    solve();
    return 0;
}
