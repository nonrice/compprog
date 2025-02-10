#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

// DSU
// DSU: Construct DSU structure with path compression and union by size for graph of n vertices.
// find: Get the representative node for node u in O(alpha(n))
// merge: Merge the components of node u and v in O(alpha(n))

struct DSU {
    vector<int> t;
    vector<int> sz;

    DSU(int n){
        t = vector<int>(n+1);
        sz = vector<int>(n+1, 1);
        iota(t.begin(), t.end(), 0);
    }

    int find(int u){
        if (u == t[u]) return u;
        return t[u] = find(t[u]);
    }

    bool merge(int u, int v){
        int pu = find(u);
        int pv = find(v);
        if (pu != pv){
            if (sz[pu] < sz[pv]){
                swap(pu, pv);
            }
            t[pv] = pu;
            sz[pu] += sz[pv];
        }
        return pu == pv;
    }
};


void solve(){
    int n, m1, m2; cin >> n >> m1 >> m2;

    set<pair<int ,int>> e1, e2;
    for (int i=0; i<m1; ++i){
        int u, v; cin >> u >> v;
        --u, --v;
        e1.emplace(u, v);
    }
    for (int i=0; i<m2; ++i){
        int u, v; cin >> u >> v;
        --u, --v;
        e2.emplace(u, v);
    }

    DSU g2(n);
    for (auto [u, v] : e2){
        g2.merge(u, v);
    }

    int ans = 0;
    DSU g(n);
    for (auto it = e1.begin(); it != e1.end();){
        if (g2.find(it->first) != g2.find(it->second)){
            it = e1.erase(it);
            ++ans;
        } else {
            ++it;
        }
    }

    DSU g1(n);
    for (auto [u, v] : e1){
        g1.merge(u, v);
    }

    for (auto [u, v] : e2){
        ans += !g1.merge(u, v);
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