// Binomial Coefficient
// NCR_precomp: Precomputes factorials and inverse factorials modulo m in O(NCR_MAX log m)
// NCR: Calculates binomial coefficient modulo m in O(1)

long long binpow(long long a, long long b, long long m){
	long long ans = 1;
	while (b){
		if (b&1) ans = ans*a%m;
		a = a*a%m;
		b >>= 1;
	}
	return ans;
}

constexpr int NCR_MAX = 10000000;
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
