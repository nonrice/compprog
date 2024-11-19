#include <bits/stdc++.h>
using namespace std;

void dfs(int& impc, int& total, int cur, vector<vector<pair<int, bool>>>& adj, vector<bool>& vis, vector<bool>& imps){
    impc += imps[cur];

    for (auto& v : adj[cur]){
        if (vis[v.first] && (imps[cur]^v.second) != imps[v.first]){
            impc = -1;
            return;
        }
        if (!vis[v.first]){
            ++total;
            vis[v.first] = true;
            imps[v.first] = imps[cur]^v.second;
            dfs(impc, total, v.first, adj, vis, imps);
            if (impc == -1) return;
        }
    }
}

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<pair<int, bool>>> adj(n);
    while (m--){
        int u, v; cin >> u >> v;
        string s; cin >> s;
        adj[--u].emplace_back(--v, s=="imposter");
        adj[v].emplace_back(u, s=="imposter");
    }
    
    int ans = 0;
    vector<bool> vis(n);
    vector<bool> imps(n);
    for (int u=0; u<n; ++u) if (!vis[u]){
        int impc=0, total=0;
        dfs(impc, total, u, adj, vis, imps);

        if (impc == -1){
            cout << "-1\n";
            return;
        }
        ans += max(impc, total-impc);
    }
    
    cout << ans + n-accumulate(vis.begin(), vis.end(), 0) << '\n';
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}
