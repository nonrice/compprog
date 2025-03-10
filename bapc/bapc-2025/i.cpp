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
    vector<vector<int>> e(n);
    for (int i=0; i<n; ++i){
        int k; cin >> k;
        for (int j=0; j<k; ++j){
            int x; cin >> x;
            e[i].push_back(x);
        }
        sort(e[i].begin(), e[i].end());
    }
    vector<vector<int>> t(n);
    for (int i=0; i<m; ++i){
        int l, r; cin >> l >> r;
        --l, --r;
        t[l].push_back(r);
    }

    debug("---");
    debug(n, m);
    debug(e);
    debug(t);

    multiset<int> c;
    for (int i=0; i<n; ++i){
        while (!c.empty() && *c.begin()<i){
            c.erase(c.begin());
        }
        c.insert(t[i].begin(), t[i].end());

        for (int j=0; j<e[i].size(); ++j){
            if (e[i][j]<=j || c.empty()){
                cout << "NO\n";
                return;
            }

            c.erase(--c.end());
        }
    }

    cout << "YES\n";

}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}