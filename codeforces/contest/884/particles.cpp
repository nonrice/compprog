#include <bits/stdc++.h>
using namespace std;

long long a[200000];
long long dp[200000];

void solve(){
	int n; cin >> n;
	for (int i=0; i<n; ++i) cin >> a[i];

	long long m1 = LLONG_MIN;
	long long ans1 = 0;
	for (int i=0; i<n; i+=2){
		if (a[i] > 0) ans1 += a[i];
		m1 = max(m1, a[i]);
	}

	long long ans2 = LLONG_MIN;
	long long m2 = 0;
	if (n > 1){
		ans2 = 0;
		m2 = LLONG_MIN;
		for (int i=1; i<n; i+=2){
			if (a[i] > 0) ans2 += a[i];
			m2 = max(m2, a[i]);
		}
	}

	if (m1 < 0) ans1 = m1;
	if (m2 < 0) ans2 = m2;
	cout << max(ans1, ans2) << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
