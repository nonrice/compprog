#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

vector<int> adj[100000];

bool vis1[100000], vis2[100000];

void dfs1(int u){
    for (auto v : adj[u]){
        if (!vis1[v]){
            vis1[v] = true;
            dfs1(v);
        }
    }
}

void dfs2(int u){
    for (auto v : adj[u]){
        if (!vis2[v]){
            vis2[v] = true;
            dfs2(v);
        }
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int n, m, a, b; cin >> n >> m >> a >> b;
    --a, --b;

    for (int i=0; i<m; ++i){
        int u, v; cin >> u >> v;
        --u, --v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vis1[b] = true;
    dfs1(a);
    vis2[a] = true;
    dfs2(b);

    long long s=0, t=0;
    for (int i=0; i<n; ++i){
        if (vis1[i] && !vis2[i]){
            ++s;
        }
        if (!vis1[i] && vis2[i]){
            ++t;
        }
    }

    cout << s*t << '\n';

}
    
    