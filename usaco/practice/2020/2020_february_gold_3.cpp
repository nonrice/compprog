#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];

int k;
bool fail;
int dfs(int u, int prev){
	if (u!=1 && adj[u].size() == 1){
		return 0;
	}

	multiset<int> l;
	for (int v : adj[u]) if (v != prev){
		l.insert(dfs(v, u)+1);
	}

	/*
	cout << u << ": ";
	for (int v : l) cout << v << ' ' ;
	cout << '\n';
	*/

	int r = -1;
	while (!l.empty() && *l.begin() != k){
		int p1 = *l.begin();
		l.erase(l.begin());

		auto p2_it = l.find(k-p1);
		if (p2_it != l.end()){
			l.erase(p2_it);
		} else {
			if (r == -1){
				r = p1;
			} else {
				fail = true;
			}
		}
	}

	return max(r, 0);
}

bool check(int k){
	::k = k;
	fail = false;

	int r = dfs(1, 1);

	return !(fail || r!=0);
}

char ans[100000];

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

#ifndef LOCAL
	freopen("deleg.in", "r", stdin);
	freopen("deleg.out", "w", stdout);
#endif

	int n; cin >> n;
	for (int i=0; i<n-1; ++i){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i=1; i<=n-1; ++i){
		if ((n-1)%i==0 && check(i)){
			ans[i-1] = '1';
		} else {
			ans[i-1] = '0';
		}
	}
	cout << ans << '\n';
}

