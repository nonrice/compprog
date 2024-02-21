#include <bits/stdc++.h>
using namespace std;

struct edge {
	int u, v;
	long long w;

	edge(int u, int v, long long w) : u(u), v(v), w(w) {}
};

vector<vector<pair<int, long long>>> adj;
long long d[100000], de[100000];

void SPFA(vector<vector<pair<int, long long>>>& adj, int n, int s, long long* d){
	fill(d+1, d+n+1, LLONG_MAX);
	d[s] = 0;
	queue<int> q({ s });
	vector<bool> in(n+1);
	in[s] = true;

	while (!q.empty()){
		int u = q.front();
		q.pop();
		in[u] = false;
		for (auto [v, w] : adj[u]){
			if (d[u] != LLONG_MAX && d[u] + w < d[v]){
				d[v] = d[u] + w;
				if (!in[v]){
					q.push(v);
					in[v] = true;
				}
			}
		}
	}
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

#ifndef LOCAL
	freopen("dining.in", "r", stdin);
	freopen("dining.out", "w", stdout);
#endif

	int n, m, k; cin >> n >> m >> k;
	adj.resize(2*n + 1);
	for (int i=0; i<m; ++i){
		int u, v, w; cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
		adj[u+n].emplace_back(v+n, w);
		adj[v+n].emplace_back(u+n, w);
	}
	for (int i=0; i<k; ++i){
		int u, w; cin >> u >> w;
		adj[u+n].emplace_back(u, -w);
	}

	SPFA(adj, 2*n, n, d);
	SPFA(adj, 2*n, 2*n, de);

	for (int i=1; i<=n-1; ++i) cout << (d[i] >= de[i]) << '\n';
}
