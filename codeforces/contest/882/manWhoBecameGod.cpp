#include <bits/stdc++.h>
using namespace std;

int a[100];
int d[100];

void solve(){
	int n, k; cin >> n >> k;
	for (int i=0; i<n; ++i) cin >> a[i];

	for (int i=0; i<n-1; ++i){
		d[i] = abs(a[i+1] - a[i]);
	}

	sort(d, d+n-1, greater<int>());

	long long ans = accumulate(d, d+n-1, 0);
	for (int i=0; i<k-1; ++i) ans -= d[i];

	cout << ans << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
