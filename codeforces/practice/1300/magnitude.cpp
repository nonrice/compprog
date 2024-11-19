#include <bits/stdc++.h>
using namespace std;

int a[200000];
long long s[200001];

void solve(){
	int n; cin >> n;
	for (int i=0; i<n; ++i){
		cin >> a[i];
	}

	s[n] = 0;
	s[n-1] = a[n-1];
	for (int i=n-2; i>=0; --i){
		s[i] = s[i+1] + a[i];
	}

	long long ans = s[0];
	long long p = 0;
	for (int i=0; i<n; ++i){
		p += a[i];
		ans = max(ans, abs(p) + s[i+1]);
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
