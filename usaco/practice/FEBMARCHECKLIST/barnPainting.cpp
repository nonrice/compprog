#include <bits/stdc++.h>
using namespace std;

constexpr long long M = 1000000007;

vector<int> adj[100000];
map<pair<int, int>, long long> mem;

long long dfs(int u, int p, int c){
	if (mem.count({ u, c })){
		return mem[{ u, c }];
	}
	long long ans = 1;
	for (int v : adj[u]){
		if (v != p){
			ans = ans * ((dfs(v, u, (c+1)%3) + dfs(v, u, (c+2)%3))%M) % M;
		}
	}
	return mem[{ u, c }] = ans;
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
#ifndef LOCAL
	freopen("barnpainting.in", "r", stdin);
	freopen("barnpainting.out", "w", stdout);
#endif

	int n, k; cin >> n >> k;
	for (int i=0; i<n-1; ++i){
		int u, v; cin >> u >> v; --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i=0; i<k; ++i){
		int u, c; cin >> u >> c; --u, --c;
		mem[{ u, (c+1)%3 }] = 0;
		mem[{ u, (c+2)%3 }] = 0;
	}

	cout << ((dfs(0, -1, 0)+dfs(0, -1, 1))%M+dfs(0, -1, 2))%M << '\n';
}
