#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n, k; cin >> n >> k;
    map<int, int> f;
    for (int i=0; i<n; ++i){
        int x; cin >> x;
        ++f[x];
    }

    int ans = 0;
    for (auto [x, v] : f){
        ans += min(v, f[k-x]);
    }
    ans /= 2;
    cout << ans << '\n';

}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}