#include <bits/stdc++.h>
using namespace std;

int c[100001], s[100001], f[100001];

void solve(){
	int n, m; cin >> n >> m;
	for (int i=1; i<=n; ++i) cin >> c[i];
	for (int i=1; i<=n; ++i) cin >> s[i];
	for (int i=1; i<=n; ++i) cin >> f[i];

	vector<vector<int>> adj(n+1, vector<int>());
	for (int i=0; i<m; ++i){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	map<int, int> sf, ff;
	map<int, queue<int>> a, b;
	vector<bool> in(n+1);

	a[0].push(1);
	in[1] = true;

	while (!a.empty()){
		if (a.begin()->second.empty()){
			a.erase(a.begin());
			continue;
		}

		int u = a.begin()->second.front();
		a.begin()->second.pop();
		
		++sf[s[u]];
		++ff[f[u]];
		if (b.count(s[u])){
			auto q = b.extract(s[u]);
			a.insert(move(q));
		}

		for (auto v : adj[u]) if (!in[v]){
			in[v] = true;
			if (sf.count(c[v])){
				a[c[v]].push(v);
			} else {
				b[c[v]].push(v);
			}
		}
	}

	for (auto [k, v] : ff){
		cout << k << ' ' << v << ' ' << sf[k] << '\n';
		if (v > sf[k]){
			cout << "NO\n";
			return;
		}
	}
	for (int i=1; i<=n; ++i){
		if (!in[i] && s[i]!=f[i]){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
