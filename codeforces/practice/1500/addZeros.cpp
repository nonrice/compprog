#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;
	vector<long long> a(n);
	for (long long& v : a){
		cin >> v;
	}

	set<long long> vis;
	map<long long, vector<long long>> adj;
	for (int i=0; i<n; ++i){
		adj[a[i] - (n+1-(i+1))].push_back(i);
	}

	auto dfs = [&](auto&& self, long long u)->void{
		if (!adj.count(u)){
			return;
		}

		for (auto v : adj[u]){
			if (!vis.count(u + v)){
				vis.insert(u+v);
				self(self, u+v);
			}
		}
	};

	vis.insert(0);
	dfs(dfs, 0);

	cout << *vis.rbegin() + n << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		solve();
	}
}
