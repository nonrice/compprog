#include <bits/stdc++.h>
using namespace std;

bool f[200001];
long long c[200001];
bool vis[200001];
vector<int> adj[200001];

long long dfs(int u){
	long long brew = 0;
	for (int v : adj[u]){
		if (!vis[v]) dfs(v);
		brew += c[v];
	}

	vis[u] = true;
	if (adj[u].size() == 0 && !f[u]) return c[u];
	return c[u] = min(c[u], brew);
}

void solve(){
	int n, k; cin >> n >> k;

	fill(adj, adj+n+1, vector<int>());
	fill(vis, vis+n+1, false);
	fill(f, f+n+1, false);

	for (int i=1; i<=n; ++i) cin >> c[i];
	for (int i=0; i<k; ++i){
		int p; cin >> p;
		vis[p] = true;
		f[p] = true;
		c[p] = 0;
	}

	for (int i=1; i<=n; ++i){
		int m; cin >> m;
		for (int j=0; j<m; ++j){
			int e; cin >> e;
			adj[i].push_back(e);
		}
	}
 
	for (int i=1; i<=n; ++i) cout << dfs(i) << ' ';
	cout << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
