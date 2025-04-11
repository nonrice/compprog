#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int x; cin >> x;

    if (__builtin_popcount(x) == 1 || __builtin_popcount(x+1) == 1){
        cout << "-1\n";
        return;
    }

    int p1 = 1;
    while (!(p1 & x)){
        p1 <<= 1;
    }
    int p2 = 1;
    while (!(p2 & (~x))){
        p2 <<= 1;
    }

    debug(p1, p2);
    cout << p1+p2 << '\n';

    int y = p1+p2;
    debug(x, y, x^y);
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
