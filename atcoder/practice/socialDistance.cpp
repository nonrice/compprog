#include <bits/stdc++.h>
using namespace std;

struct edge {
	int u, v, w;

	bool operator<(const edge& o){
		return w<o.w;
	}
};

edge a[200000];
vector<int> adj[200001];
int c[200001];

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	int n, m; cin > n >> m;
	for (int i=0; i<n; ++i) cin >> a[i].u >> a[i].v >> a[i].w;

	sort(a, a+n);
	a[0]
	for (int i=0; i<n; ++i){
		
	}
}
