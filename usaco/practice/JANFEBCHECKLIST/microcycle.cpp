#include <bits/stdc++.h>
using namespace std;

struct DSU {
	vector<int> t;
	vector<int> sz;

	DSU(int n){
		t = vector<int>(n+1);
		sz = vector<int>(n+1, 1);
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
			sz[pu] += sz[pv];
		}
		return pu == pv;
	}
};

struct edge {
	int u, v, w;

	bool operator<(const edge& o) const {
		return w > o.w;
	}
};
edge e[200000];

vector<int> adj[200000];
bool vis[200000];
int x, y, w;
vector<int> ans;
bool dfs(int u){
	if (u == y){
		return true;
	}
	vis[u] = true;
	for (int v : adj[u]){
		if (!vis[v]){
			if (dfs(v)){
				ans.push_back(v+1);
				return true;
			}
		}
	}
	return false;
}

void solve(){
	int n, m; cin >> n >> m;
	for (int i=0; i<m; ++i){
		cin >> e[i].u >> e[i].v >> e[i].w;
		--e[i].u, --e[i].v;
	}

	sort(e, e+m);
	DSU dsu(n);
	for (int i=0; i<m; ++i){
		if (dsu.merge(e[i].u, e[i].v)){
			x = e[i].u;
			y = e[i].v;
			w = e[i].w;
		}
	}
	
	for (int i=0; i<n; ++i){
		adj[i].clear();
	}
	fill(vis, vis+n, false);
	for (int i=0; i<m; ++i){
		adj[e[i].u].push_back(e[i].v);
		adj[e[i].v].push_back(e[i].u);
	}
	ans.clear();
	ans.push_back(x+1);
	dfs(x);
	cout << w << ' ' << ans.size() << '\n';
	for (int u : ans){
		cout << u << ' ';
	}
	cout << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
