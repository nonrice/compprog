#include <bits/stdc++.h>
using namespace std;

struct vert {
	int p;
	vector<int> c;
}

vert adj[1001], adj_f[1001];

void set_parent(int u, int p){
	adj[u].p = p;
	for (int v : adj[u].c){
		if (v != p){
			set_parent(v, u);
		}
	}
}

void set_parent_f(int u, int p){
	adj_f[u].p = p;
	for (int v : adj_f[u].c){
		if (v != p){
			set_parent_f(v, u);
		}
	}
}

void combine(int u, int v){
	if (v > u){
		swap(u, v);
	}
	for (int w : adj[v].c){
		if (w != adj[v].p){
			adj[w].p = u;
			adj[u].c.push_back(w);
		}
	}
	adj[v].c.clear();
}

vector<pair<int, int>> ans;
void dfs(int u){
	for (int v : adj[u].c){
		if (v != adj[u].p){
			for (int w : adj[v].c){
				if (w != u){
						
				}
			}
		}
	}
}

void solve(){
	int n; cin >> n;
	for (int i=0; i<n-1; ++i){
		int u, v; cin >> u >> v;
		adj[u].c.push_back(v);
		adj[v].c.push_back(u);
	}
	int m; cin >> m;
	for (int i=0; i<m-1; ++i){
		int u, v; cin >> u >> v;
		adj_f[u].c.push_back(v);
		adj_f[v].c.push_back(u);
	}
	
	ans.clear();
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
