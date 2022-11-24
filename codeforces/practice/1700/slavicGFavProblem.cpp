#include <bits/stdc++.h>
using namespace std;

void dfs1(int u, int p, int b, vector<vector<pair<int, int>>>& adj, int cur, set<int>& pref){
    for (auto [v, w] : adj[u]){
        if (v != p && v != b){
            pref.insert(cur^w);
            dfs1(v, u, b, adj, cur^w, pref);
        }
    }
}

bool dfs2(int u, int p, vector<vector<pair<int, int>>>& adj, int cur, set<int>& pref){
    for (auto [v, w] : adj[u]){
        if (v != p){
            if (pref.count(cur^w)) return true;
            if (dfs2(v, u, adj, cur^w, pref)) return true;
        }
    }
    return false;
}

void solve(){
    int n, a, b; cin >> n >> a >> b;
    --a; --b;
    vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
    for (int i=0; i<n-1; ++i){
        int u, v, w; cin >> u >> v >> w;
        adj[--u].emplace_back(--v, w);
        adj[v].emplace_back(u, w);
    }

    set<int> pref = { 0 };
    dfs1(a, a, b, adj, 0, pref);
    if (dfs2(b, b, adj, 0, pref)) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
