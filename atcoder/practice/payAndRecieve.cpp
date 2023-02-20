#include <bits/stdc++.h>
using namespace std;

map<int, vector<pair<int, int>>> adj;
int r[100000];
long long p[100000];
bool bad[100000];
bool vis[100000];

void dfs(int u){
	for (auto [v, w] : adj[u]){
		if (!vis[v]){
			r[v] = r[u];
			p[v] = p[u] + w;
			vis[v] = true;
		} else {

		}
	}
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	int n, m, q; cin >> n >> m >> q;
	for (int i=0; i<m; ++i){
		int a, b, c; cin >> a >> b >> c;
		adj[--a].push_back({--b, c});
		adj[b].push_back({a, -c});
	}

	while (q--){
		int a, b; cin >> a >> b;

		if (r[--a] != r[--b]){
			cout << "nan\n";
		} else if (bad[a]){
			cout << "inf\n";
		} else {

		}
	}
}
