#pragma GCC optimize("Ofast,unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

struct vert {
    int u1, u2; 

    vert() {}

    vert(int u1, int u2) : u1(u1), u2(u2) {}

    bool operator<(const vert& o) const {
        if (u1 != o.u1){
            return u1 < o.u1;
        }
        return u2 < o.u2;
    }
};

void print(vert v){
    cerr << "(" << v.u1 <<  ' '<< v.u2  << ") ";
}

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

void solve(){
    int n, s1, s2; cin >> n >> s1 >> s2;

    int m1; cin >> m1;
    vector<pair<int, int>> e1(m1);
    for (int i=0; i<m1; ++i){
        cin >> e1[i].first >> e1[i].second;
    }
    int m2; cin >> m2;
    vector<pair<int, int>> e2(m2);
    for (int i=0; i<m2; ++i){
        cin >> e2[i].first >> e2[i].second;
    }

    map<vert, vector<pair<vert, long long>>> adj;
    for (int i=0; i<m1; ++i){
        for (int j=0; j<m2; ++j){
            adj[vert(e1[i].first, e2[j].first)].emplace_back(vert(e1[i].second, e2[j].second), abs(e1[i].second - e2[j].second));
            adj[vert(e1[i].second, e2[j].first)].emplace_back(vert(e1[i].first, e2[j].second), abs(e1[i].first - e2[j].second));
            adj[vert(e1[i].first, e2[j].second)].emplace_back(vert(e1[i].second, e2[j].first), abs(e1[i].second - e2[j].first));
            adj[vert(e1[i].second, e2[j].second)].emplace_back(vert(e1[i].first, e2[j].first), abs(e1[i].first - e2[j].first));
        }
    }

    auto [dist, prev] = dijkstra(adj, vert(s1, s2));

    debug(dist);
    long long ans = LLONG_MAX;
    for (int i=0; i<m1; ++i){
        for (int j=0; j<m2; ++j){
            auto [a, b] = e1[i];
            auto [c, d] = e2[j];
            if (a > b){
                swap(a, b);
            }
            if (c > d){
                swap(c, d);
            }
            if (a == c && b == d){
                if (dist.count(vert(a, c))){
                    ans = min(ans, dist[vert(a, c)]);
                }
                if (dist.count(vert(b, d))){
                    ans = min(ans, dist[vert(b, d)]);
                }
                debug(ans);
            }
        }
    }

    if (ans == LLONG_MAX){
        cout << "-1\n";
        return;
    } 
    cout << ans << '\n';

}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}