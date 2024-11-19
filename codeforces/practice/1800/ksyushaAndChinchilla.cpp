#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj[200001];

int s[200001];

int nxt_ans = 0;
int ans[200001];

void dfs(int p, int u){
	for (auto [v, i] : adj[u]){
		if (v != p){
			dfs(u, v);
			s[u] += s[v];
			if (s[v]%3 == 0) ans[nxt_ans++] = i;
		}
	}
	s[u] += 1;
}

void solve(){
	int n; cin >> n;
	
	for (int i=1; i<=n; ++i){
		adj[i].clear();
	}
	memset(s, 0, sizeof(int)*(n+1));

	for (int i=1; i<n; ++i){
		int u, v; cin >> u >> v;
		adj[u].emplace_back(v, i);
		adj[v].emplace_back(u, i);
	}

	if (n%3){
		cout << "-1\n";
		return;
	}

	nxt_ans = 0;
	dfs(0, 1);

	if (nxt_ans == n-1 - 2*(n/3)){
		cout << nxt_ans << '\n';
		for (int i=0; i<nxt_ans; ++i) cout << ans[i] << ' ';
		cout << '\n';
	} else {
		cout << "-1\n";
	}
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
