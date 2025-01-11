#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

template<class Fun> class ycomb_result {
    Fun fun_;
public:
    template<class T> explicit ycomb_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) ycomb(Fun &&fun) { return ycomb_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

uint64_t hash_add(uint64_t h, uint64_t x){
    return h * (1779033703 + 2*x);
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    vector<vector<pair<int, uint64_t>>> adj(n+1);
    for (int i=0; i<m; ++i){
        int u, v; cin >> u >> v;
        uint64_t l; cin >> l;
        adj[u].emplace_back(v, l);
    }

    vector<int> d(n+1);
    vector<long long> s(n+1);
    vector<array<uint64_t, 20>> h(n+1);
    vector<array<int, 20>> up(n+1);
    auto comp_path = [&](int u, int v)->bool{
        for (int p=19; p>=0; --p){
            if (up[u][p] != 0 && up[v][p] != 0 && h[u][p]==h[v][p]){
                u = up[u][p];
                v = up[v][p];
            }
        }

        if (up[u][0]==0 && up[v][0]==0){
            // only comp paths of same lengths--> just check if they both are equal
            return false;
        }
        return h[u][0] < h[v][0]; // hash of one ele preserves relative order
    };

    vector<bool> vis(n+1);
    auto dfs = ycomb([&](const auto& self, int u)->void{
        if (adj[u].size() == 0){
            d[u] = 0;
            return;
        }
        int mx_v = adj[u][0].first;
        int mx_l = adj[u][0].second;
        for (auto [v, l] : adj[u]){
            if (!vis[v]){
                vis[v] = true;
                self(v);
            }
            if (d[v] > d[mx_v]){
                mx_v = v;
                mx_l = l;
            } else if (d[v] == d[mx_v] && ((l<mx_l) || (mx_l==l && comp_path(v, mx_v)))){
                mx_v = v;
                mx_l = l;
            }
        }

        s[u] = s[mx_v] + mx_l;
        d[u] = d[mx_v]+1;
        up[u][0] = mx_v;
        h[u][0] = hash_add(1, mx_l);
        for (int p=1; p<=19; ++p){
            up[u][p] = up[up[u][p-1]][p-1];
            h[u][p] = h[u][p-1] * h[up[u][p-1]][p-1];
        }
    });

    for (int u=1; u<=n; ++u){
        dfs(u);
        cout << d[u] << ' ' << s[u] << '\n';
    }
}