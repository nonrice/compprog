#include <bits/stdc++.h>
using namespace std;

#define int long long

int a[200], b[200], c[200];
int tc[200];

int n, ct, mt;

int extra(){
	int ans = 0;
	for (int i=0; i<n; ++i){
		int cur = ct*a[i] + mt*b[i];
		int req = (cur - c[i] + (b[i]-1))/b[i];
		if (req >= mt) return INT_MAX;
		ans = max(ans, req);
	}

	return ans;
}

void solve(){
	cin >> n >> ct >> mt;
	for (int i=0; i<n; ++i) cin >> a[i] >> b[i] >> c[i];

	int ans = LLONG_MAX;
	const int cto = ct;
	for (int i=0; i<cto; ++i){
		ans = min(ans, i + extra());
		--ct;
	}

	cout << ans << '\n';
}

signed main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}

