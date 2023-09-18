#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200001];

int d[200001];
int f[200001];
bool bad[200001];

void dfs1(int prev, int cur){
	for (auto v : adj[cur]){
		if (v != prev){
			d[v] = d[cur]+1;
			dfs1(cur, v);
		}
	}
}

void dfs2(int prev, int cur, int life){
	if (life > 0){
		for (auto v : adj[cur]){
			if (v != prev && !bad[v]){
				bad[v] = true;
				dfs2(cur, v, life-1);
			}
		}
	}
}

bool dfs3(int prev, int cur){
	if (adj[cur].size() == 1 && cur != 1) return true;

	for (auto v : adj[cur]){
		if (v != prev && !bad[v]){
			if (dfs3(cur, v)) return true;
		}
	}
	return false;
}

void solve(){
	int n, k; cin >> n >> k;

	for (int i=0; i<=n; ++i) adj[i].clear();
	memset(bad, false, n+1);

	for (int i=0; i<k; ++i) cin >> f[i];
	for (int i=0; i<n-1; ++i){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	d[1] = 0;
	dfs1(0, 1);

	for (int i=0; i<k; ++i){
		bad[f[i]] = true;
		dfs2(0, f[i], d[f[i]]/2);
	}

	if (dfs3(0, 1)){
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
