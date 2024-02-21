#include <bits/stdc++.h>
using namespace std;

constexpr long long M = 998244353;

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

int l[1001], r[1001];
bool d[1001];

void solve(){
	int n; cin >> n;
	fill(l, l+n+1, -1);
	for (int i=0; i<2*n; ++i){
		int x; cin >> x;
		if (l[x] == -1){
			l[x] = i;
		} else {
			r[x] = i;
		}
	}

	DSU dsu(n);
	// Crush bidirectional edges
	for (int i=1; i<=n; ++i){
		for (int j=i+1; j<=n; ++j){
			int u=i, v=j;
			if (r[u] > r[v]){
				swap(u, v);
			}
			if (l[u]<l[v] && r[u]>l[v]){
				dsu.merge(u, v);
			}
		}
	}
	
	fill(d, d+n+1, false);
	// If v leads into u, u is not a root anymore
	// Unless, v leads a bidirectional edge into u, so if v was previously crushed into u we disregard it.
	for (int i=1; i<=n; ++i){
		for (int j=1; j<=n; ++j) if (j != i) {
			int u=i, v=j;
			if (r[u] > r[v]){
				swap(u, v);
			}
			if (l[u]>l[v] && r[u]<r[v] && u != v && dsu.find(v) != dsu.find(u)){
				d[dsu.find(u)] = true;
			}
		}
	}

	// For each crushed vertex that is root we choose one of the members
	// It generalizes to uncrushed vertices too
	long long ans = 0, ways = 1;
	for (int i=1; i<=n; ++i){
		if (dsu.find(i) == i && !d[i]){
			++ans;
			ways = ways*2%M * dsu.sz[i]%M;
		}
	}
	cout << ans << ' ' << ways << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
