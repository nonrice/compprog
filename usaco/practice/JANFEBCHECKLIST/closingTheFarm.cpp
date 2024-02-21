#include <bits/stdc++.h>
using namespace std;

// DSU
// DSU: Construct DSU structure with path compression and union by size for graph of n vertices.
// find: Get the representative node for node u in O(alpha(n))
// merge: Merge the components of node u and v in O(alpha(n))

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

bool ans[200000];

vector<int> adj[200000];
int u[200000];
bool p[200001];

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
#ifndef LOCAL
	freopen("closing.in", "r", stdin);
	freopen("closing.out", "w", stdout);
#endif
	
	int n, m; cin >> n >> m;
	for (int i=0; i<m; ++i){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i=0; i<n; ++i){
		cin >> u[i];
	}
	
	DSU dsu(n);
	for (int i=n-1; i>=0; --i){
		p[u[i]] = true;
		for (auto v : adj[u[i]]) if (p[v]){
			if (!dsu.merge(u[i], v)){
				p[v] = true;
			}
		}
		ans[i] = (dsu.sz[dsu.find(u[i])] == n-i);
	}

	for (int i=0; i<n; ++i){
		if (ans[i]){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}
