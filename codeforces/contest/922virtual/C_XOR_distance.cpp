#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    long long a, b, r; cin >> a >> b >> r;

    debug(bitset<70>(a));
    debug(bitset<70>(b));
    debug(bitset<70>(r));

    long long x = 0;
    bool f = false;
    bool h = false;
    for (long long m = 1LL<<62; m>=1; m>>=1){
        if ((a&m) != (b&m)){

            if (f == false){
                f = true;
                h = (a&m);
            } else {
                if ((bool(a&m) == h) && (x|m)<=r){
                    x |= m;
                }
            }
        }
    }

    debug(x);

    cout << abs((a^x) - (b^x)) << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}