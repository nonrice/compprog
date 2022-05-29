#include <bits/stdc++.h>
using namespace std;

void dfs(int parent, int cur, vector<vector<int>>& adj, vector<int>& colors){
    int color = 0;
    for (int v : adj[cur]) if (!colors[v]){
        ++color;
        color += color==colors[cur] || color==colors[parent];
        color += color==colors[cur] || color==colors[parent];
        colors[v] = color;
        dfs(cur, v, adj, colors);
    }
}

int main(){
    int n; cin >> n;
    vector<vector<int>> adj(n);
    vector<int> colors(n);
    while (--n){
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }
    
    colors[0] = 1;
    dfs(0, 0, adj, colors);
    
    cout << *max_element(colors.begin(), colors.end()) << '\n';
    for (int v : colors) cout << v << ' ';
    cout << '\n';
}

