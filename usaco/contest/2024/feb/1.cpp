#include <bits/stdc++.h>
using namespace std;

struct path {
	int u, s;
	long long w;

	path(int u, int s, long long w) : u(u), s(s), w(w) {}

	bool operator<(const path& o) const {
		return w>o.w;
	}
};

struct edge {
	int v;
	long long w;

	edge(int v, long long w) : v(v), w(w) {}
};

int k;
struct sp {
	int nxt = 0;
	set<int> s;
	long long d[10] = {};

	sp(){
		fill(d, d+10, LLONG_MAX);
	}

	bool vis(int st){
		return !(nxt == k || s.count(st);
	}

	void arrive(int st, long long w){
		d[nxt++] = w;
		s.insert(st);
	}

	long long dist(){
		return d[nxt];
	}
};

vector<edge> adj[50001];
sp d[50001];

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	int n, m, c; long long r; cin >> n >> m >> c >> r >> k;
	for (int i=0; i<m; ++i){
		int u, v; long long w; cin >> u >> v >> w;
		--u, --v;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}

	for (int i=0; i<c; ++i){
		adj[n].emplace_back(i, 0);
	}
	priority_queue<path> pq;
	pq.push({ n, -1, 0LL });
	while (!pq.empty()){
		auto [u, s, w] = pq.top();
		pq.pop();

		for (auto [v, w] : adj[u]){
			if (s == -1 && v < c){
				s = v;
			}
			
			if (auto [v, dw] : adj[u]){
				if (d[u].dist()+w < )
			}
		}
	}
}
