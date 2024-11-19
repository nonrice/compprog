#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;

	map<int, int> f;
	int mx = 0;
	for (int i=0; i<n; ++i){
		int v; cin >> v;
		mx = max(mx, ++f[v]);
	}

	cout << n - mx << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		solve();
	}
}
