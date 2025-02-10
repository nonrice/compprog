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

void solve(){
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int i=0; i<n-1; ++i){
        int u, v; cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    size_t ans = 0;
    auto dfs = ycomb([&](const auto& self, int u, int p)->size_t{
        size_t c = 0;
        size_t c1 = 0, c2 = 0;
        for (auto v : adj[u]){
            if (v != p){
                ans = max(ans, adj[u].size() + adj[v].size() - 2);
                
                size_t m = self(v, u);
                c = max(c, m);

                size_t s = max(m, adj[v].size());
                if (s >= c2){
                    c1 = c2;
                    c2 = s;
                } else if (s > c1){
                    c1 = s;
                }
            }
        }
        ans = max(ans, adj[u].size() + c - 1);
        if (c1 != 0 && c2 != 0){
            ans = max(ans, c1+c2-1);
        }

        for (auto v : adj[u]){
            if (v != p){
                c = max(c, adj[v].size());
            }
        }
        return max(c, c2);
    });

    dfs(0, -1);

    cout << ans << '\n';

}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}