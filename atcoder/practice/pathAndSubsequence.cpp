#include <bits/stdc++.h>
using namespace std;
 
vector<int> adj[100000];
int a[100000], b[100001];
 
bool done[100000];
int dist[100000];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
 
int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    
    int n, m, k; cin >> n >> m >> k;
    for (int i=0; i<m; ++i){
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }
    for (int i=0; i<n; ++i) cin >> a[i];
    for (int i=0; i<k; ++i) cin >> b[i];
    
    fill(dist+1, dist+n, INT_MAX);
    pq.emplace(a[0]==b[0], 0);
    dist[0] = a[0] == b[0];
    while (!pq.empty()){
        int u = pq.top().second; pq.pop();
        
        if (!done[u]){
            done[u] = true;
            
            for (int v : adj[u]){
                bool w = b[(dist[u]==INT_MAX) ? 0 : dist[u]] == a[v];
                if (dist[u] + w <= dist[v]){
                    dist[v] = dist[u]+w;
                    pq.emplace(dist[v], v);
                }
            }
        }
    }
    
    if (dist[n-1] == k) cout << "Yes\n";
    else cout << "No\n";
}
