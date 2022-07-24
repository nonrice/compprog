#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    int n, m; cin >> n >> m;
    vector<vector<pair<int, ll>>> adj(n, vector<pair<int, ll>>());
    while (m--){
        int u, v, w; cin >> u >> v >> w;
        adj[--u].emplace_back(--v, w);
    }

    vector<ll> dist(n, LLONG_MAX);
    vector<bool> done(n);
    dist[0] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.emplace(0, 0);
    while (!pq.empty()){
        auto u = pq.top().second; pq.pop();
        if (done[u]) continue;
        done[u] = true;
        
        for (auto [v, w] : adj[u]){
            if (dist[u]+w <= dist[v]){
                dist[v] = dist[u]+w;
                pq.emplace(dist[v], v);
            }
        }
    }
    
    for (ll v : dist) cout << v << ' ';
    cout << '\n';
}

