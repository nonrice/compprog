#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n, x; cin >> n >> x;
    vector<int> v(n);
    for (int i=0; i<n; ++i){
        int z; cin >> z;
        if (z < n){
            ++v[z];
        }
    }

    vector<int> f(min(n, x));
    for (int m=0; m<=n-1; ++m){
        if (v[m]){
            f[m % x] += v[m]-1;
        } else {
            if (f[m % x]){
                --f[m % x];
                v[m] = true;
            } else {
                cout << m << '\n';
                return;
            }
        }
    }

    cout << n << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}