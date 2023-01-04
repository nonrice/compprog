#include <bits/stdc++.h>
using namespace std;

// idea
// Bipartiteness is when a graph has no odd cycles
// First, check bipartiteness of graph, if not bipartite then the answer is 0- connecting edges can't get rid of cycles
//
// It is always possible to connect vertices between two disjoint components for the same reason, because such action cannot create cycles,
// This part can be found with simple combinatorics
//
// When connecting (u, v) from the same component, the path between them must be even length, so the created cycle has even length.
// To calculate this, first color the component bipartitely. Because path must be of even length, they must start and end on different colors
// Again, the number of such paths can be found with simple combinatorics. Note that this approach will count single edges which is not favorable.
// Fortunately, single edges can be removed by simply subtracting m from the final answer.
//

using ll = long long;

vector<vector<int>> adj;
short c[200000]; // 0=unvisited, -1=black, 1=white
ll b, w;

bool dfs(int u){
    if (c[u] == -1) ++b;
    else ++w;

    for (auto v : adj[u]){
        if (c[v]){
            if (c[u]+c[v] != 0) return false;
        } else {
            c[v] = -1*c[u];
            if (!dfs(v)) return false;
        }
    }

    return true;
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    adj.resize(n);
    for (int i=0; i<m; ++i){
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }

    ll p = 0;
    ll ans = 0;
    for (int i=0; i<n; ++i){
        if (!c[i]){
            b = w = 0;
            c[i] = -1;
            if (!dfs(i)){
                cout << "0\n";
                return 0;
            } else {
                ans += (b+w)*p + b*w;
                p += b+w;
            }
        }
    }
    ans -= m;

    cout << ans << '\n';
}

