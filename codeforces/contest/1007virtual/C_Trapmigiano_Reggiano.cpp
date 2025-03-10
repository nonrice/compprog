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
    int n, st, en;
    cin >> n >> st >> en;
    --st, --en;

    vector<vector<int>> adj(n);
    for (int i=0; i<n-1; ++i){
        int u, v; cin >> u >> v;
        --u, --v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    vector<int> s;
    auto f = ycomb([&](const auto& self, int u, int p)->bool{
        if (u == en){
            s.push_back(u);
            return true;
        }
        for (auto v : adj[u]){
            if (v != p){
                if (self(v, u)){
                    s.push_back(u);
                    return true;
                }
            }
        }

        return false;
    });
    f(0, 0);
    reverse(s.begin(), s.end());
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}