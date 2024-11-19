#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, x, y, k;
	cin >> n >> x >> y >> k;

	vector<int> a(n);
	for (int i=0; i<n; ++i){
		cin >> a[i];
	}

	long long ans = 0;
	int rx=-1, ry=-1, rb=-1;
	for (int i=0; i<n; ++i){
		if (a[i] > x || a[i] < y || a[i] == k){
			rb = i;
			rx = -1;
			ry = -1;
		}
		if (a[i] == x){
			rx = i;
		}
		if (a[i] == y){
			ry = i;
		}

		if (rx != -1 && ry != -1){
			ans += min(rx, ry)-rb;
		}
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
