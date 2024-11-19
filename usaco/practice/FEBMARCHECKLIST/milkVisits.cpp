#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100000];

constexpr int B = 16;
int p2[100000], p1[100000];
int s1[100000];
int d[100000];
int s2[100000][B+1];

void dfs(int u, int p){
	for (int v : adj[u]){
		if (v != p){
			d[v] = d[u]+1;
			p1[v] = p2[v] = u;
			dfs(v, u);
		}
	}
}

inline bool cont(int u, int c){
	for (int i=0; i<=B; ++i){
		if (s2[u][i] == c){
			return true;
		}
	}
	return false;
}

bool query(int u, int v, int c){
	if (u == v){
		return s1[u] == c;
	}
	while (d[u] != d[v] && d[p2[v]] >= d[u]){
		if (cont(v, c)){
			return true;
		}
		v = p2[v];
	}
	while (d[u] != d[v]){
		if (s1[v] == c){
			return true;
		}
		v = p1[v];
	}
	while (u != v && p2[v] != p2[u]){
		if (cont(v, c) || cont(u, c)){
			return true;
		}
		u = p2[u];
		v = p2[v];
	}
	while (u != v){
		if (s1[v]==c || s1[u]==c){
			return true;
		}
		u = p1[u];
		v = p1[v];
	}
	return s1[v]==c;
}

char ans[100001];

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
#ifndef LOCAL
	freopen("milkvisits.in", "r", stdin);
	freopen("milkvisits.out", "w", stdout);
#endif

	int n, q; cin >> n >> q;
	for (int i=0; i<n; ++i){
		cin >> s1[i];
		s2[i][0] = s1[i];
	}
	for (int i=0; i<n-1; ++i){
		int u, v; cin >> u >> v; --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(0, 0);
	for (int k=1; k<=B; ++k){
		for (int i=0; i<n; ++i){
			s2[i][k] = s1[p2[i]];
			p2[i] = p1[p2[i]];
		}
	}

	for (int i=0; i<q; ++i){
		int u, v, c; cin >> u >> v >> c; --u, --v;
		if (d[u] > d[v]){
			swap(u, v);
		}
		ans[i] = '0' + query(u, v, c);
	}
	cout << ans << '\n';
}
