#include <bits/stdc++.h>
using namespace std;

using ll = long long;


int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    
    // 2 adjacency lists, one for proper direction, other for reversed
    vector<vector<pair<int, int>>> adj[2] = {
        vector<vector<pair<int, int>>>(n, vector<pair<int, int>>()),
        vector<vector<pair<int, int>>>(n, vector<pair<int, int>>())
    };
    for (int i=0; i<m; ++i){
        int u, v, w; cin >> u >> v >> w;
        adj[0][--u].emplace_back(--v, w);
        adj[1][v].emplace_back(u, w);
    }

    // normal djikstra, but now at any point a path can switch to the set of reversed paths
    // this requires a few adaptations, mostly to handle how multiple shortest paths to a point are used
    vector<ll> dist[2] = {
        vector<ll>(n, LLONG_MAX),
        vector<ll>(n, LLONG_MAX)
    };
    vector<bool> done[2] = {
        vector<bool>(n),
        vector<bool>(n)
    };
    dist[0][0] = dist[1][0] = 0;
    priority_queue<tuple<ll, int, bool>, vector<tuple<ll, int, bool>>, greater<tuple<ll, int, bool>>> pq;
    pq.emplace(0, 0, false);
    while (!pq.empty()){
        auto [l, u, rev] = pq.top(); pq.pop();
        if (!done[rev][u]){
            done[rev][u] = true;
            
            for (int cr=rev; cr<=1; ++cr){
                for (auto [v, w] : adj[cr][u]){
                    if (dist[rev][u]+w <= dist[cr][v]){
                        dist[cr][v] = dist[rev][u]+w;
                        pq.emplace(dist[cr][v], v, cr);
                    }
                }
            }
        }
    }

    for (int i=1; i<n; ++i){
        ll d = min(dist[0][i], dist[1][i]);
        if (d == LLONG_MAX) cout << "-1 ";
        else cout << d << ' ';
    }
    cout << '\n';
}
