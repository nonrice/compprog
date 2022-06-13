#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, int cur, int prev, int kill, int& min_kill){
    if (adj[cur].size() == 1){
        min_kill = min(kill, min_kill);
        return;
    }

    if (adj[cur].size() == 2){
        min_kill = min(kill+1, min_kill);
        return;
    }

    for (int v : adj[cur]) if (v != prev){
        dfs(adj, v, cur, kill + (adj[cur].size()-1), min_kill);
    }
}

void solve(){
    int n; cin >> n;
    vector<vector<int>> adj(n);
    while (--n){
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }
    adj[0].push_back(0);
    
    int min_kill = INT_MAX;
    dfs(adj, 0, 0, 1, min_kill);
    
    cout << adj.size()-min_kill << '\n';
}

int main(){
    int cases; cin >> cases;
    while(cases--) solve();
}
