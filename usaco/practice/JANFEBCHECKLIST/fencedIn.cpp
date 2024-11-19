#include <bits/stdc++.h>
using namespace std;

int a[2002], b[2002];

pair<int, int> d[4] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

struct edge {
	int u, v, w;

	bool operator<(const edge& o) const {
		return w < o.w;
	}
};

edge e[2001*2001*4];

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
		if (sz[pu] < sz[pv]){
			swap(pu, pv);
		}
		t[pv] = pu;
		sz[pu] += sz[pv];
		return pu == pv;
	}
};

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
#ifndef LOCAL
	freopen("fencedin.in", "r", stdin);
	freopen("fencedin.out", "w", stdout);
#endif

	long long A, B; cin >> A >> B;
	int n, m; cin >> n >> m;
	for (int i=1; i<=n; ++i){
		cin >> a[i];
	}
	a[n+1] = A;
	sort(a, a+n+2);
	for (int i=1; i<=m; ++i){
		cin >> b[i];
	}
	b[m+1] = B;
	sort(b, b+m+2);

	int t = 0;
	for (int i=0; i<=n; ++i){
		for (int j=0; j<=m; ++j){
			for (auto [di, dj] : d){
				if (i+di>=0 && i+di<=n && j+dj>=0 && j+dj<=m){
					e[t].u = i*(m+1)+j;
					e[t].v = (i+di)*(m+1)+(j+dj);
					if (di == 0){
						e[t].w = a[i + 1] - a[i];
					} else {
						e[t].w = b[j + 1] - b[j];
					}
					++t;
				}
			}
		}
	}

	sort(e, e+t);
	DSU mst((n+1)*(m+1));
	long long ans = 0;
	int k = (n+1)*(m+1);
	for (auto [u, v, w] : e){
		if (!mst.merge(u, v)){
			ans += w;
			--k;
			if (k == 1){
				break;
			}
		}
	}

	cout << ans << '\n';
}
