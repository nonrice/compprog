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

map<int, vector<pair<int, int>>, greater<int>> e;

struct query {
	int k, v, i;

	bool operator<(const query& o) const {
		return k > o.k;
	}
};
query qs[100000];
int ans[100000];

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
#ifndef LOCAL
	freopen("mootube.in", "r", stdin);
	freopen("mootube.out", "w", stdout);
#endif

	int n, q; cin >> n >> q;
	for (int i=0; i<n-1; ++i){
		int u, v, w; cin >> u >> v >> w;
		e[w].emplace_back(u, v);
	}
	for (int i=0; i<q; ++i){
		cin >> qs[i].k >> qs[i].v;
		qs[i].i = i;
	}

	sort(qs, qs+q);
	DSU t(n);
	auto it = e.begin();
	for (int i=0; i<q; ++i){
		while (it != e.end() && it->first >= qs[i].k){
			for (auto [x, y] : it->second){
				t.merge(x, y);
			}
			++it;
		}
		ans[qs[i].i] = t.sz[t.find(qs[i].v)]-1;
	}

	for (int i=0; i<q; ++i){
		cout << ans[i] << '\n';
	}
}


