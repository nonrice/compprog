#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }

    map<int, int> lf, rf, mf;
    map<int, set<int>> lc, rc, mc;
    for (int i=1; i<=n; ++i){
        lc[0].insert(i);
        rc[0].insert(i);
        mc[0].insert(i);
    }
    for (int i=0; i<n; ++i){
        if (i < n-1){
            lc[lf[a[i]]].erase(a[i]);
            lc[++lf[a[i]]].insert(a[i]);
        }
        if (i > 0){
            rc[rf[a[i]]].erase(a[i]);
            rc[++rf[a[i]]].insert(a[i]);
        }
        mc[mf[a[i]]].erase(a[i]);
        mc[++mf[a[i]]].insert(a[i]);
    }

    while (q--){
        int t; cin >> t;
        debug(q, t);

        if (t == 1){
            int i, y; cin >> i >> y;
            --i;
            if (i < n-1){
                lc[lf[a[i]]].erase(a[i]);
                lc[--lf[a[i]]].insert(a[i]);
            }
            if (i > 0){
                rc[rf[a[i]]].erase(a[i]);
                rc[--rf[a[i]]].insert(a[i]);
            }
            mc[mf[a[i]]].erase(a[i]);
            mc[--mf[a[i]]].insert(a[i]);
            a[i] = y;
            if (i < n-1){
                lc[lf[a[i]]].erase(a[i]);
                lc[++lf[a[i]]].insert(a[i]);
            }
            if (i > 0){
                rc[rf[a[i]]].erase(a[i]);
                rc[++rf[a[i]]].insert(a[i]);
            }
            mc[mf[a[i]]].erase(a[i]);
            mc[++mf[a[i]]].insert(a[i]);
        } else {
            int l, r; cin >> l >> r;
            if (l == 1 && r == n){
                cout << *(mc.begin()->second.begin()) << '\n';
            } else if (l == 1){
                cout << *(lc.begin()->second.begin()) << '\n';
            } else if (r == n){
                cout << *(rc.begin()->second.begin()) << '\n';
            } else {
                cout << *(lc.begin()->second.begin()) << '\n';
            }
            debug(a, l, r);
        }
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    solve();
}