#include <bits/stdc++.h>
using namespace std;

struct query {
	char t;
	int u, v;
};

query a[200000];
vector<int> adj[100001];
vector<int> e({ -1 });

bool no_add[200000];
bool inactive[100001];

int ans[100001];

void dfs(int u, int i){
	if (ans[u] == -1){
		ans[u] = i;
		for (int v : adj[u]){
			if (ans[v] == -1){
				ans[v] = i;
				dfs(v, i);
			}
		}
	}
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	int n, q; cin >> n >> q;
	fill(ans, ans+n+1, -1);
	for (int i=0; i<q; ++i){
		cin >> a[i].t >> a[i].u;
		if (a[i].t == 'A'){
			cin >> a[i].v;
		}

		if (a[i].t == 'A'){
			e.push_back(i);
		} else if (a[i].t == 'R'){
			no_add[e[a[i].u]] = true;
			a[i].v = a[e[a[i].u]].v;
			a[i].u = a[e[a[i].u]].u;
		} else if (a[i].t == 'D'){
			inactive[a[i].u] = true;
		}
	}

	for (int i=0; i<q; ++i){
		if (a[i].t == 'A' && !no_add[i]){
			cout <<a[i].u  << ' ' << a[i].v << '\n';
			adj[a[i].u].push_back(a[i].v);
			adj[a[i].v].push_back(a[i].u);
		}
	}

	for (int i=1; i<=n; ++i){
		if (!inactive[i]){
			dfs(i, q);
		}
	}
	
	for (int i=q-1; i>=0; --i){
		if (a[i].t == 'R'){
			adj[a[i].u].push_back(a[i].v);
			adj[a[i].v].push_back(a[i].u);
			if (ans[a[i].u] != -1 || ans[a[i].v] != -1){
				dfs(a[i].u, i);
				dfs(a[i].v, i);
			}
		} else if (a[i].t == 'D'){
			dfs(a[i].u, i);
		}
	}

	for (int i=1; i<=n; ++i) cout << (ans[i]==-1 ? q : ans[i]) << '\n';
}
