#include <bits/stdc++.h>
using namespace std;

int a[300001];

void solve(){
	int n, k; cin >> n >> k;
	for (int i=1; i<=n; ++i) cin >> a[i];

	long long ans = LLONG_MIN;
	for (int i=n; (n-i)*(n-i)<2*k*n && i>=1; --i){
		for (int j=i-1; (n-i)*(n-j)<2*k*n && j>=1; --j){
			ans = max(ans, 1LL*i*j-k*(a[i]|a[j]));
		}
	}

	cout << ans << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
