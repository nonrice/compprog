#include <bits/stdc++.h>
using namespace std;

int edge[51][51];
int ans[2525];

void solve(){
	int n, m; cin >> n >> m;

	vector<vector<int>> adj(n, vector<int>());
	for (int i=0; i<m; ++i){
		int u, v; cin >> u >> v;
		adj[--u].push_back(--v);
		adj[v].push_back(u);
		edge[u][v] = edge[v][u] = i;
	}

	int dv=-1;

again:
	for (int i=0; i<n; ++i){
		if (adj[i].size() != n-1){
			//cout << adj[i].size() << '\n';
			memset(ans, 0, m*sizeof(int));
			for (auto v : adj[i]){
				ans[edge[v][i]] = 1;
			}
			if (dv != -1){
				ans[edge[0][dv]] = 2;
				cout << "3\n";
			} else {
				cout << "2\n";
			}
			for (int i=0; i<m; ++i) cout << ans[i]+1 << ' ';
			cout << '\n';
			return;
		}
	}

	dv = adj[0].back();
	adj[0].pop_back();

	goto again;
	
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
