#include <bits/stdc++.h>
using namespace std;

int dsu[100000];
pair<int, int> segs[100000];
unordered_set<int> active;

int get_rep(int u){
	if (u == dsu[u]) return u;
	return dsu[u] = get_rep(dsu[u]);
}

void merge_sets(int u, int v){
	int pu = get_rep(u);
	int pv = get_rep(v);
	if (pu != pv){
		segs[pv] = { min(segs[pu].first, segs[pv].first), max(segs[pu].second, segs[pv].second) };
		active.insert(pv);
		active.erase(pu);
		dsu[pu] = pv;
	}
}

vector<int> p[100001];
vector<pair<int, int>> ans;
bool vis[100000];

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	
	int n; cin >> n;
	for (int i=0; i<n; ++i){
		dsu[i] = i;
		segs[i] = { i, i };
		int x; cin >> x;
		p[x].push_back(i);
	}

	for (int i=100000; i>0; --i){
		for (int j : p[i]){
			active.insert(j);
			if (j > 0 && vis[j-1]) merge_sets(j-1, j);
			if (j < n-1 && vis[j+1]) merge_sets(j+1, j);
			vis[j] = true;
		}

		for (int i : active){
			ans.push_back(segs[i]);
		}
	}

	cout << ans.size() << '\n';
	for (auto [l, r] : ans) cout << l+1 << ' ' << r+1 << '\n';
}
