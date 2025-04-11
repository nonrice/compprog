#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

constexpr long long M = 998244353;

void solve(){
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int u=1; u<n; ++u){
        int v; cin >> v;
        --v;
        adj[v].push_back(u);
    }

    vector<int> d(n);
    queue<int> bfs({ 0 });
    while (!bfs.empty()){
        auto u = bfs.front(); bfs.pop();
        for (auto v : adj[u]){
            d[v] = d[u]+1;
            bfs.push(v);
        }
    }

    vector<int> o(n);
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](int a, int b){
        return d[a] > d[b];
    });

    vector<long long> s(n+1);
    vector<long long> dp(n);
    for (int i=0; i<n; ++i){
        dp[o[i]] = (s[d[o[i]]+1] + 1) % M;
        for (auto v : adj[o[i]]){
            dp[o[i]] = (dp[o[i]] + M - dp[v]) % M;
        }
        s[d[o[i]]] = (s[d[o[i]]] + dp[o[i]]) % M;
    }

    cout << (s[1]+1) % M << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
