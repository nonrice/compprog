#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200000];
int a[200000];

long long r[200000], s[200000];
void dfs_pre(int u, int p){
	r[u] = a[u];
	s[u] = 2;
	for (int v : adj[u]){
		if (v != p){
			dfs_pre(v, u);
			r[u] += r[v];
			s[u] += s[v];
		}
	}
	sort(adj[u].begin(), adj[u].end(), [&](int i, int j){
		return s[i]*r[j] < s[j]*r[i];
	});
}

int t = 0;
long long f = 0;
void dfs_ans(int u, int p){
	f += 1LL*t*a[u];
	for (int v : adj[u]){
		if (v != p){
			++t;
			dfs_ans(v, u);
			++t;
		}
	}
}

int m = 0;
int d[200000];
long long c[200000];
void dfs_adj(int u, int p){
	m = max(d[u], m);
	long long rr=r[u]-a[u], rs=s[u]-2;
	for (int v : adj[u]){
		if (v != p){
			d[v] = d[u]+1;
			rr -= r[v];
			rs -= s[v];
			c[v] = c[u] - s[v]*rr + rs*r[v];
			dfs_adj(v, u);
		}
	}
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	int n, t; cin >> n >> t;
	for (int i=1; i<n; ++i){
		int p, x; cin >> p >> x; --p;
		adj[p].push_back(i);
		a[i] = x;
	}
	
	dfs_pre(0, -1);
	dfs_ans(0, -1);
	if (t == 1){
		dfs_adj(0, -1);
		::t -= m;
		long long o = LLONG_MAX;
		for (int i=0; i<n; ++i){
			if (d[i] == m){
				o = min(o, c[i]);
			}
		}
		f += o;
	}

	cout << ::t << ' ' << f << '\n';
}
