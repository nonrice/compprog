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

