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
int target; int ans;
void lucky(int num=0, int idx=0) {
    // base case
    if (num > target) {
        return;
    }
    if (num == target) {
        ans=idx;
        return;
    }

    // transition
    lucky(num*10+4, 2*idx+1);
    lucky(num*10+7, 2*idx+2);
}

void solve() {
    cin >> target;
    lucky();
    cout << ans << endl;

}


int main() {
    fastIO();
    solve();
    return 0;
}
