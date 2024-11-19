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

struct edge {
	int u, v;
}

char s[100001];
edge e[100000];

void solve(){
	int n; cin >> n;
	for (int i=0; i<n-1; ++i){
		cin >> e[i].u >> e[i].v;
	}
	cin >> s;

	DSU g(n);

	for (int i=0; i<n-1; ++i){
		if (e[i].u == 'C' || e[i].v == 'C'){

		}
	}
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		solve();
	}
}

