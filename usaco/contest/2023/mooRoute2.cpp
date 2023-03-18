#include <bits/stdc++.h>
using namespace std;

#define int long long

struct flight {
	int r, s, d;

	bool operator<(const flight& o) const{
		return r<o.r;
	}
};

unordered_map<int, bool> vis[200000]; //arrival-got here?
multiset<flight> adj[200000]; //depature-arrival
int a[200000];
/*
void dfs(int cur, int cur_time){
	multiset<flight>::iterator it;
	if (cur!=0 || cur_time!=0) it = adj[cur].lower_bound({cur_time+a[cur], LLONG_MIN, 1337});
	else it = adj[cur].lower_bound({cur_time, LLONG_MIN, 1337});
	while (it != adj[cur].end()){
		if (!vis[it->d][it->s]){
			vis[it->d][it->s] = true;
			int temp_d=it->d, temp_s=it->s;
			it = adj[cur].erase(it);
			dfs(temp_d, temp_s);
		} else {
			++it;
		}
	}
}*/

signed main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;
	for (int i=0; i<m; ++i){
		int c, r, d, s; cin >> c >> r >> d >> s;
		--c; --d;
		vis[d][s] = false;
		adj[c].insert({r, s, d});
	}
	for (int i=0; i<n; ++i) cin >> a[i];

	vis[0][0] = true;
	queue<pair<int, int>> bfs;
	bfs.emplace(0, 0);
	while (!bfs.empty()){
		auto [cur, cur_time] = bfs.front(); bfs.pop();
		multiset<flight>::iterator it;
		if (cur!=0 || cur_time!=0) it = adj[cur].lower_bound({cur_time+a[cur], LLONG_MIN, 1337});
		else it = adj[cur].lower_bound({cur_time, LLONG_MIN, 1337});
		while (it != adj[cur].end()){
			if (!vis[it->d][it->s]){
				vis[it->d][it->s] = true;
				int temp_d=it->d, temp_s=it->s;
				it = adj[cur].erase(it);
				bfs.emplace(temp_d, temp_s);
			} else {
				++it;
			}
		}
	}
	
	for (int i=0; i<n; ++i){
		bool reachable = false;
		int ans = LLONG_MAX;
		for (auto [k, v] : vis[i]){
			if (v){
				ans = min(ans, k);
				reachable = true;
			}
		}
		if (!reachable) cout << "-1";
		else cout << ans;

		if (i != n-1) cout << '\n';
	}
}
