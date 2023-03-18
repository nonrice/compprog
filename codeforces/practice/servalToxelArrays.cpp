#include <bits/stdc++.h>
using namespace std;

int q[200000][2];
int u[200000];
int a[200000];

void solve(){
	int n, m; cin >> n >> m;
	int cur = 0;
	for (int i=0; i<n; ++i){
		cin >> a[i];
		if (u[--a[i]] == 0) ++cur;
		u[a[i]] += 2;
	}

	int add = 0;
	for (int i=0; i<m; ++i){
		cin >> q[i][0] >> q[i][1];
		--q[i][0]; --q[i][1];
		if (--u[a[q[i][0]]] == 0) --cur;
		if (u[q[i][1]]++ == 0) ++cur;
		add += cur;
	}

	cout << add << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
