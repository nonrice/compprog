#include <bits/stdc++.h>
using namespace std;

// Binomial Coefficient
// NCR_precomp: Precomputes factorials and inverse factorials modulo m in O(NCR_MAX log m)
// NCR: Calculates binomial coefficient modulo m in O(1)

constexpr long long M = 1000000007;

long long binpow(long long a, long long b, long long m){
	long long ans = 1;
	while (b){
		if (b&1) ans = ans*a%m;
		a = a*a%m;
		b >>= 1;
	}
	return ans;
}

constexpr int NCR_MAX = 200000;
long long f[NCR_MAX+1] = { 1 }, fi[NCR_MAX+1] = { 1 };

void NCR_precomp(long long m){
	for (int i=1; i<=NCR_MAX; ++i){
		f[i] = f[i-1]*i%m;
		fi[i] = binpow(f[i], m-2, m);
	}
}

long long NCR(int n, int k, long long m){
	if (n<k){
		return 0;
	}
	return f[n]*fi[n-k]%m*fi[k]%m;
}

void solve(){
	int n, k; cin >> n >> k;
	int a=0, b=0;
	for (int i=0; i<n; ++i){
		int x; cin >> x;
		a += (x==1);
		b += (x==0);
	}

	long long ans = 0;
	for (int c=(k+1)/2; c<=k; ++c){
		ans = (ans + NCR(a, c, M)*NCR(b, k-c, M)%M) % M;
	}

	cout << ans << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	NCR_precomp(M);

	int t; cin >> t;
	while (t--){
		solve();
	}
}
