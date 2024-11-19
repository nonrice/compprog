#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, q; cin >> n >> q;
	vector<long long> a(n);
	for (int i=0; i<n; ++i){
		cin >> a[i];
	}

	vector<long long> p(n+1);
	for (int i=1; i<=n; ++i){
		p[i] = p[i-1] + a[i-1];
	}
	long long s = accumulate(a.begin(), a.end(), 0LL);
	while (q--){
		long long l, r; cin >> l >> r;
		long long u = (l+n-1)/n;
		long long v = (r-n+1)/n;
		long long ans = s * max(0LL, v-u);
	}
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		solve();
	}
}
