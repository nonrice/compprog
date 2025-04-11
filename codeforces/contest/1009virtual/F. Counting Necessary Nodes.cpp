#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

int f(int l1, int r1, int l2, int r2){
    debug(l1, r1, l2, r2);
    if (l1 == r1 || l2 == r2){
        return 0;
    }
    if (l1+1 == r1){
        return r2-l2;
    }
    if (l2+1 == r2){
        return r1-l1;
    }
    int p = 1<<20;
    while ((l1+p-1)/p*p >= r1/p*p || (l2+p-1)/p*p >= r2/p*p){
        p >>= 1;
    }
    debug(l1, r1, l2, r2);

    int sl1 = (l1+p-1)/p*p;
    int sr1 = r1/p*p;
    int sl2 = (l2+p-1)/p*p;
    int sr2 = r2/p*p;

    sl1 = max(sl1, l1);
    sl2 = max(sl2, l2);
    sr1 = min(sr1, r1);
    sr2 = min(sr2, r2);

    int c = (sr1-sl1)/p * ((sr2-sl2)/p);
    debug(c);

    return c + f(l1, sl1, l2, r2) + f(sr1, r1, l2, r2) + f(sl1, sr1, l2, sl2) + f(sl1, sr1, sr2, r2);
}

void solve(){
    int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
    debug(l1);

    cout << f(l1, r1, l2, r2) << '\n';

}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
