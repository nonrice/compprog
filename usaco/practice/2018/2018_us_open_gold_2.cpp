#include <bits/stdc++.h>
using namespace std;

vector<int> a[50000];

int n;
vector<int> adj[100001];
int in[100001];

map<int, int> check(int x){
	for (int i=1; i<=n; ++i){
		adj[i].clear();
		in[i] = 0;
	}

	for (int i=0; i<=x; ++i){
		for (int j=1; j<a[i].size(); ++j){
			adj[a[i][j-1]].push_back(a[i][j]);
			++in[a[i][j]];
		}
	}
	
	vector<int> s;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int u=1; u<=n; ++u){
		if (in[u] == 0){
			pq.push(u);
		}
	}
	if (pq.empty()){
		return map<int, int>({ { -1, -1 }});
	}

	int i=0;
	map<int, int> p;
	int cnt = n - pq.size();
	while (!pq.empty()){
		int u = pq.top();
		p[u] = i++;
		pq.pop();

		for (int v : adj[u]){
			if (--in[v] == 0){
				pq.push(v);
				--cnt;
			}
		}
	}
	if (cnt != 0){
		return map<int, int>({ { -1, -1} });
	}

	for (int i=0; i<=x; ++i){
		for (int j=1; j<a[i].size(); ++j){
			if (p[a[i][j]] < p[a[i][j-1]]){
				return map<int, int>({ { -1, -1 } });
			}
		}
	}

	return p;
}

int ans[100000];

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

#ifndef LOCAL
	freopen("milkorder.in", "r", stdin);
	freopen("milkorder.out", "w", stdout);
#endif

	int m; cin >> n >> m;
	for (int i=0; i<m; ++i){
		int l; cin >> l;
		for (int j=0; j<l; ++j){
			int u; cin >> u;
			a[i].push_back(u);
		}
	}

	int cur = 0;
	for (int step=m-1; step>=1; step/=2){
		while (cur + step < m){
			map<int, int> r = check(cur+step);
			if (r[-1] == 0){
				cur += step;
			} else {
				break;
			}
		}
	}

	map<int, int> r = check(cur);
	for (auto [k, v] : r){
		ans[v] = k;
	}

	for (int i=0; i<n; ++i){
		cout << ans[i];
		if (i != n-1){
			cout << ' ';
		}
	}
}
