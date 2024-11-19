#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;

	map<int, int> r, c, d1, d2;

	long long ans = 0;
	for (int i=0; i<n; ++i){
		int x, y; cin >> x >> y;
		ans += (r[y]++) + (c[x]++) + (d1[x+y]++) + (d2[x-y]++);
	}

	cout << ans*2 << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
