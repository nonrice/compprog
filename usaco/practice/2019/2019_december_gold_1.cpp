#include <bits/stdc++.h>
using namespace std;

struct edge {
	int v, c, f;

	edge(int v, int c, int f) : v(v), c(c), f(f) {}
};

int n;
vector<edge> adj[1001];

int SPFA(int min_f){
	vector<int> d(n+1, INT_MAX);
	d[1] = 0;
	queue<int> q({ 1 });
	vector<bool> in(n+1);
	in[1] = true;

	while (!q.empty()){
		int u = q.front();
		q.pop();
		in[u] = false;
		for (auto [v, c, f] : adj[u]) if (f >= min_f) {
			if (d[u] != INT_MAX && d[u] + c < d[v]){
				d[v] = d[u] + c;
				if (!in[v]){
					q.push(v);
					in[v] = true;
				}
			}
		}
	}

	return d[n];
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

#ifndef LOCAL
	freopen("pump.in", "r", stdin);
	freopen("pump.out", "w", stdout);
#endif

	int m; cin >> n >> m;
	for (int i=0; i<m; ++i){
		int u, v, c, f; cin >> u >> v >> c >> f;
		adj[u].emplace_back(v, c, f);
		adj[v].emplace_back(u, c, f);
	}

	int of=0, oc=1;
	for (int f=1; f<=1000; ++f){
		int c = SPFA(f);
		if (c != INT_MAX && f*oc > of*c){
			of = f;
			oc = c;
		}
	}

	cout << 1000000LL*of/oc << '\n';
}
