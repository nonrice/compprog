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
    vector<int> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }

    auto cmp = [&](int i, int j){
        return a[i] < a[j];
    };
    vector<multiset<int, decltype(cmp)>> dp;
    for (int i=0; i<=n+1; ++i){
        dp.emplace_back(cmp);
    }

    auto chk = [&](int x, int l){
        if (dp[l].empty()){
            return l == 0;
        }
        return a[*dp[l].begin()] < x;
    };
    vector<vector<int>> adj(n);
    for (int i=0; i<n; ++i){
        int l = 0;
        for (int s=n; s>=1; s/=2){
            while (l+s<=n && chk(a[i], l+s)){
                l += s;
            }
        }
        for (auto j : dp[l]){
            if (a[j] < a[i]){
                adj[i].push_back(j);
            } else {
                break;
            }
        }
        debug(n, i, l+1, dp[l+1]);
        dp[l+1].insert(i);
        debug(n, i, l+1, dp[l+1]);
    }

    vector<bool> vis(n);
    auto dfs = ycomb([&](const auto& self, int u)->void{
        vis[u] = true;
        for (auto v : adj[u]){
            if (!vis[v]){
                vis[v] = true;
                self(v);
            }
        }
    });
    for (int l=n; l>=0; --l){
        if (!dp[l].empty()){
            for (auto i : dp[l]){
                dfs(i);
            }
            break;
        }
    }

    vector<int> ans;
    for (int i=0; i<n; ++i){
        if (vis[i]){
            ans.push_back(i+1);
        }
    }

    cout << ans.size() << '\n';
    for (int i=0; i<ans.size(); ++i){
        cout << ans[i] << ' ';
    }
    cout << '\n';

    debug(dp);
    debug(adj);
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}