#include <bits/stdc++.h>
using namespace std;

int a[200001];

vector<int> adj[200001];
struct DSU {
	vector<int> t;

	DSU(int n){
		t = vector<int>(n+1);
		iota(t.begin(), t.end(), 0);
	}

	int find(int u){
		if (u == t[u]) return u;
		return t[u] = find(t[u]);
	}

	bool merge(int u, int v){
		int pu = find(u);
		int pv = find(v);
		t[pu] = pv;
		return pu == pv;
	}
};
vector<pair<int, int>> e;

map<int, int> dp;
int dfs(int u){
	if (dp.count(u)){
		return dp[u];
	}
	int ans = INT_MIN;
	for (auto v : adj[u]){
		ans = max(ans, dfs(v));
	}
	return dp[u]=ans+1;
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	
	int n, m; cin >> n >> m;
	for (int i=1; i<=n; ++i){
		cin >> a[i];
	}

	DSU dsu(n);
	for (int i=0; i<m; ++i){
		int u, v; cin >> u >> v;
		if (a[u] == a[v]){
			dsu.merge(u, v);
		} else {
			e.emplace_back(u, v);
		}
	}
	for (auto [u, v] : e){
		int pu = dsu.find(u);
		int pv = dsu.find(v);
		if (pu != pv){
			if (a[pv] < a[pu]){
				swap(pv, pu);
			}
			adj[pu].push_back(pv);
		}
	}

	dp[dsu.find(n)] = 1;
	cout << max(0, dfs(dsu.find(1))) << '\n';
}
