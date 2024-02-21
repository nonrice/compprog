#include <bits/stdc++.h>
using namespace std;

struct edge {
	int v;
	int l;

	edge(int v, int l) : v(v), l(l) {}

	bool operator<(const edge& o) const {
		return l < o.l;
	}
};

vector<vector<edge>> adj;

long long s[200001], d[200001];
long long p[200001];


bool cmp(int a, int b){
	if (p[a]==-1 && p[b]!=-1) return true;
	if (p[a]!=-1 && p[b]==-1) return false;
	if (p[a]==-1 || p[b]==-1) return false;
	return adj[a][p[a]].l < adj[b][p[b]].l;
}

void dfs(int u){
	if (adj[u].size() == 0){
		d[u] = 0;
	}

	if (d[u] != -1){
		return;
	}

	for (int i=0; i<adj[u].size(); ++i){
		auto [v, l] = adj[u][i];
		dfs(v);
		if (d[v]+1 >= d[u]){
			bool better = d[v]+1 > d[u]; 
			if (p[u] != -1 && !better){
				if (l < adj[u][p[u]].l){
					better = true;
				} else if (l == adj[u][p[u]].l){
					better = cmp(v, adj[u][p[u]].v);
				}
			}
			if (better){
				d[u] = d[v]+1;
				s[u] = s[v]+l;
				p[u] = i;
			}
		}
	}
	//cout << p[u] << '\n';
}


int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;
	adj.resize(n+1);
	for (int i=0; i<m; ++i){
		int u, v, l; cin >> u >> v >> l;
		adj[u].emplace_back(v, l);
	}
	for (int i=1; i<=n; ++i) sort(adj[i].begin(), adj[i].end());

	fill(d+1, d+1+n, -1);
	fill(p+1, p+1+n, -1);

	for (int i=1; i<=n; ++i){
		dfs(i);
	}

	for (int i=1; i<=n; ++i){
		cout << d[i] << ' ' << s[i] << '\n';
	}
}
