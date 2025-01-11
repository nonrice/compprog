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
    long long m; cin >> m;
    vector<vector<int>> l(n);
    for (int i=0; i<n; ++i){
        int k; cin >> k;
        l[i] = vector<int>(k);
        for (int j=0; j<k; ++j){
            cin >> l[i][j];
        }
        sort(l[i].begin(), l[i].end());
    }

    vector<long long> a1(n), a2(n);
    for (int i=0; i<n; ++i){
        size_t j = 0;
        for (; j<l[i].size(); ++j){
            if (l[i][j] == a1[i]){
                ++a1[i];
            } else if (l[i][j] > a1[i]-1) {
                break;
            }
        }
        a2[i] = a1[i]+1; 
        for (; j<l[i].size(); ++j){
            if (l[i][j] == a2[i]){
                ++a2[i];
            } else if (l[i][j] > a2[i]-1) {
                break;
            }
        }
    }
    
    
    map<long long, vector<long long>> adj;
    for (int i=0; i<n; ++i){
        adj[a1[i]].push_back(a2[i]);
    }

    map<long long, long long> dp;
    auto dfs = ycomb([&](const auto& self, long long u)->long long{
        if (dp.count(u)){
            return dp[u];
        }   

        if (!adj.count(u)){
            return adj.rbegin()->first;
        }

        long long h = u;
        for (auto v : adj[u]){
            if (!dp.count(v)){
                h = max(h, self(v));
            }
        }
        return dp[u] = h;
    });

     

    adj[-1] = a1;
    dfs(-1);





}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}