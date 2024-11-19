#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> adj[100001];

int x, r;
int dfs(int u, int p){
	int s = 1;
	for (int v : adj[u]){
		if (v != p){
			s += dfs(v, u);
		}
	}
	if (s >= x && r >= 1){
		--r;
		return 0;
	}
	return s;
}

bool check(int x){
	::x = x;
	r = k;
	return dfs(1, -1)>=x && r == 0;
}

void solve(){
	cin >> n >> k;
	for (int i=1; i<=n; ++i){
		adj[i].clear();
	}
	for (int i=0; i<n-1; ++i){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int x = 1;
	for (int s=n-1; s>=1; s/=2){
		while (x+s<=n && check(x+s)){
			x += s;
		}
	}
	cout << x << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		solve();
	}
}
