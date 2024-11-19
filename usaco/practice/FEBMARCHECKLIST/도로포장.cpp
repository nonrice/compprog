#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj[10000];

struct path {
	int u;
	long long w;
	int j;
	
	bool operator<(const path& o) const {
		return w > o.w;
	}

	path(int u, long long w, int j) : u(u), w(w), j(j) {}
};
priority_queue<path> q;
long long d[10000][21];
bool vis[10000][21];

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	
	int n, m, k; cin >> n >> m >> k;
	for (int i=0; i<m; ++i){
		int u, v, w; cin >> u >> v >> w;
		--u, --v;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}

	for (int i=0; i<n; ++i){
		fill(d[i], d[i]+k+1, LLONG_MAX);
	}
	d[0][0] = 0;
	q.emplace(0, 0, 0);
	while (!q.empty()){
		auto [u, w, j] = q.top();
		q.pop();
		if (vis[u][j]){
			continue;
		}
		vis[u][j] = true;
		for (auto [v, w] : adj[u]){
			if (d[u][j] + w < d[v][j]){
				d[v][j] = d[u][j]+w;
				q.emplace(v, d[v][j], j);
			}
		}
		if (j<k){
			for (auto [v, w] : adj[u]){
				if (d[u][j] < d[v][j+1]){
					d[v][j+1] = d[u][j];
					q.emplace(v, d[v][j+1], j+1);
				}
			}
		}
	}

	cout << *min_element(d[n-1], d[n-1]+k+1) << '\n';
}
