#include <bits/stdc++.h>
using namespace std;

char b;

vector<int> adj[100001];
int l[100001], r[100001], s[100001];

int mx_l, mn_r;

int ans;
uint8_t dfs(int u, int p, uint8_t m){
	uint8_t st = 0;
	for (int v : adj[u]) if (v != p){
		st |= dfs(v, u, m | (s[v]==mx_l ? 1 : 0) | (s[v]==mn_r ? 2 : 0));
	}

	uint8_t fm = st|m;
	if (fm == 0 || fm == 3){
		s[u] = max(l[u], min(r[u], (mx_l+mn_r)/2));
		ans = max(ans, max(abs(s[u]-mx_l), abs(s[u]-mn_r)));
	} else if (fm == 1){
		s[u] = max(l[u], min(r[u], mx_l));
		ans = max(ans, abs(s[u]-mx_l));
	} else if (fm == 2){
		s[u] = max(l[u], min(r[u], mn_r));
		ans = max(ans, abs(s[u]-mn_r));
	}

	return st | (s[u]==mx_l ? 1 : 0) | (s[u]==mn_r ? 2 : 0);
}

void solve(){
	int n; cin >> n;
	fill(adj, adj+n+1, vector<int>());
	for (int u=2; u<=n; ++u){
		int v; cin >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	mx_l = INT_MIN, mn_r = INT_MAX;
	for (int i=1; i<=n; ++i){
		cin >> l[i] >> r[i];
		s[i] = -1;
		mx_l = max(mx_l, l[i]);
		mn_r = min(mn_r, r[i]);
	}

	if (mx_l <= mn_r){
		cout << "0\n";
		if (b == '1'){
			for (int i=1; i<=n; ++i){
				cout << mx_l;
				if (i != n){
					cout << ' ';
				}
			}
			cout << '\n';
		}
		return;
	}

	for (int i=1; i<=n; ++i){
		l[i] = max(l[i], mn_r);
		r[i] = min(r[i], mx_l);
		if (l[i] == r[i]){
			s[i] = l[i];
		}
	}

	ans = 0;
	dfs(1, 0, (s[1]==mx_l ? 1 : 0) | (s[1]==mn_r ? 2 : 0));
	cout << ans << '\n';
	if (b == '1'){
		for (int i=1; i<=n; ++i){
			cout << s[i];
			if (i != n){
				cout << ' ';
			}
		}
		cout << '\n';
	}
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t >> b;
	while (t--) solve();
}
