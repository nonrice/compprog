#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n, m; cin >> n >> m;
    set<long long> a;
    for (int i=0; i<n; ++i){
        long long x; cin >> x;
        a.insert(x);
    }

    while (m--){
        char ch; cin >> ch;
        long long l, r; cin >> l >> r;

        auto it = a.upper_bound(r);
        if (it != a.begin() && *--it >= l){
            if (ch == '+'){
                a.insert(*it+1);
            } else {
                a.insert(*it-1);
            }
            a.erase(*it);
        }

        cout << (*--a.end()) << ' ';
    }
    cout << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}