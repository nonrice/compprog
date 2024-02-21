#include <bits/stdc++.h>
using namespace std;

// Binary Exponentation
// binpow: Computes a^b (mod m) in O(log(b)).

constexpr long long M = 1000000007;

long long binpow(long long a, long long b, long long m=M){
	long long ans = 1;
	while (b){
		if (b&1) ans = ans*a%m;
		a = a*a%m;
		b >>= 1;
	}
	return ans;
}

struct seg {
	int l, r;

	bool operator<(const seg& o) const {
		return r<o.r;
	}
};

seg a[100001];
long long dp[100001];

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

#ifndef LOCAL
	freopen("help.in", "r", stdin);
	freopen("help.out", "w", stdout);
#endif

	int n; cin >> n;
	for (int i=1; i<=n; ++i) cin >> a[i].l >> a[i].r;
	
	sort(a+1, a+n+1);

	long long ans = 0;
	for (int i=1; i<=n; ++i){
		long long p = 1;
		for (int j=1; j<i; ++j){
			if (a[j].r >= a[i].l){
				dp[i] = (dp[i] + dp[j]*(i-j)%M) % M;
				break;
			}
			p = p*2%M;
			dp[i] = (dp[i] + dp[j]) % M;
		}
		dp[i] = (dp[i] + p) % M;

		ans = (ans + dp[i]) % M;
	}

	cout << ans << '\n';
}
