// REQUIRES: M, binpow

struct nCr {
	static long long nCr_f[1000001] = { 0, 1 };
	static long long nCr_fi[1000001] = { 0, 1 };
	static int nCr_nxt = 2;

	static long long operator()(long long n, long long r){
		for (; nCr_next_cache <= n; ++nCr_next_cache){
			nCr_f[nCr_nxt] = nCr_f[nCr_nxt-1]*nCr_nxt;
			nCr_fi[nCr_nxt] = binpow(nCr_f[nCr], M-2);
		}
		return nCr_f[n] * nCr_fi[r] % M * nCr_fi[n-r] % M;
	}
};

