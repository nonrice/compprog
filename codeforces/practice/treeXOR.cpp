#include <bits/stdc++.h>
using namespace std;

int c[200001], p[200001], s[200001], a[200001];
vector<int> adj[200001];
long long cur_ans = 0;
long long ans[200001];
int r = 1;
int n;

void init(int u, int prev){
	p[u] = prev;
	c[u] = a[u] ^ a[prev];
	++s[u];
	for (int v : adj[u]) if (v != prev){
		init(v, u);
		s[u] += s[v];
	}

	cur_ans += 1LL*c[u]*s[u];
}

void shift(int u){
	p[r] = u;
	s[r] = n-s[u];
	c[r] = a[r] ^ a[p[r]];
	cur_ans += 1LL*c[r]*s[r] - 1LL*c[u]*s[u];
	r = u;
}

void calc_ans(int u, int prev){
	ans[u] = cur_ans;
	for (int v : adj[u]) if (v != prev){
		shift(v);
		calc_ans(v, u);
		shift(u);
	}
}

void solve(){
	cin >> n;
	
	memset(c, 0, sizeof(int)*(n+1));
	memset(p, 0, sizeof(int)*(n+1));
	memset(s, 0, sizeof(int)*(n+1));
	memset(a, 0, sizeof(int)*(n+1));
	memset(ans, 0, sizeof(long long)*(n+1));
	fill(adj, adj+n+1, vector<int>());
	cur_ans = 0;
	r = 1;

	for (int i=1; i<=n; ++i) cin >> a[i];
	for (int i=0; i<n-1; ++i){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	init(1, 1);
	calc_ans(1, 1);

	for (int i=1; i<=n; ++i) cout << ans[i] << ' ';
	cout << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
