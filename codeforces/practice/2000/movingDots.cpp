#include <bits/stdc++.h>
using namespace std;

int a[3002];

// Thanks, https://cp-algorithms.com/algebra/binary-exp.html#implementation
long long binpow(long long a, long long b, long long m) {
	a %= m;
	long long res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	int n; cin >> n;
	a[0] = INT_MIN;
	a[n+1] = INT_MAX;
	for (int i=1; i<=n; ++i) cin >> a[i];

	int ans = 0;
	for (int i=1; i<=n; ++i){
		for (int j=i+1; j<=n; ++j){
			int r = lower_bound(a, a+n+1, a[j] + a[j]-a[i]) - a;
			int l = lower_bound(a, a+n+1, a[i] - (a[j]-a[i])) - a;
			if (a[l] >= a[i] - (a[j]-a[i])) --l;
			ans = (ans + binpow(2, n-(r-l-1), 1000000007)) % 1000000007;
		}
	}

	cout << ans << '\n';
}
