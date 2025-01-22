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
int n; vector<ll> v;
ll fun(int i, ll sum1 , ll sum2) {
    // base case
    if(i==n) return abs(sum1-sum2);

    // transition
    ll ch1=fun(i+1,sum1+v[i],sum2);
    ll ch2=fun(i+1,sum1,sum2+v[i]);

    return min(ch1,ch2);
}

void solve() {
    cin>>n; v.resize(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    cout<<fun(0,0,0)<<endl;
}


int main() {
    fastIO();
    solve();
    return 0;
}
