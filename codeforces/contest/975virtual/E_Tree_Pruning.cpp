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

    auto dfs = ycomb([&](const auto& self, int u, int p, int d)->int{
        if (d == 0){
            return 1;
        }

        if (adj[u].size() == 1 && d != 0){
            return -1;
        }

        int c = 1;
        for (auto v : adj[u]){
            int r = self(v, u, d-1);
            if (r == -1){
                return -1;
            }
            c += r;
        }
        return c;
    });

    int r = 0;
    for (int s=n; s>=1; s/=2){
        while (dfs(0, 0, r+s) != -1){
            r += s;
        }
    }

    debug(r);
    cout << n - dfs(0, 0, r) << '\n'; 



}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}