#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    uint64_t x, m; cin >> x >> m;

    int xw = 64-__builtin_clzll(x);
    uint64_t s = (m>>xw);
    uint64_t tx = x >> (min(xw, __builtin_ctzll(x)));
    debug(x);
    long long ans = 0;
    for (uint64_t y=0; (y==0) || (y<=m && __builtin_clzll(y)>=64-xw); ++y){
        bool o = ((m>>xw<<xw)|y) > m;
        if ((x^y) % x == 0){
            ans += s/tx + (y!=0) - (o && s%tx==0);
        }
        if (y != 0 && (x^y) % y == 0){
            uint64_t ty = y >> (min(xw, __builtin_ctzll(y)-1));
            ans += s/ty + 1 - (o && s%ty==0);
        }
        if (y != 0 && (x^y) % x == 0 && (x^y) % y == 0){
            uint64_t d = x*y/gcd(x, y);
            uint64_t td = d >> (min(xw, __builtin_ctzll(d)-1));
            ans -= s/td + 1 - (o && s%td==0);
        }
        debug(y, ans);
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