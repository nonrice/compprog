#include <bits/stdc++.h>
using namespace std;

struct DSU {
	vector<int> t;
	vector<int> sz;
	int max_sz = 0;

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
			max_sz = max(sz[pu], max_sz);
		}
		return pu == pv;
	}
};

set<int> adj[100000];

struct cow {
	int u;

	bool operator<(const cow o) const {
		if (adj[u].size() != adj[o.u].size()){
			return adj[u].size() < adj[o.u].size();
		}
		return u>o.u;
	}
};
set<cow> q;

struct event {
	int t, u, v;
};
vector<event> e;

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;
	for (int i=0; i<m; ++i){
		int u, v; cin >> u >> v; --u, --v;
		adj[u].insert(v);
		adj[v].insert(u);
	}

	for (int i=0; i<n; ++i){
		q.insert({ i });
	}
	while (!q.empty()){
		int u = q.begin()->u;
		e.push_back({ 2, (int)adj[u].size(), -1 });
		q.erase(q.begin());
		for (int v : adj[u]){
			q.erase({ v });
			adj[v].erase(u);
			e.push_back({ 1, u, v });
			q.insert({ v });
		}
	}
	reverse(e.begin(), e.end());
	DSU g(n);
	int ans = 0;
	for (auto [t, u, v] : e){
		if (t == 1){
			g.merge(u, v);
		} else {
			ans = max(ans, u*g.max_sz);
		}
	}

	cout << ans << '\n';
}
