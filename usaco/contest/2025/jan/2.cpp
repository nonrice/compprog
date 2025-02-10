#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> t;
    vector<int> sz;
    vector<int> d;

    DSU(int n){
        t = vector<int>(n+1);
        sz = vector<int>(n+1, 1);
        d = vector<int>(n+1, 0);
        iota(t.begin(), t.end(), 0);
    }

    int find(int u){
        if (u == t[u]) return u;
        return t[u] = find(t[u]);
    }

    bool merge(int u, int v){
        int pu = find(u);
        int pv = find(v);
        if (pu != pv){
            if (sz[pu] < sz[pv]){
                swap(pu, pv);
            }
            t[pv] = pu;
            d[pu] += d[pv];
            sz[pu] += sz[pv];
        }
        return pu == pv;
    }
};

inline long long c2(long long s){
    return s*(s-1)/2;
}

int main(){
    int n, m; cin >> n >> m;
    string s; cin >> s; 

    vector<vector<int>> adj(n);
    for (int i=0; i<m; ++i){
        int u, v; cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }   

    vector<long long> ans(n);
    DSU g(n);
    long long y = 0;

    for (int u=0; u<n; ++u){
        if (s[u] == '1'){
            ++g.d[g.find(u)];

            for (auto v : adj[u]){
                if (s[v] == '1'){
                    g.merge(u, v);
                }
            }
        }
    }

    for (int u=n-1; u>=0; --u){

        if (s[u] == '1'){
            int pu = g.find(u);
            y -= c2(g.sz[pu]-g.d[pu]);
            --g.d[pu];
            y += c2(g.sz[pu]-g.d[pu]);
        }

        for (auto v : adj[u]){
            int pu = g.find(u);
            int pv = g.find(v);
            if (pu != pv && (v>u || s[v]=='1')){
                y -= c2(g.sz[pu]-g.d[pu]) + c2(g.sz[pv]-g.d[pv]);
                y += c2(g.sz[pu]+g.sz[pv]-g.d[pu]-g.d[pv]);
                g.merge(u, v);
            }
        }

        ans[u] = y;

    }

    for (int i=0; i<n; ++i){
        cout << ans[i] << '\n';
    }
}