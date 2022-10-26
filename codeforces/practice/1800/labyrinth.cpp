#include <bits/stdc++.h>
using namespace std;

int s;

bool dfs(int cur, int id, vector<int>& vis, vector<vector<int>>& adj, vector<int>& p1, vector<int>& p2, vector<int>& bp){
    //cout << cur << ' ';
    for (int v : adj[cur]){
        if (vis[v] == -1){
            vis[v] = id;
            bp[v] = cur;
            if (dfs(v, id, vis, adj, p1, p2, bp)){
                p1.push_back(cur);
                return true;
            }
        } else if (vis[v] != id && vis[v] != -2){
            p1.push_back(v);
            p1.push_back(cur);
            int u = v;
            while (u != -1){
                p2.push_back(u);
                u = bp[u];
            }
            return true;
        }
    }

    return false;
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    
    int n, m; cin >> n >> m >> s;
    --s;
    vector<vector<int>> adj(n, vector<int>());
    while (m--){
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v);
    }

    vector<int> vis(n, -1), bp(n, -1);
    vis[s] = -2;
    vector<int> p1, p2;
    for (size_t i=0; i<adj[s].size(); ++i){
        bp[s] = -1;
        if (vis[adj[s][i]] != -1){
            p1.push_back(adj[s][i]);
            int u = adj[s][i];
            while (u != -1){
                p2.push_back(u);
                u = bp[u];
            }
            goto found;
        }
        vis[adj[s][i]] = i;
        bp[adj[s][i]] = s;
        if (dfs(adj[s][i], i, vis, adj, p1, p2, bp)){
found: 
            p1.push_back(s);
            cout << "Possible\n" << p1.size() << '\n';
            for (int i=p1.size()-1; i>=0; --i) cout << p1[i]+1 << ' ';
            cout << '\n' << p2.size() << '\n';
            for (int i=p2.size()-1; i>=0; --i) cout << p2[i]+1 << ' ';
            cout << '\n';
            //goto debug;
            return 0;
        }
    }
    /*
debug:
    for (int v : bp) cout << v << ' ';
    cout << '\n';

    for (int v : vis) cout << v << ' ';
    cout << '\n';
    */
   
    cout << "Impossible\n";
}
