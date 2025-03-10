#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int x, n; cin >> x >> n;

    int ans = 1;
    for (int f=1; f*f<=x; ++f){
        if (x%f == 0){
            if (x/f >= n){
                ans = max(ans, f);
            }
            if (f >= n){
                ans = max(ans, x/f);
            }
        }
    }
    cout << ans << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}