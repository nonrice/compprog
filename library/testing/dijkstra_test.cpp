// https://cses.fi/problemset/task/1671

#include <bits/stdc++.h>
using namespace std;

template<typename T, typename U>
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

int main(){
    int n, m; cin >> n >> m;
    
    map<int, vector<pair<int, long long>>> adj;
    for (int i=0; i<m; ++i){
        int u, v, w; cin >> u >> v >> w;
        --u, --v;
        adj[u].emplace_back(v, w);
    }

    auto [d, p] = dijkstra<int, long long>(adj, 0);
    assert(d.size() == n);
    for (auto [u, w] : d){
        cout << w << ' ' ;
    }
    cout << '\n';
}