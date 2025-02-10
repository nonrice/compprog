template<typename T, typename U>
// compute shortest path distances and path trees from source s 
pair<map<T, U>, map<T, T>> dijkstra(map<T, vector<pair<T, U>>>& adj, T s){
    map<T, U> d;
    map<T, T> p;
    map<T, bool> vis;
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
