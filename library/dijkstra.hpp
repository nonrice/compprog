template<typename T, typename U>
// compute shortest path distances and path trees from source s 
pair<vector<U>, vector<U>> dijkstra(vector<vector<pair<T, U>>>& adj, T s, T n){
    vector<U> d(n+1);
    vector<T> p(n+1);
    vector<bool> vis(n+1);
    priority_queue<pair<U, T>, vector<pair<U, T>>, greater<pair<U, T>>> q;
    d[s] = U{};
    q.emplace(U{}, s);
    while (!q.empty()){
        T u = q.top().second; q.pop();
        if (vis[u]){
            continue;
        }
        vis[u] = true;
        for (auto [v, w] : adj[u]){
            if (!vis[v]){
                if (!d.count(v)){
                    d[v] = numeric_limits<U>::max();
                }
                if (d[u]+w <= d[v]){
                    d[v] = d[u]+w;
                    p[v] = u;
                    q.emplace(d[v], v);
                }
            }
        }
    }
    return make_pair(d, p);
}
