#include <bits/stdc++.h>
using namespace std;

// SPFA
// SPFA: Given graph adj and source s, computes shortest paths from s to all n nodes into d in O(|E||V|) and O(|E|) on a random graph.

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

long long dist[100001];

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;
	vector<vector<pair<int, long long>>> adj(n+1);
	for (int i=0; i<m; ++i){
		int u, v, w; cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	int s, f; cin >> s >> f;

	SPFA(adj, n, s, dist);

	if (dist[f] != LLONG_MAX){
		cout << dist[f] << '\n';
	} else {
		cout << "-1\n";
	}
}
