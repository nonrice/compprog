#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void dfs(vector<vector<int>>& adj, vector<int>& d, int u){
	for (auto v : adj[u]){
		if (d[v] == -1){
			d[v] = d[u] + 1;
			dfs(adj, d, v);
		}
	}
}

vector<int> get_dist(vector<vector<int>>& adj, int u){
	vector<int> d(adj.size(), -1);
	d[u] = 0;
	dfs(adj, d, u);
	return d;
}

vector<int> get_diam_mdists(vector<vector<int>>& adj){
	vector<int> d1 = get_dist(adj, 0);
	auto u1 = max_element(d1.begin(), d1.end()) - d1.begin();
	vector<int> d2 = get_dist(adj, u1);
	auto u2 = max_element(d2.begin(), d2.end()) - d2.begin();
	vector<int> d3 = get_dist(adj, u2);

	vector<int> d4(d3.size());
	for (int i=0; i<d3.size(); ++i){
		d4[i] = max(d3[i], d2[i]);
	}

	return d4;
}

void solve(){
	int n1; cin >> n1; 
	vector<vector<int>> adj1(n1);
	for (int i=0; i<n1-1; ++i){
		int u, v; cin >> u >> v;
		--u, --v;
		adj1[u].push_back(v);
		adj1[v].push_back(u);
	}
	int n2; cin >> n2;
	vector<vector<int>> adj2(n2);
	for (int i=0; i<n2-1; ++i){
		int u, v; cin >> u >> v;
		--u, --v;
		adj2[u].push_back(v);
		adj2[v].push_back(u);
	}

	auto d1 = get_diam_mdists(adj1);
	auto d2 = get_diam_mdists(adj2);

	sort(d1.begin(), d1.end());
	sort(d2.begin(), d2.end());

	int h = max(d1.back(), d2.back());
	debug(h);
	debug(d1, d2);

	int j = n2-1;
	long long ans = 0;
	long long s = 0;
	for (int i=0; i<n1; ++i){
		while (j>=0 && d2[j]+d1[i]+1 > h){
			s += d2[j];
			--j;
		}
		
		ans += s + 1LL*(n2-j-1)*d1[i] + 1LL*(j+1)*h + (n2-j-1);
	}

	cout << ans << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	solve();
}
