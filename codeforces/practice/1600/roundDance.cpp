#include <bits/stdc++.h>
using namespace std;

struct DSU {
	int* t;
	int cmps;

	DSU(int* t, int n) : t(t) {
		cmps = n-1;
		while (n--) t[n] = n;
	}
	
	int find(int v){
		if (v == t[v]) return v;
		return t[v] = find(t[v]);
	}

	bool merge(int u, int v){
		int up = find(u);
		int vp = find(v);
		t[up] = vp;
		if (up != vp) --cmps;
		return up == vp;
	}
};

int a[200001];
int t[200001];

void solve(){
	int n; cin >> n;

	DSU dsu(t, n+1);
	int dbl = 0;
	for (int i=1; i<=n; ++i){
		cin >> a[i];
		if (a[i] < i && a[a[i]] == i) ++dbl;
		dsu.merge(a[i], i);
	}

	cout << max(1, dsu.cmps - max(0, dbl-1)) << ' ' << dsu.cmps << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
