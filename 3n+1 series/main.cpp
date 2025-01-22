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
int n;
ll s(int i) {
    // base case
    if(i==1) return 1;
    // transition
    if(i%2==0) {
        return s(i/2)+1;
    }
    else {
        return s(3*i+1)+1;
    }
}

void solve() {
    cin>>n;
    cout<<s(n)<<endl;
}


int main() {
    fastIO();
    solve();
    return 0;
}
