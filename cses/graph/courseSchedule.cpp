#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100000];
int vis[100000];
pair<int, int> depth[100000];

int dfs_no = 0;
int nodes_left;
bool cycle = false;

void dfs(int u, int cur_depth){
	for (auto v : adj[u]){
		if (!vis[v]){
			vis[v] = dfs_no;
			depth[v].first = cur_depth+1;
			--nodes_left;
			dfs(v, cur_depth+1);
		} else if (vis[v] == dfs_no){
			cycle = true;
			return;
		}
	}
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;
	for (int i=0; i<m; ++i){
		int u, v; cin >> u >> v;
		adj[--u].push_back(--v);
	}
	for (int i=0; i<n; ++i){
		depth[i].second = i;
	}

	nodes_left = n;
	int last_start = INT_MAX - n;
	for (int i=0; i<n; ++i){
		if (!vis[i]){
			--nodes_left;
			vis[i] = ++dfs_no;
			depth[i].first = (last_start -= nodes_left);
			dfs(i, last_start);

			if (cycle){
				cout << "IMPOSSIBLE\n";
				return 0;
			}
		}
	}

	sort(depth, depth+n);

	for (int i=0; i<n; ++i) cout << depth[i].second+1 << ' ';
	cout << '\n';
}
