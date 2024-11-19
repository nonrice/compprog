#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;

	array<vector<bool>, 2> g = { vector<bool>(n+1), vector<bool>(n+1) };
	for (int i=0; i<n; ++i){
		int x, y; cin >> x >> y;
		g[y][x] = true;
	}

	long long ans = 0;
	for (int i=0; i<=n; ++i){
		if (g[0][i] && g[1][i]){
			ans += n-2;
		}
	}
	for (int i=0; i+2<=n; ++i){
		ans += (g[0][i] && g[1][i+1] && g[0][i+2]) + (g[1][i] && g[0][i+1] && g[1][i+2]);
	}
	cout << ans << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		solve();
	}
}
