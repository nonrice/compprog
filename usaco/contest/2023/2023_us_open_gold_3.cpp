#include <bits/stdc++.h>
using namespace std;

int depth[1001];
bool vis[1001];
int p[1001], p2[1001];
bool gone[1001];

vector<set<int>> adj;
vector<pair<int, int>> ans;

int nodes[1000];

void calc_depth(int x){
	if (p[x] == 0){ // root
		depth[x] = 0;
		return;
	}

	if (!vis[p[x]]){
		calc_depth(p[x]);
	}

	depth[x] = depth[p[x]] + 1;
	vis[x] = true;
}

void solve(){
	int n; cin >> n;

	memset(p, 0, (n+1) * sizeof(int));
	memset(p2, 0, (n+1) * sizeof(int));
	memset(depth, 0, (n+1) * sizeof(int));
	memset(vis, 0, n+1);
	memset(gone, 0, n+1);
	adj = vector<set<int>>(n+1, set<int>());
	ans.clear();

	for (int i=0; i<n-1; ++i){
		int u, v; cin >> u >> v;
		p[u] = v;
		adj[v].insert(u);
	}

	for (int i=1; i<=n; ++i){
		calc_depth(i);
	}
	
	iota(nodes, nodes+n, 1);
	sort(nodes, nodes+n, [&](int a, int b){
			return depth[a] > depth[b];
	});
	// nodes are now sorted by depth
	
	// Idea:
	// node v requires some nodes, and also is parent of some useless nodes. 
	//
	// If node v requires node u, merge p[u] with v and set p[u]=v. You would merge all of p[u]s nodes at once but this way also is fine because the operations are guaranteed valid. Add (v, p[u]) to some unique vals data struct
	
	int m; cin >> m;
	for (int i=0; i<m-1; ++i){
		int u, v; cin >> u >> v;
		p2[u] = v;
	}
	
	for (int i=0; i<n; ++i){
		if (p2[nodes[i]] != p[nodes[i]]){
			if (p2[nodes[i]] != 0){
				ans.emplace_back(p2[nodes[i]], p[nodes[i]]);
				int a = p2[nodes[i]];
				int b = p[nodes[i]];
				assert(a > b);
				for (auto v : adj[b]){
					p[v] = a;
				}
				adj[a].merge(adj[b]);
				adj[p[b]].erase(b);
				p[b] = 0;
				gone[b] = true;
			}
		}
	}

	for (int i=1; i<=n; ++i){
		if (p[i] != 0 && p2[i] == 0 && !gone[i]){
			ans.emplace_back(i, *adj[p[i]].rbegin());
		}
	}

	/*
	for (int i=1; i<=n; ++i){
		cout << i << ": ";
		for (auto x : adj[i]) cout << x << ' ';
		cout << '\n';
	}
	*/

	cout << ans.size() << '\n';
	for (auto [x, y] : ans){
		assert(x != y);
		cout << x << ' ' << y << '\n';
	}
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
