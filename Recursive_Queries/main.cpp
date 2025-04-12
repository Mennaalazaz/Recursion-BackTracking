#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void fastIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
}


// Get product of non-Zero digits of n
ll f(ll n) {
    ll res = 1;
    while (n) {
        int d = n % 10;
        if(d!=0)res = res * d;
        n /= 10;
    }
    return res;
}

int g(ll n) {
    if(n<10) return n;
    return g(f(n));
}

const int Max= 1e6+5;
vector<vector<int>> prefix(10, vector<int>(Max));

void precompute() {
    // Compute prefix sums for each k
    for (int k = 1; k <= 9; ++k) {
        for (int x = 1; x < Max; ++x) {
            prefix[k][x] = prefix[k][x - 1] + (g(x) == k ? 1 : 0);
        }
    }
}


int main() {
    fastIO();
    precompute();

    int Q;cin >> Q;
    while (Q--) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << prefix[k][r] - prefix[k][l - 1] << '\n';
    }
    return 0;
}