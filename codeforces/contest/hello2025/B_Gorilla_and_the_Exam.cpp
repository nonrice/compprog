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
    vector<int> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }

    map<int, int> f;
    for (int i=0; i<n; ++i){
        ++f[a[i]];
    }

    vector<pair<int, int>> g;
    for (auto [k, v] : f){
        g.emplace_back(v, k);
    }
    sort(g.begin(), g.end());

    int ans = g.size();
    int p = 0;
    for (int i=0; i<g.size(); ++i){
        p += g[i].first;

        if (p <= k){
            ans = max((size_t)1, g.size() - i-1);
        } else {
            break;
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