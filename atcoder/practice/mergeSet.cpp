#include <bits/stdc++.h>
using namespace std;

set<int> adj[400001];
bool vis[400001];

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	
	int n, m; cin >> n >> m;
	for (int i=0; i<n; ++i){
		int ai; cin >> ai;
		for (int j=0; j<ai; ++j){
			int u; cin >> u;
			adj[u].insert(m+i+1);
			adj[m+i+1].insert(u);
		}
	}

	queue<pair<int, int>> bfs({{ 0, 1 }});
	vis[1] = true;
	while (!bfs.empty()){
		auto [d, u] = bfs.front(); bfs.pop();
		if (u == m){
			cout << d/2-1 << '\n';
			return 0;
		}
		for (auto v : adj[u]){
			if (!vis[v]){
				bfs.emplace(d+1, v);
				vis[v] = true;
			}
		}
	}

	cout << "-1\n";
}
