#include <bits/stdc++.h>
using namespace std;

using ll = long long;

short a[2500];

int dfs(int cur, int prev, vector<vector<int>>& adj){
    int total = 0;
    for (int v : adj[cur]) if (v != prev){
        total += dfs(v, cur, adj);
    }
    return 12 - ((a[cur]+total)%12);
}

int main(){
#ifndef LOCAL
    freopen("clocktree.in", "r", stdin);
    freopen("clocktree.out", "w", stdout);
#endif
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int n; cin >> n;
    for (int i=0; i<n; ++i) cin >> a[i];
    vector<vector<int>> adj(n, vector<int>());
    for (int i=0; i<n-1; ++i){
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }

    int ans = 0;
    for (int i=0; i<n; ++i){
        if (dfs(i, i, adj) == 11 || dfs(i, i, adj) == 0){
            ++ans;
        }
    }

    cout << ans << '\n';
}

